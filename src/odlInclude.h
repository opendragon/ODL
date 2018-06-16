//--------------------------------------------------------------------------------------------------
//
//  File:       odlInclude.h
//
//  Project:    ODL
//
//  Contains:   The function declarations and macro definitions for the logging facility.
//
//  Written by: Norman Jaffe
//
//  Copyright:  (c) 2013 by OpenDragon.
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
//  Created:    2013-04-07
//
//--------------------------------------------------------------------------------------------------

#if (! defined(ODL_INCLUDE_H_))
# define ODL_INCLUDE_H_ /* Header guard */

# include <odlConfig.h>

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

# if defined(ODL_DISABLE_LOGGING_)
#  undef ODL_ENABLE_LOGGING_
# endif // defined(ODL_DISABLE_LOGGING_)

# undef ODL_OBJPRINTABLE_STRING
# undef ODL_SELF_OR_THIS_OR_NULL_

# undef ODL_LOG
# undef ODL_B1
# undef ODL_B2
# undef ODL_B3
# undef ODL_B4
# undef ODL_C1
# undef ODL_C2
# undef ODL_C3
# undef ODL_C4
# undef ODL_D1
# undef ODL_D2
# undef ODL_D3
# undef ODL_D4
# undef ODL_ENTER
# undef ODL_EXIT
# undef ODL_EXIT_B
# undef ODL_EXIT_C
# undef ODL_EXIT_D
# undef ODL_EXIT_EXIT
# undef ODL_EXIT_L
# undef ODL_EXIT_LL
# undef ODL_EXIT_O
# undef ODL_EXIT_P
# undef ODL_EXIT_RECT
# undef ODL_EXIT_S
# undef ODL_EXIT_s
# undef ODL_EXIT_SIZE
# undef ODL_EXIT_THROW_L
# undef ODL_EXIT_THROW_S
# undef ODL_EXIT_THROW_X
# undef ODL_EXIT_X
# undef ODL_EXIT_XL
# undef ODL_INIT
# undef ODL_IP
# undef ODL_L1
# undef ODL_L2
# undef ODL_L3
# undef ODL_L4
# undef ODL_LL1
# undef ODL_LL2
# undef ODL_LL3
# undef ODL_LL4
# undef ODL_LS
# undef ODL_O1
# undef ODL_O2
# undef ODL_O3
# undef ODL_O4
# undef ODL_OBJENTER
# undef ODL_OBJEXIT
# undef ODL_OBJEXIT_B
# undef ODL_OBJEXIT_C
# undef ODL_OBJEXIT_D
# undef ODL_OBJEXIT_EXIT
# undef ODL_OBJEXIT_L
# undef ODL_OBJEXIT_LL
# undef ODL_OBJEXIT_O
# undef ODL_OBJEXIT_P
# undef ODL_OBJEXIT_RECT
# undef ODL_OBJEXIT_S
# undef ODL_OBJEXIT_s
# undef ODL_OBJEXIT_SIZE
# undef ODL_OBJEXIT_THROW_L
# undef ODL_OBJEXIT_THROW_S
# undef ODL_OBJEXIT_THROW_X
# undef ODL_OBJEXIT_X
# undef ODL_OBJEXIT_XL
# undef ODL_P1
# undef ODL_P2
# undef ODL_P3
# undef ODL_P4
# undef ODL_PACKET
# undef ODL_RECT
# undef ODL_S1
# undef ODL_S1s
# undef ODL_S2
# undef ODL_S2s
# undef ODL_S3
# undef ODL_S3s
# undef ODL_S4
# undef ODL_S4s
# undef ODL_SIZE
# undef ODL_Sp
# undef ODL_TIME
# undef ODL_X1
# undef ODL_X2
# undef ODL_X3
# undef ODL_X4
# undef ODL_XL1
# undef ODL_XL2
# undef ODL_XL3
# undef ODL_XL4

# if defined(ODL_ENABLE_LOGGING_)
#  if defined(__OBJC__)
/*! @brief The pointer to the calling object for a method. */
#   define ODL_SELF_OR_THIS_OR_NULL_   (__bridge const void *) self
/*! @brief Return the string description for an Objective-C object. */
#   define ODL_OBJPRINTABLE_STRING(xx) (xx ? [[xx description] UTF8String] : "<>")
#  elif defined(__cplusplus)
/*! @brief The pointer to the calling object for a method. */
#   define ODL_SELF_OR_THIS_OR_NULL_   (const void *) this
#  else // ! defined(__cplusplus)
/*! @brief The pointer to the calling object for a method. */
#   define ODL_SELF_OR_THIS_OR_NULL_   NULL
#  endif // defined(__cplusplus)

