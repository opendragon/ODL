//--------------------------------------------------------------------------------------------------
//
//  File:       odlFunctions.h
//
//  Project:    ODL
//
//  Contains:   The function declarations and macro definitions for the logging facility.
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
//  Created:    2021-01-04
//
//--------------------------------------------------------------------------------------------------

#if (! defined(ODL_FUNCTIONS_H_))
# define ODL_FUNCTIONS_H_ /* Header guard */

# include <odlConfig.h>

# include <stdint.h>
# if defined(__OBJC__)
#  import <Foundation/Foundation.h>
# endif // defined(__OBJC__)
# if defined(__APPLE__)
#  include <CoreGraphics/CGGeometry.h>
# endif // defined(__APPLE__)

# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunknown-pragmas"
#  pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# endif // defined(__APPLE__)
/*! @file
 @brief The function declarations and macro definitions for the logging facility. */
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)

// Make sure that a couple of critical macros are defined!
# if (! defined(TRUE))
#  define TRUE  1
# endif // ! defined(TRUE)
# if (! defined(FALSE))
#  define FALSE 0
# endif // ! defined(FALSE)

# undef BSD_
# if defined(__FreeBSD__)
#  define BSD_	TRUE
# elif defined(__NetBSD__)
#  define BSD_	TRUE
# elif defined(__OpenBSD__)
#  define BSD_	TRUE
# elif defined(__bsdi__)
#  define BSD_	TRUE
# elif defined(__Dragonfly__)
#  define BSD_	TRUE
# else // ! defined(__Dragonfly__)
#  define BSD_	FALSE
# endif // ! defined(__Dragonfly__)

# if (! defined(MAC_OR_LINUX_))
  /* TRUE if non-Windows, FALSE if Windows. */
#  if defined(__APPLE__)
#   define MAC_OR_LINUX_ TRUE
#   define LINUX_ FALSE
#  elif defined(__linux__)
#   define MAC_OR_LINUX_ TRUE
#   define LINUX_ TRUE
#  else // ! defined(__linux__)
#   define MAC_OR_LINUX_ BSD_
#   define LINUX_ FALSE
#  endif // ! defined(__linux__)
# endif // ! defined(MAC_OR_LINUX_)

# if MAC_OR_LINUX_
#  define ODL_FUNC_NAME_ __func__
# else // ! MAC_OR_LINUX_
#  define ODL_FUNC_NAME_ __FUNCTION__
# endif // ! MAC_OR_LINUX_

/*! @brief The options available for logging. */
enum ODLoption
{
    /*! @brief No special logging options. */
    kODLoggingOptionNone = 0x00,

    /*! @brief Write the logging output to a file. */
    kODLoggingOptionWriteToFile = 0x01,

    /*! @brief Include the process identifier in the logging output. */
    kODLoggingOptionIncludeProcessID = 0x02,

    /*! @brief Include the thread identifier in the logging output. */
    kODLoggingOptionIncludeThreadID = 0x04,

    /*! @brief Enable threading support for logging. */
    kODLoggingOptionEnableThreadSupport = 0x08,

    /*! @brief Write the logging output to 'stderr' as well, if not logging to a file. */
    kODLoggingOptionWriteToStderr = 0x10

}; // ODLoption

