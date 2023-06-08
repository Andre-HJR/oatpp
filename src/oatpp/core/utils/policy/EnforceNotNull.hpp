#ifndef oatpp_utils_policy_EnforceNotNull_hpp
#define oatpp_utils_policy_EnforceNotNull_hpp

#include "oatpp/core/utils/policy/ToDoPolicy.hpp"
namespace oatpp {
namespace utils {
    namespace policy {
        namespace EnforceNotNull_ {
            template <typename T> struct EnforceNotNUll: ::oatpp::utils::policy::ToDoPolicy
            {
                class NullPointerException : public std::Exception {};
                static void Check(T* ptr)
                {
                    if (!ptr)
                        throw NullPointerException;
                }
            };
        }
        template <typename T> using EnforceNotNull = ::oatpp::utils::policy::EnforceNotNull_::EnforceNotNUll;
    }  // namespace policy
}  // namespace utils
}  // namespace oatpp
#endif
