#ifndef oatpp_utils_policy_nocopyablepolicy_hpp
#define oatpp_utils_policy_nocopyablepolicy_hpp
#include "oatpp/core/utils/policy/NoCopyAssignAblePolicy.hpp"
#include "oatpp/core/utils/policy/NoMoveAssignAblePolicy.hpp"
namespace oatpp {
namespace utils {
namespace policy {
	namespace NoCopyAblePolicy_ {
        class NoCopyAblePolicy: 
            ::oatpp::utils::policy::NoCopyAssignAblePolicy,
              ::oatpp::utils::policy::NoMoveAssignAblePolicy
        {
          protected:
            NoCopyAblePolicy() {}
            ~NoCopyAblePolicy() {}

          private:
            NoCopyAblePolicy(const NoCopyAblePolicy&);
        };
	}
    typedef ::oatpp::utils::policy::NoCopyAblePolicy_::NoCopyAblePolicy
        NoCopyAblePolicy;
}}}  // namespace oatpp
#endif