#Example CMakeLists.txt

cmake_minimum_required(VERSION 3.10.0)
project(testingProject VERSION 0.1.0 LANGUAGES C CXX)

include(errorReportLib/CMakeLists.txt)

add_executable(mainTesting example/testMain.cpp)
target_link_libraries(mainTesting PRIVATE errorReport) 
target_include_directories(mainTesting PRIVATE errorReportLib)