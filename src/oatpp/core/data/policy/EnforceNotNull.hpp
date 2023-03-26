#ifndef oatpp_data_policy_EnforceNotNull_hpp
#define oatpp_data_policy_EnforceNotNUll_hpp

namespace oatpp
{
    namespace data {
        namespace policy {
            template <typename T> struct EnforceNotNUll
            {
                class NullPointerException : public std::Exception {};
                static void Check(T* ptr)
                {
                    if (!ptr)
                        throw NullPointerException;
                }
            };
        }
    }
}

#endif