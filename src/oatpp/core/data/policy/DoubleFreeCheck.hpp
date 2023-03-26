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
#ifndef oatpp_data_policy_DoubleFreeCheck_hpp
#define oatpp_data_policy_DoubleFreeCheck_hpp

namespace oatpp {
namespace data {
    namespace policy {
        template <typename T> struct DoubleFreeCheck
        {
            template <typename Type>
			static void check_delete(Type* _x) {
				typedef char type_must_be_complete[sizeof(T) ? 1 : -1];
				(void)sizeof(type_must_be_complete);
				delete _x;
			}
			// TODO: Array Delete.
			template <typename Pointer>
            static void check_array_delete(Pointer _p)
            {
                delete _p;
            }
        };
    }
}  // namespace data
}

#endif