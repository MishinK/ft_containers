#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <utility>
#include "iterator.hpp"
#include "help.hpp"
namespace ft
{

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T 																	value_type;
		typedef Alloc 																allocator_type;
		typedef value_type& 														reference;
		typedef const value_type&													const_reference;
		typedef value_type* 														pointer;
		typedef const value_type*													const_pointer;
		typedef VectorIterator<value_type>											iterator;
		typedef VectorConstIterator<value_type>										const_iterator;
		typedef VectorReverseIterator<iterator>										reverse_iterator;
		typedef VectorReverseConstIterator<const_iterator>							const_reverse_iterator;
		typedef ptrdiff_t                                   						difference_type;
		typedef size_t		                                   						size_type;
	private:
		pointer 		data;
		size_type 		vsize;
		size_type 		vcapacity;
		allocator_type 	valloc;
	public:
		explicit vector (const allocator_type& _alloc = allocator_type()): vsize(0), vcapacity(0), valloc(_alloc)
		{
			data = valloc.allocate(vcapacity);
		};
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& _alloc = allocator_type()): vsize(n), vcapacity(n), valloc(_alloc)
		{
			data = valloc.allocate(vcapacity);
            for (size_type i = 0; i < vsize; ++i)
				valloc.construct(&data[i], val);
		};
		template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& _alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0): vsize(0), vcapacity(0), valloc(_alloc)
		{
			InputIterator tmp(first);
            
			while (tmp != last)
			{
                vsize++;
				vcapacity++;
				tmp++;
			}   
            data = valloc.allocate(vcapacity);
			for (size_type i = 0; first != last; ++first, ++i)
                	valloc.construct(&data[i], *first);
		};
		vector (const vector& x): vsize(x.vsize), vcapacity(x.vcapacity), valloc(x.valloc)
		{
			*this = x;
		};
		~vector()
		{
			for (iterator it = begin(); it != end(); ++it)
                valloc.destroy(&(*it));
            valloc.deallocate(data, vcapacity);
		};
		vector& operator= (const vector&x)
		{
			data = valloc.allocate(x.vcapacity);
			vcapacity = x.vcapacity;
			vsize = x.vsize;
            for (ft::pair<int, const_iterator> i(0, x.begin()); i.second != x.end(); ++i.first, ++i.second)
				valloc.construct(&data[i.first], *i.second);
			return (*this);
		};
	public:
		iterator 				begin(){return (iterator(data));};
		const_iterator 			begin() const {return (const_iterator(data));};
		iterator 				end(){return (iterator(data + vsize));};
		const_iterator 			end() const {return (const_iterator(data + vsize));};
		reverse_iterator 		rbegin(){return (reverse_iterator(data - 1 + vsize));};
		const_reverse_iterator	rbegin() const {return (const_reverse_iterator(data - 1 + vsize));};
		reverse_iterator 		rend(){return (reverse_iterator(data - 1));};
		const_reverse_iterator	rend() const {return (const_reverse_iterator(data - 1));};
	public:
		size_type size() const {return (vsize);};
		size_type max_size() const {return (valloc.max_size());};
		void resize (size_type n, value_type val = value_type())
		{
			while (n < vsize)
				pop_back();
			if (n > vcapacity)
				reserve(n);
			while (n > vsize)
				push_back(val);
		}
		size_type capacity() const {return (vcapacity);};
		bool empty() const {return (vsize == 0);};
		void reserve (size_type n)
		{
            if (n > max_size())
                throw std::length_error("vector");
            if (n > vcapacity)
                realloc(n);
		};
	public:
		reference operator[] (size_type n) {return (data[n]);};
		const_reference operator[] (size_type n) const {return (data[n]);}
		reference at (size_type n)
		{
            if (n >= vsize)
                throw std::out_of_range("vector");
            return (data[n]);
        };
		const_reference at (size_type n) const
		{
            if (n >= vsize)
                throw std::out_of_range("vector");
            return (data[n]);
        };
		reference front(){return (data[0]);};
		const_reference front() const{return (data[0]);};
		reference back(){return (data[vsize - 1]);};
		const_reference back() const{return (data[vsize - 1]);};
	public:
		void assign (size_type n, const value_type& val)
		{
			clear();
			while (n)
			{
				push_back(val);
				--n;
			}
			vcapacity = vsize;
		};

		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
		{
			clear();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
			vcapacity = vsize;
		};

		void push_back (const value_type& val)
		{
			if (vsize >= vcapacity)
			{
				if (vcapacity == 0)
					realloc(1);
				else
					realloc(vcapacity * 2);
			}
			valloc.construct(&data[vsize], val);
			vsize++;
		};
		void pop_back()
		{
			if (vsize)
                valloc.destroy(&data[vsize - 1]);
			vsize--;
		};
		iterator insert(iterator position, const value_type& val)
		{
			difference_type idx = position - begin();
			insert(position, 1, val);
			return (iterator(&data[idx]));
		};
    	void insert(iterator position, size_type n, const value_type& val)
		{
			difference_type idx = position - begin();
			if (vsize + n > vcapacity)
                realloc(vcapacity + n);
			iterator newPosition(&data[idx]);
			if (newPosition != end())
                push_right(newPosition, n);
			for (size_type i = 0; i < n; ++i)
                valloc.construct(&(*newPosition++), val);
			vsize += n;
		};
		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
		{
			size_type n = 0;
            InputIterator tmp(first);
            while (tmp++ != last)
                ++n;
			difference_type idx = position - begin();
			if (vsize + n > vcapacity)
                realloc(vcapacity + n);
			iterator newPosition(&data[idx]);
			if (newPosition != end())
                push_right(newPosition, n);
			for (size_type i = 0; i < n; ++i)
                valloc.construct(&(*newPosition++), *first++);
            vsize += n;
		};
		iterator erase (iterator position)
		{
			return (erase(position, position + 1));
		};
		iterator erase (iterator first, iterator last)
		{
			if (first == end() || first == last)
                return (first);
			difference_type idx = first - begin();
			if (last < end())
            {
                push_left(first, last);
				vsize -= static_cast<size_type>(last - first);
            }
			else
            {
                size_type newSize = vsize - static_cast<size_type>(last - first);
                while (vsize != newSize)
                    pop_back();
            }
			return (iterator(&data[idx]));
		};
		void swap (vector& x)
		{
            ft::swap(data, x.data);
            ft::swap(vsize, x.vsize);
            ft::swap(vcapacity, x.vcapacity);
			ft::swap(valloc, x.valloc);
		};
		void clear()
		{
			while (vsize)
                pop_back();
		};
	public:
		template <class A, class B>
		friend bool operator==(const vector<A, B>& lhs, const vector<A, B>& rhs)
        {
			return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
        };
		template <class A, class B>
		friend bool operator!=(const vector<A, B>& lhs, const vector<A, B>& rhs)
		{
			return (!(lhs == rhs));
		};
		template <class A, class B>
		friend bool operator<(const vector<A, B>& lhs, const vector<A, B>& rhs)
        {
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
        };
		template <class A, class B>
		friend bool operator>(const vector<A, B>& lhs, const vector<A, B>& rhs)
		{
			return (rhs < lhs);
		};
		template <class A, class B>
		friend bool operator>=(const vector<A, B>& lhs, const vector<A, B>& rhs)
		{
			return (!(lhs < rhs));
		};
		template <class A, class B>
		friend bool operator<=(const vector<A, B>& lhs, const vector<A, B>& rhs)
		{
			return !(lhs > rhs);
		};
		template <class A, class B>
		friend void swap (const vector<A, B>& x, const vector<A, B>& y)
		{
			x.swap(y);
		};

	private:
		void realloc(size_type newCapacity)
        {
            pointer tmp = valloc.allocate(newCapacity);
            for (size_type i = 0; i < vsize; ++i)
                valloc.construct(&tmp[i], data[i]);
            for (iterator it = begin(); it != end(); ++it)
                valloc.destroy(&(*it));
            valloc.deallocate(data, vcapacity);
            vcapacity = newCapacity;
            data = tmp;
        };
		void push_right(iterator pos, size_type lenMov)
        {
            for (ft::pair<iterator, iterator> it(end() - 1, end()); it.second != pos; --it.first, --it.second)
            {
                valloc.construct(&(*(it.first + lenMov)), *it.first);
                valloc.destroy(&(*it.first));
            }
        };
		void push_left(iterator first, iterator last)
        {
            for (; first != end(); ++first, ++last)
            {
            	valloc.destroy(&(*first));
                if (last < end())
                    valloc.construct(&(*(first)), *last);
            }
        };

	};
};
#endif