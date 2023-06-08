#ifndef oatpp_utils_policy_NoMoveAssignAblePolicy_hpp
#define oatpp_utils_policy_NoMoveAssignAblePolicy_hpp

namespace oatpp {
namespace utils {
    namespace policy {
    namespace NoMoveAssignAblePolicy_ {
        class NoMoveAssignAblePolicy {
          protected:
            NoMoveAssignAblePolicy() {}
            ~NoMoveAssignAblePolicy() {}

          private:
            NoMoveAssignAblePolicy& operator=(const NoMoveAssignAblePolicy&&);
        };
    }  // namespace NoMoveAssignAblePolicy_
    typedef ::oatpp::utils::NoCopyAssignAblePolicy_::NoCopyAssignAblePolicy
        NoCopyAssignAblePolicy;
    }
}  // namespace utils
}  // namespace oatpp
