#ifndef HELP_HPP
#define HELP_HPP

#include <memory>
#include <utility>
#include <iostream>

namespace ft
{

	template <bool, typename _Tp = void>
	struct enable_if
	{
	};

	template <typename _Tp>
	struct enable_if<true, _Tp>
	{
		typedef _Tp type;
	};

	struct false_type
	{
	};
	struct true_type
	{
	};

	template <class _Tp>
	struct is_integral
	{
		enum
		{
			value = 0
		};
		typedef false_type __type;
	};
	template <>
	struct is_integral<bool>
	{
		enum
		{
			value = 1
		};
		typedef true_type __type;
	};
	template <>
	struct is_integral<char>
	{
		enum
		{
			value = 1
		};
		typedef true_type __type;
	};
	template <>
	struct is_integral<signed char>
	{
		enum
		{
			value = 1
		};
		typedef true_type __type;
	};
	template <>
	struct is_integral<unsigned char>
	{
		enum
		{
			value = 1
		};
		typedef true_type __type;
	};
	template <>
	struct is_integral<wchar_t>
	{
		enum
		{
			value = 1
		};
		typedef true_type __type;
	};
	template <>
	struct is_integral<short>
	{
		enum
		{
			value = 1
		};
		typedef true_type __type;
	};
	template <>
	struct is_integral<unsigned short>
	{
		enum
		{
			value = 1
		};
		typedef true_type __type;
	};
	template <>
	struct is_integral<int>
	{
		enum
		{
			value = 1
		};
		typedef true_type __type;
	};
	template <>
	struct is_integral<unsigned int>
	{
		enum
		{
			value = 1
		};
		typedef true_type __type;
	};
	template <>
	struct is_integral<long>
	{
		enum
		{
			value = 1
		};
		typedef true_type __type;
	};
	template <>
	struct is_integral<unsigned long>
	{
		enum
		{
			value = 1
		};
		typedef true_type __type;
	};
	template <>
	struct is_integral<long long>
	{
		enum
		{
			value = 1
		};
		typedef true_type __type;
	};
	template <>
	struct is_integral<unsigned long long>
	{
		enum
		{
			value = 1
		};
		typedef true_type __type;
	};
	template <>
	struct is_integral<__int128_t>
	{
		enum
		{
			value = 1
		};
		typedef true_type __type;
	};
	template <>
	struct is_integral<__uint128_t>
	{
		enum
		{
			value = 1
		};
		typedef true_type __type;
	};

	template <class A, class B>
	class pair
	{
	public:
		typedef pair<A, B> 			pair_type;
		typedef A 					first_type;
		typedef B 					second_type;

		first_type first;
		second_type second;

		pair() : first(), second(){};

		template <class C, class D>
		pair(const pair<C, D> &other) : first(other.first), second(other.second) {}

		pair(const pair_type &other) : first(other.first), second(other.second) {}

		pair(const first_type &a, const second_type &b) : first(a), second(b) {}

		pair &operator=(const pair_type &other)
		{
			if (this == &other)
				return (*this);
			first = other.first;
			second = other.second;
			return (*this);
		}
	};

	template <class A, class B>
	bool operator==(const ft::pair<A, B> &lhs, const std::pair<A, B> &rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class A, class B>
	bool operator==(const std::pair<A, B> &lhs, const ft::pair<A, B> &rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class A, class B>
	bool operator==(const ft::pair<A, B> &lhs, const ft::pair<A, B> &rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}


	template <class A, class B>
	bool operator<(const ft::pair<A, B> &lhs, const std::pair<A, B> &rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class A, class B>
	bool operator<(const std::pair<A, B> &lhs, const ft::pair<A, B> &rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class A, class B>
	bool operator<(const ft::pair<A, B> &lhs, const ft::pair<A, B> &rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class A, class B>
	bool operator!=(const ft::pair<A, B> &lhs, const std::pair<A, B> &rhs) { return !(lhs == rhs); }
	template <class A, class B>
	bool operator!=(const std::pair<A, B> &lhs, const ft::pair<A, B> &rhs) { return !(lhs == rhs); }
	template <class A, class B>
	bool operator!=(const ft::pair<A, B> &lhs, const ft::pair<A, B> &rhs) { return !(lhs == rhs); }

	template <class A, class B>
	bool operator>(const ft::pair<A, B> &lhs, const std::pair<A, B> &rhs) { return (rhs < lhs); }
	template <class A, class B>
	bool operator>(const std::pair<A, B> &lhs, const ft::pair<A, B> &rhs) { return (rhs < lhs); }
	template <class A, class B>
	bool operator>(const ft::pair<A, B> &lhs, const ft::pair<A, B> &rhs) { return (rhs < lhs); }

	template <class A, class B>
	bool operator<=(const ft::pair<A, B> &lhs, const std::pair<A, B> &rhs) { return !(rhs < lhs); }
	template <class A, class B>
	bool operator<=(const std::pair<A, B> &lhs, const ft::pair<A, B> &rhs) { return !(rhs < lhs); }
	template <class A, class B>
	bool operator<=(const ft::pair<A, B> &lhs, const ft::pair<A, B> &rhs) { return !(rhs < lhs); }

	template <class A, class B>
	bool operator>=(const ft::pair<A, B> &lhs, const std::pair<A, B> &rhs) { return !(lhs < rhs); }
	template <class A, class B>
	bool operator>=(const std::pair<A, B> &lhs, const ft::pair<A, B> &rhs) { return !(lhs < rhs); }
	template <class A, class B>
	bool operator>=(const ft::pair<A, B> &lhs, const ft::pair<A, B> &rhs) { return !(lhs < rhs); }

	template <class A, class B>
	pair<A, B> make_pair(A x, B y)
	{
		return (pair<A, B>(x, y));
	}

	template <class _Arg, class _Arg2, class _Result>
	struct binary_function
	{
		typedef _Arg 		first_argument_type;
		typedef _Arg2 		second_argument_type;
		typedef _Result 	result_type;
	};

	template<typename _Arg, typename _Result>
    struct unary_function
    {
      typedef _Arg 		argument_type;   
      typedef _Result 	result_type;  
    };
	
	template<typename T>
	struct less: public ft::binary_function<T, T, bool> {
		bool	operator()(const T& x, const T& y) const {
			return (x < y);
		}
	};

	template <class _Pair>
	struct _Select1st : public ft::unary_function<_Pair, typename _Pair::first_type>
	{
		typename _Pair::first_type& operator()(_Pair& __x) const
		{
			return (__x.first);
		}
		const typename _Pair::first_type& operator()(const _Pair& __x) const
		{
			return (__x.first);
		}
	};
	template<typename _Tp>
	struct _Identity : public ft::unary_function<_Tp,_Tp>
	{
		_Tp& operator()(_Tp& __x) const { return (__x); }
		const _Tp& operator()(const _Tp& __x) const { return __x; }
	};

	template <typename A>
    void swap(A& a, A&b)
    {
        A tmp = a;
        a = b;
        b = tmp;
    };

	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                             InputIt2 first2, InputIt2 last2)
	{
    	for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
        	if (*first1 < *first2) return true;
        	if (*first2 < *first1) return false;
    	}
    return (first1 == last1) && (first2 != last2);
	}

	template< class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
        	if (comp(*first1, *first2)) return true;
        	if (comp(*first2, *first1)) return false;
    	}
    	return (first1 == last1) && (first2 != last2);
	}
	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
    	for (; first1 != last1; ++first1, ++first2) {
        	if (!(*first1 == *first2)) {
            	return false;
        	}
    	}
    	return true;
	}
};
#endif