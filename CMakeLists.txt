cmake_minimum_required (VERSION 2.6)
include_directories("include")
project (collections_test)
set(CHECK_INSTALL_DIR "/usr/local/lib")
add_executable(collections_test src/test.c)