/*! @brief Write a string to the log.
 @param[in] text The string to be written. */
#  define ODL_LOG(text) \
        ODL_(__FILE__, ODL_FUNC_NAME_,  __LINE__, text)

/*! @brief Write a boolean value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#  define ODL_B1(text1, val1) \
        ODLB1_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, (long) (val1))

/*! @brief Write two boolean values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_B2(text1, val1, text2, val2) \
        ODLB2_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, (long) (val1), text2, (long) (val2))

/*! @brief Write three boolean values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_B3(text1, val1, text2, val2, text3, val3) \
        ODLB3_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, (long) (val1), text2, (long) (val2),\
               text3, (long) (val3))

/*! @brief Write four boolean values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_B4(text1, val1, text2, val2, text3, val3, text4, val4) \
        ODLB4_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, (long) (val1), text2, (long) (val2),\
               text3, (long) (val3), text4, (long) (val4))

/*! @brief Write a character value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#  define ODL_C1(text1, val1) \
        ODLC1_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, (char) (val1))

/*! @brief Write two character values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_C2(text1, val1, text2, val2) \
        ODLC2_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, (char) (val1), text2, (char) (val2))

/*! @brief Write three character values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_C3(text1, val1, text2, val2, text3, val3) \
        ODLC3_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, (char) (val1), text2, (char) (val2),\
               text3, (char) (val3))

/*! @brief Write four character values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_C4(text1, val1, text2, val2, text3, val3, text4, val4) \
        ODLC4_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, (char) (val1), text2, (char) (val2),\
               text3, (char) (val3), text4, (char) (val4))

/*! @brief Write a double value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#  define ODL_D1(text1, val1) \
        ODLD1_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, val1)

/*! @brief Write two double values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_D2(text1, val1, text2, val2) \
        ODLD2_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, val1, text2, val2)

/*! @brief Write three double values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_D3(text1, val1, text2, val2, text3, val3) \
        ODLD3_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, val1, text2, val2, text3, val3)

/*! @brief Write four double values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_D4(text1, val1, text2, val2, text3, val3, text4, val4) \
        ODLD4_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, val1, text2, val2, text3, val3, text4,\
               val4)

/*! @brief Write a function entry string to the log. */
#  define ODL_ENTER() \
        ODLEnter_(__FILE__, ODL_FUNC_NAME_, __LINE__)

/*! @brief Write a void function exit string to the log. */
#  define ODL_EXIT() \
        ODLExit_(__FILE__, ODL_FUNC_NAME_, __LINE__)

/*! @brief Write a boolean function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_B(val) \
        ODLExitB_(__FILE__, ODL_FUNC_NAME_, __LINE__, val)

/*! @brief Write a character function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_C(val) \
        ODLExitC_(__FILE__, ODL_FUNC_NAME_, __LINE__, val)

/*! @brief Write a double function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_D(val) \
        ODLExitD_(__FILE__, ODL_FUNC_NAME_, __LINE__, val)

/*! @brief Write an exit function string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_EXIT(val) \
        ODLExitExit_(__FILE__, ODL_FUNC_NAME_, __LINE__, val)

/*! @brief Write a long function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_L(val) \
        ODLExitL_(__FILE__, ODL_FUNC_NAME_, __LINE__, val)

/*! @brief Write a long long function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_LL(val) \
        ODLExitLL_(__FILE__, ODL_FUNC_NAME_, __LINE__, val)

#  if defined(__OBJC__)
/*! @brief Write an object function exit string to the log.
 @param[in] val The value being returned by the function. */
#   define ODL_EXIT_O(val) \
        ODLExitO_(__FILE__, ODL_FUNC_NAME_, __LINE__, val)
#  endif // defined(__OBJC__)

/*! @brief Write a pointer function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_P(val) \
        ODLExitP_(__FILE__, ODL_FUNC_NAME_, __LINE__, val)

#  if defined(__APPLE__)
/*! @brief Write a rectangle function exit string to the log.
 @param[in] val The value being returned by the function. */
