cmake_minimum_required (VERSION 3.4.3)

# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_VERBOSE_MAKEFILE ON)

set(TARGET
    "gst-template"
    )

project(${TARGET}
    VERSION 1.0.0
    LANGUAGES "CXX"
    )

find_package(PkgConfig)

pkg_check_modules(GST REQUIRED gstreamer-1.0)

set(SOURCES
    )

set(DEPENDENCIES_LIST
    ${GST_LIBRARIES}
    )

link_directories(
    ${GST_LIBRARY_DIRS}
    )

include_directories(
    ${GST_INCLUDE_DIRS}
    )

add_compile_options(
    -std=c++11
    -Wall
    -Wextra
    -Werror
    -Wno-unused-parameter
    )

add_definitions(
    )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(gst-helloworld "gst-helloworld.cpp")
target_link_libraries(gst-helloworld "${DEPENDENCIES_LIST}")

# add_executable(gst-appsink "gst-appsink.cpp")
# target_link_libraries(gst-appsink "${DEPENDENCIES_LIST}")