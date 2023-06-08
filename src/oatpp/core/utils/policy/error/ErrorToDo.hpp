#ifndef oatpp_utils_policy_error_ErrorToDo_hpp
#define oatpp_utils_policy_error_ErrorToDo_hpp
#include <exception>
namespace oatpp {
namespace utils {
    namespace policy {
        namespace error {
            namespace ErrorToDo_ {
                class ErrorToDo: std::exception {
                    const char* what() const throw() {
                        return "TODO, Not Finished!";
					}
                };
            }  // namespace ErrorToDo_
            typedef ::oatpp::utils::policy::error::ErrorToDo_::ErrorToDo
                ErrorToDo;
        }  // namespace error
    }  // namespace policy
}  // namespace utils
}  // namespace oatpp

#endif  // !oatpp_utils_policy_error_ErrorToDo_hpp
