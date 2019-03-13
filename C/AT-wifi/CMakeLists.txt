cmake_minimum_required (VERSION 3.4.3)

# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_VERBOSE_MAKEFILE ON)

set(TARGET
    "wifi"
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
    )

if(NOT DEFINED __arm__)
    message("[CONF] WiFi implementation: POSIX message queue")
    set(SOURCES ${SOURCES} src/wifi_posix_socket.c)
    set(LIBS ${LIBS} rt)
else(NOT DEFINED __arm__)
    message("[CONF] WiFi implementation: AT command")
    set(SOURCES ${SOURCES} src/wifi_at_cmd.c)
endif(NOT DEFINED __arm__)


link_directories(
    # ${SOME_LIB_LIBRARY_DIRS}
    )

include_directories(
    # ${SOME_LIB_INCLUDE_DIRS}
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

add_library(${TARGET} SHARED
    "${SOURCES}"
    )

set(PUBLIC_HEADER_FILES
    ${TARGET}.h
    )

set_target_properties(${TARGET} PROPERTIES
    PUBLIC_HEADER "${PUBLIC_HEADER_FILES}"
    )

install(TARGETS ${TARGET}
    LIBRARY         DESTINATION lib
    PUBLIC_HEADER   DESTINATION include
    )

target_link_libraries(${TARGET} "${LIBS}")
