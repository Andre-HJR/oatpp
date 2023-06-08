/***************************************************************************
 *
 * Project         _____    __   ____   _      _
 *                (  _  )  /__\ (_  _)_| |_  _| |_
 *                 )(_)(  /(__)\  )( (_   _)(_   _)
 *                (_____)(__)(__)(__)  |_|    |_|
 *
 *
 * Copyright 2018-present, Leonid Stryzhevskyi <lganzzzo@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************************/

#ifndef oatpp_concurrency_Thread_hpp
#define oatpp_concurrency_Thread_hpp

#include "oatpp/core/base/Environment.hpp"
#include <thread>

namespace oatpp { namespace concurrency {

/**
 * Set thread affinity to one CPU.
 * @param nativeHandle - `std::thread::native_handle_type`.
 * @param cpuIndex - index of CPU.
 * @return - zero on success. Negative value on failure.
 * -1 if platform that runs application does not support this call.
 */
v_int32 setThreadAffinityToOneCpu(std::thread::native_handle_type nativeHandle, v_int32 cpuIndex);

/**
 * Set thread affinity [firstCpuIndex..lastCpuIndex].
 * @param nativeHandle - `std::thread::native_handle_type`.
 * @param firstCpuIndex - from CPU-index.
 * @param lastCpuIndex - to CPU-index included.
 * @return - zero on success. Negative value on failure.
 * -1 if platform that runs application does not support this call.
 */
v_int32 setThreadAffinityToCpuRange(std::thread::native_handle_type nativeHandle, v_int32 firstCpuIndex, v_int32 lastCpuIndex);

/**
 * Get hardware concurrency.
 * @return - OATPP_THREAD_HARDWARE_CONCURRENCY config value if set <br>
 * else return std::thread::hardware_concurrency() <br>
 * else return 1. <br>
 */
v_int32 getHardwareConcurrency();

/** SingleThreaded Mode
 * This is a SingleThread, simple and do not deal with asynchronous.
 * Function: template argument is an abstract of a SingleThread Api or Policy.
 */
template <class Host, class MutexPolicy, class Function = SingleThreadedFunction<Host>> class SingleThreaded {
    struct Lock
    {
        Lock() {}
        explicit Lock(const SingleThreaded&) {}
        explicit Lock(const SingleThreaded*) {}
    };
    using VolatileType = Host;
    using IntType = int;
    static inline IntType AtomicAdd(volatile IntType& lval, IntType val) {
        return Function::AtomicAdd(lval, val);
    }
    static inline IntType AtomicSubtract(volatile IntType& lval, IntType val)
    {
        return Function::AtomicSubtract(lval, val);
    }
    
    static inline IntType AtomicMultiply(volatile IntType& lval, IntType val)
    {
        return Function::AtomicMultiply(lval, val);
    }
    
    static inline IntType AtomicDivide(volatile IntType& lval, IntType val)
    {
        return Function::AtomicDivide(lval, val);
    }
    
    static inline IntType AtomicIncrement(volatile IntType& lval)
    {
        return Function::AtomicIncrement(lval);
    }
    
    static inline IntType AtomicDecrement(volatile IntType& lval)
    {
        return Function::AtomicDecrement(lval);
    }
    
    static inline void AtomicAssign(volatile IntType & lval, IntType val)
    {
        return Function::AtomicAssign(lval, val);
    }
    
    static inline void AtomicAssign(IntType & lval, volatile IntType & val)
    {
        return Function::AtomicAssign(lval, val);
    }
};
template <typename Host> class SingleThreadedFunction {
    using VolatileType = Host;
    using IntType      = int;
    static inline IntType AtomicAdd(volatile IntType& lval, IntType val) {
        return lval += val;
    }
    static inline IntType AtomicSubtract(volatile IntType& lval, IntType val)
    { return lval -= val; }
    
    static inline IntType AtomicMultiply(volatile IntType& lval, IntType val)
    { return lval *= val; }
    
    static inline IntType AtomicDivide(volatile IntType& lval, IntType val)
    { return lval /= val; }
    
    static inline IntType AtomicIncrement(volatile IntType& lval)
    { return ++lval; }
    
    static inline IntType AtomicDecrement(volatile IntType& lval)
    { return --lval; }
    
    static inline void AtomicAssign(volatile IntType & lval, IntType val)
    { lval = val; }
    
    static inline void AtomicAssign(IntType & lval, volatile IntType & val)
    { lval = val; }

};
}}

#endif /* concurrency_Thread_hpp */
