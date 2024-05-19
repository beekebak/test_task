#!/bin/bash

cmake -S . -B build
cmake --build build
make build
cp build/main .
rm -rf build
