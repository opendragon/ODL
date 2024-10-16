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
# include <odlFunctions.h>

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

# undef ODL_OBJ_PRINTABLE_STRING
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
# undef ODL_EXIT_I
# undef ODL_EXIT_O
# undef ODL_EXIT_P
# undef ODL_EXIT_RECT
# undef ODL_EXIT_S
# undef ODL_EXIT_s
# undef ODL_EXIT_SIZE
# undef ODL_EXIT_THROW_I
# undef ODL_EXIT_THROW_S
# undef ODL_EXIT_THROW_X
# undef ODL_EXIT_X
# undef ODL_I1
# undef ODL_I2
# undef ODL_I3
# undef ODL_I4
# undef ODL_INIT
# undef ODL_IP
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
# undef ODL_OBJEXIT_I
# undef ODL_OBJEXIT_O
# undef ODL_OBJEXIT_P
# undef ODL_OBJEXIT_RECT
# undef ODL_OBJEXIT_S
# undef ODL_OBJEXIT_s
# undef ODL_OBJEXIT_SIZE
# undef ODL_OBJEXIT_THROW_I
# undef ODL_OBJEXIT_THROW_S
# undef ODL_OBJEXIT_THROW_X
# undef ODL_OBJEXIT_X
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

# if defined(ODL_ENABLE_LOGGING_)
#  if defined(__OBJC__)
/*! @brief The pointer to the calling object for a method. */
#   define ODL_SELF_OR_THIS_OR_NULL_   (__bridge const void *) self
/*! @brief Return the string description for an Objective-C object. */
#   define ODL_OBJ_PRINTABLE_STRING(xx) (xx ? [[xx description] UTF8String] : "<>")
#  elif defined(__cplusplus)
/*! @brief The pointer to the calling object for a method. */
#   define ODL_SELF_OR_THIS_OR_NULL_   (const void *) this
#  else // ! defined(__cplusplus)
/*! @brief The pointer to the calling object for a method. */
#   define ODL_SELF_OR_THIS_OR_NULL_   nullptr
#  endif // defined(__cplusplus)

/*! @brief Write a string to the log.
 @param[in] text The string to be written. */
#  define ODL_LOG(text) \
        ODL_(ODL_Std_Args, text)

/*! @brief Write a boolean value to the log.
 @param[in] val1 The value to be written. */
