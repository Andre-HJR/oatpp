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
#ifndef oatpp_data_policy_ThreadingModel_hpp
#define oatpp_data_policy_ThreadingModel_hpp

namespace oatpp {
namespace data {
    namespace policy {
        /**
         * ThreadingModel
         * In Thread Program, there are three step for `++x`
         *  1. Obtain `x` from memory.
         *  2. ALU in CPU inc the x. (ALU is work-station for inc operation).
         *  3. Rewrite the `x` into memory.
         *  Read - Modify - Write
         */
        template <typename T> class ThreadingModel {};
    }
}  // namespace data
}  // namespace oatpp
#endif