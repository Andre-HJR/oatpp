#ifndef oatpp_utils_policy_NoChecking_hpp
#define oatpp_utils_policy_NoChecking_hpp
#include "oatpp/core/utils/policy/ToDoPolicy.hpp"
namespace oatpp {
namespace utils {
    namespace policy {
        namespace NoChecking_ {
        template <typename T> struct NoChecking: ::oatpp::utils::policy::ToDoPolicy
        {
            static void Check(T*) {}
        };
        }
        template <typename T> using NoChecking = ::oatpp::utils::policy::NoChecking_::NoChecking<T>;
    }  // namespace policy
}  // namespace utils
}  // namespace oatpp

#endif  // !oatpp_utils_policy_NoChecking_hpp
