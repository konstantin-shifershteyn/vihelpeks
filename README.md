# VI Helpeks toolkit for LabVIEW

Copyright (c) 2012-2026 Konstantin Shifershteyn. All rights reserved.

## Introduction
VI Helpeks is a toolkit for LabVIEW providing UI tools and API VIs for building professional HTML/CHM help for VIs and Function Palettes. It automatically generates documentation in the native LabVIEW Help style by collecting information directly from source VIs, while offering extensive options to customize the final output.

This repository contains VI Helpeks source code, developer tools, and the end-user documentation.

## Tools and Requirements
To open, modify, or rebuild the various components of this toolkit, the following environment tools are used:
* **LabVIEW Version:** All LabVIEW VIs in this repository are saved natively in **LabVIEW 2014** format.
* **Documentation Compiler:** Microsoft HTML Help Workshop is used to compile the final documentation CHM file.
* **Help Generation Tool:** VI Helpeks itself is used to generate documentation HTML files for its API VIs.

## No Dependencies & EU CRA Compliance

To simplify compliance tracking and risk assessments for commercial systems covered by the **EU Cyber Resilience Act (CRA)**, the dependency footprint and system interactions of this toolkit are detailed below:

* **Zero Third-Party Dependencies:** The toolkit is written in 100% pure LabVIEW graphical code. It does not utilize, bundle, or rely on any third-party open-source libraries, external packages, or commercial software components.
* **Environmental Tooling (CHM Compilation):** To optionally compile Microsoft HTML Help (`.chm`) binaries, the toolkit requires the standard external Microsoft HTML Help Workshop environment (`hhc.exe`) to be installed on the host system. This is an environment tooling prerequisite and is not bundled with or embedded inside the toolkit's code footprint.
* **Native LabVIEW Execution:** All core logic, documentation parsing, and HTML generation consist exclusively of native LabVIEW primitives and standard functions.
* **Isolated Local OS Interactivity:** 
  * *System Interactivity:* The toolkit utilizes standard LabVIEW `System Exec.vi` and `Call Library Function Node (CLFN)` for a minimal number of tasks. For example, invoking the local Microsoft HTML Help Compiler (`hhc.exe`) to compile `.chm` help files, or opening localized project assets (such as HTML or image files) for editing or browsing.
  * *Network Isolation:* The toolkit operates entirely locally. Neither the LabVIEW code nor the generated generated files invoke any APIs, scripts, or commands for networking, telemetry, internet data transmission, or remote execution.
* **HTML/CSS/JS Assets:** The toolkit uses HTML template and CSS files, and can generate standard HTML files or HTML utilizing embedded JavaScript (JS) for enhanced UI layout and features. 
  * All default HTML, JavaScript, and CSS styles supplied with the toolkit are exclusively of custom development, contain no third-party scripts, libraries, or external imports, and operate completely offline.
  * *Custom Templates:* Users can optionally assign their own custom HTML templates, CSS, or JS files. While utilizing custom assets does not affect the toolkit's native security footprint, the security vetting and compliance of these user-supplied files are exclusively the responsibility of the end-user.
* **Audit-Ready:** Because the full LabVIEW source code is completely unlocked and visible, the toolkit is 100% auditable for corporate Software Bill of Materials (SBOM) generation, supply-chain validation, and static code analysis.


## Versions Log
The list of new features is disclosed directly inside the accompanying help documentation and the [CHANGELOG.md](CHANGELOG.md) file.

Starting with version 3.1, VI Helpeks transitioned to a completely open-source project under the terms of the **MIT License** to extend the audience and build 100% developer trust.

## Maintenance & Support Notice
VI Helpeks is a mature product with a rich history. With the launch of Version 3.1, the toolkit has transitioned to a fully open-source project and is provided **AS IS, WITHOUT WARRANTY OF ANY KIND**. 

The author is an individual developer and **can no longer guarantee technical support, email troubleshooting, or ongoing maintenance**. Because the full source code is now unlocked, you have complete control. If you encounter an edge-case bug or wish to optimize the engine further for your specific needs, you are enthusiastically welcome to fork this repository, make modifications, and submit a Pull Request.

## Licensing (MIT)
This project is completely open-source under the terms of the **MIT License** (see the full text in the accompanying `LICENSE` file). 

You are entirely free to download, install, modify, and build VI Helpeks into your proprietary, closed-source commercial or distributed applications without any legal restrictions. The only requirement is that the original copyright notice remains intact within the source code.

* **Legacy Customer Notice:** If you or your company hold historical commercial licenses for older versions (2.x and earlier), please see the dedicated [Legacy License Holders section in the CHANGELOG](CHANGELOG.md#important-notice-for-existing-license-holders-versions-2x-and-earlier) for terms regarding your upgrade path and discontinued tracking fees.

## Support the Developer & Project
VI Helpeks Toolkit is distributed 100% free of charge to maximize adoption and accessibility across the global LabVIEW community. However, maintaining comprehensive developer tools requires considerable effort over years. 

If VI Helpeks saves your team valuable hours or is actively used in your projects or documentation workflows, please consider supporting the author's efforts and ongoing work.

### Sponsorship & Invoicing
At the moment, sponsorship payments can be accepted exclusively via direct international bank wire transfer (SWIFT). If your company requires formal documentation for tax compliance, the author can provide a manual invoice and payment receipt. To request bank wire routing details or a formal corporate invoice, please contact the author via the verified contact details on the **[GitHub Profile Page](https://github.com/konstantin-shifershteyn)** with your billing details and desired sponsorship amount.

---

## Repository Structure

### Source files targeted to their respective LabVIEW directory locations
* `/Examples/` folder contains Example VIs targeted to `<labview>\examples\`.
* `/Help/` folder contains Documentation files targeted to `<labview>\help\`.
* `/Project/` folder contains the main VI Helpeks UI and utilities targeted to `<labview>\project\`.
* `/vi.lib/` folder contains VI Helpeks API VIs and palettes targeted to `<labview>\vi.lib\`.

### Developer tools
* `/Developer Tools/` folder contains VIs used at development phase and assets. In addition, it contains VI Helpeks Project, HTML files, and assets to build VI Helpeks end-user documentation.

### Building and Distribution
* `/__Build/` folder contains VIs and configuration files to build VI Helpeks distribution packages for installation on end-user computers.
* `/__Deploy/` folder is the target for generating LabVIEW code that is used for building distribution packages. See the [/__Deploy/README.md](/__Deploy/README.md) file for details.
* `/__Packaged/` folder is the target for distribution packages you build. See the [/__Packaged/README.md](/__Packaged/README.md) file for details.
