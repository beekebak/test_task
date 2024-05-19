#!/bin/bash

cmake -S . -B build
cmake --build build/
cp build/main .
cp build/my_googletest .
rm -rf build