# if defined(__cplusplus)
extern "C"
{
# endif // defined(__cplusplus)

    /*! @brief Write a string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text The string to be written. */
    void
    ODL_
        (ODL_Std_Params,
         const char *   text);

    /*! @brief Write a boolean value to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the value to be written.
     @param[in] val1 The value to be written. */
    void
    ODLB1_
        (ODL_Std_Params,
         const char *   text1,
         const bool     val1);

    /*! @brief Write two boolean values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] val1 The first value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] val2 The second value to be written. */
    void
    ODLB2_
        (ODL_Std_Params,
         const char *   text1,
         const bool     val1,
         const char *   text2,
         const bool     val2);

    /*! @brief Write three boolean values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] val1 The first value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] val2 The second value to be written.
     @param[in] text3 The caption for the third value to be written.
     @param[in] val3 The third value to be written. */
    void
    ODLB3_
        (ODL_Std_Params,
         const char *   text1,
         const bool     val1,
         const char *   text2,
         const bool     val2,
         const char *   text3,
         const bool     val3);

    /*! @brief Write four boolean values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] val1 The first value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] val2 The second value to be written.
     @param[in] text3 The caption for the third value to be written.
     @param[in] val3 The third value to be written.
     @param[in] text4 The caption for the fourth value to be written.
     @param[in] val4 The fourth value to be written. */
    void
    ODLB4_
        (ODL_Std_Params,
         const char *   text1,
         const bool     val1,
         const char *   text2,
         const bool     val2,
         const char *   text3,
         const bool     val3,
         const char *   text4,
         const bool     val4);

    /*! @brief Write a character value to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the value to be written.
     @param[in] val1 The value to be written. */
    void
    ODLC1_
        (ODL_Std_Params,
         const char *   text1,
         const char     val1);

    /*! @brief Write two character values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] val1 The first value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] val2 The second value to be written. */
    void
    ODLC2_
        (ODL_Std_Params,
         const char *   text1,
         const char     val1,
         const char *   text2,
         const char     val2);

    /*! @brief Write three character values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] val1 The first value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] val2 The second value to be written.
     @param[in] text3 The caption for the third value to be written.
     @param[in] val3 The third value to be written. */
    void
    ODLC3_
        (ODL_Std_Params,
         const char *   text1,
         const char     val1,
         const char *   text2,
         const char     val2,
         const char *   text3,
         const char     val3);

    /*! @brief Write four character values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] val1 The first value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] val2 The second value to be written.
     @param[in] text3 The caption for the third value to be written.
     @param[in] val3 The third value to be written.
     @param[in] text4 The caption for the fourth value to be written.
     @param[in] val4 The fourth value to be written. */
    void
    ODLC4_
        (ODL_Std_Params,
         const char *   text1,
         const char     val1,
         const char *   text2,
         const char     val2,
         const char *   text3,
         const char     val3,
         const char *   text4,
         const char     val4);

    /*! @brief Write a double value to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the value to be written.
     @param[in] val1 The value to be written. */
    void
    ODLD1_
        (ODL_Std_Params,
         const char *   text1,
         const double   val1);

    /*! @brief Write two double values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] val1 The first value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] val2 The second value to be written. */
    void
    ODLD2_
        (ODL_Std_Params,
         const char *   text1,
         const double   val1,
         const char *   text2,
         const double   val2);

    /*! @brief Write three double values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] val1 The first value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] val2 The second value to be written.
     @param[in] text3 The caption for the third value to be written.
     @param[in] val3 The third value to be written. */
    void
    ODLD3_
        (ODL_Std_Params,
         const char *   text1,
         const double   val1,
         const char *   text2,
         const double   val2,
         const char *   text3,
         const double   val3);

    /*! @brief Write four double values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] val1 The first value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] val2 The second value to be written.
     @param[in] text3 The caption for the third value to be written.
     @param[in] val3 The third value to be written.
     @param[in] text4 The caption for the fourth value to be written.
     @param[in] val4 The fourth value to be written. */
    void
    ODLD4_
        (ODL_Std_Params,
         const char *   text1,
         const double   val1,
         const char *   text2,
         const double   val2,
         const char *   text3,
         const double   val3,
         const char *   text4,
         const double   val4);

    /*! @brief Write a function entry string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs. */
    void
    ODLEnter_
        (ODL_Std_Params);

    /*! @brief Write a void function exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs. */
    void
    ODLExit_
        (ODL_Std_Params);

    /*! @brief Write a boolean function exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] val The value being returned by the function. */
    void
    ODLExitB_
        (ODL_Std_Params,
         const bool     val);

    /*! @brief Write a character function exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] val The value being returned by the function. */
    void
    ODLExitC_
        (ODL_Std_Params,
         const char     val);

    /*! @brief Write a double function exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] val The value being returned by the function. */
    void
    ODLExitD_
        (ODL_Std_Params,
         const double   val);

    /*! @brief Write an exit function string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] val The value being returned by the function. */
    void
    ODLExitExit_
        (ODL_Std_Params,
         const long     val);

    /*! @brief Write an integer function exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] val The value being returned by the function. */
    void
    ODLExitI_
        (ODL_Std_Params,
         const intmax_t val);

# if defined(__OBJC__)
    /*! @brief Write an object function exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] val The value being returned by the function. */
    void
    ODLExitO_
        (ODL_Std_Params,
         const id       val);
# endif // defined(__OBJC__)

    /*! @brief Write a pointer function exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] val The value being returned by the function. */
    void
    ODLExitP_
        (ODL_Std_Params,
         const void *   val);

# if defined(__APPLE__)
    /*! @brief Write a rectangle function exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] val The value being returned by the function. */
    void
    ODLExitRect_
        (ODL_Std_Params,
         const CGRect   val);
# endif // defined(__APPLE__)

    /*! @brief Write a string function exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] val The value being returned by the function. */
    void
    ODLExitS_
        (ODL_Std_Params,
         const char *   val);

# if defined(__APPLE__)
    /*! @brief Write a size function exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] val The value being returned by the function. */
    void
    ODLExitSize_
        (ODL_Std_Params,
         const CGSize   val);
# endif // defined(__APPLE__)

    /*! @brief Write a throw/integer function exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] val The value being thrown by the function. */
    void
    ODLExitThrowI_
        (ODL_Std_Params,
         const intmax_t val);

    /*! @brief Write a throw/string function exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] val The value being thrown by the function. */
    void
    ODLExitThrowS_
        (ODL_Std_Params,
         const char *   val);

    /*! @brief Write a throw/integer hexadecimal function exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] val The value being thrown by the function. */
    void
    ODLExitThrowX_
        (ODL_Std_Params,
         const intmax_t val);

    /*! @brief Write an integer hexadecimal function exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] val The value being returned by the function. */
    void
    ODLExitX_
        (ODL_Std_Params,
         const intmax_t val);

    /*! @brief Write an integer value to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the value to be written.
     @param[in] val1 The value to be written. */
    void
    ODLI1_
        (ODL_Std_Params,
         const char *   text1,
         const intmax_t val1);

    /*! @brief Write two integer values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] val1 The first value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] val2 The second value to be written. */
    void
    ODLI2_
        (ODL_Std_Params,
         const char *   text1,
         const intmax_t val1,
         const char *   text2,
         const intmax_t val2);

    /*! @brief Write three integer values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] val1 The first value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] val2 The second value to be written.
     @param[in] text3 The caption for the third value to be written.
     @param[in] val3 The third value to be written. */
    void
    ODLI3_
        (ODL_Std_Params,
         const char *   text1,
         const intmax_t val1,
         const char *   text2,
         const intmax_t val2,
         const char *   text3,
         const intmax_t val3);

    /*! @brief Write four integer values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] val1 The first value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] val2 The second value to be written.
     @param[in] text3 The caption for the third value to be written.
     @param[in] val3 The third value to be written.
     @param[in] text4 The caption for the fourth value to be written.
     @param[in] val4 The fourth value to be written. */
    void
    ODLI4_
        (ODL_Std_Params,
         const char *   text1,
         const intmax_t val1,
         const char *   text2,
         const intmax_t val2,
         const char *   text3,
         const intmax_t val3,
         const char *   text4,
         const intmax_t val4);

    /*! @brief Set up the logging state.
     @param[in] prefix The output prefix string to be applied.
     @param[in] options The logging options to be applied.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs. */
    void
    ODLInit_
        (const char *   prefix,
         const int      options,
         ODL_Std_Params);

    /*! @brief Write an IP address to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the value to be written.
     @param[in] val1 The IP address value to be written.
     @param[in] val2 The port value to be written. */
    void
    ODLIP_
        (ODL_Std_Params,
         const char *   text1,
         const int32_t  val1,
         const int      val2);

    /*! @brief Write a long string value to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the value to be written.
     @param[in] val1 The value to be written. */
    void
    ODLLS_
        (ODL_Std_Params,
         const char *   text1,
         const char *   val1);

# if defined(__OBJC__)
    /*! @brief Write an object value to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the value to be written.
     @param[in] obj1 The value to be written. */
    void
    ODLO1_
        (ODL_Std_Params,
         const char *   text1,
         const id       obj1);

    /*! @brief Write two object values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] obj1 The value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] obj2 The second value to be written. */
    void
    ODLO2_
        (ODL_Std_Params,
         const char *   text1,
         const id       obj1,
         const char *   text2,
         const id       obj2);

    /*! @brief Write three object values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] obj1 The value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] obj2 The second value to be written.
     @param[in] text3 The caption for the third value to be written.
     @param[in] obj3 The third value to be written. */
    void
    ODLO3_
        (ODL_Std_Params,
         const char *   text1,
         const id       obj1,
         const char *   text2,
         const id       obj2,
         const char *   text3,
         const id       obj3);

    /*! @brief Write four object values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] obj1 The value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] obj2 The second value to be written.
     @param[in] text3 The caption for the third value to be written.
     @param[in] obj3 The third value to be written.
     @param[in] text4 The caption for the fourth value to be written.
     @param[in] obj4 The fourth value to be written. */
    void
    ODLO4_
        (ODL_Std_Params,
         const char *   text1,
         const id       obj1,
         const char *   text2,
         const id       obj2,
         const char *   text3,
         const id       obj3,
         const char *   text4,
         const id       obj4);
# endif // defined(__OBJC__)

    /*! @brief Write a method entry string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] objPtr The this/self pointer for the caller.*/
    void
    ODLObjEnter_
        (ODL_Std_Params,
         const void *   objPtr);

    /*! @brief Write a void method exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] objPtr The this/self pointer for the caller.*/
    void
    ODLObjExit_
        (ODL_Std_Params,
         const void *   objPtr);

    /*! @brief Write a boolean method exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] objPtr The this/self pointer for the caller.
     @param[in] val The value being returned by the method. */
    void
    ODLObjExitB_
        (ODL_Std_Params,
         const void *   objPtr,
         const bool     val);

    /*! @brief Write a character method exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] objPtr The this/self pointer for the caller.
     @param[in] val The value being returned by the method. */
    void
    ODLObjExitC_
        (ODL_Std_Params,
         const void *   objPtr,
         const char     val);

    /*! @brief Write a double method exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] objPtr The this/self pointer for the caller.
     @param[in] val The value being returned by the method. */
    void
    ODLObjExitD_
        (ODL_Std_Params,
         const void *   objPtr,
         const double   val);

    /*! @brief Write an exit method string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] objPtr The this/self pointer for the caller.
     @param[in] val The value being returned by the method. */
    void
    ODLObjExitExit_
        (ODL_Std_Params,
         const void *   objPtr,
         const long     val);

    /*! @brief Write an integer method exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] objPtr The this/self pointer for the caller.
     @param[in] val The value being returned by the method. */
    void
    ODLObjExitI_
        (ODL_Std_Params,
         const void *   objPtr,
         const intmax_t val);

# if defined(__OBJC__)
    /*! @brief Write an object method exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] objPtr The this/self pointer for the caller.
     @param[in] val The value being returned by the method. */
    void
    ODLObjExitO_
        (ODL_Std_Params,
         const void *   objPtr,
         const id       val);
# endif // defined(__OBJC__)

    /*! @brief Write a pointer method exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] objPtr The this/self pointer for the caller.
     @param[in] val The value being returned by the method. */
    void
    ODLObjExitP_
        (ODL_Std_Params,
         const void *   objPtr,
         const void *   val);

# if defined(__APPLE__)
    /*! @brief Write a rectangle method exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] objPtr The this/self pointer for the caller.
     @param[in] val The value being returned by the method. */
    void
    ODLObjExitRect_
        (ODL_Std_Params,
         const void *   objPtr,
         const CGRect   val);
# endif // defined(__APPLE__)

    /*! @brief Write a string method exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] objPtr The this/self pointer for the caller.
     @param[in] val The value being returned by the method. */
    void
    ODLObjExitS_
        (ODL_Std_Params,
         const void *   objPtr,
         const char *   val);

# if defined(__APPLE__)
    /*! @brief Write a size method exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] objPtr The this/self pointer for the caller.
     @param[in] val The value being returned by the method. */
    void
    ODLObjExitSize_
        (ODL_Std_Params,
         const void *   objPtr,
         const CGSize   val);
# endif // defined(__APPLE__)

    /*! @brief Write a throw/integer method exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] objPtr The this/self pointer for the caller.
     @param[in] val The value being thrown by the method. */
    void
    ODLObjExitThrowI_
        (ODL_Std_Params,
         const void *   objPtr,
         const intmax_t val);

    /*! @brief Write a throw/string method exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] objPtr The this/self pointer for the caller.
     @param[in] val The value being thrown by the method. */
    void
    ODLObjExitThrowS_
        (ODL_Std_Params,
         const void *   objPtr,
         const char *   val);

    /*! @brief Write a throw/integer hexadecimal method exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] objPtr The this/self pointer for the caller.
     @param[in] val The value being thrown by the method. */
    void
    ODLObjExitThrowX_
        (ODL_Std_Params,
         const void *   objPtr,
         const intmax_t val);

    /*! @brief Write an integer hexadecimal method exit string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] objPtr The this/self pointer for the caller.
     @param[in] val The value being returned by the method. */
    void
    ODLObjExitX_
        (ODL_Std_Params,
         const void *   objPtr,
         const intmax_t val);

    /*! @brief Write a pointer value to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the value to be written.
     @param[in] ptr1 The value to be written. */
    void
    ODLP1_
        (ODL_Std_Params,
         const char *   text1,
         const void *   ptr1);

    /*! @brief Write two pointer values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] ptr1 The value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] ptr2 The second value to be written. */
    void
    ODLP2_
        (ODL_Std_Params,
         const char *   text1,
         const void *   ptr1,
         const char *   text2,
         const void *   ptr2);

    /*! @brief Write three pointer values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] ptr1 The value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] ptr2 The second value to be written.
     @param[in] text3 The caption for the third value to be written.
     @param[in] ptr3 The third value to be written. */
    void
    ODLP3_
        (ODL_Std_Params,
         const char *   text1,
         const void *   ptr1,
         const char *   text2,
         const void *   ptr2,
         const char *   text3,
         const void *   ptr3);

    /*! @brief Write four pointer values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] ptr1 The value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] ptr2 The second value to be written.
     @param[in] text3 The caption for the third value to be written.
     @param[in] ptr3 The third value to be written.
     @param[in] text4 The caption for the fourth value to be written.
     @param[in] ptr4 The fourth value to be written. */
    void
    ODLP4_
        (ODL_Std_Params,
         const char *   text1,
         const void *   ptr1,
         const char *   text2,
         const void *   ptr2,
         const char *   text3,
         const void *   ptr3,
         const char *   text4,
         const void *   ptr4);

    /*! @brief Write a region of memory to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] caption The caption for the region to be written.
     @param[in] buffer The starting address of the region.
     @param[in] size The number of bytes to be written. */
    void
    ODLPacket_
        (ODL_Std_Params,
         const char *   caption,
         const void *   buffer,
         const int      size);

# if defined(__APPLE__)
    /*! @brief Write a rectangle to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] caption The caption for the value to be written.
     @param[in] rect The value to be written. */
    void
    ODLRect_
        (ODL_Std_Params,
         const char *   caption,
         const CGRect   rect);
# endif // defined(__APPLE__)

    /*! @brief Write a string value to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the value to be written.
     @param[in] val1 The value to be written. */
    void
    ODLS1_
        (ODL_Std_Params,
         const char *   text1,
         const char *   val1);

    /*! @brief Write two string values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] val1 The first value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] val2 The second value to be written. */
    void
    ODLS2_
        (ODL_Std_Params,
         const char *   text1,
         const char *   val1,
         const char *   text2,
         const char *   val2);

    /*! @brief Write three string values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] val1 The first value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] val2 The second value to be written.
     @param[in] text3 The caption for the third value to be written.
     @param[in] val3 The third value to be written. */
    void
    ODLS3_
        (ODL_Std_Params,
         const char *   text1,
         const char *   val1,
         const char *   text2,
         const char *   val2,
         const char *   text3,
         const char *   val3);

    /*! @brief Write four string values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] val1 The first value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] val2 The second value to be written.
     @param[in] text3 The caption for the third value to be written.
     @param[in] val3 The third value to be written.
     @param[in] text4 The caption for the fourth value to be written.
     @param[in] val4 The fourth value to be written. */
    void
    ODLS4_
        (ODL_Std_Params,
         const char *   text1,
         const char *   val1,
         const char *   text2,
         const char *   val2,
         const char *   text3,
         const char *   val3,
         const char *   text4,
         const char *   val4);

# if defined(__APPLE__)
    /*! @brief Write a size to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] caption The caption for the value to be written.
     @param[in] size The value to be written. */
    void
    ODLSize_
        (ODL_Std_Params,
         const char *   caption,
         const CGSize   size);
# endif // defined(__APPLE__)

    /*! @brief Write a (possibly unterminated) string to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text The caption for the value to be written.
     @param[in] len The number of bytes to be written.
     @param[in] val The value to be written. */
    void
    ODLSp_
        (ODL_Std_Params,
         const char *   text,
         const int      len,
         const char *   val);

# if MAC_OR_LINUX_
    /*! @brief Write a time value to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the value to be written.
     @param[in] val1 The value to be written. */
    void
    ODLTime_
        (ODL_Std_Params,
         const char *           text1,
         const struct timeval * val1);
# endif // MAC_OR_LINUX_

    /*! @brief Write an integer hexadecimal value to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the value to be written.
     @param[in] val1 The value to be written. */
    void
    ODLX1_
        (ODL_Std_Params,
         const char *   text1,
         const intmax_t val1);

    /*! @brief Write two integer hexadecimal values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] val1 The first value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] val2 The second value to be written. */
    void
    ODLX2_
        (ODL_Std_Params,
         const char *   text1,
         const intmax_t val1,
         const char *   text2,
         const intmax_t val2);

    /*! @brief Write three integer hexadecimal values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] val1 The first value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] val2 The second value to be written.
     @param[in] text3 The caption for the third value to be written.
     @param[in] val3 The third value to be written. */
    void
    ODLX3_
        (ODL_Std_Params,
         const char *   text1,
         const intmax_t val1,
         const char *   text2,
         const intmax_t val2,
         const char *   text3,
         const intmax_t val3);

    /*! @brief Write four integer hexadecimal values to the log.
     @param[in] fileName The name of the source file containing the call to this function.
     @param[in] funcName The name of the calling function.
     @param[in] lineNumber The line number in the source file where the call occurs.
     @param[in] text1 The caption for the first value to be written.
     @param[in] val1 The first value to be written.
     @param[in] text2 The caption for the second value to be written.
     @param[in] val2 The second value to be written.
     @param[in] text3 The caption for the third value to be written.
     @param[in] val3 The third value to be written.
     @param[in] text4 The caption for the fourth value to be written.
     @param[in] val4 The fourth value to be written. */
    void
    ODLX4_
        (ODL_Std_Params,
         const char *   text1,
         const intmax_t val1,
         const char *   text2,
         const intmax_t val2,
         const char *   text3,
         const intmax_t val3,
         const char *   text4,
         const intmax_t val4);

# if defined(__cplusplus)
}
# endif // defined(__cplusplus)

#endif // ! defined(ODL_FUNCTIONS_H_)
