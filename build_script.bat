@echo off
cmake "-S" "." "-B" "build"
cmake "--build" "build\"
copy  "build\Debug\main.exe" "."
copy  "build\main.exe" "."
copy  "build\Debug\my_googletest.exe" "."
copy  "build\my_googletest.exe" "."
rd /s /q "build"
