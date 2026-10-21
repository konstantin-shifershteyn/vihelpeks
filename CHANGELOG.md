# VI Helpeks Changelog

---

# VERSION 3.1

* **Note:** Please review the release notes for version 3.0 below, which introduced critical security and architectural updates.

## Licensing

### Transition to MIT
Since this version, VI Helpeks has transitioned to the Open Source model under the terms of the **MIT License** (see the full text in the accompanying `LICENSE` file). All source code of the Toolkit is available at GitHub:
	https://github.com/konstantin-shifershteyn/vihelpeks

You are entirely free to download, install, modify, and build VI Helpeks into your proprietary, closed-source commercial applications or distributed automated test systems without any legal restrictions. The only requirement is that the original copyright notice remains intact within the source code.

### Legacy License Holders
* For owners of commercial licenses for the previous versions (2.x and earlier), please review the important notice below in this document.


## VI Helpeks UI (Project Manager)
* **Erasing** a template file path control causes it to reset to the default value.
* **'Compiled HTML Help'** dialog now warns the user on an attempt to create an HHP project that already exists.
* **Project File** (`.hgprj`) stores the target `.CHM` file path as relative to the path of the `.HHP` file.
* **Bug Fix:** In the Control Descriptions category, changing selection in the Controls List while editing properties of a Control, could cause improper value assignment. This has been resolved.

## Help Generation
* **'Help Info File'** is now always created, regardless of whether `.HHP` or `.CHM` files are being generated.
* **Default Template files** used for help generation (HTML/CSS/JS) are updated to ensure high-quality documentation.
* **Custom HTML Templates** can use new keywords to define the appearance of VI Name. The default `%%VIName%%` can be replaced with `%%VIShortName%%` or `%%VIFullName%%`.

## VI Helpeks API
* **API VIs** are updated and optimized.
* **The API usage example** is updated for better understanding and learning.
* **The API example** can now be opened directly from the LabVIEW menu via `Tools >> VI Helpeks >> Help and Support`.

## Miscellaneous Changes
* Various minor enhancements, code cleanups, and performance tweaks were implemented throughout the VIs, which are not explicitly listed in this file.


---

## Important Notice for Existing License Holders (Versions 2.x and earlier)

If you or your company has previously purchased commercial licenses for older versions of VI Helpeks, please review the following terms regarding the Version 3.1 transition:

1. **Validity of Prior Licenses:** 
All commercial licenses purchased over the past years remain completely valid, active, and legally binding for the specific versions they were issued for. Your deployment history remains fully compliant.

2. **Transition to Version 3.1:** 
With the launch of Version 3.1, the entire toolkit has transitioned to the permissive **MIT License**. As a legacy customer, you are highly encouraged to upgrade your applications to Version 3.1 completely free of charge. By upgrading, your project automatically inherits the unrestricted commercial rights granted under the MIT framework.

3. **Support and Maintenance Transition:** 
All historical support arrangements, email troubleshooting channels, and direct engineering consultations associated with legacy purchases have officially concluded. Version 3.1 is a mature release provided strictly **AS IS**. Legacy users requiring ongoing updates or specific modifications are welcome to leverage the unlocked source code in this repository.

---

# VERSION 3.0

* **Free and Open:** As of version 3.0, VI Helpeks has transitioned to Free/Source-Available software. VI Helpeks VIs now feature unlocked Block Diagrams, allowing you to view, modify, and adapt the toolkit to your specific workflow. 

* **JavaScript:** VI Helpeks now utilizes new native JavaScript files to embed into generated HTML/CHM help (on demand). This eliminates third-party dependencies and strengthens the security profile for both the toolkit itself and the help files it produces. 

* **HTML and CSS:** Updated HTML templates and CSS files, combined with new JavaScript files, enable the creation of high-quality HTML/CHM help. 

* **File Association:** VI Helpeks no longer automatically sets Windows file associations for its project files. This strengthens the security profile of the toolkit. Please use the File menu to open projects. (This behavior can still be enabled manually; see the `Migration from Previous Versions` topic below.) 

* **General:** Includes various code optimizations and UI enhancements. 


### Migration from Previous Versions

* **Default JS Files:** When opening a project created in a previous version, VI Helpeks will automatically update references from old JavaScript files to the new native ones. This transition is designed to be seamless and should not affect help file functionality if default CSS and HTML templates are used. However, we recommend a quick verification of your generated output after the update. 

* **Custom CSS files:** If your project uses custom CSS, you should update it with the code from either the `default.css` or `default2.css` file, depending on your project type (Default or JS based). These files are located in the `<labview>\project\VI Helpeks\_Template` folder. Copy the code marked with the comment `new VI Helpeks 3.0 definitions` from the default CSS into your custom file. 

* **Custom HTML Templates:** If your project uses custom HTML templates, it is recommended to update the <body> tag. Replace it with the `<body class="helpVI">`, `<body class="helpPolyVI">`, or `<body class="helpMenu">`, depending on the template's intended use (ordinary VI, polymorphic VI, or palette). 

* **File Association:** To preserve VI Helpeks project file associations, use the support and example files located in the <labview>\project\VI Helpeks\_rsrc folder to build the VI Helpeks Project Runner executable. This allows you to restore file associations manually (via Windows Settings or the VI Helpeks Settings dialog) without modifying the core toolkit's security profile. 


---

# VERSIONS 2.x and earlier

* A history of features, changes, and updates across legacy VI Helpeks versions can be found directly within the compiled end-user documentation included with the product.


---