#ifndef oatpp_utils_policy_ToDoPolicy_hpp
#define oatpp_utils_policy_ToDoPolicy_hpp

#include "oatpp/core/utils/policy/error/ErrorToDo.hpp"

namespace oatpp {
namespace utils {
    namespace policy {
        namespace ToDoPolicy_ {
            class ToDoPolicy {
              protected:
                ToDoPolicy() {
                    throw ::oatpp::utils::policy::error::ErrorToDo();
                }
                ~ToDoPolicy() {}
            };
        }
    }  // namespace policy
}  // namespace utils
}  // namespace oatpp
#endif