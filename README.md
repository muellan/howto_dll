# How to build MSVC-compatible DLLs with g++ on Windows

Demo project that shows how to make an MSVC-compatible DLL that exposes some pure C functions with g++ on Windows.

## source files:
 * mtm.h is the interface header that will accompany your DLL
 * stuff.h/ccp is some other example code that goes into the DLL
 * demo.cpp is a small demo program that uses the DLL
 * Makefile 

## files when built
 * mtm.dll
 * libmtm.a : import library for your DLL
 * demo.exe : demo that uses your DLL, should execute the DLL function

## deployment
If you want to deploy your DLL you should also make sure to provide the MinGW runtime DLLs. For the latest 64-bit MinGW-w64 these should be at least libstdc++6.dll, libwinpthread.dll and libgcc_s_seh.dll.

## Build tested with
 * MinGW-w64 g++ 4.9.2 32bit with dwarf exceptions on Windows 7, 64 bit, Powershell
 * MinGW-w64 g++ 5.1.0 64bit with SEH on Windows 8.1, 64bit, Powershell

## Tested in
 * a Visual C# Express project
 * a Visual C++ Express project
 * an MS Excel 2013 VBA macro

