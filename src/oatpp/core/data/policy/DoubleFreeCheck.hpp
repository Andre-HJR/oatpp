#ifndef oatpp_data_policy_DoubleFreeCheck_hpp
#define oatpp_data_policy_DoubleFreeCheck_hpp

namespace oatpp {
namespace data {
    namespace policy {
        template <typename T> struct DoubleFreeCheck
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
    }
}  // namespace data
}

#endif