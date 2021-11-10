#ifndef TREE_HPP
#define TREE_HPP
#include <iterator>
#include <limits>
#include <iostream>
#include <vector>

#include "help.hpp"

namespace ft {
	enum Color
	{
		red = false,
		black = true
	};

	class RB_node
	{
	public:
		typedef RB_node*			RB_ptr;
		typedef const RB_node*		RB_const_ptr;
	  	
		Color	color;
	  	RB_ptr		parent;
	  	RB_ptr 		left;
	  	RB_ptr 		right;
		
	  	RB_node() {}
	  	RB_node(RB_ptr node)
		{
	    	color = red;
	    	parent = node->parent;
	    	left = node->left;
	    	right = node->right;
	  	}
	  	RB_ptr s_minimum(RB_ptr x, RB_ptr end)
		{
			while (x->left != end)
		  		x = x->left;
			return (x);
	  	}
	  	RB_const_ptr s_minimum(RB_const_ptr x, RB_const_ptr end) const
	  	{
			while (x->left != end)
		  		x = x->left;
			return (x);
	  	}
	  	RB_ptr s_maximum(RB_ptr x, RB_ptr end)
		{
			while (x->right != end)
		  		x = x->right;
			return (x);
	  	}
	  	RB_const_ptr s_maximum(RB_const_ptr x, RB_const_ptr end) const 
	  	{
			while (x->right != end)
		  		x = x->right;
			return (x);
	  	}
		RB_ptr RB_inc(RB_ptr x, RB_ptr end)
		{
			if (x->right != end)
				return (s_minimum(x->right, end));
			RB_ptr y = x->parent;
			while (y != end && x == y->right)
			{
				x = y;
				y = y->parent;
  			}
  			return (y);
		}
		RB_const_ptr RB_inc(RB_const_ptr x, RB_const_ptr end) const
		{
			if (x->right != end)
				return (s_minimum(x->right, end));
			RB_ptr y = x->parent;
			while (y != end && x == y->right)
			{
				x = y;
				y = y->parent;
  			}
  			return (y);
		}
		RB_ptr RB_dec(RB_ptr x, RB_ptr end)
		{
			if (x == end)
				return (end->right);
  			if (x->left != end)
				return (s_maximum(x->left, end));
  			RB_ptr y = x->parent;
  			while (y != end && x == y->left)
			{
				x = y;
				y = y->parent;
  			}
			return (y);
		}
		RB_const_ptr RB_dec(RB_const_ptr x, RB_const_ptr end) const
		{
			if (x == end)
				return (end->right);
  			if (x->left != end)
				return (s_maximum(x->left, end));
  			RB_ptr y = x->parent;
  			while (y != end && x == y->left)
			{
				x = y;
				y = y->parent;
  			}
			return (y);
		}
	};

	class RB_head
	{
	public:
		RB_node 			header;
		std::size_t			node_count;
		
		RB_head() : header()
		{
			header.color = black;
			reset();
		}
		void reset()
		{
			header.parent = &header;
			header.left = &header;
			header.right = &header;
			node_count = 0;
		}
	};

	template<typename T>
	class RB_base : public RB_node
	{
	public:
		typedef RB_base<T>*		link;
		RB_base(T value) : RB_node(), value_type(value) {}
		RB_base(T value, RB_ptr node) : RB_node(node), value_type(value) {}
		T* getptr() { return (__builtin_addressof(value_type)); }
		const T* getptr() const { return (__builtin_addressof(value_type)); }
	private:
		T 								value_type;
	};
	
	template<typename T>
	class RB_tree_iterator
	{
	public:
		typedef T									value_type;
	  	typedef T&									reference;
	  	typedef T*									pointer;
		typedef RB_tree_iterator<T>					iterator_type;
	  	typedef RB_node::RB_ptr						RB_ptr;
	  	typedef RB_base<T>*							link;

		RB_ptr node;
		RB_ptr end;
		RB_tree_iterator(): node(), end() { }
		explicit RB_tree_iterator(RB_ptr x, RB_ptr end): node(x), end(end) { }
	//	RB_tree_iterator(const iterator_type& it): node(it.node), end(it.end) { }
		