#   define ODL_EXIT_RECT(val) \
        ODLExitRect_(__FILE__, ODL_FUNC_NAME_, __LINE__, val)
#  endif // defined(__APPLE__)

/*! @brief Write a string function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_S(val) \
        ODLExitS_(__FILE__, ODL_FUNC_NAME_, __LINE__, val)

#  if defined(__APPLE__)
/*! @brief Write a size function exit string to the log.
 @param[in] val The value being returned by the function. */
#   define ODL_EXIT_SIZE(val) \
        ODLExitSize_(__FILE__, ODL_FUNC_NAME_, __LINE__, val)
#  endif // defined(__APPLE__)

/*! @brief Write a throw/long function exit string to the log.
 @param[in] val The value being thrown by the function. */
#  define ODL_EXIT_THROW_L(val) \
        ODLExitThrowL_(__FILE__, ODL_FUNC_NAME_, __LINE__, val)

/*! @brief Write a throw/string function exit string to the log.
 @param[in] val The value being thrown by the function. */
#  define ODL_EXIT_THROW_S(val) \
        ODLExitThrowS_(__FILE__, ODL_FUNC_NAME_, __LINE__, val)

/*! @brief Write a throw/long hexadecimal function exit string to the log.
 @param[in] val The value being thrown by the function. */
#  define ODL_EXIT_THROW_X(val) \
        ODLExitThrowX_(__FILE__, ODL_FUNC_NAME_, __LINE__, val)

/*! @brief Write a long hexadecimal function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_X(val) \
        ODLExitX_(__FILE__, ODL_FUNC_NAME_, __LINE__, val)

/*! @brief Write a long long hexadecimal function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_XL(val) \
        ODLExitXL_(__FILE__, ODL_FUNC_NAME_, __LINE__, val)

/*! @brief Set up the logging state.
 @param[in] prefix The output prefix string to be applied.
 @param[in] options The logging options to be applied. */
#  define ODL_INIT(prefix, options) \
        ODLInit_(prefix, options, __FILE__, ODL_FUNC_NAME_, __LINE__)

/*! @brief Write an IP address to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The IP address value to be written.
 @param[in] val2 The port value to be written. */
#  define ODL_IP(text1, val1, val2) \
        ODLIP_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, (long) (val1), (long) (val2))

/*! @brief Write a long value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#  define ODL_L1(text1, val1) \
        ODLL1_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, (long) (val1))

/*! @brief Write two long values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_L2(text1, val1, text2, val2) \
        ODLL2_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, (long) (val1), text2, (long) (val2))

/*! @brief Write three long values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_L3(text1, val1, text2, val2, text3, val3) \
        ODLL3_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, (long) (val1), text2, (long) (val2),\
               text3, (long) (val3))

/*! @brief Write four long values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_L4(text1, val1, text2, val2, text3, val3, text4, val4) \
        ODLL4_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, (long) (val1), text2, (long) (val2),\
               text3, (long) (val3), text4, (long) (val4))

/*! @brief Write a long long value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#  define ODL_LL1(text1, val1) \
        ODLLL1_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, val1)

/*! @brief Write two long long values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_LL2(text1, val1, text2, val2) \
        ODLLL2_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, val1, text2, val2)

/*! @brief Write three long long values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_LL3(text1, val1, text2, val2, text3, val3) \
        ODLLL3_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, val1, text2, val2, text3, val3)

/*! @brief Write four long long values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_LL4(text1, val1, text2, val2, text3, val3, text4, val4) \
        ODLLL4_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, val1, text2, val2, text3, val3,\
                text4, val4)

/*! @brief Write a long string value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#  define ODL_LS(text1, val1) \
        ODLLS_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, val1)

#  if defined(__OBJC__)
/*! @brief Write an object value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] obj1 The value to be written. */
#   define ODL_O1(text1, obj1) \
        ODLO1_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, obj1)

/*! @brief Write two object values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] obj1 The value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] obj2 The second value to be written. */
#   define ODL_O2(text1, obj1, text2, obj2) \
        ODLO2_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, obj1, text2, obj2)

/*! @brief Write three object values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] obj1 The value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] obj2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] obj3 The third value to be written. */
#   define ODL_O3(text1, obj1, text2, obj2, text3, obj3) \
        ODLO3_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, obj1, text2, obj2, text3, obj3)

