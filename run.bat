@echo off
setlocal enabledelayedexpansion

cd /d "%~dp0"

if not exist "build\Release\numerical-methods.exe" (
    if exist "build\Debug\numerical-methods.exe" (
        echo [+] Launching Debug build...
        "build\Debug\numerical-methods.exe"
        exit /b 0
    )
    echo [*] Binary not found. Running build.bat first...
    call build.bat
    if errorlevel 1 exit /b 1
)

echo [+] Launching numerical-methods.exe...
"build\Release\numerical-methods.exe"