		reference operator*() const
		{
			return (*static_cast<link>(node)->getptr());
		}

		pointer operator->() const
		{
			return (static_cast<link>(node)->getptr());
		}

		iterator_type& operator++()
		{
			node = node->RB_inc(node, end);
			return (*this);
		}
		iterator_type operator++(int)
		{
			iterator_type out(*this);
			node = node->RB_inc(node, end);
			return (out);
		}
		iterator_type& operator--()
		{
			node = node->RB_dec(node, end);
			return (*this);
		}
		iterator_type operator--(int)
		{
			iterator_type out(*this);
			node = node->RB_dec(node, end);
			return (out);
		}
		friend bool operator==(const iterator_type& x, const iterator_type& y) {return (x.node == y.node);}
		friend bool operator!=(const iterator_type& x, const iterator_type& y) {return (x.node != y.node);}
	};

	template<typename T>
	class RB_tree_reverse_iterator
	{
	public:
		typedef T									value_type;
	  	typedef T&									reference;
	  	typedef T*									pointer;
		typedef RB_tree_reverse_iterator<T>			iterator_type;
	  	typedef RB_node::RB_ptr						RB_ptr;
	  	typedef RB_base<T>*							link;

		RB_ptr node;
		RB_ptr end;
		RB_tree_reverse_iterator(): node(), end() { }
		explicit RB_tree_reverse_iterator(RB_ptr x, RB_ptr end): node(x), end(end) { }
	//	RB_tree_reverse_iterator(const iterator_type& it): node(it.node), end(it.end) { }
		
		
		reference operator*() const
		{
			return (*static_cast<link>(node)->getptr());
		}

		pointer operator->() const
		{
			return (static_cast<link>(node)->getptr());
		}

		iterator_type& operator--()
		{
			node = node->RB_inc(node, end);
			return (*this);
		}
		iterator_type operator--(int)
		{
			iterator_type out(*this);
			node = node->RB_inc(node, end);
			return (out);
		}
		iterator_type& operator++()
		{
			node = node->RB_dec(node, end);
			return (*this);
		}
		iterator_type operator++(int)
		{
			iterator_type out(*this);
			node = node->RB_dec(node, end);
			return (out);
		}
		friend bool operator==(const iterator_type& x, const iterator_type& y) {return (x.node == y.node);}
		friend bool operator!=(const iterator_type& x, const iterator_type& y) {return (x.node != y.node);}
	};

	template<typename T>
	class RB_tree_const_iterator
	{
	public:
		typedef T									value_type;
	  	typedef const T&							reference;
	  	typedef const T*							pointer;
		typedef RB_tree_const_iterator<T>			iterator_type;
	  	typedef RB_node::RB_const_ptr				RB_ptr;
	  	typedef const RB_base<T>*					link;

		typedef RB_tree_iterator<T> 				iterator;

		RB_ptr node;
		RB_ptr end;
		RB_tree_const_iterator(): node(), end() { }
		explicit RB_tree_const_iterator(RB_ptr x, RB_ptr end): node(x), end(end) { }
	//	RB_tree_const_iterator(const iterator_type& it): node(it.node), end(it.end) { }
		RB_tree_const_iterator(const iterator& it): node(it.node), end(it.end) { }

		iterator _const_cast() const {
			return  iterator(const_cast<typename iterator::RB_ptr>(node), const_cast<typename iterator::RB_ptr>(end));
		}

		reference operator*() const
		{
			return (*static_cast<link>(node)->getptr());
		}

		pointer operator->() const
		{
			return (static_cast<link>(node)->getptr());
		}

		iterator_type& operator++()
		{
			node = node->RB_inc(node, end);
			return (*this);
		}
		iterator_type operator++(int)
		{
			iterator_type out(*this);
			node = node->RB_inc(node, end);
			return (out);
		}
		iterator_type& operator--()
		{
			node = node->RB_dec(node, end);
			return (*this);
		}
		iterator_type operator--(int)
		{
			iterator_type out(*this);
			node = node->RB_dec(node, end);
			return (out);
		}
		friend bool operator==(const iterator_type& x, const iterator_type& y) {return (x.node == y.node);}
		friend bool operator!=(const iterator_type& x, const iterator_type& y) {return (x.node != y.node);}
	};

