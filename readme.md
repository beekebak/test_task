How to use: build it manually or using scripts
  linux: build_script.sh
  win: build_script.bat (not sure if works properly)
then
  on linux $main file
  on windows $main.exe file.txt
for tests
  uncomment #set(TESTMODE "testing") in CMakeLists.txt
  build
  on linux $my_googletest file
  on windows $my_googletest.exe file.txt 
