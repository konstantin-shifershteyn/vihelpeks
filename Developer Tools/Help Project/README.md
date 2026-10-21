# VI Helpeks Help Sources (`/Developer Tools/Help Project/`)

This folder contains the source files, project assets, and raw HTML pages used to compile the official **VI Helpeks HTML Help manual (`VIHelpeks.chm`)**.

---

## Files & Sub-Folders

* `VIHelpeks.hgprj` is a **VI Helpeks Project** file. This file is used to make VI Helpeks generate final documentation for itself.

* `/HTML Files/` folder contains static source HTML files and layout assets. These files contain general toolkit information. **These files are edited manually** and do not contain individual VI descriptions.

* `/Output/` folder contains the finalized, fully compiled HTML tree and deployment assets for the VI Helpeks help manual. This folder represents the complete help system as a collection of standalone HTML files, images, CSS stylesheets, and JavaScript files. 
  * *Automation Note:* These files are automatically updated/overwritten whenever you regenerate help using VI Helpeks.
  * *CHM Compiler Project:* This folder also contains the master **Microsoft HTML Help Workshop** project files (`.hhp`, `.hhc`, `.hhk`) required to compile the final runtime Compiled HTML Help file (`VIHelpeks.chm`).
  * *.CHM destination:* The compiled `VIHelpeks.chm` file is output directly into the target `/help/VI Helpeks/` folder.

* `/Templates/` folder contains custom HTML template files used for documentation generation.
