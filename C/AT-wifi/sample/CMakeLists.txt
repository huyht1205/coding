cmake_minimum_required (VERSION 3.4.3)

# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_VERBOSE_MAKEFILE ON)

set(TARGET
    "Sample of libwifi"
    )

project(${TARGET}
    VERSION 1.0.0
    LANGUAGES "C"
    )

# find_package(PkgConfig)

# pkg_check_modules(SOME_LIB REQUIRED somelib)

set(SOURCES
    )

set(LIBS
    # ${SOME_LIB_LIBRARIES}
    wifi
    pthread
    )

link_directories(
    # ${SOME_LIB_LIBRARY_DIRS}
    ../_build
    )

include_directories(
    # ${SOME_LIB_INCLUDE_DIRS}
    ../inc
    inc
    )

add_compile_options(
    -std=c99
    -Wall
    -Wextra
    -Werror
    -Wno-unused-parameter
    -g
    )

add_definitions(
    )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(server "src/server.c")
target_link_libraries(server "${LIBS}")

add_executable(client "src/client.c")
target_link_libraries(client "${LIBS}")
