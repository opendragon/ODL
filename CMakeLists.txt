#--------------------------------------------------------------------------------------------------
#
#  File:       odl/CMakeLists.txt
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

if(WIN32)
    set(CMAKE_CONFIGURATION_TYPES Debug Release CACHE INTERNAL "" FORCE)
endif(WIN32)

project(odl)

set(odl_VERSION_MAJOR 1)
set(odl_VERSION_MINOR 0)
set(odl_VERSION_PATCH 0)
set(odl_VERSION_STRING "${odl_VERSION_MAJOR}.${odl_VERSION_MINOR}.${odl_VERSION_PATCH}")
set(odl_COMPANY "OpenDragon")

set(odl_SOURCE_DIR "${PROJECT_SOURCE_DIR}")

# Make some flags to control the build flags visibilities
mark_as_advanced(CLEAR BUILD_SHARED_LIBS)
mark_as_advanced(CLEAR CMAKE_OSX_ARCHITECTURES)
#mark_as_advanced(CLEAR CMAKE_OSX_DEPLOYMENT_TARGET)
mark_as_advanced(SET CMAKE_INSTALL_RPATH)
mark_as_advanced(SET CMAKE_BUILD_WITH_INSTALL_RPATH)

if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
    set(LINUX ON)
    if(CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "unknown")
        set(UNKNOWN_CPU ON)
    else(CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "unknown")
        set(UNKNOWN_CPU OFF)
    endif(CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "unknown")
else(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
    set(LINUX OFF)
    set(UNKNOWN_CPU OFF)
endif(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")

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
            TARGET_LINK_LIBRARIES(${appname} "${FRAMEWORK_${fwname}}/${fwname}")
            MESSAGE(STATUS "Framework ${fwname} found at ${FRAMEWORK_${fwname}}")
        endif()
    endmacro(ADD_FRAMEWORK)
endif(APPLE)

if(APPLE)
    set(E_PATH "@executable_path")
    set(CMAKE_OSX_ARCHITECTURES "x86_64" CACHE STRING "Build architectures for Mac OSX" FORCE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.9" CACHE STRING "Deployment target for Mac OSX" FORCE)
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11" CACHE STRING "Fixes linking error for odl"
        FORCE)
    set(CMAKE_EXE_LINKER_FLAGS "-headerpad_max_install_names" CACHE STRING "Increases link limit"
        FORCE)
    set(CMAKE_INSTALL_PREFIX "/opt/odl" CACHE STRING "Fixes install path for odl" FORCE)
    set(CMAKE_INSTALL_RPATH
"${E_PATH}/../lib;${E_PATH}/../odl;${E_PATH}/../odl;${E_PATH}/../../odl;${E_PATH}/../../odl;${CMAKE_INSTALL_PREFIX}/lib"
        CACHE STRING "Fixes rpath" FORCE)
    set(CMAKE_BUILD_WITH_INSTALL_RPATH ON CACHE BOOL "Make sure to use rpath")
# 'rpath' warning
    cmake_policy(SET CMP0042 OLD)
endif(APPLE)

if(WIN32)
    if(NOT ("${CMAKE_EXE_LINKER_FLAGS}" MATCHES ".*NODEFAULTLIB:libcmt.*"))
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:libcmt" CACHE STRING
            "Flags used by the linker." FORCE)
    endif(NOT ("${CMAKE_EXE_LINKER_FLAGS}" MATCHES ".*NODEFAULTLIB:libcmt.*"))
endif(WIN32)

set(CMAKE_USE_RELATIVE_PATHS ON CACHE BOOL "Always set file paths as relative")

if(WIN32)
    option(WIN64 "Build 64-bit binaries" ON)
else(WIN32)
    set(WIN64 OFF)
endif(WIN32)

option(odl_ChattyStart "Report the version numbers when launching an executable")

option(odl_DoExplicitCheckForOK "Check OK responses for validity")

option(odl_DO_SWIG "Build the SWIG files" OFF)

# Add the odl target path so that odl can be found
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_INSTALL_PREFIX}")

# Find SWIG
if(odl_DO_SWIG)
    find_package(SWIG REQUIRED)
    include(${SWIG_USE_FILE})
    set(CMAKE_SWIG_FLAGS "")
endif(odl_DO_SWIG)

include_directories("${odl_SOURCE_DIR}")

set(THIS_TARGET odLogging)
set(OTHER_TARGET_CSHARP odLogging_swig_csharp)
set(OTHER_TARGET_PYTHON odLogging_swig_python)

if(APPLE)
    set(DO_SHARED "SHARED")
else(APPLE)
    set(DO_SHARED "")
endif(APPLE)

option(ODL_DO_SWIG OFF)
mark_as_advanced(ODL_DO_SWIG)

add_library(${THIS_TARGET}
            ${DO_SHARED}
            ODLogging.cpp)

install(TARGETS ${THIS_TARGET}
        DESTINATION lib
        COMPONENT libraries)

install(FILES
        ODDisableLogging.h
        ODEnableLogging.h
        ODLogging.h
        DESTINATION include
        COMPONENT headers)

if(APPLE)
    set(THIS_TARGET odLoggingOC)

    add_library(${THIS_TARGET}
                ${DO_SHARED}
                ODLogging.m)
    add_framework(Foundation ${THIS_TARGET})

    install(TARGETS ${THIS_TARGET}
            DESTINATION lib
            COMPONENT libraries)
endif(APPLE)

if(ODL_DO_SWIG)
    set(ODL_SWIG_SOURCES swig_odl_in/ODLogging.i ODLogging.h ODLogging.cpp)

    include_directories("${PROJECT_SOURCE_DIR}/odl")
    set_source_files_properties(swig_odl_in/ODLogging.i PROPERTIES CPLUSPLUS ON)
    set_source_files_properties(swig_odl_in/ODLogging.i PROPERTIES SWIG_FLAGS "-includeall")

    set(CMAKE_SWIG_OUTDIR "${PROJECT_SOURCE_DIR}/odl/swig_odl_out_csharp")

    swig_add_module(${OTHER_TARGET_CSHARP} csharp ${ODL_SWIG_SOURCES})

    install(TARGETS ${OTHER_TARGET_CSHARP}
            DESTINATION lib
            COMPONENT libraries)

    install(FILES
            swig_odl_out_csharp/ODLogging.cs
            swig_odl_out_csharp/ODLoggingPINVOKE.cs
            DESTINATION csharp
            COMPONENT headers)

    set(CMAKE_SWIG_OUTDIR "${PROJECT_SOURCE_DIR}/odl/swig_odl_out_python")

    find_package(PythonLibs)
    include_directories(${PYTHON_INCLUDE_PATH})

    swig_add_module(${OTHER_TARGET_PYTHON} python ${ODL_SWIG_SOURCES})

    swig_link_libraries(${OTHER_TARGET_PYTHON}
                        ${THIS_TARGET}
                        ${PYTHON_LIBRARIES})

    # Note the modified target name!
    install(TARGETS _${OTHER_TARGET_PYTHON}
            DESTINATION lib
            COMPONENT libraries)

    install(FILES
            swig_odl_out_python/ODLogging.py
            swig_odl_out_python/ODLoggingPYTHON_wrap.cxx
            DESTINATION python
            COMPONENT headers)

endif(ODL_DO_SWIG)

#add_subdirectory(CPack)

enable_testing()
