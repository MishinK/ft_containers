#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

# include <memory>
# include <cstddef>

namespace ft {

	template < typename T, class Category = std::random_access_iterator_tag >
	class VectorIterator {
	public:
		typedef VectorIterator<T>													iterator_type;
		typedef ptrdiff_t															difference_type;
		typedef	Category															iterator_category;
		typedef	T																	value_type;
		typedef T*																	pointer;
		typedef T&																	reference;
	protected:
		pointer	__i;
	public:

		VectorIterator() : __i() {}
		explicit
		VectorIterator(const pointer p) : __i(p) {}
		VectorIterator(const iterator_type& it) {*this = it;}
		~VectorIterator() {}
		iterator_type&	operator=(const iterator_type& it) {
			__i = it.__i;
			return (*this);
		}

		iterator_type&	operator++() {
			++__i;
			return (*this);
		}
		iterator_type	operator++(int) {
			iterator_type out(*this);
			++__i;
			return (out);
		}
		iterator_type&	operator--() {
			--__i;
			return (*this);
		}
		iterator_type	operator--(int) {
			iterator_type out(*this);
			--__i;
			return (out);
		}

		difference_type	operator-(iterator_type it) const {
			return (__i - it.__i);
		}

		difference_type	operator+(iterator_type it) const {
			return (__i + it.__i);
		}

		iterator_type	operator-(difference_type n) const {
			iterator_type out(*this);
			out.__i -= n;
			return (out);
		}

		iterator_type	operator+(difference_type n) const {
			iterator_type out(*this);
			out.__i += n;
			return (out);
		}

		iterator_type&	operator+=(difference_type n) {
			__i += n;
			return (*this);
		}
		iterator_type&	operator-=(difference_type n) {
			__i -= n;
			return (*this);
		}

		reference	operator*() const {
			return (*__i);
		}

		pointer		operator->() const {
			return (__i);
		}
		
		reference	operator[](difference_type n) const {
			return (*(__i + n));
		}

		friend bool operator==(const iterator_type& lhs, const iterator_type& rhs) { return (lhs.__i == rhs.__i);}		
		friend bool operator!=(const iterator_type& lhs, const iterator_type& rhs) { return !(lhs == rhs); }
		friend bool operator<(const iterator_type& lhs, const iterator_type& rhs) { return (lhs.__i < rhs.__i);}
		friend bool operator>(const iterator_type& lhs, const iterator_type& rhs) { return (rhs < lhs); }
		friend bool operator<=(const iterator_type& lhs, const iterator_type& rhs) { return !(rhs < lhs); }
		friend bool operator>=(const iterator_type& lhs, const iterator_type& rhs) { return !(lhs < rhs); }
	};

	template < typename T, class Category = std::random_access_iterator_tag >
	class VectorConstIterator {
	public:
		typedef VectorConstIterator<T>												iterator_type;
		typedef ptrdiff_t															difference_type;
		typedef	Category															iterator_category;
		typedef	T																	value_type;
		typedef T*																	pointer;
		typedef T&																	reference;
	protected:
		pointer	__i;
	public:
		VectorConstIterator() : __i() {}
		explicit
		VectorConstIterator(const pointer p) : __i(p) {}
		VectorConstIterator(const iterator_type& it) {*this = it;}
		VectorConstIterator(const VectorIterator<T> &it): __i(it.__i) { }
		~VectorConstIterator() {}
		iterator_type&	operator=(const iterator_type& it) {
			__i = it.__i;
			return (*this);
		}

		iterator_type&	operator++() {
			++__i;
			return (*this);
		}
		iterator_type	operator++(int) {
			iterator_type out(*this);
			++__i;
			return (out);
		}
		iterator_type&	operator--() {
			--__i;
			return (*this);
		}
		iterator_type	operator--(int) {
			iterator_type out(*this);
			--__i;
			return (out);
		}

		difference_type	operator-(iterator_type it) const {
			return (__i - it.__i);
		}
		difference_type	operator+(iterator_type it) const {
			return (__i + it.__i);
		}

		iterator_type	operator-(difference_type n) const {
			iterator_type out(*this);
			out.__i -= n;
			return (out);
		}

		iterator_type	operator+(difference_type n) const {
			iterator_type out(*this);
			out.__i += n;
			return (out);
		}

		iterator_type&	operator+=(difference_type n) {
			__i += n;
			return (*this);
		}
		iterator_type&	operator-=(difference_type n) {
			__i -= n;
			return (*this);
		}

		reference	operator*() const {
			return (*__i);
		}

		pointer		operator->() const {
			return (__i);
		}
		
		reference	operator[](difference_type n) const {
			return (*(__i + n));
		}

		friend bool operator==(const iterator_type& lhs, const iterator_type& rhs) { return (lhs.__i == rhs.__i);}		
		friend bool operator!=(const iterator_type& lhs, const iterator_type& rhs) { return !(lhs == rhs); }
		friend bool operator<(const iterator_type& lhs, const iterator_type& rhs) { return (lhs.__i < rhs.__i);}
		friend bool operator>(const iterator_type& lhs, const iterator_type& rhs) { return (rhs < lhs); }
		friend bool operator<=(const iterator_type& lhs, const iterator_type& rhs) { return !(rhs < lhs); }
		friend bool operator>=(const iterator_type& lhs, const iterator_type& rhs) { return !(lhs < rhs); }
	};