/*! @brief Write four object values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] obj1 The value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] obj2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] obj3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] obj4 The fourth value to be written. */
#   define ODL_O4(text1, obj1, text2, obj2, text3, obj3, text4, obj4) \
        ODLO4_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, obj1, text2, obj2, text3, obj3, text4,\
               obj4)
#  endif // defined(__OBJC__)

/*! @brief Write a method entry string to the log. */
#  define ODL_OBJENTER() \
        ODLObjEnter_(__FILE__, ODL_FUNC_NAME_, __LINE__, ODL_SELF_OR_THIS_OR_NULL_)

/*! @brief Write a void method exit string to the log. */
#  define ODL_OBJEXIT() \
        ODLObjExit_(__FILE__, ODL_FUNC_NAME_, __LINE__, ODL_SELF_OR_THIS_OR_NULL_)

/*! @brief Write a boolean method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_B(val) \
        ODLObjExitB_(__FILE__, ODL_FUNC_NAME_, __LINE__, ODL_SELF_OR_THIS_OR_NULL_, val)

/*! @brief Write a character method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_C(val) \
        ODLObjExitC_(__FILE__, ODL_FUNC_NAME_, __LINE__, ODL_SELF_OR_THIS_OR_NULL_, val)

/*! @brief Write a double method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_D(val) \
        ODLObjExitD_(__FILE__, ODL_FUNC_NAME_, __LINE__, ODL_SELF_OR_THIS_OR_NULL_, val)

/*! @brief Write an exit method string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_EXIT(val) \
        ODLObjExitExit_(__FILE__, ODL_FUNC_NAME_, __LINE__, ODL_SELF_OR_THIS_OR_NULL_, val)

/*! @brief Write a long method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_L(val) \
        ODLObjExitL_(__FILE__, ODL_FUNC_NAME_, __LINE__, ODL_SELF_OR_THIS_OR_NULL_, val)

/*! @brief Write a long long method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_LL(val) \
        ODLObjExitLL_(__FILE__, ODL_FUNC_NAME_, __LINE__, ODL_SELF_OR_THIS_OR_NULL_, val)

#  if defined(__OBJC__)
/*! @brief Write an object method exit string to the log.
 @param[in] val The value being returned by the method. */
#   define ODL_OBJEXIT_O(val) \
        ODLObjExitO_(__FILE__, ODL_FUNC_NAME_, __LINE__, ODL_SELF_OR_THIS_OR_NULL_, val)
#  endif // defined(__OBJC__)

/*! @brief Write a pointer method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_P(val) \
        ODLObjExitP_(__FILE__, ODL_FUNC_NAME_, __LINE__, ODL_SELF_OR_THIS_OR_NULL_, val)

#  if defined(__APPLE__)
/*! @brief Write a rectangle method exit string to the log.
 @param[in] val The value being returned by the method. */
#   define ODL_OBJEXIT_RECT(val) \
        ODLObjExitRect_(__FILE__, ODL_FUNC_NAME_, __LINE__, ODL_SELF_OR_THIS_OR_NULL_, val)
#  endif // defined(__APPLE__)

/*! @brief Write a string method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_S(val) \
        ODLObjExitS_(__FILE__, ODL_FUNC_NAME_, __LINE__, ODL_SELF_OR_THIS_OR_NULL_, val)

#  if defined(__APPLE__)
/*! @brief Write a size method exit string to the log.
 @param[in] val The value being returned by the method. */
#   define ODL_OBJEXIT_SIZE(val) \
        ODLObjExitSize_(__FILE__, ODL_FUNC_NAME_, __LINE__, ODL_SELF_OR_THIS_OR_NULL_, val)
#  endif // defined(__APPLE__)

/*! @brief Write a throw/long method exit string to the log.
 @param[in] val The value being thrown by the method. */
#  define ODL_OBJEXIT_THROW_L(val) \
        ODLObjExitThrowL_(__FILE__, ODL_FUNC_NAME_, __LINE__, ODL_SELF_OR_THIS_OR_NULL_, val)

/*! @brief Write a throw/string method exit string to the log.
 @param[in] val The value being thrown by the method. */
#  define ODL_OBJEXIT_THROW_S(val) \
        ODLObjExitThrowS_(__FILE__, ODL_FUNC_NAME_, __LINE__, ODL_SELF_OR_THIS_OR_NULL_, val)

/*! @brief Write a throw/long hexadecimal method exit string to the log.
 @param[in] val The value being thrown by the method. */
