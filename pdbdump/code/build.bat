@echo off

if not exist ..\..\build mkdir ..\..\build
pushd ..\..\build

cl -nologo ../pdbdump/code/win32_pdbdump.c -Z7 -FC /link -incremental:no

popd