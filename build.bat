@echo off

mkdir ..\engine\build
pushd ..\engine\build
cl -FC -Zi -nologo  ..\Engine\code\Engine.c -IW:\lib\SDL2-2.0.5\include -link SDL2.lib SDL2main.lib -LIBPATH:W:\lib\SDL2-2.0.5\lib\x64 -SUBSYSTEM:CONSOLE
popd