#  define ODL_OBJEXIT_THROW_X(val) \
        ODLObjExitThrowX_(__FILE__, ODL_FUNC_NAME_, __LINE__, ODL_SELF_OR_THIS_OR_NULL_, val)

/*! @brief Write a long hexadecimal method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_X(val) \
        ODLObjExitX_(__FILE__, ODL_FUNC_NAME_, __LINE__, ODL_SELF_OR_THIS_OR_NULL_, val)

/*! @brief Write a long long hexadecimal method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_XL(val) \
        ODLObjExitXL_(__FILE__, ODL_FUNC_NAME_, __LINE__, ODL_SELF_OR_THIS_OR_NULL_, val)

/*! @brief Write a pointer value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] ptr1 The value to be written. */
#  define ODL_P1(text1, ptr1) \
        ODLP1_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, ptr1)

/*! @brief Write two pointer values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] ptr1 The value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] ptr2 The second value to be written. */
#  define ODL_P2(text1, ptr1, text2, ptr2) \
        ODLP2_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, ptr1, text2, ptr2)

/*! @brief Write three pointer values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] ptr1 The value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] ptr2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] ptr3 The third value to be written. */
#  define ODL_P3(text1, ptr1, text2, ptr2, text3, ptr3) \
        ODLP3_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, ptr1, text2, ptr2, text3, ptr3)

/*! @brief Write four pointer values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] ptr1 The value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] ptr2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] ptr3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] ptr4 The fourth value to be written. */
#  define ODL_P4(text1, ptr1, text2, ptr2, text3, ptr3, text4, ptr4) \
        ODLP4_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, ptr1, text2, ptr2, text3, ptr3, text4,\
               ptr4)

/*! @brief Write a region of memory to the log.
 @param[in] caption The caption for the region to be written.
 @param[in] buffer The starting address of the region.
 @param[in] size The number of bytes to be written. */
#  define ODL_PACKET(caption, buffer, size) \
        ODLPacket_(__FILE__, ODL_FUNC_NAME_,  __LINE__, caption, buffer, size)

#  if defined(__APPLE__)
/*! @brief Write a rectangle to the log.
 @param[in] caption The caption for the value to be written.
 @param[in] rect The value to be written. */
#   define ODL_RECT(caption, rect) \
        ODLRect_(__FILE__, ODL_FUNC_NAME_,  __LINE__, caption, rect)
#  endif // defined(__APPLE__)

/*! @brief Write a string value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#  define ODL_S1(text1, val1) \
        ODLS1_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, val1)

/*! @brief Write two string values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_S2(text1, val1, text2, val2) \
        ODLS2_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, val1, text2, val2)

/*! @brief Write three string values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_S3(text1, val1, text2, val2, text3, val3) \
        ODLS3_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, val1, text2, val2, text3, val3)

/*! @brief Write four string values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_S4(text1, val1, text2, val2, text3, val3, text4, val4) \
        ODLS4_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, val1, text2, val2, text3, val3, text4,\
               val4)

#  if defined(__APPLE__)
/*! @brief Write a size to the log.
 @param[in] caption The caption for the value to be written.
 @param[in] size The value to be written. */
#   define ODL_SIZE(caption, size) \
        ODLSize_(__FILE__, ODL_FUNC_NAME_,  __LINE__, caption, size)
#  endif // defined(__APPLE__)

/*! @brief Write a (possibly unterminated) string to the log.
 @param[in] text The caption for the value to be written.
 @param[in] len The number of bytes to be written.
 @param[in] val The value to be written. */
#  define ODL_Sp(text, len, val) \
        ODLSp_(__FILE__, ODL_FUNC_NAME_, __LINE__, text, (long) len, val)

