@echo off

mkdir ..\..\build
pushd ..\..\build
cl -FC -Zi /I W:\lib\SDL2-2.0.5\lib\x64\SDL2 ..\Engine\code\Engine.c   /link SDL2.lib SDL.lib /SUBSYSTEM:CONSOLE
popd
