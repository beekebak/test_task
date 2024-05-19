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



###############################################################################

Found some ambiguousity. If id2 event happens it isn't said that id12 event
should happen but in id12 event description it seems so. In my realization
it happens.