#  if defined(MAC_OR_LINUX_)
/*! @brief Write a time value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#   define ODL_TIME(text1, val1) \
        ODLTime_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, val1)
#  endif // defined(MAC_OR_LINUX_)

/*! @brief Write a long hexadecimal value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#  define ODL_X1(text1, val1) \
        ODLX1_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, (long) (val1))

/*! @brief Write two long hexadecimal values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_X2(text1, val1, text2, val2) \
        ODLX2_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, (long) (val1), text2, (long) (val2))

/*! @brief Write three long hexadecimal values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_X3(text1, val1, text2, val2, text3, val3) \
        ODLX3_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, (long) (val1), text2, (long) (val2),\
               text3, (long) (val3))

/*! @brief Write four long hexadecimal values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_X4(text1, val1, text2, val2, text3, val3, text4, val4) \
        ODLX4_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, (long) (val1), text2, (long) (val2),\
               text3, (long) (val3), text4, (long) (val4))

/*! @brief Write a long long hexadecimal value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#  define ODL_XL1(text1, val1) \
        ODLXL1_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, val1)

/*! @brief Write two long long hexadecimal values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_XL2(text1, val1, text2, val2) \
        ODLXL2_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, val1, text2, val2)

/*! @brief Write three long long hexadecimal values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_XL3(text1, val1, text2, val2, text3, val3) \
        ODLXL3_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, val1, text2, val2, text3, val3)

/*! @brief Write four long long hexadecimal values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_XL4(text1, val1, text2, val2, text3, val3, text4, val4) \
        ODLXL4_(__FILE__, ODL_FUNC_NAME_, __LINE__, text1, val1, text2, val2, text3, val3,\
                text4, val4)

# else // ! defined(ODL_ENABLE_LOGGING_)
#  if defined(__OBJC__)
 /* Return the string description of an Objective-C object. */
#   define ODL_OBJPRINTABLE_STRING(xx) ""
#  endif // defined(__OBJC__)

/*! @brief Write a string to the log.
 @param[in] text The string to be written. */
#  define ODL_LOG(text) /* */

/*! @brief Write a boolean value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#  define ODL_B1(text1, val1) /* */

/*! @brief Write two boolean values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_B2(text1, val1, text2, val2) /* */

/*! @brief Write three boolean values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_B3(text1, val1, text2, val2, text3, val3) /* */

/*! @brief Write four boolean values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_B4(text1, val1, text2, val2, text3, val3, text4, val4) /* */

/*! @brief Write a character value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#  define ODL_C1(text1, val1) /* */

/*! @brief Write two character values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_C2(text1, val1, text2, val2) /* */

/*! @brief Write three character values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_C3(text1, val1, text2, val2, text3, val3) /* */

/*! @brief Write four character values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_C4(text1, val1, text2, val2, text3, val3, text4, val4) /* */

/*! @brief Write a double value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#  define ODL_D1(text1, val1) /* */

/*! @brief Write two double values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_D2(text1, val1, text2, val2) /* */

/*! @brief Write three double values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_D3(text1, val1, text2, val2, text3, val3) /* */

/*! @brief Write four double values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_D4(text1, val1, text2, val2, text3, val3, text4, val4) /* */

/*! @brief Write a function entry string to the log. */
#  define ODL_ENTER() /* */

/*! @brief Write a void function exit string to the log. */
#  define ODL_EXIT() /* */

/*! @brief Write a boolean function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_B(val) /* */

/*! @brief Write a character function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_C(val) /* */

/*! @brief Write a double function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_D(val) /* */

/*! @brief Write an exit function string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_EXIT(val) /* */

/*! @brief Write a long function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_L(val) /* */

/*! @brief Write a long long function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_LL(val) /* */

#  if defined(__OBJC__)
/*! @brief Write an object function exit string to the log.
 @param[in] val The value being returned by the function. */
#   define ODL_EXIT_O(val) /* */
#  endif // defined(__OBJC__)

/*! @brief Write a pointer function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_P(val) /* */

#  if defined(__APPLE__)
/*! @brief Write a rectangle function exit string to the log.
 @param[in] val The value being returned by the function. */
#   define ODL_EXIT_RECT(val) /* */
#  endif // defined(__APPLE__)

/*! @brief Write a string function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_S(val) /* */

#  if defined(__APPLE__)
/*! @brief Write a size function exit string to the log.
 @param[in] val The value being returned by the function. */
#   define ODL_EXIT_SIZE(val) /* */
#  endif // defined(__APPLE__)

/*! @brief Write a throw/long function exit string to the log.
 @param[in] val The value being thrown by the function. */
#  define ODL_EXIT_THROW_L(val) /* */

/*! @brief Write a throw/string function exit string to the log.
 @param[in] val The value being thrown by the function. */
#  define ODL_EXIT_THROW_S(val) /* */

/*! @brief Write a throw/long hexadecimal function exit string to the log.
 @param[in] val The value being thrown by the function. */
#  define ODL_EXIT_THROW_X(val) /* */

/*! @brief Write a long hexadecimal function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_X(val) /* */

