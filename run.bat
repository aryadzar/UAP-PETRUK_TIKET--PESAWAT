@echo off

g++ utaman.cpp -o coba -lsfml-audio-2

if %ERRORLEVEL% neq 0 (
    echo Kesalahan pada program
    exit /b 1
)

.\coba.exe

