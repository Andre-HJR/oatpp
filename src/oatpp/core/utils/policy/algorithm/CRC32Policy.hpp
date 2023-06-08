#ifndef oatpp_utils_policy_algorithm_crc32policy_hpp
#define oatpp_utils_policy_algorithm_crc32policy_hpp
#include "oatpp/core/base/Environment.hpp"

#include "oatpp/encoding/Hex.hpp"
#include "oatpp/core/utils/policy/NoCopyAblePolicy.hpp"

namespace oatpp {
namespace utils {
    namespace policy {
        namespace algorithm {
            namespace CRC32Policy_ {
                /**
                 * Implementation of CRC-32 Policy. Cyclic redundancy check
                 * algorithm.
                 */

                struct CRC32Policy: ::oatpp::utils::policy::NoCopyAblePolicy
                {
                    static v_uint32 bitReverse(v_uint32 poly);

                    /**
                     *  Generates v_uint32 table[256] for polynomial
                     */
                    static p_uint32 generateTable(v_uint32 poly);

                    /**
                     * Calculate CRC32 value for buffer of defined size
                     * @param buffer
                     * @param size
                     * @param crc
                     * @param initValue
                     * @param xorOut
                     * @param table
                     * @return - CRC32 value (v_uint32)
                     */
                    static v_uint32 calc(const void* buffer,
                                         v_buff_size size,
                                         v_uint32    crc,
                                         v_uint32    initValue,
                                         v_uint32    xorOut,
                                         p_uint32    table);
                };
            }  // namespace CRC32Policy_
            typedef ::oatpp::utils::policy::algorithm::CRC32Policy_::CRC32Policy
                CRC32Policy;
        }
    }
}  // namespace utils
}  // namespace oatpp

#endif