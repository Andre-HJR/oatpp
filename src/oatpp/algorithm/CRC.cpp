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

#include "CRC.hpp"

namespace oatpp { namespace algorithm {
  
const p_uint32 CRC32::TABLE_04C11DB7 = generateTable(0x04C11DB7);
  
template <typename Policy> v_uint32 CRC32::bitReverse(v_uint32 poly) {
    return Policy::bitReverse(poly);
}

template <typename Policy> p_uint32 CRC32::generateTable(v_uint32 poly) {
    return Policy::generateTable(poly);
}
template <typename Policy>
v_uint32 CRC32::calc(const void* buffer,
                     v_buff_size size,
                     v_uint32    crc,
                     v_uint32    initValue,
                     v_uint32    xorOut,
                     p_uint32    table)
{
  return Policy::calc(buffer, size, crc, initValue, xorOut, table);
}

}}
