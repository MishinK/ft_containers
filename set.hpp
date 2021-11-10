#ifndef SET_HPP
#define SET_HPP
#include <memory>
#include <utility>
#include <iostream>

#include "tree.hpp"
namespace ft {

	template < class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
    class set
	{
	private:
		typedef RB_tree<T, T, ft::_Identity<T>, Compare> Tree;
  		Tree tree;
	public:	
		typedef T										key_type;
  		typedef T										value_type;
  		typedef Compare									key_compare;
  		typedef Compare									value_compare;
		typedef	Alloc									allocator_type;
		typedef T&										reference;
  		typedef const T&								const_reference;
		typedef T*										pointer;
  		typedef const T*								const_pointer;
		typedef typename Tree::iterator					iterator;
  		typedef typename Tree::const_iterator			const_iterator;
  		typedef typename Tree::reverse_iterator			reverse_iterator;
  		typedef typename Tree::const_reverse_iterator	const_reverse_iterator;
		typedef typename Tree::size_type				size_type;


		set(): tree() { }

		explicit set (const Compare& comp) : tree(comp) { }
		
		template <class InputIterator>
		set (InputIterator first, InputIterator last): tree()
		{ tree.insert_range_unique(first, last); }
		
		template<typename InputIterator>
		set(InputIterator first, InputIterator last, const Compare& comp): tree(comp)
		{ tree.insert_range_unique(first, last); }
		
		set (const set& x): tree(x.tree) { }
	
		set& operator=(const set& x)
		{
			tree = x.tree;
			return (*this);
		}

		iterator begin() { return (tree.begin()); }
		const_iterator begin() const { return (tree.begin()); }
		iterator end() { return (tree.end()); }
		const_iterator end() const { return (tree.end()); }
		reverse_iterator rbegin() { return (tree.rbegin()); }
		const_reverse_iterator rbegin() const { return (tree.rbegin()); }
		reverse_iterator rend() { return (tree.rend()); }
		const_reverse_iterator rend() const { return (tree.rend()); }

		bool empty() const { return (tree.empty()); }
		size_type size() const { return (tree.size()); }
		size_type max_size() const { 
		std::allocator<T> alloc;
		return (alloc.max_size() / sizeof(pointer));}

		
		ft::pair<iterator, bool> insert(const value_type& val) { return (tree.insert_unique(val)); }

		iterator insert(iterator position, const value_type& val) { return (tree.insert_unique(position, val)); }

		template<typename InputIterator>
		void insert(InputIterator first, InputIterator last) { tree.insert_range_unique(first, last); }

		void erase(iterator position) { tree.erase(position); }

		size_type erase(const value_type& val) { return (tree.erase(val)); }

		void erase(iterator first, iterator last) { tree.erase(first, last); }

		void swap(set &x) { tree.swap(x.tree); }

		void clear() { tree.clear(); }

		key_compare key_comp() const { return (tree.key_comp()); }
		value_compare value_com() const { return (tree.key_comp()); }

		iterator find(const value_type& val) { return (tree.find(val)); }
		const_iterator find (const value_type& val) const { return (tree.find(val)); }

		size_type count (const value_type& val) const { return (tree.count(val)); }

		iterator lower_bound (const value_type& val) { return (tree.lower_bound(val));}
		const_iterator lower_bound (const value_type& val) const { return (tree.lower_bound(val));}
		iterator upper_bound (const value_type& val)  { return (tree.upper_bound(val)); }
		const_iterator upper_bound (const value_type& val) const { return (tree.upper_bound(val)); }

		ft::pair<iterator, iterator> equal_range (const value_type& val) { return (tree.equal_range(val)); }
		ft::pair<const_iterator,const_iterator> equal_range (const value_type& val) const { return (tree.equal_range(val)); }

	};


};
#endif