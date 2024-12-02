# CMake generated Testfile for 
# Source directory: /workspaces/tp4-note-tommy_bastienf_christine
# Build directory: /workspaces/tp4-note-tommy_bastienf_christine/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyTests "/workspaces/tp4-note-tommy_bastienf_christine/build/runTests")
set_tests_properties(MyTests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/tp4-note-tommy_bastienf_christine/CMakeLists.txt;45;add_test;/workspaces/tp4-note-tommy_bastienf_christine/CMakeLists.txt;0;")
subdirs("googletest")
