@echo off

IF NOT EXIST build mkdir build
pushd build

set MAIN_PATH=..\code\engine.c
set LIBRARYPATH=W:\lib\SDL2-2.0.5\lib\x64
set LIBRARIES=SDL2.lib SDL2main.lib
set INCLUDE=W:\lib\SDL2-2.0.5\include

cl  /nologo ^
    /I%INCLUDE% ^
    /FC ^
    /Zi ^
    %MAIN_PATH% ^
    /link ^ 
    /LIBPATH:%LIBRARYPATH% ^
    %LIBRARIES% ^
    /SUBSYSTEM:CONSOLE

popd

