#ifndef oatpp_utils_policy_DoubleFreeCheck_hpp
#define oatpp_utils_policy_DoubleFreeCheck_hpp
#include "oatpp/core/utils/policy/ToDoPolicy.hpp"
namespace oatpp {
namespace utils {
    namespace policy {
        namespace DoubleFreeCheck_ {
        template <typename T> struct DoubleFreeCheck: ::oatpp::utils::policy::ToDoPolicy
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
        }  // namespace DoubleFreeCheck_
        template<typename T> using DoubleFreeCheck = ::oatpp::utils::policy::DoubleFreeCheck_::DoubleFreeCheck;
    }  // namespace policy
}  // namespace utils
}  // namespace oatpp
#endif  // !oatpp_utils_policy_DoubleFreeCheck_hpp
