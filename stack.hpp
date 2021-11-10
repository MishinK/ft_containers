#ifndef STAVK_HPP
#define STAVK_HPP
#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T 			value_type;
		typedef Container 	container_type;
		typedef size_t 		size_type;
	protected:
		container_type ctnr;
	public:
		explicit stack(const container_type& _ctnr = container_type()): ctnr(_ctnr){}
	public:
		bool empty() const {return (ctnr.empty());}
		size_type size() const {return (ctnr.size());}
		value_type& top() {return (ctnr.back());}
		const value_type& top() const {return (ctnr.back());}
		void push(const value_type& val) {ctnr.push_back(val);}
		void pop() {ctnr.pop_back();}
	
		template <class A, class B>
  		friend bool operator== (const stack<A, B>& lhs, const stack<A, B>& rhs);
		
		template <class A, class B>
  		friend bool operator!= (const stack<A, B>& lhs, const stack<A, B>& rhs);
		
		template <class A, class B>
  		friend bool operator<  (const stack<A, B>& lhs, const stack<A, B>& rhs);
		
		template <class A, class B>
  		friend bool operator<= (const stack<A, B>& lhs, const stack<A, B>& rhs);
	
		template <class A, class B>
  		friend bool operator>  (const stack<A, B>& lhs, const stack<A, B>& rhs);
		
		template <class A, class B>
  		friend bool operator>= (const stack<A, B>& lhs, const stack<A, B>& rhs);
		 
		  
	};
	template <class T, class Container>
  	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs){return (lhs.ctnr == rhs.ctnr);}
	template <class T, class Container>
  	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){return !(lhs == rhs);}
	template <class T, class Container>
  	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){return (lhs.ctnr < rhs.ctnr);}
	template <class T, class Container>
  	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){return !(lhs > rhs);}
	template <class T, class Container>
  	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){return (rhs < lhs);}
	template <class T, class Container>
  	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){return !(rhs < lhs);}
};
#endif