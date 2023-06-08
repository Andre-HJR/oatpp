#ifndef oatpp_utils_policy_NoCopyAssignAblePolicy_hpp
#define oatpp_utils_policy_NoCopyAssignAblePolicy_hpp

namespace oatpp {
namespace utils {
namespace policy {
    namespace NoCopyAssignAblePolicy_ {
        class NoCopyAssignAblePolicy {
          protected:
            NoCopyAssignAblePolicy() {}
            ~NoCopyAssignAblePolicy() {}

          private:
            NoCopyAssignAblePolicy& operator=(const NoCopyAssignAblePolicy&);
        };
    }  // namespace NoCopyAssignAblePolicy_
    typedef ::oatpp::utils::policy::NoCopyAssignAblePolicy_::NoCopyAssignAblePolicy
        NoCopyAssignAblePolicy;
}}} // namespace oatpp
#endif
