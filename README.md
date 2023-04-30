<div id="top"></div>
<br />
<div align="center">
<h2 align="center">header_docu_qt-hd_json_CycloneDX_writer_plugin</h2>

  <p align="center">
      JSon CycloneDX (SPDX) writer plugin for header_docu
    <br />
    <br />
    <a href="https://github.com/Zheng-Bote/hd_json_CycloneDX_writer_plugin/issues">Report Bug</a>
    ·
    <a href="https://github.com/Zheng-Bote/hd_json_CycloneDX_writer_plugin/issues">Request Feature</a>
  </p>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#screenshots-and-samples">Screenshots and Samples</a></li>

  </ol>
</details>

<!-- ABOUT THE PROJECT -->

### About the Project 

**JSon CycloneDX (SPDX) writer plugin for header_docu (e.g. \*.c[pp], \*.h[pp], ...)**

*short description:*

_still in progress_

### built with

Build on GNU/Linux with QT 6.5 C++17 


## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- CONTACT -->

## Contact

ZHENG Robert Zhèng Bó Tè 郑 伯特

Project Link: [https://github.com/Zheng-Bote/header_docu_qt/](https://github.com/Zheng-Bote/header_docu_qt/)


## Screenshots and Samples

**sample JSON output**

```
{
    "bomFormat": "CycloneDX",
    "components": [
        {
            "author": "ZHENG Robert",
            "contact": [
                {
                    "email": "",
                    "name": "ZHENG Robert"
                }
            ],
            "hashes": [
                {
                    "alg": "SHA256",
                    "content": "eca48024cda6ec914b4ba3e1b0be9d66cdc89f2002064607e4a2b16224d2eef8"
                }
            ],
            "licenses": [
                {
                    "expression": "GPL2"
                }
            ],
            "metadata": {
                "properties": [
                    {
                        "name": "BRIEF",
                        "value": "header_docu_cpp (main.cpp)"
                    },
                    {
                        "name": "DESC",
                        "value": "header_docu_cpp is a small nafty C++ commandline tool to read the first\ncomment block of a textfile and outputs it as HTML5- or markdown- snippet"
                    },
                    {
                        "name": "COMMENT",
                        "value": "keinen"
                    },
                    {
                        "name": "FILE_LastModified_localtime",
                        "value": "2023-04-30 13:40:10"
                    },
                    {
                        "name": "FILE_Perm_AlphaNumeric",
                        "value": "-rwxr-xr-x"
                    },
                    {
                        "name": "FILE_Perm_Numeric",
                        "value": "755"
                    },
                    {
                        "name": "FILE_Scan_UTCcurrent",
                        "value": "2023-04-30T13:17:47Z"
                    },
                    {
                        "name": "FILE_Size",
                        "value": "6818"
                    },
                    {
                        "name": "FILE_absolutePath",
                        "value": "/media/zb_bamboo/500GB/Dev/QT/header_docu_qt/ESP32_libs-main"
                    },
                    {
                        "name": "FILE_baseDirName",
                        "value": "ESP32_libs-main"
                    },
                    {
                        "name": "FILE_baseDirName",
                        "value": "ESP32_libs-main"
                    },
                    {
                        "name": "FILE_lastModified_humanUTC",
                        "value": "2023-04-30 11:40:10"
                    }
                ]
            },
            "name": "header_docu_cpp.cpp",
            "purl": "https//github.com/Zheng-Bote/header_docu",
            "type": "application",
            "version": "0.4.0"
        }
    ],
    "serialNumber": "urn:uuid:3e671687-395b-41f5-a30f-a58921a69b79",
    "specVersion": "1.4",
    "version": "1"
}
```


### the end

:vulcan_salute:

<p align="right">(<a href="#top">back to top</a>)</p>
