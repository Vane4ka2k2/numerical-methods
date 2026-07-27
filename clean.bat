@echo off
cd /d "%~dp0"

echo [numerical-methods] Cleaning build directory...

if exist build (
    rmdir /s /q build
    echo [numerical-methods] Build directory successfully removed!
) else (
    echo [numerical-methods] Build directory does not exist. Nothing to clean.
)
