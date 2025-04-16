cmake_minimum_required(VERSION 3.10.0)
project(errorReport VERSION 0.1.0 LANGUAGES C CXX)

add_library(errorReport
    "${CMAKE_CURRENT_SOURCE_DIR}/errorReportLib/errorReport.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/errorReportLib/errorReport.hpp"
)
