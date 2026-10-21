/*
vihrun.cpp - VI Helpeks Project Runner Example

Copyright (c) 2012-2026 Konstantin Shifershteyn.

Description:
This file is provided as a simple example of source code for VIHRUN.EXE program.
VIHRUN.EXE is used for integrating VI Helpeks project files with Windows Explorer.
For this, it should be associated with (set as a default program for) VI Helpeks
Project file type (.hgprj).

How it works:
When run, VIHRUN.EXE starts VI Helpeks in LabVIEW Development Environment and
makes it to open a given VI Helpeks Project file.
Command line:
	vihrun [options] [project_file_path]
run with "/?" or "/help" for getting options list.

How to build:
MS Visual C++ 2010 (MS Visual Studio 2010) or newer can be used for building
VIHRUN.EXE from this file. Create Win32 Project and add this file to it.
Some important project parameters:
	- Platform: WIN32
	- Linker: Windows subsystem
	- General: No Unicode or Multi-byte support
	- General: Standard Windows Libraries
	- Target file: VIHRUN.EXE

LICENSE:
This specific file is provided under a permissive license. You are 
granted the right to use, copy, modify, and redistribute this file 
and its derivatives for any purpose, including commercial applications, 
without any restrictions.

This file is provided "AS IS", without warranty of any kind.
*/

#include <stdio.h>
#include <windows.h>
#include <ShellAPI.h>

#define	MAXPATHLEN	1024	// MAX_PATH

// ========================================

int		main(int argc, char *argv[]);
int		FindLvPath(char *pathBuf, size_t pathSize);
int		OpenVIHelpeksVI(const char *DOCpath);

// ---------------
const char	*VIRelPath	= "project\\VI Helpeks\\_Start VI Helpeks.vi";
const char	*ParFileName= "vihpar.txt";

int			opt_help	= 0;
int			opt_debug	= 0;
int			opt_norun	= 0;
int			opt_build	= 0;

// ---------------
char		gbl_msgBuf[10000]	= "";
int			gbl_msgLen = 0;

#define		printf_1(fmt)			gbl_msgLen += sprintf_s(gbl_msgBuf+gbl_msgLen, sizeof(gbl_msgBuf)-gbl_msgLen-1, fmt)			//gbl_msgLen += sprintf(gbl_msgBuf + gbl_msgLen, fmt)
#define		printf_2(fmt, v1)		gbl_msgLen += sprintf_s(gbl_msgBuf+gbl_msgLen, sizeof(gbl_msgBuf)-gbl_msgLen-1, fmt, v1)		//gbl_msgLen += sprintf(gbl_msgBuf + gbl_msgLen, fmt, v1)


// ######################################################
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	return main(__argc, __argv);		//__argc and __argv are CRT global variables
}

// ######################################################
int main(int argc, char *argv[])
{
	char	DOCpath[MAXPATHLEN] = "";
	int		err = 0;

	// *** Parse command line arguments
	for (int i = 1; i < argc; i++) {
		switch (*argv[i]) {
			case '-' :
			case '/' :
				if		(strcmp(argv[i]+1, "?") == 0)		opt_help  = 1;
				else if (strcmp(argv[i]+1, "help") == 0)	opt_help  = 1;
				else if (strcmp(argv[i]+1, "debug") == 0)	opt_debug = 1;
				else if (strcmp(argv[i]+1, "norun") == 0)	opt_norun = 1;
				else if (strcmp(argv[i]+1, "build") == 0)	opt_build = 1;
				else {
					printf_2("ERROR: unsupported option '%s'.\n", argv[i]);
					err = 1;
				}
				break;
			default:
				strcpy_s(DOCpath, sizeof(DOCpath), argv[i]);	//strcpy(DOCpath, argv[i]);
		}
	}
	if (err)
		goto exit;

	// *** If started with the help option
	if (opt_help) {
		printf_1("vihrun [options] [project_file_path]\n");
		printf_1("Options:\n");
		printf_1("/?     - display help (this info)\n");
		printf_1("/debug - opens a message box with debug info\n");
		printf_1("/norun - don't run VIHelpeks\n");
		printf_1("/build - force VIHelpeks to open and build project\n");
		goto exit;
	}

	// *** open VI helpeks VI
	if (GetFileAttributes(DOCpath) == INVALID_FILE_ATTRIBUTES) {
		printf_2("ERROR: File does not exist:\n\"%s\"\n", DOCpath);
		err = 7;
		goto exit;
	}
	err = OpenVIHelpeksVI(DOCpath);

exit:
	if (opt_help || opt_debug)
		MessageBox(NULL, gbl_msgBuf, "VIHelpeks Runner", MB_OK | MB_SYSTEMMODAL);
	return err;
}


