//--------------------------------------------------------------------------------------------------
//
//  File:       CppVersions.h
//
//  Project:    ODL
//
//  Contains:   The macro definitions used to detect versions of C++.
//
//  Written by: Norman Jaffe
//
//  Copyright:  (c) 2021 by OpenDragon.
//
//              All rights reserved. Redistribution and use in source and binary forms, with or
//              without modification, are permitted provided that the following conditions are met:
//                * Redistributions of source code must retain the above copyright notice, this list
//                  of conditions and the following disclaimer.
//                * Redistributions in binary form must reproduce the above copyright notice, this
//                  list of conditions and the following disclaimer in the documentation and / or
//                  other materials provided with the distribution.
//                * Neither the name of the copyright holders nor the names of its contributors may
//                  be used to endorse or promote products derived from this software without
//                  specific prior written permission.
//
//              THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//              EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//              OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//              SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//              INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//              TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//              BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//              CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//              ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//              DAMAGE.
//
//  Created:    2021-01-01
//
//--------------------------------------------------------------------------------------------------

#if (! defined(CPP_VERSIONS_H_))
# define CPP_VERSIONS_H_ /* Header guard */

# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunknown-pragmas"
#  pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# endif // defined(__APPLE__)
/*! @file
 @brief The macro definitions used to detect versions of C++. */
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)

# undef CPP_1997_
# undef CPP_2003_
# undef CPP_2011_
# undef CPP_2014_
# undef CPP_2017_
# undef CPP_2020_
# undef CPP_2023_
/*! @brief @c TRUE if C++ features from pre-2003 are supported. */
# define CPP_1997_	TRUE	/* Minimum supported C++ version */
/*! @brief @c TRUE if C++ features from C++03 are supported. */
# define CPP_2003_	(__cplusplus >= 199711L)
/*! @brief @c TRUE if C++ features from C++11 are supported. */
# define CPP_2011_	(__cplusplus >= 201103L)
/*! @brief @c TRUE if C++ features from C++14 are supported. */
# define CPP_2014_	(__cplusplus >= 201402L)
/*! @brief @c TRUE if C++ features from C++17 are supported. */
# define CPP_2017_	(__cplusplus >= 201703L)
/*! @brief @c TRUE if C++ features from C++20 are supported. */
# define CPP_2020_	(__cplusplus >= 202002L)
/*! @brief @c TRUE if C++ features from C++23 are supported. */
# define CPP_2023_    (__cplusplus >= 202302L)

#endif // ! defined(CPP_VERSIONS_H_)
