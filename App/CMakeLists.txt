###
# Slums: A simple F Prime application that blinks the onboard TM4C123GXL
#            LED at 1Hz.
###
cmake_minimum_required(VERSION 3.13)
cmake_policy(SET CMP0048 NEW)
project(App VERSION 0.0.0.0 DESCRIPTION "A simple F´ application for templating" HOMEPAGE_URL "https://github.com/ThibFrgsGmz/Slums" LANGUAGES C CXX )

# include all of the f prime core components and imports the make system.
include("${FPRIME_FRAMEWORK_PATH}/cmake/FPrime.cmake")
include("${FPRIME_FRAMEWORK_PATH}/cmake/FPrime-Code.cmake")
# include("${PROJECT_SOURCE_DIR}/../fprime-tiva/fprime-tiva.cmake")

# include the component(s)
add_fprime_subdirectory(${PROJECT_SOURCE_DIR}/Blinker)
add_fprime_subdirectory(${PROJECT_SOURCE_DIR}/Top)

# create the topology and deployment
set(SOURCE_FILES ${CMAKE_CURRENT_LIST_DIR}/Top/main.cpp)
set(MOD_DEPS ${PROJECT_NAME}/Top)
register_fprime_deployment()

# get_module_name(${CMAKE_CURRENT_LIST_DIR})
# add_tiva_startup_dependency(${MODULE_NAME})

# The following compile options will only apply to the deployment executable.
# The extra warnings trigger in core F Prime so we don't apply them there.
target_compile_options(${PROJECT_NAME} PUBLIC -Wall)
target_compile_options(${PROJECT_NAME} PUBLIC -Wextra)
target_compile_options(${PROJECT_NAME} PUBLIC -Werror)
target_compile_options(${PROJECT_NAME} PUBLIC -Wpedantic)
target_compile_options(${PROJECT_NAME} PUBLIC -Wshadow)
target_compile_options(${PROJECT_NAME} PUBLIC -Wconversion)
target_compile_options(${PROJECT_NAME} PUBLIC -Wsign-conversion)
target_compile_options(${PROJECT_NAME} PUBLIC -Wformat-security)
target_compile_options(${PROJECT_NAME} PUBLIC -Wnon-virtual-dtor)
target_compile_options(${PROJECT_NAME} PUBLIC -Wnull-dereference)
target_compile_options(${PROJECT_NAME} PUBLIC -Wold-style-cast)
target_compile_options(${PROJECT_NAME} PUBLIC -Wcast-align)
target_compile_options(${PROJECT_NAME} PUBLIC -Woverloaded-virtual)
target_compile_options(${PROJECT_NAME} PUBLIC -Wno-unused-parameter)
target_compile_options(${PROJECT_NAME} PUBLIC -Wundef)
target_compile_options(${PROJECT_NAME} PUBLIC -Wdouble-promotion)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)