	template<typename T>
	class RB_tree_const_reverse_iterator
	{
	public:
		typedef T									value_type;
	  	typedef const T&							reference;
	  	typedef const T*							pointer;
		typedef RB_tree_const_reverse_iterator<T>	iterator_type;
	  	typedef RB_node::RB_const_ptr	RB_ptr;
	  	typedef const RB_base<T>*					link;

		typedef RB_tree_reverse_iterator<T>			iterator;

		RB_ptr node;
		RB_ptr end;
		RB_tree_const_reverse_iterator(): node(), end() { }
		explicit RB_tree_const_reverse_iterator(RB_ptr x, RB_ptr end): node(x), end(end) { }
		RB_tree_const_reverse_iterator(const iterator& it): node(it.node), end(it.end) { }
		//RB_tree_const_reverse_iterator(const RB_tree_reverse_iterator<T>& it): node(it.node), end(it.end) { }
		

		iterator _const_cast() const {
			return  (iterator(const_cast<typename iterator::RB_ptr>(node), const_cast<typename iterator::RB_ptr>(end)));
		}

		reference operator*() const
		{
			return (*static_cast<link>(node)->getptr());
		}

		pointer operator->() const
		{
			return (static_cast<link>(node)->getptr());
		}

		iterator_type& operator--()
		{
			node = node->RB_inc(node, end);
			return (*this);
		}
		iterator_type operator--(int)
		{
			iterator_type out(*this);
			node = node->RB_inc(node, end);
			return (out);
		}
		iterator_type& operator++()
		{
			node = node->RB_dec(node, end);
			return (*this);
		}
		iterator_type operator++(int)
		{
			iterator_type out(*this);
			node = node->RB_dec(node, end);
			return (out);
		}
		friend bool operator==(const iterator_type& x, const iterator_type& y) {return (x.node == y.node);}
		friend bool operator!=(const iterator_type& x, const iterator_type& y) {return (x.node != y.node);}
	};


	template<typename key, typename val_type, typename key_val, typename compare>
	class RB_tree
	{
	public:
		typedef RB_node*							RB_ptr;
	  	typedef const RB_node*						RB_const_ptr;
	  	typedef RB_base<val_type>*					link;
	  	typedef const RB_base<val_type>*			const_link;

		typedef const key							key_type;
	  	typedef val_type							value_type;

	  	typedef val_type*							pointer;
	  	typedef const val_type*						const_pointer;
	  	typedef val_type&							reference;
	  	typedef const val_type&						const_reference;

	  	typedef size_t								size_type;
		
		typedef RB_tree_iterator<value_type>				iterator;
	  	typedef RB_tree_const_iterator<value_type>			const_iterator;
	  	typedef RB_tree_reverse_iterator<value_type>		reverse_iterator;
	  	typedef RB_tree_const_reverse_iterator<value_type>	const_reverse_iterator;

		RB_head			*head;
	  	compare			key_compare;
		
