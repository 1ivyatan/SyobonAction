#!/bin/bash
[ -d "build" ] || mkdir "build"
cmake . -B "build" && make -C "./build/" && cp "./build/SyobonActionRaylib" "./SyobonActionRaylib"