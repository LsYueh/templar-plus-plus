# TeMPlar++
`TMP`是臺灣證券交易所（TWSE）所使用的專屬傳輸協定，全名為`Transaction Message Protocol`，用於證券交易相關的訊息傳輸。此工具用於解析TMP提供的`委託`/`成交`/`申報`/`檔案傳輸`服務訊息內容，將序列化的字串資料轉為非序列化的資料物件後再加以利用。

<br>

Meson/Ninja + Visual Studio Build Tools 2026 (C++20)  

下載[Visual Studio Build Tools](https://visualstudio.microsoft.com/visual-cpp-build-tools/)  

<br><br>

# 開發

## launch.json

```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Debug Test App (MSVC)",
      "type": "cppvsdbg",
      "request": "launch",
      "program": "${workspaceFolder}/builddir/tests/test_tmp.exe",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [
        {
          "name": "PATH",
          "value": "${workspaceFolder}/builddir/src;${env:PATH}"
        }
      ]
    }
  ]
}
```

<br>

## settings.json

```json
{
    "terminal.integrated.profiles.windows": {
        "MSVC x64": {
            "path": "C:\\Windows\\System32\\cmd.exe",
            "args": ["/k", "C:\\Program Files (x86)\\Microsoft Visual Studio\\18\\BuildTools\\VC\\Auxiliary\\Build\\vcvars64.bat"],
            "icon": "terminal-cmd"
        }
    },
    "terminal.integrated.defaultProfile.windows": "MSVC x64",
    "editor.tabSize": 2
}
```

<br>