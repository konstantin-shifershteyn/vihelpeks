# Build Distribution Tools (`/__Build/`)

This folder contains VIs and configuration files to build VI Helpeks distribution packages for installation on end-user computers.


## Preamble

1. A **standard** distribution package must comply with these requirements:
   * It is a `.vip` package.
   * It is built for (and contains all VIs saved in) **LabVIEW 2014**.
   * All Pre-/Post- Build/Install/Uninstall VIs used by the **VIPM Package Builder** must be saved in LabVIEW 2014.

2. LabVIEW versions for the VIs:
   * All source VI Helpeks VIs in this repository are saved in **LabVIEW 2014**.

*(Note: Unless explicitly stated otherwise, LabVIEW 2014 or later can be used to open and run VIs from this repository. Any VI that contains `LV2014` in its name MUST be saved and run in LabVIEW 2014.)*

*(Note: To create a **standard** distribution using the VIPM Package Builder, you MUST have LabVIEW 2014 installed. If you do not have it installed, you can create a **non-standard** distribution (see below). **IMPORTANT:** Non-standard distribution packages CANNOT be distributed over the official channels, including but not limited to `VIPM`.)*


## Creating **standard** VI Helpeks distribution

1. Run `/__Build/Build VIHelpeks Deployment.vi` to build the deployment version of the toolkit VIs. This VI creates two deployments in the `/__Deploy/` folder: an intermediate deployment for the current active LabVIEW version, and a target deployment for **LabVIEW 2014** (`/__Deploy/LV 14.0/` folder), which serves as the source to build the final distribution package.
 
2. Open the `/__Build/VI Helpeks (LV2014).vipb` file in the **VIPM Package Builder** and build the package.


## Creating **non-standard** VI Helpeks Distribution

### Using the **VIPM Package Builder**

1. Create your `.vipb` file. You can use `/__Build/VI Helpeks (LV2014).vipb` as a template and reconfigure it for your needs (e.g., changing the target LabVIEW version).

2. Follow the same build steps as described for creating a standard distribution, except that you will use your custom `.vipb` file.

### Using a **ZIP** or alternative archive utility

1. Follow the step 1 as described for creating a standard distribution.

2. Pack the folders from `/__Deploy/LV 14.0/` (or deployment for your active LabVIEW version within the `/__Deploy/` folder) to your archive file (excluding project files in the root). This archive file can then be simply extracted into the LabVIEW root directory on target computers.