// ######################################################
// Read string value of a Registry Key
int Registry_ReadKeyValueStr(HKEY rootkey, const char *KeyName, char *ValName, char *ValData, int ValDataSize)
{
	HKEY	hkey;
	int		err = 0;
	BYTE	buf[1024];
	DWORD	size;

	err = RegOpenKeyEx(	rootkey, KeyName, 0, KEY_QUERY_VALUE, &hkey);		//KEY_READ
	if (err == ERROR_SUCCESS) {
		size = __min(ValDataSize, sizeof(buf)/sizeof(buf[0])) - 1;
		err = RegQueryValueEx(hkey, ValName, NULL, NULL, buf, &size);
		if (err == ERROR_SUCCESS)
			strncpy_s(ValData, ValDataSize, (char*)buf, size);		//strncpy(ValData, (char*)buf, size);
		RegCloseKey(hkey);
	}
	return err;
}

// ######################################################
// Find a path of an actual LabVIEW instance
int FindLvPath(char *pathBuf, size_t pathSize)
{
	const	HKEY	rootkey		= HKEY_CLASSES_ROOT;
	const	char	*KeyName	= "LabVIEWInstrument\\shell\\open\\command";
	char	*p;
	int		err = 0;

	if ((err = Registry_ReadKeyValueStr(rootkey, KeyName, "", pathBuf, pathSize)) != ERROR_SUCCESS)
		goto exit;
	if (*pathBuf == '\"') {
		memmove(pathBuf, pathBuf+1, pathSize-1);
		if ((p = strchr(pathBuf, '\"')) != NULL)
			*p = 0;
	}
exit:
	return err;
}

// ######################################################
// Open VIHelpeks VI in LabVIEW and pass parameters to it
int OpenVIHelpeksVI(const char *DOCpath)
{
	char	PARpath[MAXPATHLEN];
	char	LVpath[MAXPATHLEN];
	char	VIpath[MAXPATHLEN];
	char	*p;
	int		err = 0;

	printf_2("DOC path: \"%s\"\n", DOCpath);

	// ==============================================
	//	Find actual LabVIEW EXE path
	// ==============================================
	FindLvPath(LVpath, sizeof(LVpath));
	if (strlen(LVpath) == 0) {
		printf_1("ERROR: LabVIEW not found\n");
		err = 2;
		goto exit;
	}
	printf_2("LV path:  \"%s\"\n", LVpath);

	// ==============================================
	//	Build absolute path to VIHelpeks VI
	// ==============================================
	strcpy_s(VIpath, sizeof(VIpath), LVpath);		//strcpy(VIpath, LVpath);
	p  = strrchr(VIpath, '\\');
	if (!p || (strlen(VIpath) >= sizeof(VIpath)-1)) {
		printf_1("ERROR: building VI path\n");
		err = 3;
		goto exit;
	}
	*++p = 0;
	strcat_s(VIpath, sizeof(VIpath), VIRelPath);	//strcat(VIpath, VIRelPath);

	printf_2("VI path:  \"%s\"\n", VIpath);
	if (opt_norun)	goto exit;

	// ==============================================
	//	Write params file (used to pass commands to VIHelpeks) 
	// ==============================================
	if (strlen(DOCpath) > 0) {
		GetTempPath(sizeof(PARpath), PARpath);
		if (strlen(PARpath) > 0) { 
			p = PARpath + strlen(PARpath);
			if (*(--p) == '\\')
				*p = 0;
		}
		strcat_s(PARpath, sizeof(PARpath), "\\");			//strcat(PARpath, "\\");
		strcat_s(PARpath, sizeof(PARpath), ParFileName);	//strcat(PARpath, ParFileName);
		printf_2("PAR path: \"%s\"\n", PARpath);

		HANDLE	hFile;
		DWORD	bytes;
		hFile = CreateFile(
					PARpath,				// file to open
					GENERIC_WRITE,			// open for writing
					FILE_SHARE_READ,		// share for reading
					NULL,					// default security
					CREATE_ALWAYS,			// always create file
					FILE_ATTRIBUTE_NORMAL,	// normal file
					NULL					// no attr. template
				);
		if (hFile != INVALID_HANDLE_VALUE) {
			char	buf[MAXPATHLEN + 10];
			if (opt_build)
				sprintf_s(buf, sizeof(buf), "build = %s\r\n", DOCpath);	//sprintf(buf, "build = %s\r\n", DOCpath);
			else
				sprintf_s(buf, sizeof(buf), "open = %s\r\n", DOCpath);	//sprintf(buf, "open = %s\r\n", DOCpath);
			WriteFile(hFile, buf, (DWORD)strlen(buf), &bytes, NULL);
			CloseHandle(hFile);
		}
	}

	// ==============================================
	//	Open VIHelpeks VI in LabVIEW
	// ==============================================
	printf_1("Open VI with ShellExecute\n");
	err = (int)ShellExecute(NULL, "open", VIpath, "", "", SW_SHOWNORMAL);	// open VI with ShellExecute
	if (err > 32)
		err = 0;
		if (err)	printf_2("ERROR %d\n", err);
		else		printf_1("SUCCESS\n");
exit:
	return err;
}
