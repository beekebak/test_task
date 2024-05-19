#!/bin/bash

cmake -S . -B build
cmake --build build/
cp build/main .
rm -rf build