#  define ODL_B1(val1) \
        ODLB1_(ODL_Std_Args, #val1 ": ", (long) (val1))

/*! @brief Write two boolean values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_B2(val1, val2) \
        ODLB2_(ODL_Std_Args, #val1 ": ", (long) (val1), #val2 ": ", (long) (val2))

/*! @brief Write three boolean values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_B3(val1, val2, val3) \
        ODLB3_(ODL_Std_Args, #val1 ": ", (long) (val1), #val2 ": ", (long) (val2), #val3 ": ", (long) (val3))

/*! @brief Write four boolean values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_B4(val1, val2, val3, val4) \
        ODLB4_(ODL_Std_Args, #val1 ": ", (long) (val1), #val2 ": ", (long) (val2), #val3 ": ", (long) (val3), #val4 ": ", (long) (val4))

/*! @brief Write a character value to the log.
 @param[in] val1 The value to be written. */
#  define ODL_C1(val1) \
        ODLC1_(ODL_Std_Args, #val1 ": ", (char) (val1))

/*! @brief Write two character values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_C2(val1, val2) \
        ODLC2_(ODL_Std_Args, #val1 ": ", (char) (val1), #val2 ": ", (char) (val2))

/*! @brief Write three character values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_C3(val1, val2, val3) \
        ODLC3_(ODL_Std_Args, #val1 ": ", (char) (val1), #val2 ": ", (char) (val2), #val3 ": ", (char) (val3))

/*! @brief Write four character values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_C4(val1, val2, val3, val4) \
        ODLC4_(ODL_Std_Args, #val1 ": ", (char) (val1), #val2 ": ", (char) (val2), #val3 ": ", (char) (val3), #val4 ": ", (char) (val4))

/*! @brief Write a double value to the log.
 @param[in] val1 The value to be written. */
#  define ODL_D1(val1) \
        ODLD1_(ODL_Std_Args, #val1 ": ", val1)

/*! @brief Write two double values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_D2(val1, val2) \
        ODLD2_(ODL_Std_Args, #val1 ": ", val1, #val2 ": ", val2)

/*! @brief Write three double values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_D3(val1, val2, val3) \
        ODLD3_(ODL_Std_Args, #val1 ": ", val1, #val2 ": ", val2, #val3 ": ", val3)

/*! @brief Write four double values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_D4(val1, val2, val3, val4) \
        ODLD4_(ODL_Std_Args, #val1 ": ", val1, #val2 ": ", val2, #val3 ": ", val3, #val4 ": ", val4)

/*! @brief Write a function entry string to the log. */
#  define ODL_ENTER() \
        ODLEnter_(ODL_Std_Args)

/*! @brief Write a void function exit string to the log. */
#  define ODL_EXIT() \
        ODLExit_(ODL_Std_Args)

/*! @brief Write a boolean function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_B(val) \
        ODLExitB_(ODL_Std_Args, val)

/*! @brief Write a character function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_C(val) \
        ODLExitC_(ODL_Std_Args, val)

/*! @brief Write a double function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_D(val) \
        ODLExitD_(ODL_Std_Args, val)

/*! @brief Write an exit function string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_EXIT(val) \
        ODLExitExit_(ODL_Std_Args, val)

/*! @brief Write an integer function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_I(val) \
        ODLExitI_(ODL_Std_Args, val)

#  if defined(__OBJC__)
/*! @brief Write an object function exit string to the log.
 @param[in] val The value being returned by the function. */
#   define ODL_EXIT_O(val) \
        ODLExitO_(ODL_Std_Args, val)
#  endif // defined(__OBJC__)

/*! @brief Write a pointer function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_P(val) \
        ODLExitP_(ODL_Std_Args, val)

#  if defined(__APPLE__)
/*! @brief Write a rectangle function exit string to the log.
 @param[in] val The value being returned by the function. */
#   define ODL_EXIT_RECT(val) \
        ODLExitRect_(ODL_Std_Args, val)
#  endif // defined(__APPLE__)

/*! @brief Write a string function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_S(val) \
        ODLExitS_(ODL_Std_Args, val)

#  if defined(__APPLE__)
/*! @brief Write a size function exit string to the log.
 @param[in] val The value being returned by the function. */
#   define ODL_EXIT_SIZE(val) \
        ODLExitSize_(ODL_Std_Args, val)
#  endif // defined(__APPLE__)

/*! @brief Write a throw/integer function exit string to the log.
 @param[in] val The value being thrown by the function. */
#  define ODL_EXIT_THROW_I(val) \
        ODLExitThrowI_(ODL_Std_Args, val)

/*! @brief Write a throw/string function exit string to the log.
 @param[in] val The value being thrown by the function. */
#  define ODL_EXIT_THROW_S(val) \
        ODLExitThrowS_(ODL_Std_Args, val)

/*! @brief Write a throw/integer hexadecimal function exit string to the log.
 @param[in] val The value being thrown by the function. */
#  define ODL_EXIT_THROW_X(val) \
        ODLExitThrowX_(ODL_Std_Args, val)

/*! @brief Write an integer hexadecimal function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_X(val) \
        ODLExitX_(ODL_Std_Args, val)

/*! @brief Write an integer value to the log.
 @param[in] val1 The value to be written. */
#  define ODL_I1(val1) \
        ODLI1_(ODL_Std_Args, #val1 ": ", (intmax_t) (val1))

/*! @brief Write two integer values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_I2(val1, val2) \
        ODLI2_(ODL_Std_Args, #val1 ": ", (intmax_t) (val1), #val2 ": ", (intmax_t) (val2))

/*! @brief Write three integer values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_I3(val1, val2, val3) \
        ODLI3_(ODL_Std_Args, #val1 ": ", (intmax_t) (val1), #val2 ": ", (intmax_t) (val2), #val3 ": ", (intmax_t) (val3))

/*! @brief Write four integer values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_I4(val1, val2, val3, val4) \
        ODLI4_(ODL_Std_Args, #val1 ": ", (intmax_t) (val1), #val2 ": ", (intmax_t) (val2), #val3 ": ", (intmax_t) (val3), #val4 ": ", (intmax_t) (val4))

/*! @brief Set up the logging state.
 @param[in] prefix The output prefix string to be applied.
 @param[in] options The logging options to be applied. */
#  define ODL_INIT(prefix, options) \
        ODLInit_(prefix, options, ODL_Std_Args)

/*! @brief Write an IP address to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The IP address value to be written.
 @param[in] val2 The port value to be written. */
#  define ODL_IP(text1, val1, val2) \
        ODLIP_(ODL_Std_Args, text1, (long) (val1), (long) (val2))

/*! @brief Write a long string value to the log.
 @param[in] val1 The value to be written. */
#  define ODL_LS(val1) \
        ODLLS_(ODL_Std_Args, #val1 ": ", val1)

#  if defined(__OBJC__)
/*! @brief Write an object value to the log.
 @param[in] obj1 The value to be written. */
#   define ODL_O1(obj1) \
        ODLO1_(ODL_Std_Args, #obj1 ": ", obj1)

/*! @brief Write two object values to the log.
 @param[in] obj1 The value to be written.
 @param[in] obj2 The second value to be written. */
#   define ODL_O2(obj1, obj2) \
        ODLO2_(ODL_Std_Args, #obj1 ": ", obj1, #obj2 ": ", obj2)

/*! @brief Write three object values to the log.
 @param[in] obj1 The value to be written.
 @param[in] obj2 The second value to be written.
 @param[in] obj3 The third value to be written. */
#   define ODL_O3(obj1, obj2, obj3) \
        ODLO3_(ODL_Std_Args, #obj1 ": ", obj1, #obj2 ": ", obj2, #obj3 ": ", obj3)

/*! @brief Write four object values to the log.
 @param[in] obj1 The value to be written.
 @param[in] obj2 The second value to be written.
 @param[in] obj3 The third value to be written.
 @param[in] obj4 The fourth value to be written. */
#   define ODL_O4(obj1, obj2, obj3, obj4) \
        ODLO4_(ODL_Std_Args, #obj1 ": ", obj1, #obj2 ": ", obj2, #obj3 ": ", obj3, #obj4 ": ", obj4)
#  endif // defined(__OBJC__)

/*! @brief Write a method entry string to the log. */
#  define ODL_OBJENTER() \
        ODLObjEnter_(ODL_Std_Args, ODL_SELF_OR_THIS_OR_NULL_)

/*! @brief Write a void method exit string to the log. */
#  define ODL_OBJEXIT() \
        ODLObjExit_(ODL_Std_Args, ODL_SELF_OR_THIS_OR_NULL_)

/*! @brief Write a boolean method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_B(val) \
        ODLObjExitB_(ODL_Std_Args, ODL_SELF_OR_THIS_OR_NULL_, val)

/*! @brief Write a character method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_C(val) \
        ODLObjExitC_(ODL_Std_Args, ODL_SELF_OR_THIS_OR_NULL_, val)

/*! @brief Write a double method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_D(val) \
        ODLObjExitD_(ODL_Std_Args, ODL_SELF_OR_THIS_OR_NULL_, val)

/*! @brief Write an exit method string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_EXIT(val) \
        ODLObjExitExit_(ODL_Std_Args, ODL_SELF_OR_THIS_OR_NULL_, val)

/*! @brief Write an integer method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_I(val) \
        ODLObjExitI_(ODL_Std_Args, ODL_SELF_OR_THIS_OR_NULL_, val)

#  if defined(__OBJC__)
/*! @brief Write an object method exit string to the log.
 @param[in] val The value being returned by the method. */
#   define ODL_OBJEXIT_O(val) \
        ODLObjExitO_(ODL_Std_Args, ODL_SELF_OR_THIS_OR_NULL_, val)
#  endif // defined(__OBJC__)

/*! @brief Write a pointer method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_P(val) \
        ODLObjExitP_(ODL_Std_Args, ODL_SELF_OR_THIS_OR_NULL_, val)

#  if defined(__APPLE__)
/*! @brief Write a rectangle method exit string to the log.
 @param[in] val The value being returned by the method. */
#   define ODL_OBJEXIT_RECT(val) \
        ODLObjExitRect_(ODL_Std_Args, ODL_SELF_OR_THIS_OR_NULL_, val)
#  endif // defined(__APPLE__)

/*! @brief Write a string method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_S(val) \
        ODLObjExitS_(ODL_Std_Args, ODL_SELF_OR_THIS_OR_NULL_, val)

#  if defined(__APPLE__)
/*! @brief Write a size method exit string to the log.
 @param[in] val The value being returned by the method. */
#   define ODL_OBJEXIT_SIZE(val) \
        ODLObjExitSize_(ODL_Std_Args, ODL_SELF_OR_THIS_OR_NULL_, val)
#  endif // defined(__APPLE__)

/*! @brief Write a throw/integer method exit string to the log.
 @param[in] val The value being thrown by the method. */
#  define ODL_OBJEXIT_THROW_I(val) \
        ODLObjExitThrowI_(ODL_Std_Args, ODL_SELF_OR_THIS_OR_NULL_, val)

/*! @brief Write a throw/string method exit string to the log.
 @param[in] val The value being thrown by the method. */
#  define ODL_OBJEXIT_THROW_S(val) \
        ODLObjExitThrowS_(ODL_Std_Args, ODL_SELF_OR_THIS_OR_NULL_, val)

/*! @brief Write a throw/integer hexadecimal method exit string to the log.
 @param[in] val The value being thrown by the method. */
#  define ODL_OBJEXIT_THROW_X(val) \
        ODLObjExitThrowX_(ODL_Std_Args, ODL_SELF_OR_THIS_OR_NULL_, val)

/*! @brief Write an integer hexadecimal method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_X(val) \
        ODLObjExitX_(ODL_Std_Args, ODL_SELF_OR_THIS_OR_NULL_, val)

/*! @brief Write a pointer value to the log.
 @param[in] ptr1 The value to be written. */
#  define ODL_P1(ptr1) \
        ODLP1_(ODL_Std_Args, #ptr1 ": ", ptr1)

/*! @brief Write two pointer values to the log.
 @param[in] ptr1 The value to be written.
 @param[in] ptr2 The second value to be written. */
#  define ODL_P2(ptr1, ptr2) \
        ODLP2_(ODL_Std_Args, #ptr1 ": ", ptr1, #ptr2 ": ", ptr2)

/*! @brief Write three pointer values to the log.
 @param[in] ptr1 The value to be written.
 @param[in] ptr2 The second value to be written.
 @param[in] ptr3 The third value to be written. */
#  define ODL_P3(ptr1, ptr2, ptr3) \
        ODLP3_(ODL_Std_Args, #ptr1 ": ", ptr1, #ptr2 ": ", ptr2, #ptr3 ": ", ptr3)

/*! @brief Write four pointer values to the log.
 @param[in] ptr1 The value to be written.
 @param[in] ptr2 The second value to be written.
 @param[in] ptr3 The third value to be written.
 @param[in] ptr4 The fourth value to be written. */
#  define ODL_P4(ptr1, ptr2, ptr3, ptr4) \
        ODLP4_(ODL_Std_Args, #ptr1 ": ", ptr1, #ptr2 ": ", ptr2, #ptr3 ": ", ptr3, #ptr4 ": ", ptr4)

/*! @brief Write a region of memory to the log.
 @param[in] caption The caption for the region to be written.
 @param[in] buffer The starting address of the region.
 @param[in] size The number of bytes to be written. */
#  define ODL_PACKET(caption, buffer, size) \
        ODLPacket_(ODL_Std_Args, caption, buffer, size)

#  if defined(__APPLE__)
/*! @brief Write a rectangle to the log.
 @param[in] rect The value to be written. */
#   define ODL_RECT(rect) \
ODLRect_(ODL_Std_Args, #rect ": ", rect)
#  endif // defined(__APPLE__)

/*! @brief Write a string value to the log.
 @param[in] val1 The value to be written. */
#  define ODL_S1(val1) \
        ODLS1_(ODL_Std_Args, #val1 ": ", val1)

/*! @brief Write two string values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_S2(val1, val2) \
        ODLS2_(ODL_Std_Args, #val1 ": ", val1, #val2 ": ", val2)

/*! @brief Write three string values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_S3(val1, val2, val3) \
        ODLS3_(ODL_Std_Args, #val1 ": ", val1, #val2 ": ", val2, #val3 ": ", val3)

/*! @brief Write four string values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_S4(val1, val2, val3, val4) \
        ODLS4_(ODL_Std_Args, #val1 ": ", val1, #val2 ": ", val2, #val3 ": ", val3, #val4 ": ", val4)

/*! @brief Write a string value to the log.
 @param[in] val1 The value to be written. */
# define ODL_S1s(val1) \
        ODLS1_(ODL_Std_Args, #val1 ": ", val1.c_str())

/*! @brief Write two string values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written. */
# define ODL_S2s(val1, val2) \
        ODLS2_(ODL_Std_Args, #val1 ": ", val1.c_str(), #val2 ": ", val2.c_str())

/*! @brief Write three string values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written. */
# define ODL_S3s(val1, val2, val3) \
        ODLS3_(ODL_Std_Args, #val1 ": ", val1.c_str(), #val2 ": ", val2.c_str(), #val3 ": ", val3.c_str())

/*! @brief Write four string values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written.
 @param[in] val4 The fourth value to be written. */
# define ODL_S4s(val1, val2, val3, val4) \
        ODLS4_(ODL_Std_Args, #val1 ": ", val1.c_str(), #val2 ": ", val2.c_str(), #val3 ": ", val3.c_str(), #val4 ": ", val4.c_str())

#  if defined(__APPLE__)
/*! @brief Write a size to the log.
 @param[in] size The value to be written. */
#   define ODL_SIZE(size) \
        ODLSize_(ODL_Std_Args, #size ": ", size)
#  endif // defined(__APPLE__)

/*! @brief Write a (possibly unterminated) string to the log.
 @param[in] text The caption for the value to be written.
 @param[in] len The number of bytes to be written.
 @param[in] val The value to be written. */
#  define ODL_Sp(text, len, val) \
        ODLSp_(ODL_Std_Args, text, (long) len, val)

#  if MAC_OR_LINUX_
/*! @brief Write a time value to the log.
 @param[in] val1 The value to be written. */
#   define ODL_TIME(val1) \
        ODLTime_(ODL_Std_Args, #val1 ": ", val1)
#  endif // MAC_OR_LINUX_

/*! @brief Write an integer hexadecimal value to the log.
 @param[in] val1 The value to be written. */
#  define ODL_X1(val1) \
        ODLX1_(ODL_Std_Args, #val1 ": ", (intmax_t) (val1))

/*! @brief Write two integer hexadecimal values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_X2(val1, val2) \
        ODLX2_(ODL_Std_Args, #val1 ": ", (intmax_t) (val1), #val2 ": ", (intmax_t) (val2))

/*! @brief Write three integer hexadecimal values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_X3(val1, val2, val3) \
        ODLX3_(ODL_Std_Args, #val1 ": ", (intmax_t) (val1), #val2 ": ", (intmax_t) (val2), #val3 ": ", (intmax_t) (val3))

/*! @brief Write four integer hexadecimal values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_X4(val1, val2, val3, val4) \
        ODLX4_(ODL_Std_Args, #val1 ": ", (intmax_t) (val1), #val2 ": ", (intmax_t) (val2), #val3 ": ", (intmax_t) (val3), #val4 ": ", (intmax_t) (val4))

# else // ! defined(ODL_ENABLE_LOGGING_)
#  if defined(__OBJC__)
 /* Return the string description of an Objective-C object. */
#   define ODL_OBJ_PRINTABLE_STRING(xx) ""
#  endif // defined(__OBJC__)

/*! @brief Write a string to the log.
 @param[in] text The string to be written. */
#  define ODL_LOG(text) /* */

/*! @brief Write a boolean value to the log.
 @param[in] val1 The value to be written. */
#  define ODL_B1(val1) /* */

/*! @brief Write two boolean values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_B2(val1, val2) /* */

/*! @brief Write three boolean values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_B3(val1, val2, val3) /* */

/*! @brief Write four boolean values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_B4(val1, val2, val3, val4) /* */

/*! @brief Write a character value to the log.
 @param[in] val1 The value to be written. */
#  define ODL_C1(val1) /* */

/*! @brief Write two character values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_C2(val1, val2) /* */

/*! @brief Write three character values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_C3(val1, val2, val3) /* */

/*! @brief Write four character values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_C4(val1, val2, val3, val4) /* */

/*! @brief Write a double value to the log.
 @param[in] val1 The value to be written. */
#  define ODL_D1(val1) /* */

/*! @brief Write two double values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_D2(val1, val2) /* */

/*! @brief Write three double values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_D3(val1, val2, val3) /* */

/*! @brief Write four double values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_D4(val1, val2, val3, val4) /* */

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

/*! @brief Write an integer function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_I(val) /* */

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

/*! @brief Write a throw/integer function exit string to the log.
 @param[in] val The value being thrown by the function. */
#  define ODL_EXIT_THROW_I(val) /* */

/*! @brief Write a throw/string function exit string to the log.
 @param[in] val The value being thrown by the function. */
#  define ODL_EXIT_THROW_S(val) /* */

/*! @brief Write a throw/integer hexadecimal function exit string to the log.
 @param[in] val The value being thrown by the function. */
#  define ODL_EXIT_THROW_X(val) /* */

/*! @brief Write an integer hexadecimal function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_X(val) /* */

/*! @brief Write an integer value to the log.
 @param[in] val1 The value to be written. */
#  define ODL_I1(val1) /* */

/*! @brief Write two integer values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_I2(val1, val2) /* */

/*! @brief Write three integer values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_I3(val1, val2, val3) /* */

/*! @brief Write four integer values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_I4(val1, val2, val3, val4) /* */

/*! @brief Set up the logging state.
 @param[in] prefix The output prefix string to be applied.
 @param[in] options The logging options to be applied. */
#  define ODL_INIT(prefix, options) /* */

/*! @brief Write an IP address to the log.
 @param[in] text1 The caption for the value to be written.
 @param[in] val1 The IP address value to be written.
 @param[in] val2 The port value to be written. */
#  define ODL_IP(text1, val1, val2) /* */

/*! @brief Write a long string value to the log.
 @param[in] val1 The value to be written. */
#  define ODL_LS(val1) /* */

#  if defined(__OBJC__)
/*! @brief Write an object value to the log.
 @param[in] obj1 The value to be written. */
#   define ODL_O1(obj1) /* */

/*! @brief Write two object values to the log.
 @param[in] obj1 The value to be written.
 @param[in] obj2 The second value to be written. */
#   define ODL_O2(obj1, obj2) /* */

/*! @brief Write three object values to the log.
 @param[in] obj1 The value to be written.
 @param[in] obj2 The second value to be written.
 @param[in] obj3 The third value to be written. */
#   define ODL_O3(obj1, obj2, obj3) /* */

/*! @brief Write four object values to the log.
 @param[in] obj1 The value to be written.
 @param[in] obj2 The second value to be written.
 @param[in] obj3 The third value to be written.
 @param[in] obj4 The fourth value to be written. */
#   define ODL_O4(obj1, obj2, obj3, obj4) /* */
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

/*! @brief Write an integer method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_I(val) /* */

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

/*! @brief Write a throw/integer method exit string to the log.
 @param[in] val The value being thrown by the method. */
#  define ODL_OBJEXIT_THROW_I(val) /* */

/*! @brief Write a throw/string method exit string to the log.
 @param[in] val The value being thrown by the method. */
#  define ODL_OBJEXIT_THROW_S(val) /* */

/*! @brief Write a throw/integer hexadecimal method exit string to the log.
 @param[in] val The value being thrown by the method. */
#  define ODL_OBJEXIT_THROW_X(val) /* */

/*! @brief Write an integer hexadecimal method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_X(val) /* */

/*! @brief Write a pointer value to the log.
 @param[in] ptr1 The value to be written. */
#  define ODL_P1(ptr1) /* */

/*! @brief Write two pointer values to the log.
 @param[in] ptr1 The value to be written.
 @param[in] ptr2 The second value to be written. */
#  define ODL_P2(ptr1, ptr2) /* */

/*! @brief Write three pointer values to the log.
 @param[in] ptr1 The value to be written.
 @param[in] ptr2 The second value to be written.
 @param[in] ptr3 The third value to be written. */
#  define ODL_P3(ptr1, ptr2, ptr3) /* */

/*! @brief Write four pointer values to the log.
 @param[in] ptr1 The value to be written.
 @param[in] ptr2 The second value to be written.
 @param[in] ptr3 The third value to be written.
 @param[in] ptr4 The fourth value to be written. */
#  define ODL_P4(ptr1, ptr2, ptr3, ptr4) /* */

/*! @brief Write a region of memory to the log.
 @param[in] caption The caption for the region to be written.
 @param[in] buffer The starting address of the region.
 @param[in] size The number of bytes to be written. */
#  define ODL_PACKET(caption, buffer, size) /* */

#  if defined(__APPLE__)
/*! @brief Write a rectangle to the log.
 @param[in] rect The value to be written. */
#   define ODL_RECT(rect) /* */
#  endif // defined(__APPLE__)

/*! @brief Write a string value to the log.
 @param[in] val1 The value to be written. */
#  define ODL_S1(val1) /* */

/*! @brief Write two string values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_S2(val1, val2) /* */

/*! @brief Write three string values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_S3(val1, val2, val3) /* */

/*! @brief Write four string values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_S4(val1, val2, val3, val4) /* */

/*! @brief Write a string value to the log.
 @param[in] val1 The value to be written. */
# define ODL_S1s(val1) /* */

/*! @brief Write two string values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written. */
# define ODL_S2s(val1, val2) /* */

/*! @brief Write three string values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written. */
# define ODL_S3s(val1, val2, val3) /* */

/*! @brief Write four string values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written.
 @param[in] val4 The fourth value to be written. */
# define ODL_S4s(val1, val2, val3, val4) /* */

#  if defined(__APPLE__)
/*! @brief Write a size to the log.
 @param[in] size The value to be written. */
#   define ODL_SIZE(size) /* */
#  endif // defined(__APPLE__)

/*! @brief Write a (possibly unterminated) string to the log.
 @param[in] text The caption for the value to be written.
 @param[in] len The number of bytes to be written.
 @param[in] val The value to be written. */
#  define ODL_Sp(text, len, val) /* */

#  if MAC_OR_LINUX_
/*! @brief Write a time value to the log.
 @param[in] val1 The value to be written. */
#   define ODL_TIME(val1) /* */
#  endif // MAC_OR_LINUX_

/*! @brief Write an integer hexadecimal value to the log.
 @param[in] val1 The value to be written. */
#  define ODL_X1(val1) /* */

/*! @brief Write two integer hexadecimal values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written. */
#  define ODL_X2(val1, val2) /* */

/*! @brief Write three integer hexadecimal values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written. */
#  define ODL_X3(val1, val2, val3) /* */

/*! @brief Write four integer hexadecimal values to the log.
 @param[in] val1 The first value to be written.
 @param[in] val2 The second value to be written.
 @param[in] val3 The third value to be written.
 @param[in] val4 The fourth value to be written. */
#  define ODL_X4(val1, val2, val3, val4) /* */

# endif // ! defined(ODL_ENABLE_LOGGING_)

/*! @brief Write a string function exit string to the log.
 @param[in] val The value being returned by the function. */
#  define ODL_EXIT_s(val) \
        ODL_EXIT_S(val.c_str())

/*! @brief Write a string method exit string to the log.
 @param[in] val The value being returned by the method. */
#  define ODL_OBJEXIT_s(val) \
        ODL_OBJEXIT_S(val.c_str())

#endif // ! defined(ODL_INCLUDE_H_)
