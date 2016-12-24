@echo off

IF NOT EXIST ..\engine\build mkdir ..\engine\build
pushd ..\engine\build

del *pdb > NUL 2> NUL

set PathMain=..\Engine\code\engine.c
set Library=W:\lib\SDL2-2.0.5\lib\x64

set CompilerFlags=-FC -Zi -nologo

cl 	%CompilerFlags% ^ 
	%PathMain% ^
	-IW:\lib\SDL2-2.0.5\include ^
	-link SDL2.lib SDL2main.lib ^
	-LIBPATH:%Library% ^
	-SUBSYSTEM:CONSOLE
	
popd
