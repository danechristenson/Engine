@echo off

IF NOT EXIST ..\engine\build mkdir ..\engine\build
pushd ..\engine\build

set MAIN_PATH=..\..\Engine\code\engine.c
set LIBRARYPATH=W:\lib\SDL2-2.0.5\lib\x64
set LIBRARIES=SDL2.lib SDL2main.lib
set INCLUDE=W:\lib\SDL2-2.0.5\include

set CompilerFlags=-FC -Zi -nologo

cl %CompilerFlags% ^ 
	%MAIN_PATH% ^
	-I%INCLUDE% ^
	-link %LIBRARIES% ^
	-LIBPATH:%LIBRARYPATH% ^
	-SUBSYSTEM:CONSOLE
		
popd
