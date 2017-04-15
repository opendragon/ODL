#--------------------------------------------------------------------------------------------------
#
#  File:       odl/non-iOS/CMakeLists.txt
#
#  Project:    odl
#
#  Contains:   The CMAKE definitions for the debugging library.
#
#  Written by: Norman Jaffe
#
#  Copyright:  (c) 2014 by OpenDragon.
#
#              All rights reserved. Redistribution and use in source and binary forms, with or
#              without modification, are permitted provided that the following conditions are met:
#                * Redistributions of source code must retain the above copyright notice, this list
#                  of conditions and the following disclaimer.
#                * Redistributions in binary form must reproduce the above copyright notice, this
#                  list of conditions and the following disclaimer in the documentation and / or
#                  other materials provided with the distribution.
#                * Neither the name of the copyright holders nor the names of its contributors may
#                  be used to endorse or promote products derived from this software without
#                  specific prior written permission.
#
#              THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
#              EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
#              OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
#              SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
#              INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
#              TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
#              BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
#              CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
#              ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
#              DAMAGE.
#
#  Created:    2014-02-06
#
#--------------------------------------------------------------------------------------------------

# CPack requires CMake 2.6 or greater
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

set(PROJECT_NAME "ODL")

if(APPLE)
    set(CMAKE_OSX_ARCHITECTURES "x86_64" CACHE STRING "Build architectures for Mac OSX" FORCE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.7" CACHE STRING "Deployment target for Mac OSX" FORCE)
endif()

project(${PROJECT_NAME})

include(../odlCommonSettings.cmake NO_POLICY_SCOPE)

if(WIN32)
    set(CMAKE_CONFIGURATION_TYPES Debug Release CACHE INTERNAL "" FORCE)
endif()

# Make some flags to control the build flags visibilities
mark_as_advanced(CLEAR BUILD_SHARED_LIBS)

if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
    set(LINUX ON)
    if(CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "unknown")
        set(UNKNOWN_CPU ON)
    else()
        set(UNKNOWN_CPU OFF)
    endif()
else()
    set(LINUX OFF)
    set(UNKNOWN_CPU OFF)
endif()

if(APPLE)
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11" CACHE STRING "Fixes linking error for odl"
        FORCE)
    set(CMAKE_INSTALL_PREFIX "/opt/odl" CACHE STRING "Fixes install path for odl" FORCE)
# 'rpath' warning
    cmake_policy(SET CMP0042 OLD)
endif()

set(CMAKE_USE_RELATIVE_PATHS ON CACHE BOOL "Always set file paths as relative")

if(WIN32)
    option(WIN64 "Build 64-bit binaries" ON)
else()
    set(WIN64 OFF)
endif()

# Add the ODL target path so that odl can be found
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_INSTALL_PREFIX}")

configure_file(${ODL_CONFIG_DIR}/ODLConfigVersion.cmake.in
               ${CMAKE_CURRENT_BINARY_DIR}/ODLConfigVersion.cmake @ONLY)
configure_file("${ODL_SOURCE_DIR}/odlConfig.h.in" "${ODL_SOURCE_DIR}/odlConfig.h")

if(APPLE)
    macro(ADD_FRAMEWORK fwname appname)
        find_library(FRAMEWORK_${fwname}
                    NAMES ${fwname}
                    PATHS ${CMAKE_OSX_SYSROOT}/System/Library
                    PATH_SUFFIXES Frameworks
                    NO_DEFAULT_PATH)
        if( ${FRAMEWORK_${fwname}} STREQUAL FRAMEWORK_${fwname}-NOTFOUND)
            MESSAGE(ERROR ": Framework ${fwname} not found")
        else()
            TARGET_LINK_LIBRARIES(${appname} "${FRAMEWORK_${fwname}}")
            MESSAGE(STATUS "Framework ${fwname} found at ${FRAMEWORK_${fwname}}")
        endif()
    endmacro(ADD_FRAMEWORK)
endif()

set(TARGET_ONE odlC)

if(APPLE)
    set(DO_SHARED "SHARED")
else()
    set(DO_SHARED "")
endif()

add_library(${TARGET_ONE}
            ${DO_SHARED}
            ${ODL_SOURCE_DIR}/odlSupport.cpp)
target_include_directories(${TARGET_ONE} PUBLIC
                            $<BUILD_INTERFACE:${ODL_SOURCE_DIR}> # for headers when building
                            $<INSTALL_INTERFACE:${INCLUDE_DEST}> # for client in install mode
                            )

install(TARGETS ${TARGET_ONE}
        EXPORT ${PROJECT_NAME}
        DESTINATION ${LIB_DEST}
        COMPONENT libraries)

install(FILES
        ${ODL_SOURCE_DIR}/odlDisable.h
        ${ODL_SOURCE_DIR}/odlEnable.h
        ${ODL_SOURCE_DIR}/odlInclude.h
        ${ODL_SOURCE_DIR}/odlConfig.h
        DESTINATION ${INCLUDE_DEST}
        COMPONENT headers)

install(FILES
        ${ODL_CONFIG_DIR}/ODLConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/ODLConfigVersion.cmake
        DESTINATION ${LIB_DEST}
        COMPONENT scripts)

if(APPLE)
    set(TARGET_TWO odlOC)

    add_library(${TARGET_TWO}
                ${DO_SHARED}
                ${ODL_SOURCE_DIR}/odlSupport.m)
    add_framework(Foundation ${TARGET_TWO})
    target_include_directories(${TARGET_TWO} PUBLIC
                                $<BUILD_INTERFACE:${ODL_SOURCE_DIR}> # for headers when building
                                $<INSTALL_INTERFACE:${INCLUDE_DEST}> # for client in install mode
                                )
    install(TARGETS ${TARGET_TWO}
            EXPORT ${PROJECT_NAME}
            DESTINATION ${LIB_DEST}
            COMPONENT libraries)

endif()

install(EXPORT ${PROJECT_NAME}
        DESTINATION ${LIB_DEST})

add_subdirectory(CPack)
