#Example CMakeLists.txt
#You may need to update this depending on the location of your CMakeLists.txt and main
cmake_minimum_required(VERSION 3.10.0)
project(testingProject LANGUAGES C CXX)

include(errorReportLib/CMakeLists.txt)

add_executable(mainTesting example/testMain.cpp)
target_link_libraries(mainTesting PRIVATE errorReport) 
target_include_directories(mainTesting PRIVATE errorReportLib)
