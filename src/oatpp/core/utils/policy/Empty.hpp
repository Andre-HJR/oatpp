#ifndef oatpp_utils_policy_Empty_hpp
#define oatpp_utils_policy_Empty_hpp
#include "oatpp/core/utils/policy/ToDoPolicy.hpp"
namespace oatpp {
namespace utils {
    namespace policy {
        namespace Empty_ {
        template <typename T> struct Empty: ::oatpp::utils::policy::ToDoPolicy
        {
            static void empty_check(T* _) {}
        };
        }
        template <typename T> using Empty = ::oatpp::utils::policy::Empty_::Empty<T>;
    }  // namespace policy
}  // namespace utils
}  // namespace oatpp
#endif  // !oatpp_utils_policy_Empty_hpp
