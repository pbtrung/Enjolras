cmake_minimum_required(VERSION 3.2)
project(enjolras)

set(CMAKE_CXX_STANDARD 14)

set(ENJOLRAS_VERSION_MAJOR 0)
set(ENJOLRAS_VERSION_MINOR 999999)
set(ENJOLRAS_VERSION_PATCH 0)

set(SRC_PATH "${PROJECT_SOURCE_DIR}/src")
set(INC_PATH "${PROJECT_SOURCE_DIR}/include")

# Build flags
set(COMMON_FLAGS "-Wall -Wl,--no-as-needed -lblas -llapacke")
set(CMAKE_CXX_FLAGS_RELEASE "${COMMON_FLAGS} -O3 -march=native")
set(CMAKE_CXX_FLAGS_DEBUG "${COMMON_FLAGS} -O0 -ggdb")

configure_file(
    "${SRC_PATH}/${PROJECT_NAME}-cfg.hpp.in"
    "${INC_PATH}/${PROJECT_NAME}-cfg.hpp"
)

# Default is debug build
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Common
file(GLOB_RECURSE ENJOLRAS_COMMON_SRC "${SRC_PATH}/utils/*.cpp")
set(ENJOLRAS_SRC ${ENJOLRAS_COMMON_SRC})
file(GLOB_RECURSE ENJOLRAS_COMMON_SRC "${SRC_PATH}/yaml-cpp/*.cpp")
list(APPEND ENJOLRAS_SRC ${ENJOLRAS_COMMON_SRC})
include_directories(${INC_PATH})

# Solid mechanics module
option(USE_SM "Enable solid mechanics module" ON)
if(USE_SM)
    file(GLOB_RECURSE ENJOLRAS_SM_SRC "${SRC_PATH}/sm/*.cpp")
    list(APPEND ENJOLRAS_SRC ${ENJOLRAS_SM_SRC})
endif()

# Build library
option(BUILD_LIB "Build library" ON)
if(BUILD_LIB)
    set(ENJOLRAS_LIB "lib${PROJECT_NAME}")
    set(ENJOLRAS_LIB_SRC "${SRC_PATH}/${PROJECT_NAME}.cpp")
    add_library(${ENJOLRAS_LIB} STATIC ${ENJOLRAS_LIB_SRC} ${ENJOLRAS_SRC})
    
    set_target_properties(
        ${ENJOLRAS_LIB}
        PROPERTIES
        PREFIX                           ""
        SUFFIX                           ""
        OUTPUT_NAME                      "lib${PROJECT_NAME}.a"
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${PROJECT_SOURCE_DIR}/bin/debug"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/bin/release"
    )
endif()

# Build executable binary
option(BUILD_EXE "Build executable binary" ON)
if(BUILD_EXE AND BUILD_LIB)
    set(ENJOLRAS_BIN ${PROJECT_NAME})
    add_executable(${ENJOLRAS_BIN} "${SRC_PATH}/main.cpp")
    target_link_libraries(${ENJOLRAS_BIN} ${ENJOLRAS_LIB})
    
    set_target_properties(
        ${ENJOLRAS_BIN}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${PROJECT_SOURCE_DIR}/bin/debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/bin/release"
    )
endif()

# Build test
option(BUILD_TEST "Build test" ON)
if(BUILD_TEST AND BUILD_LIB)
    set(ENJOLRAS_TEST "test-${PROJECT_NAME}")
    set(ENJOLRAS_TEST_SRC "${PROJECT_SOURCE_DIR}/test/test-${PROJECT_NAME}.cpp")
    include_directories("${PROJECT_SOURCE_DIR}/test")
    add_executable(${ENJOLRAS_TEST} ${ENJOLRAS_TEST_SRC})
    target_link_libraries(${ENJOLRAS_TEST} ${ENJOLRAS_LIB})
    
    set_target_properties(
        ${ENJOLRAS_TEST}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${PROJECT_SOURCE_DIR}/bin/debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/bin/release"
    )
endif()