/*! @brief Write a long long hexadecimal function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_XL(val) /* */

/*! @brief Set up the logging state.
 @param[in] prefix The output prefix string to be applied.
 @param[in] options The logging options to be applied. */
#  define ODL_INIT(prefix, options) /* */

/*! @brief Write an IP address to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The IP address value to be written.
 @param[in] val2 The port value to be written. */
#  define ODL_IP(text1, val1, val2) /* */

/*! @brief Write a long value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#  define ODL_L1(text1, val1) /* */

/*! @brief Write two long values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_L2(text1, val1, text2, val2) /* */

/*! @brief Write three long values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_L3(text1, val1, text2, val2, text3, val3) /* */

/*! @brief Write four long values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_L4(text1, val1, text2, val2, text3, val3, text4, val4) /* */

/*! @brief Write a long long value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#  define ODL_LL1(text1, val1) /* */

/*! @brief Write two long long values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_LL2(text1, val1, text2, val2) /* */

/*! @brief Write three long long values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_LL3(text1, val1, text2, val2, text3, val3) /* */

/*! @brief Write four long long values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_LL4(text1, val1, text2, val2, text3, val3, text4, val4) /* */

/*! @brief Write a long string value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#  define ODL_LS(text1, val1) /* */

#  if defined(__OBJC__)
/*! @brief Write an object value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] obj1 The value to be written. */
#   define ODL_O1(text1, obj1) /* */

/*! @brief Write two object values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] obj1 The value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] obj2 The second value to be written. */
#   define ODL_O2(text1, obj1, text2, obj2) /* */

/*! @brief Write three object values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] obj1 The value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] obj2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] obj3 The third value to be written. */
#   define ODL_O3(text1, obj1, text2, obj2, text3, obj3) /* */

/*! @brief Write four object values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] obj1 The value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] obj2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] obj3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] obj4 The fourth value to be written. */
#   define ODL_O4(text1, obj1, text2, obj2, text3, obj3, text4, obj4) /* */
#  endif // defined(__OBJC__)

/*! @brief Write a method entry string to the log. */
#  define ODL_OBJENTER() /* */

/*! @brief Write a void method exit string to the log. */
#  define ODL_OBJEXIT() /* */

/*! @brief Write a boolean method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_B(val) /* */

/*! @brief Write a character method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_C(val) /* */

/*! @brief Write a double method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_D(val) /* */

/*! @brief Write an exit method string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_EXIT(val) /* */

/*! @brief Write a long method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_L(val) /* */

/*! @brief Write a long long method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_LL(val) /* */

#  if defined(__OBJC__)
/*! @brief Write an object method exit string to the log.
 @param[in] val The value being returned by the method. */
#   define ODL_OBJEXIT_O(val) /* */
#  endif // defined(__OBJC__)

/*! @brief Write a pointer method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_P(val) /* */

#  if defined(__APPLE__)
/*! @brief Write a rectangle method exit string to the log.
 @param[in] val The value being returned by the method. */
#   define ODL_OBJEXIT_RECT(val) /* */
#  endif // defined(__APPLE__)

/*! @brief Write a string method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_S(val) /* */

#  if defined(__APPLE__)
/*! @brief Write a size method exit string to the log.
 @param[in] val The value being returned by the method. */
#   define ODL_OBJEXIT_SIZE(val) /* */
#  endif // defined(__APPLE__)

/*! @brief Write a throw/long method exit string to the log.
 @param[in] val The value being thrown by the method. */
#  define ODL_OBJEXIT_THROW_L(val) /* */

/*! @brief Write a throw/string method exit string to the log.
 @param[in] val The value being thrown by the method. */
#  define ODL_OBJEXIT_THROW_S(val) /* */

/*! @brief Write a throw/long hexadecimal method exit string to the log.
 @param[in] val The value being thrown by the method. */
#  define ODL_OBJEXIT_THROW_X(val) /* */

/*! @brief Write a long hexadecimal method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_X(val) /* */

/*! @brief Write a long long hexadecimal method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_XL(val) /* */

/*! @brief Write a pointer value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] ptr1 The value to be written. */
#  define ODL_P1(text1, ptr1) /* */

/*! @brief Write two pointer values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] ptr1 The value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] ptr2 The second value to be written. */
#  define ODL_P2(text1, ptr1, text2, ptr2) /* */

