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