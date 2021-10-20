//https://www.boost.org/doc/libs/1_63_0/boost/type_traits/integral_constant.hpp
	template <typename T, bool val>
	struct is_integral_val
	{
		typedef T type;
		static const bool value = val;
	};
	template <typename> struct is_integral_type : is_integral_val<bool, false>{};
	template <> struct is_integral_type<bool> : is_integral_val<bool, true>{};
	template <> struct is_integral_type<char> : is_integral_val<char, true>{};
	template <> struct is_integral_type<signed char> : is_integral_val<signed char, true>{};
	template <> struct is_integral_type<short int> : is_integral_val<short int, true>{};
	template <> struct is_integral_type<int> : is_integral_val<int, true>{};
	template <> struct is_integral_type<long int> : is_integral_val<long int, true>{};
	template <> struct is_integral_type<long long int> : is_integral_val<long long int, true>{};
	template <> struct is_integral_type<unsigned char> : is_integral_val<unsigned char, true>{};
	template <> struct is_integral_type<unsigned short int> : is_integral_val<unsigned short int, true>{};
	template <> struct is_integral_type<unsigned int> : is_integral_val<unsigned int, true>{};
	template <> struct is_integral_type<unsigned long int> : is_integral_val<unsigned long int, true>{};
	template <> struct is_integral_type<unsigned long long int> : is_integral_val<unsigned long long int, true>{};
	//https://www.boost.org/doc/libs/1_63_0/boost/type_traits/is_integral.hpp
    template <typename T> struct is_integral : public is_integral_type<T>
	{
	};
