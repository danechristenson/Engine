@echo off

mkdir ..\..\build
pushd ..\..\build
cl -FC -Zi ..\Engine\code\Engine.c
popd