/*! @brief Write three pointer values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] ptr1 The value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] ptr2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] ptr3 The third value to be written. */
#  define ODL_P3(text1, ptr1, text2, ptr2, text3, ptr3) /* */

/*! @brief Write four pointer values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] ptr1 The value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] ptr2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] ptr3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] ptr4 The fourth value to be written. */
#  define ODL_P4(text1, ptr1, text2, ptr2, text3, ptr3, text4, ptr4) /* */

/*! @brief Write a region of memory to the log.
 @param[in] caption The caption for the region to be written.
 @param[in] buffer The starting address of the region.
 @param[in] size The number of bytes to be written. */
#  define ODL_PACKET(caption, buffer, size) /* */

#  if defined(__APPLE__)
/*! @brief Write a rectangle to the log.
 @param[in] caption The caption for the value to be written.
 @param[in] rect The value to be written. */
#   define ODL_RECT(caption, rect) /* */
#  endif // defined(__APPLE__)

/*! @brief Write a string value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#  define ODL_S1(text1, val1) /* */

/*! @brief Write two string values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_S2(text1, val1, text2, val2) /* */

/*! @brief Write three string values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_S3(text1, val1, text2, val2, text3, val3) /* */

/*! @brief Write four string values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_S4(text1, val1, text2, val2, text3, val3, text4, val4) /* */

#  if defined(__APPLE__)
/*! @brief Write a size to the log.
 @param[in] caption The caption for the value to be written.
 @param[in] size The value to be written. */
#   define ODL_SIZE(caption, size) /* */
#  endif // defined(__APPLE__)

/*! @brief Write a (possibly unterminated) string to the log.
 @param[in] text The caption for the value to be written.
 @param[in] len The number of bytes to be written.
 @param[in] val The value to be written. */
#  define ODL_Sp(text, len, val) /* */

#  if defined(MAC_OR_LINUX_)
/*! @brief Write a time value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#   define ODL_TIME(text1, val1) /* */
#  endif // defined(MAC_OR_LINUX_)

/*! @brief Write a long hexadecimal value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#  define ODL_X1(text1, val1) /* */

/*! @brief Write two long hexadecimal values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_X2(text1, val1, text2, val2) /* */

/*! @brief Write three long hexadecimal values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_X3(text1, val1, text2, val2, text3, val3) /* */

/*! @brief Write four long hexadecimal values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_X4(text1, val1, text2, val2, text3, val3, text4, val4) /* */

/*! @brief Write a long long hexadecimal value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
#  define ODL_XL1(text1, val1) /* */

/*! @brief Write two long long hexadecimal values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_XL2(text1, val1, text2, val2) /* */

/*! @brief Write three long long hexadecimal values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_XL3(text1, val1, text2, val2, text3, val3) /* */

/*! @brief Write four long long hexadecimal values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_XL4(text1, val1, text2, val2, text3, val3, text4, val4) /* */

# endif // ! defined(ODL_ENABLE_LOGGING_)

/*! @brief Write a string function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_s(val) \
        ODL_EXIT_S(val.c_str())

/*! @brief Write a string method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_s(val) \
        ODL_OBJEXIT_S(val.c_str())

/*! @brief Write a string value to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The value to be written. */
# define ODL_S1s(text1, val1) \
        ODL_S1(text1, val1.c_str())

/*! @brief Write two string values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written. */
# define ODL_S2s(text1, val1, text2, val2) \
        ODL_S2(text1, val1.c_str(), text2, val2.c_str())

/*! @brief Write three string values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written. */
# define ODL_S3s(text1, val1, text2, val2, text3, val3) \
        ODL_S3(text1, val1.c_str(), text2, val2.c_str(), text3, val3.c_str())

/*! @brief Write four string values to the log.
 @param[in] text1 The caption for the first value to be written.
 @param[in] val1 The first value to be written.
 @param[in] text2 The caption for the second value to be written.
 @param[in] val2 The second value to be written.
 @param[in] text3 The caption for the third value to be written.
 @param[in] val3 The third value to be written.
 @param[in] text4 The caption for the fourth value to be written.
 @param[in] val4 The fourth value to be written. */
# define ODL_S4s(text1, val1, text2, val2, text3, val3, text4, val4) \
        ODL_S4(text1, val1.c_str(), text2, val2.c_str(), text3, val3.c_str(), text4,\
                    val4.c_str())

#endif // ! defined(ODL_INCLUDE_H_)
