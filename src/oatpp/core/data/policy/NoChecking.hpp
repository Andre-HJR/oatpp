
#ifndef oatpp_data_policy_NoChecking_hpp
#define oatpp_data_policy_NoChecking_hpp
namespace oatpp {
namespace data {
    namespace policy {
        template <typename T> struct NoChecking
        {
            static void Check(T*) {}
        };
    }
}  // namespace data
}  // namespace oatpp

#endif