	template<class iterator>
	class VectorReverseIterator
	{
	public:
		typedef VectorReverseIterator<iterator> 	iterator_type;
		typedef typename iterator::reference		reference;
		typedef typename iterator::pointer			pointer;
		typedef typename iterator::difference_type	difference_type;
	protected:
      	iterator current;
	public:
		VectorReverseIterator(): current(){}
		explicit
		VectorReverseIterator(const pointer p) : current(p) {}
		VectorReverseIterator(const iterator& it) : current(it) {}
		VectorReverseIterator(const iterator_type& it) : current(it.current) { }
		

		reference operator*() const
      	{
		  iterator out(current);
		  return (*out);
      	}
		
		pointer operator->() const
		{
			iterator out(current);
			return (S_to_pointer(out));
      	}

		iterator_type& operator++()
      	{
			--current;
			return (*this);
		}

		iterator_type operator++(int)
      	{
			iterator_type out(*this);
		  	--current;
		  	return (out);
		}

		iterator_type&	operator--()
		{
			++current;
			return (*this);
		}

		iterator_type operator--(int)
      	{
		  iterator_type out(*this);
		  ++current;
		  return (out);
		}

		iterator_type operator+(difference_type n) const {
			return (iterator_type(current - n));
		}
		
		iterator_type& operator+=(difference_type n) {
			current -= n;
			return (*this);
		}
		
		iterator_type operator-(difference_type n) const {
			return (iterator_type(current + n));
		}
		
		iterator_type& operator-=(difference_type n) {
			current += n;
			return (*this);
		}
		
		reference operator[](difference_type n) const {
			return *(*this + n);
		}
		
		friend bool operator==(const iterator_type& lhs, const iterator_type& rhs) { return (lhs.current == rhs.current);}		
		friend bool operator!=(const iterator_type& lhs, const iterator_type& rhs) { return !(lhs == rhs); }
		friend bool operator<(const iterator_type& lhs, const iterator_type& rhs) { return (lhs.current > rhs.current);}
		friend bool operator>(const iterator_type& lhs, const iterator_type& rhs) { return (rhs < lhs); }
		friend bool operator<=(const iterator_type& lhs, const iterator_type& rhs) { return !(rhs < lhs); }
		friend bool operator>=(const iterator_type& lhs, const iterator_type& rhs) { return !(lhs < rhs); }

	private:
    	template<typename T>
		static T* S_to_pointer(T* p){
			return (p);
		}

    	template<typename T>
		static pointer	S_to_pointer(T t){
			return (t.operator->());
		}
	};

	template<class iterator>
	class VectorReverseConstIterator
	{
	public:
		typedef VectorReverseConstIterator<iterator> 	iterator_type;
		typedef typename iterator::reference			reference;
		typedef typename iterator::pointer				pointer;
		typedef typename iterator::difference_type		difference_type;
	protected:
      	iterator current;
	public:
		VectorReverseConstIterator(): current(){}
		explicit
		VectorReverseConstIterator(const pointer p) : current(p) {}
		VectorReverseConstIterator(const iterator& it) : current(it) {}
		VectorReverseConstIterator(const iterator_type& it) : current(it.current) { }
		
		reference operator*() const
      	{
		  iterator out(current);
		  return (*out);
      	}
		
		pointer operator->() const
		{
			iterator out(current);
			return (S_to_pointer(out));
      	}

		iterator_type& operator++()
      	{
			--current;
			return (*this);
		}

		iterator_type operator++(int)
      	{
			iterator_type out(*this);
		  	--current;
		  	return (out);
		}

		iterator_type&	operator--()
		{
			++current;
			return (*this);
		}

		iterator_type operator--(int)
      	{
		  iterator_type out(*this);
		  ++current;
		  return (out);
		}

		iterator_type operator+(difference_type n) const {
			return (iterator_type(current - n));
		}
		
		iterator_type& operator+=(difference_type n) {
			current -= n;
			return (*this);
		}
		
		iterator_type operator-(difference_type n) const {
			return (iterator_type(current + n));
		}
		
		iterator_type& operator-=(difference_type n) {
			current += n;
			return (*this);
		}
		
		reference operator[](difference_type n) const {
			return *(*this + n);
		}
		
		friend bool operator==(const iterator_type& lhs, const iterator_type& rhs) { return (lhs.current == rhs.current);}		
		friend bool operator!=(const iterator_type& lhs, const iterator_type& rhs) { return !(lhs == rhs); }
		friend bool operator<(const iterator_type& lhs, const iterator_type& rhs) { return (lhs.current > rhs.current);}
		friend bool operator>(const iterator_type& lhs, const iterator_type& rhs) { return (rhs < lhs); }
		friend bool operator<=(const iterator_type& lhs, const iterator_type& rhs) { return !(rhs < lhs); }
		friend bool operator>=(const iterator_type& lhs, const iterator_type& rhs) { return !(lhs < rhs); }

	private:
    	template<typename T>
		static T* S_to_pointer(T* p){
			return (p);
		}

    	template<typename T>
		static pointer	S_to_pointer(T t){
			return (t.operator->());
		}

	};

}

#endif