		protected:
		RB_ptr _root() { return (head->header.parent); }
		RB_const_ptr _root() const { return (head->header.parent); }
		RB_ptr _leftmost() { return (head->header.left); }
		RB_const_ptr _leftmost() const { return (head->header.left); }
		RB_ptr _rightmost() { return (head->header.right); }
		RB_const_ptr _rightmost() const { return (head->header.right); }
		link _begin() { return (static_cast<link>(head->header.parent)); }
		const_link _begin() const { return (static_cast<const_link>(head->header.parent)); }
		RB_ptr _end(){ return (&head->header); }
		RB_const_ptr _end() const { return (&head->header); }
		const_reference _s_value(const_link x) { return (*x->getptr()); }
		const key_type& _s_key(const_link x) const { return (key_val()(*x->getptr())); }
		const key_type& _s_key(RB_const_ptr x) const { return (_s_key(static_cast<const_link>(x))); }
		link _s_left(RB_ptr x) { return (static_cast<link>(x->left)); }
		const_link _s_left(RB_const_ptr x) const { return (static_cast<const_link>(x->left)); }
		link _s_right(RB_ptr x) { return (static_cast<link>(x->right)); }
		const_link _s_right(RB_const_ptr x) const  { return (static_cast<const_link>(x->right)); }
		const_reference _s_value(RB_const_ptr x) { return (*static_cast<const_link>(x)->getptr()); }
		RB_ptr _s_minimum(RB_ptr x) { return (x->s_minimum(x, _end())); }
		RB_const_ptr _s_minimum(RB_const_ptr x) { return (x->s_minimum(x, _end())); }
		RB_ptr _s_maximum(RB_ptr x) { return (x->s_maximum(x, _end())); }
		RB_const_ptr _s_maximum(RB_const_ptr x) { return (x->s_maximum(x, _end())); }
		public:
		void _leftRotate(RB_ptr x)
	  	{
			RB_ptr y = x->right;
			x->right = y->left;
			if (y->left != _end())
		  		y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == _end())
		 		head->header.parent = y;
			else if (x == x->parent->left)
		  		x->parent->left = y;
			else
		  		x->parent->right = y;
			y->left = x;
			x->parent = y;
	  	}
		void _rightRotate(RB_ptr x)
		{
			RB_ptr y = x->left;
			x->left = y->right;
			if (y->right != _end())
		  		y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == _end())
		  		head->header.parent = y;
			else if (x == x->parent->right)
		  		x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
	  	}
		void _insertFixUp(RB_ptr z)
	  	{
			while (z->parent->color == red)
		  	{
				if (z->parent == z->parent->parent->left)
				{
					RB_ptr y = z->parent->parent->right;
					if (y->color == red)
					{
						z->parent->color = black;
						y->color = black;
						z->parent->parent->color = red;
						z = z->parent->parent;
					}
					else
					{
			  			if (z == z->parent->right)
						{
							z = z->parent;
							_leftRotate(z);
						}
						z->parent->color = black;
						z->parent->parent->color = red;
						_rightRotate(z->parent->parent);
					}	
		  		}
				else
				{
					RB_ptr y = z->parent->parent->left;
					if (y->color == red)
					{
			  			z->parent->color = black;
			  			y->color = black;
			  			z->parent->parent->color = red;
			  			z = z->parent->parent;
					}
					else
					{
			  			if (z == z->parent->left)
						{
							z = z->parent;
							_rightRotate(z);
			  			}
			  			z->parent->color = black;
			  			z->parent->parent->color = red;
			  			_leftRotate(z->parent->parent);
					}
		  		}
			}
			_root()->color = black;
	  	}

		ft::pair<iterator, bool> _insert_unique(RB_ptr n)
		{
			RB_ptr y = _end();
			RB_ptr temp = _root();
			while (temp != _end())
			{
		  		y = temp;
		  		if (key_compare(_s_key(n), _s_key(temp)))
					temp = temp->left;
		  		else if (key_compare(_s_key(temp), _s_key(n)))
					temp = temp->right;
		  		else
				{
					return (ft::pair<iterator, bool>(iterator(temp, _end()), false));
		  		}
			}
			n->parent = y;
			if (y == _end())
		  		head->header.parent = n;
			else if (key_compare(_s_key(n), _s_key(y)))
		  		y->left = n;
			else
		  		y->right = n;
			n->left = _end();
			n->right = _end();
			head->node_count++;
			_insertFixUp(n);
			return (ft::pair<iterator, bool>(iterator(n, _end()), true));
	  	}
		
		void _insert_equal(RB_ptr n)
		{
			RB_ptr y = _end();
			RB_ptr temp = _root();
			while (temp != _end())
			{
				y = temp;
				if (key_compare(_s_key(n), _s_key(temp)))
					temp = temp->left;
		  		else
					temp = temp->right;
			}
			n->parent = y;
			if (y == _end())
		  		head->header.parent = n;
			else if (key_compare(_s_key(n), _s_key(y)))
		  		y->left = n;
			else
		  		y->right = n;
			n->left = _end();
			n->right = _end();
			head->node_count++;
			_insertFixUp(n);
	  	}

		void _transplant(RB_ptr u, RB_ptr v)
		{
			if (u->parent == _end())
		  		head->header.parent = v;
			else if (u == u->parent->left)
		  		u->parent->left = v;
			else
		  		u->parent->right = v;
			if (v->parent != head->header.parent)
		  		v->parent = u->parent;
		}

		void _deleteFixUp(RB_ptr x)
		{
			while (x != head->header.parent && x->color == black)
			{
		  		if (x == x->parent->left)
				{
					RB_ptr w = x->parent->right;
					if (w->color == red)
					{
			  			w->color = black;
						x->parent->color = red;
			  			_leftRotate(x->parent);
			  			w = x->parent->right;
					}
					if (w->left->color == black && w->right->color == black)
					{
			  			w->color = red;
			  			x = x->parent;
					}
					else
					{
			  			if (w->right->color == black)
			  			{
							w->left->color = black;
							w->color = red;
							_rightRotate(w);
							w = x->parent->right;
			  			}
			  			w->color = x->parent->color;
			  			x->parent->color = black;
			  			w->right->color = black;
			  			_leftRotate(x->parent);
			  			x = head->header.parent;
					}
		  		}
				else
				{
					RB_ptr w = x->parent->left;
					if (w->color == red)
					{
			  			w->color = black;
			  			x->parent->color = red;
			  			_rightRotate(x->parent);
			  			w = x->parent->left;
					}
					if (w->left->color == black && w->right->color == black)
					{
			  			w->color = red;
			  			x = x->parent;
					}
					else
					{
			  			if (w->left->color == black)
			  			{
							w->right->color = black;
							w->color = red;
							_leftRotate(w);
							w = x->parent->left;
			  			}
			  			w->color = x->parent->color;
			  			x->parent->color = black;
			  			w->left->color = black;
			  			_rightRotate(x->parent);
			  			x = head->header.parent;
					}
		  		}
			}
			x->color = black;
	  	}

		void _delete(RB_ptr z)
	  	{
			RB_ptr y = z;
			RB_ptr x;
			Color y_original_color = y->color;
			if (z->left == _end())
			{
		  		x = z->right;
		  		_transplant(z, z->right);
			}
			else if (z->right == _end())
			{
		  		x = z->left;
		  		_transplant(z, z->left);
			}
			else
			{
		  		y = _s_minimum(z->right);
		  		x = y->right;
		  		y_original_color = y->color;
				if (y->parent == z)
				{
					if (x->parent != head->header.parent)
			  			x->parent = y;
		  		}
				else
				{
					_transplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
		  		}
		  		if (x == _end())
		    		x = y;
		  		_transplant(z, y);
		  		y->left = z->left;
		  		y->left->parent = y;
		  		y->color = z->color;
			}
			if (y_original_color == black)
				_deleteFixUp(x);
		}
		
		iterator _lower_bound(link x, RB_ptr y, const key_type& k)
		{
			while (x != _end())
			{
				if (!key_compare(_s_key(x), k))
				{
					y = x;
					x = _s_left(x);
				}
				else
				{
					x = _s_right(x);
				}
			}
			return iterator(y, _end());
		}
		
		const_iterator _lower_bound(const_link x, RB_const_ptr y, const key_type& k) const
		{
			while (x != _end())
			{
				if (!key_compare(_s_key(x), k))
				{
					y = x;
					x = _s_left(x);
				}
				else
				{
					x = _s_right(x);
				}
			}
			return const_iterator(y, _end());
		}
		
		iterator _upper_bound(link x, RB_ptr y, const key_type& k)
		{
			while (x != _end())
			{
				if (key_compare(k, _s_key(x)))
				{
					y = x;
					x = _s_left(x);
				}
				else
				{
					x = _s_right(x);
				}
			}
			return iterator(y, _end());
		}
		
		const_iterator _upper_bound(const_link x, RB_const_ptr y, const key_type& k) const
		{
			while (x != _end())
			{
				if (key_compare(k, _s_key(x)))
				{
					y = x;
					x = _s_left(x);
				}
				else
				{
					x = _s_right(x);
				}
			}
			return const_iterator(y, _end());
		}

		RB_tree() : head(new RB_head) { }
		RB_tree(const compare& comp) : head(new RB_head), key_compare(comp) { }
		RB_tree(const RB_tree& x) : head(new RB_head)
		{
			const_iterator begin = x.begin();
			const_iterator end = x.end();
			while (begin != end)
			{
				insert_equal(*begin);
				begin++;
			}
		}
		
		void del(link x)
		{
			if (x != _end())
			{
				del(_s_left(x));
				del(_s_right(x));
				delete x;
			}
		}
		
		~RB_tree()
		{
			del(_begin());
			delete head;
		}
		
		RB_tree& operator=(const RB_tree& x)
		{
			if (this == &x)
				return (*this);
			clear();
			const_iterator begin = x.begin();
			const_iterator end = x.end();
			while (begin != end)
			{
				insert_equal(*begin);
				begin++;
			}
			return (*this);
		}
		
		compare key_comp() const { return (key_compare); }
		
		iterator begin() { return (iterator(head->header.left, _end())); }
		
		const_iterator begin() const { return (const_iterator(head->header.left, _end())); }
		
		iterator end() { return (iterator(_end(), _end())); }
		
		const_iterator end() const { return (const_iterator(_end(), _end())); }
		
		reverse_iterator rbegin() { return (++reverse_iterator(_end(), _end())); }
		
		const_reverse_iterator rbegin() const { return (++const_reverse_iterator(_end(), _end())); }
		
		reverse_iterator rend() { return (reverse_iterator (head->header.left, _end()));}
		
		const_reverse_iterator rend() const { return (const_reverse_iterator (head->header.left, _end()));}
		
		bool empty() const { return (head->node_count == 0); }
		
		size_type size() const { return (head->node_count); }
		
		size_type max_size() const  { 
		return (std::numeric_limits<size_type>::max() / sizeof(RB_base<value_type>)); }
		
		void swap(RB_tree &t)
		{
			ft::swap(head, t.head);
			ft::swap(key_compare, t.key_compare);
		}
		
		ft::pair<iterator, bool> insert_unique(const_reference value)
		{
			link node = new RB_base<value_type>(value);
			node->parent = _end();
			node->left = _end();
			node->right = _end();
			node->color = red;
			ft::pair<iterator, bool> ret = _insert_unique(node);
			if (ret.second == false)
			{
				delete node;
				return (ret);
			}
			else
			{
				if (head->header.left == _end() || key_compare(_s_key(node), _s_key(head->header.left)))
				{
					head->header.left = node;
				}
				if (head->header.right == _end() || key_compare(_s_key(head->header.right), _s_key(node)))
				{
					head->header.right = node;
				}
		  		return (ft::pair<iterator, bool>(iterator(node, _end()), true));
			}
		}
		
		iterator insert_equal(const_reference x)
		{
			link node = new RB_base<value_type>(x);
			node->parent = _end();
			node->left = _end();
			node->right = _end();
			node->color = red;
			_insert_equal(node);
			if (head->header.left == _end() || key_compare(_s_key(node), _s_key(head->header.left)))
			{
				head->header.left = node;
			}
			if (head->header.right == _end() || key_compare(_s_key(head->header.right), _s_key(node)) || (!key_compare(_s_key(head->header.right), _s_key(node)) && !key_compare(_s_key(node),_s_key(head->header.right))))
			{
				head->header.right = node;
			}
			return iterator(node, _end());
		}
		
		iterator insert_unique(iterator position, const_reference x) { 
			(void) position;
			return (insert_unique(x).first);
		}
		
		iterator insert_equal(iterator position, const_reference x) { 
			(void) position;
			return (insert_equal(x));
		}
		
		template<typename InputIterator>
		void insert_range_unique(InputIterator first, InputIterator last)
		{
			for (; first != last; ++first)
				insert_unique(*first);
		}
		
		template<typename InputIterator>
		void insert_range_equal(InputIterator first, InputIterator last)
		{
			for (; first != last; ++first)
				insert_equal(*first);
		}
		
		void erase(iterator pos)
		{
			iterator tmp;
			if (_leftmost() == pos.node)
			{
				tmp = pos;
				++tmp;
				head->header.left = tmp.node;
			}
			if (_rightmost() == pos.node)
			{
				tmp = pos;
				--tmp;
				head->header.right = tmp.node;
			}
			head->node_count--;
			_delete(pos.node);
			delete static_cast<link>(pos.node);
		}
		
		void erase(const_iterator pos) { erase(pos._const_cast()); }
		
		size_type erase(const key_type &x)
		{
			ft::pair<iterator, iterator> range = equal_range(x);
			size_type n = 0;
			iterator first = range.first;
			iterator last = range.second;
			while (first != last)
			{
				iterator tmp = first++;
				erase(tmp);
				n++;
			}
			return n;
		}
		
		void erase(iterator first, iterator last)
		{
			while (first != last)
			{
				iterator tmp = first++;
				erase(tmp);
			}
		}
		
		void erase(const_iterator first, const_iterator last)
		{
			erase(first._const_cast(), last._const_cast());
		}
		
		void clear()
		{
			del(_begin());
			head->header.parent = &head->header;
			head->header.right = &head->header;
			head->header.left = &head->header;
			head->node_count = 0;
		}
		
		iterator find(const key_type& k)
		{
			iterator j = lower_bound(k);
			if (j == end() || key_compare(k, _s_key(j.node)))
				return (end());
			return (j);
		}
		
		const_iterator find(const key_type& k) const
		{
			const_iterator j = lower_bound(k);
			if (j == end() || key_compare(k, _s_key(j.node)))
				return (end());
			return (j);
		}
		
		size_type count(const key_type& k) const
		{
			ft::pair<const_iterator, const_iterator> p = equal_range(k);
			const_iterator first = p.first;
			const_iterator last = p.second;
			size_type n = 0;
			for (; first != last ; ++first)
				n++;
			return (n);
		}
		
		iterator lower_bound(const key_type& k) { return (_lower_bound(_begin(), _end(), k)); }

		const_iterator lower_bound(const key_type& k) const { return (_lower_bound(_begin(), _end(), k)); }

		iterator upper_bound(const key_type& k) { return (_upper_bound(_begin(), _end(), k)); }

		const_iterator upper_bound(const key_type& k) const { return (_upper_bound(_begin(), _end(), k)); }

		ft::pair<iterator, iterator> equal_range(const key_type& k)
		{
			link x = _begin();
			RB_ptr y = _end();
			while (x != _end())
			{
				if (key_compare(_s_key(x), k))
				{
					x = _s_right(x);
				}
				else if (key_compare(k, _s_key(x)))
				{
					y = x;
					x = _s_left(x);
				}
				else
				{
					link xu = x;
					RB_ptr yu = y;
					y = x;
					x = _s_left(x);
					xu = _s_right(xu);
					return (ft::pair<iterator, iterator>(_lower_bound(x, y, k), _upper_bound(xu, yu, k)));
				}
			}
			return (ft::pair<iterator, iterator>(iterator(y, _end()), iterator(y, _end())));
		}
		
		ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const
		{
			const_link x = _begin();
			RB_const_ptr y = _end();
			while (x != _end())
			{
				if (key_compare(_s_key(x), k))
				{
					x = _s_right(x);
				}
				else if (key_compare(k, _s_key(x)))
				{
					y = x;
					x = _s_left(x);
				}
				else
				{
					const_link xu = x;
					RB_const_ptr yu = y;
					y = x;
					x = _s_left(x);
					xu = _s_right(xu);
					return (ft::pair<const_iterator, const_iterator>(_lower_bound(x, y, k), _upper_bound(xu, yu, k)));
				}
			}
			return (ft::pair<const_iterator, const_iterator>(const_iterator(y, _end()), const_iterator(y, _end())));
		}
		
		friend bool operator==(const RB_tree& x, const RB_tree& y)
		{
			return (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()));
		}
		
		friend bool operator<(const RB_tree& x, const RB_tree& y)
		{
			return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
		}
		
		friend bool operator!=(const RB_tree& x, const RB_tree& y) { return !(x == y); }
		
		friend bool operator>(const RB_tree& x, const RB_tree& y) { return y < x; }
		
		friend bool operator<=(const RB_tree& x, const RB_tree& y) { return !(y < x); }
		
		friend bool operator>=(const RB_tree& x, const RB_tree& y) { return !(x < y); }
	
	};

}

#endif