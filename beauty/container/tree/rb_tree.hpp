
#ifndef beauty__container__tree___rb_tree_hpp
#define beauty__container__tree___rb_tree_hpp

#include<./beauty/container/tree/rb_tree_detail/rb_tree_node.hpp>
#include<./beauty/container/tree/rb_tree_detail/rb_tree_iterator.hpp>
#include<./beauty/allocator/simple_allocator.hpp>
#include<./beauty/allocator/function/construct.hpp>
#include<./beauty/allocator/function/destroy.hpp>
#include<./beauty/container/pair/pair.hpp>
#include<./beauty/container/pair/make_pair.hpp>
#include<./beauty/container/pair/pair_operator_function.hpp>
#include<./beauty/config.hpp>
#include<./beauty/algorithm/algorithmbase/equal.hpp>
#include<./beauty/algorithm/algorithmbase/lexicographical_compare.hpp>
#include<./beauty/iterator/function/distance.hpp>


namespace beauty{namespace container{namespace tree{
//0 == black  1 == red

template<class Key, class Value, 
	class KeyOfValue, class KeyCompare,
	class alloc = beauty::allocator::allocator>
class rb_tree{
	
	public:
	typedef beauty::container::tree::rb_tree_detail::
	rb_tree_iterator<Value,Value&,Value*>             iterator;
	typedef beauty::container::tree::rb_tree_detail::
	rb_tree_iterator<Value,const Value&,const Value*> 
	                                            const_iterator;

	typedef Value                                   value_type;
	typedef Key                                       key_type;
	typedef value_type*                                pointer;
	typedef const value_type*                    const_pointer;
	typedef value_type&                              reference;
	typedef const value_type&                  const_reference;
	typedef beauty::ptrdiff_t                  difference_type;
	typedef beauty::size_t                           size_type;
 	
 	
 	
 	
 	protected:
	typedef beauty::container::tree::rb_tree_detail::
		rb_tree_node<Value>                     tree_node;
	typedef tree_node*                      tree_node_ptr;
	
 	typedef beauty::allocator::
	 	simple_allocator<tree_node,alloc>       allocator;
 	typedef beauty::container::pair::
	 	pair<iterator,bool>            pair_iterator_bool;
 	typedef beauty::container::pair::
	 pair<const_iterator,bool>   pair_const_iterator_bool;
 	typedef beauty::container::pair::
 		pair<iterator,iterator>    pair_iterator_iterator;
 	typedef beauty::container::pair::
 		pair<const_iterator,const_iterator>
		               pair_const_iterator_const_iterator;	
 	typedef rb_tree                                  self;
 	typedef char                               color_type;
 	size_type node_count;
 	tree_node_ptr header;
 	KeyOfValue get_key;
 	KeyCompare compare;
 	
 	tree_node_ptr create_node(const value_type &x){
	 	tree_node_ptr p = allocator::allocate();
	 	beauty::allocator::function::
		 	construct(&p->value_filed, x);
		 	
	 	return p;
	 	
	}
	
	void destroy_node(tree_node_ptr p){
		beauty::allocator::function::
			destroy(&p->value_filed);
		allocator::deallocate(p);
	}
	
	tree_node_ptr clone_node(tree_node_ptr p){
		tree_node_ptr p0 = create_node(p->value_filed);
		p0->color = p->color;
		//p0->left = nullptr;
		//p0->right = nullptr;
		return p0;
	}
	
	tree_node_ptr copy_tree(tree_node_ptr p){
		tree_node_ptr temp;
		
		temp = clone_node(p);
		if(p->left != nullptr){
			temp->left = copy_tree(p->left);
		}else{
			temp->left = nullptr;
		}
		
		if(p->right != nullptr){
			temp = copy_tree(p->right);			
		}else{
			temp->right = nullptr;
		}
		return temp;
	}
	
	tree_node_ptr leftmost(tree_node_ptr p){
		while(p->left != nullptr){
			p = p->left;
		}
		return p;
	}

	tree_node_ptr rightmost(tree_node_ptr p){
		while(p->right != nullptr){
			p = p->right;
		}
		return p;
	}
	
	void left_rotate(tree_node_ptr y){
		tree_node_ptr x = y->right;
		y->right = x->left;
		if(y->right != nullptr){
			y->right->parent = y;
		}
		
		
		x->parent = y->parent;
		x->left = y;		
		y->parent = x;
		
		if(x->parent != header){
			if(y == x->parent->left){
				x->parent->left = x;
			}else{
				x->parent->right = x;
			}
		}else{
			header->parent = x;
			x->parent = header;
		}
	}
	
	void right_rotate(tree_node_ptr y){
		tree_node_ptr x = y->left;
		y->left = x->right;
		if(y->left != nullptr){
			y->left->parent = y;
		}
		
		x->parent = y->parent;
		x->right = y;
		y->parent = x;
		
		if(x->parent != header){
			if(y == x->parent->left){
				x->parent->left = x;
			}else{
				x->parent->right = x;
			}
		}else{
			header->parent = x;
			x->parent = header;
		}
		
	}
	
	void insert_balance(tree_node_ptr x){
		x->color = 1;//red
		tree_node_ptr xp, xpp;
		
		while(x != header->parent 
			&& x->parent->color == 1){
			
			xp = x->parent;
			xpp = xp->parent;
			
			if(xp == xpp->left){
				if(xpp->right != nullptr){
					if(xpp->right->color == 1){
						xp->color = 0;
						xpp->right->color = 0;
						xpp->color = 1;
						x = xpp;
					}else{
						if(x == xp->left){
							xp->color = 0;
							xpp->color = 1;
							right_rotate(xpp);
							x = xp;
						}else{
							x->color = 0;
							xpp->color = 1;
							left_rotate(xp);
							right_rotate(xpp);
							x = xp;
						}					
					}
				}else{
					if(x == xp->left){
						xp->color = 0;
						xpp->color = 1;
						right_rotate(xpp);
					}else{
						x->color = 0;
						xpp->color = 1;
						left_rotate(xp);
						right_rotate(xpp);
						x = xp;
					}
				}
			}else{
				if(xpp->left != nullptr){
					if(xpp->left->color == 1){
						xpp->left->color = 0;
						xp->color = 0;
						xpp->color = 1;
						x = xpp;
					}else{
						if(x == xp->right){
							xpp->color = 1;
							xp->color = 0;
							left_rotate(xpp);
						}else{
							x->color = 1;
							xpp->color = 0;
							right_rotate(xp);
							left_rotate(xpp);
							x = xp;
						}
					}
				}else{
					if(x == xp->right){
						xp->color = 0;
						xpp->color = 1;
						left_rotate(xpp);
					}else{
						x->color = 0;
						xpp->color = 1;
						right_rotate(xp);
						left_rotate(xpp);
						x = xp;
					}
				}
			}
		}
		
		header->parent->color = 0;
	}
	
	tree_node_ptr insert(tree_node_ptr y, const value_type &v){
		
		tree_node_ptr x = create_node(v);
		x->left = nullptr;
		x->right = nullptr;
		++node_count;
		
		if(y == header){
			header->left = x;
			header->parent = x;
			header->right = x;
			
			x->parent = header;
			x->color = 0;//black
			
			return x;
		}
		
		x->parent = y;
		if(compare(get_key(v), get_key(y->value_filed))){
			y->left = x;
			if(y == header->left){
				header->left = x;
			}
		}else{
			y->right = x;
			if(y == header->right){
				header->right = x;
			}
		}
		insert_balance(x);
		return x;
	}

	void erase_balance(tree_node_ptr x){
		tree_node_ptr xp;
		color_type color;
		
		while(x != header->parent 
			&& x->color == 0){
			
			xp = x->parent;
			if(x == xp->left){
				if(xp->right != nullptr){
					if(xp->right->color == 1){
						xp->color = 1;
						xp->right->color = 0;
						left_rotate(xp);
					}else{
						if(xp->right->right != nullptr){
							if(xp->right->right->color == 1){
								xp->right->right->color = 0;
								color = xp->color;
								xp->color = xp->right->color;
								xp->right->color = color;
								left_rotate(xp);
								x = header->right;
								break;
							}else{
								if(xp->right->left != nullptr
								 && xp->right->left->color == 1){
									xp->right->left->color = 0;
									xp->right->color = 1;
									right_rotate(xp->right);
								}else{
									xp->right->color = 1;
								}
							}
						}else{
							xp->right->color = 1;
						}
					}
				}else{
					x = xp;
				}
			}else{
				if(xp->left != nullptr){
					if(xp->left->color == 1){
						xp->color = 1;
						xp->left->color = 0;
						right_rotate(xp);
					}else{
						if(xp->left->left != nullptr){
							if(xp->left->left->color == 1){
								xp->left->left->color = 0;
								color = xp->color;
								xp->color = xp->left->color;
								xp->left->color = color;
								right_rotate(xp);
								x = header->left;
								break;
							}else{
								if(xp->left->right != nullptr
								 && xp->left->right->color == 1){
									xp->left->right->color = 0;
									xp->left->color = 1;
									left_rotate(xp->left);
								}else{
									xp->left->color = 1;
								}
							}
						}else{
							xp->left->color = 1;
						}
					}
				}else{
					x = xp;
				}
					
			}
		}
		x->color = 0;
	}
	
	void erase_has_left_node(tree_node_ptr p){
		tree_node_ptr p0 = p->left;
		tree_node_ptr pt;
		color_type color;
		if(p0->right != nullptr){
			p0 = p0->right;
			while(p0->right != nullptr){
				p0 = p0->right;
			}
			color = p0->color;
			
			if(p0->left != nullptr){
				p0->left->parent = p0->parent;
				pt = p0->left;
			}else{
				if(p0->parent->left == nullptr){
					pt = p0->parent;
				}else{
					pt = nullptr;
				}
			}
			p0->parent->right = p0->left;
			
			p->left->parent = p0;
			p0->left = p->left;
			
			if(p->right != nullptr){
				p->right->parent = p0;
			}else{
				if(p == header->right){
					header->right = p0;
					
				}
			}
			p0->right = p->right;
			
			if(p->parent != header){
				if(p->parent->left == p){
					p->parent->left = p0;
				}else{
					p->parent->right = p0;
				}
			}else{
				header->parent = p0;
			}
			p0->parent = p->parent;
			p0->color = p->color;
			
		}else{			
			if(p0->left != nullptr){
				pt = p0->left;
			}else{
				pt = nullptr;
			}
			color = p0->color;
			
			if(p->right != nullptr){
				p->right->parent = p0;
			}else{
				if(p == header->right){
					header->right = p0;
				}
			}
			p0->right = p->right;
			
			if(p->parent != header){
				if(p->parent->left == p){
					p->parent->left = p0;
				}else{
					p->parent->right = p0;
				}
			}else{
				header->parent = p0;
			}
			p0->parent = p->parent;
			p0->color = p->color;
		}
		if(color == 0 && pt != nullptr){
			erase_balance(pt);
		}
	}	
	
	void erase_not_left_has_right(tree_node_ptr p){
		tree_node_ptr p0 = p->right;
		tree_node_ptr pt;
		color_type color;
		if(p0->left != nullptr){
			p0 = p0->left;
			while(p0->left != nullptr){
				p0 = p0->left;
			}
			color = p0->color;
			
			if(p0->right != nullptr){
				p0->right->parent = p0->parent;
				pt = p0->right;
			}else{
				if(p0->parent->right == nullptr){
					pt = p0->parent;
				}else{
					pt = nullptr;
				}
			}
			p0->parent->left = p0->right;
			
			p0->left = nullptr;
			p->right->parent = p0;
			p0->right = p->right;
			
			if(p->parent != header){
				if(p->parent->left == p){
					p->parent->left = p0;
				}else{
					p->parent->right = p0;
				}
			}else{
				header->parent = p0;
			}
			p0->parent = p->parent;
			p0->color = p->color;
			if(header->left == p){
				header->left = p0;
			}
						
		}else{
			color = p0->color;
			if(p0->right != nullptr){
				pt = p0->right;
			}else{
				pt = nullptr;
			}
			if(p->parent != header){
				if(p->parent->left == p){
					p->parent->left = p0;
				}else{
					p->parent->right = p0;
				}
			}else{
				header->parent = p0;
			}
			p0->parent = p->parent;
			p0->color = p->color;
			if(header->left == p){
				header->left = p0;
			}
		}
		if(color == 0 && pt != nullptr){
			erase_balance(pt);
		}
	}
	
	void erase_not_left_not_right(tree_node_ptr p){
		if(p->parent != header){
			if(p->parent->left == p){
				p->parent->left = nullptr;
				if(header->left == p){
					header->left = p->parent;
				}
				if(p->parent->right == nullptr
					&& p->color == 0){
					erase_balance(p->parent);
				}
			}else{
				p->parent->right = nullptr;
				if(header->right == p){
					header->right = p->parent;
				}
				if(p->parent->left == nullptr
					&& p->color == 0){
					erase_balance(p->parent);
				}
			}
		}else{
			header->parent = nullptr;
			header->left = nullptr;
			header->right = nullptr;
		}
	}
		
	
	tree_node_ptr lower_bound_help(const key_type &key)const{
		tree_node_ptr x = header->parent;
		tree_node_ptr y = nullptr;
		while(x != nullptr){
			if(!compare(get_key(x->value_filed),
			 	key)){
		 		y = x;
	 			x = x->left;	
			}else{
				x = x->right;
			}
		}
		return (y == nullptr ||
			compare(get_key(y->value_filed), key)) ?
			header : y;
	}

		
	tree_node_ptr upper_bound_help(const key_type &key)const{
		tree_node_ptr x = header->parent;
		tree_node_ptr y = nullptr;
		while(x != nullptr){
			if(compare(key,
				get_key(x->value_filed))){
				y = x;
				x = x->left;	
			}else{
				x = x->right;
			}
		}
		return (y == nullptr) ? header : y;
	}

	tree_node_ptr insert_equal_help(const value_type &v){
	
		tree_node_ptr y = header;
		tree_node_ptr x = header->parent;
		
		while(x != nullptr){
			y = x;
			x = compare(get_key(v), get_key(x->value_filed))
				? x->left : x->right;
		}
		return insert(y, v);
	}
			
	void erase_help(tree_node_ptr position){
		
		if(position->left != nullptr){
			erase_has_left_node(position);
		}else{
			if(position->right != nullptr){
				erase_not_left_has_right(position);
			}else{
				erase_not_left_not_right(position);
			}
		}
		
		destroy_node(position);
		--node_count;	
	}
	
	tree_node_ptr find_help(const Key &key)const{
		tree_node_ptr p = header->parent;
		tree_node_ptr ps = nullptr;
		
		while(p != nullptr){
			//ps = p;
			if(!compare(get_key(p->value_filed), key)){
				ps = p;
				p = p->left;
			}else{
				p = p->right;
			}
		}
		return (ps == nullptr || 
			compare(get_key(ps->value_filed), key))
			? header : ps;
	}
		
	public:	
	rb_tree():node_count(0){
		header = allocator::allocate();
		header->left = nullptr;
		header->right = nullptr;
		header->parent = nullptr;
	}
	
	rb_tree(const KeyOfValue &kov):get_key(kov){}
	
	rb_tree(const KeyCompare &kc):compare(kc){}
	
	rb_tree(const KeyOfValue &kov, const KeyCompare &kc):
		get_key(kov), compare(kc){}
	
	rb_tree(rb_tree &x):
		node_count(x.node_count){
			
		if(this != &x
			&& x.header->parent != nullptr){
				
			header->parent = 
			copy_tree(x.header->parent);
			header->left = 
			leftmost(header->parent);
			header->right = 
			rightmost(header->parent);
				
		}else{
			header->parent = nullptr;
			header->left = nullptr;
			header->right = nullptr;
		}
	}
	

	void clear(){
		if(node_count != 0){
			node_count = 0;
			
			tree_node_ptr p = header->left;
			header->parent->parent = nullptr;
			
			tree_node_ptr pp;
			bool is_left = true;
			
			header->parent = nullptr;
			header->left = nullptr;
			header->right = nullptr;
			
			while(true){
				while(p->left != nullptr){
					p = p->left;
					is_left = true;
				}
				if(p->right != nullptr){
					p = p->right;
					is_left = false;
				}else{
					pp = p->parent;
					if(pp != nullptr){
						if(is_left){
							pp->left = nullptr;
						}else{
							pp->right = nullptr;
						}
					}
					destroy_node(p);
					p = pp;
					if(p != nullptr){
						if(p->parent != nullptr){
							is_left = (p->parent->left == p);
						}
					}else{
						break;
					}
				}
			}
		}
	}
	
	~rb_tree(){
		clear();
		allocator::deallocate(header);
		header = nullptr;
	}
	
	
	KeyCompare key_compare()const{
		return compare;
	}
	
	KeyCompare key_comp()const{
		return compare;
	}
		
	KeyOfValue key_of_value()const{
		return get_key;
	}	

	iterator begin(){
		return (header->left == nullptr) ? header : header->left;
	}
	
	const_iterator begin()const{
		return (header->left == nullptr) ? header : header->left;		
	}
 	
	iterator end(){
		return header;
	}
	
	const_iterator end()const{
		return header;
	}
	
	bool is_empty()const{
		return node_count == 0;
	}
	
	bool empty()const{
		return node_count == 0;
	}
	
	size_type size()const{
		return node_count;
	}
	
	size_type max_size()const{
		return size_type(-1);
	}
	
	iterator leftmost(){
		return (header->left == nullptr) ? header : header->left;
	}
	
	const_iterator leftmost()const{
		return (header->left == nullptr) ? header : header->left;		
	}
	
	iterator leftmost(iterator p){
		if(p.node == nullptr){
			return p;
		}
		
		return leftmost(p.node);
	}
	
	const_iterator leftmost(const_iterator p)const{
		if(p.node == nullptr){
			return p;
		}
		
		return leftmost(p.node);		
	}

	iterator rightmost(){
		return (header->right == nullptr) ? header : header->left;
	}
	
	const_iterator rightmost()const{
		return (header->right == nullptr) ? header : header->left;		
	}
	

	iterator rightmost(iterator p){
		if(p.node == nullptr){
			return p;
		}
		
		return rightmost(p.node);
	}
	
	const_iterator rightmost(const_iterator p)const{
		if(p.node == nullptr){
			return p;
		}
		
		return rightmost(p.node);
	}
	
	iterator root(){
		return (header->parent == nullptr) ? header : header->parent;
	}
	
	const_iterator root()const{
		return (header->parent == nullptr) ? header : header->parent;		
	}
	
	pair_iterator_bool insert_unique(const value_type &v){
		
		tree_node_ptr y = header;
		tree_node_ptr x = header->parent;
		bool comp = true;
		
		while(x != nullptr){
			y = x;
			comp = compare(get_key(v), get_key(x->value_filed));
			x = comp ? x->left : x->right;
		}
		
		iterator j(y);
		if(comp){
			if(y == header->left || y == header){
				return pair_iterator_bool(insert(y, v), true);
			}else{
				--j;
			}
		}
		if(compare(get_key(j.node->value_filed), get_key(v))){
			return pair_iterator_bool(insert(y, v), true);
		}
		return pair_iterator_bool(j, false);
	}

	pair_const_iterator_bool const_insert_unique(const value_type &v){
		
		tree_node_ptr y = header;
		tree_node_ptr x = header->parent;
		bool comp = true;
		
		while(x != nullptr){
			y = x;
			comp = compare(get_key(v), get_key(x->value_filed));
			x = comp ? x->left : x->right;
		}
		
		const_iterator j(y);
		if(comp){
			if(y == header->left || y == header){
				return pair_const_iterator_bool(insert(y, v), true);
			}else{
				--j;
			}
		}
		if(compare(get_key(j.node->value_filed), get_key(v))){
			return pair_const_iterator_bool(insert(y, v), true);
		}
		return pair_const_iterator_bool(j, false);
	}

	template<class InputIter>
	void insert_unique(InputIter first, InputIter last){
		while(first != last){
			insert_unique(*first);
			++first;
		}
	}



	
	iterator insert_equal(const value_type &v){
		return insert_equal_help(v);
	}
	
	const_iterator const_insert_equal(const value_type &v){
		return insert_equal_help(v);
	}

	template<class InputIter>
	void insert_equal(InputIter first, InputIter last){
		while(first != last){
			insert_equal(*first);
			++first;
		}
	}



	
	void erase(iterator position){
		erase_help(position.node);
	}
	
	
	void erase(const_iterator position){
		erase_help(position.node);	
	}

	void erase(iterator first, iterator last){
		if(first.node == header->left
		&& last.node == nullptr){
			clear();
		}else{
			while(first != last){
				erase(first++);
			}
		}		
	}

	void erase(const_iterator first, const_iterator last){
		if(first.node == header->left
		&& last.node == nullptr){
			clear();
		}else{
			while(first != last){
				erase(first++);
			}
		}		
	}

	size_type erase(const key_type &x){
		beauty::container::pair::
		pair<iterator,iterator> p = equal_range(x);
		
		size_type n = 0;
		while(p.first != p.second){
			erase(p.first++);
			++n;
		}
		return n;
	}

	void erase(const key_type *first, const key_type *last){
		while(first != last){
			erase(*first);
			++first;
		}
	}

	size_type count(const key_type &x)const{
		pair_iterator_iterator p = equal_range(x);
		
		return beauty::iterator::function::
		distance(p.first, p.second);
	}


	iterator lower_bound(const key_type &key){
		return lower_bound_help(key);
	}
	
	const_iterator lower_bound(const key_type &key)const{
		return lower_bound_help(key);
	}

	iterator upper_bound(const key_type &key){
		return upper_bound_help(key);
	}
	
	const_iterator upper_bound(const key_type &key)const{
		return upper_bound_help(key);
	}

	pair_iterator_iterator equal_range(const key_type &x){
		return pair_iterator_iterator(
		lower_bound(x), upper_bound(x));
	}
	
	pair_const_iterator_const_iterator equal_range(const key_type &x)const{
		return pair_const_iterator_const_iterator(
		lower_bound(x), upper_bound(x));
	}
	


	iterator find(const Key &key){
		return find_help(key);
	}

	const_iterator find(const Key &key)const{
		return find_help(key);
	}
	
	void swap(rb_tree &x){
		//node_count, header;
		if(this == &x){
			return;
		}
		
		size_type tmp = node_count;
		node_count = x.node_count;
		x.node_count = tmp;
		
		tree_node_ptr p = header->parent;
		
		header->parent = x.header->parent;
		x.header->parent = p;
		
		p = header->left;
		header->left = x.header->left;
		x.header->left = p;
		
		p = header->right;
		header->right = x.header->right;
		x.header->right = p;
	}

	self& operator = (const self &x){
		if(this != &x){
			clear();
			if(x.header->parent != nullptr){
				
				x.header->parent = 
				copy_tree(x.header->parent);
				x.header->left = 
				leftmost(header->parent);
				x.header->right = 
				rightmost(header->parent);
				
				node_count = x.node_count;
			}
		}
		return *this;
	}
	
	bool operator == (const self &x)const{
		return node_count == x.node_count &&
		beauty::algorithm::algorithmbase::
			equal(begin(),end(), x.begin());
	}
	
	bool operator != (const self &x)const{
		return !((*this) == x);
	}
		
	bool operator < (const self &x)const{
		return beauty::algorithm::algorithmbase::
		lexicographical_compare(
		begin(), end(),
		x.begin(), x.end());
	}
	
	bool operator >= (const self &x)const{
		return !((*this) < x);
	}	

	
	bool operator > (const self &x)const{
		return (x < (*this));
	}
	
	bool operator <= (const self &x)const{
		return !(x < (*this)) ;
	}


	
	
	///////////////////////////////////////
	//test function
	tree_node_ptr get_root()const{
		return header->parent;
	}
	
	template<class Out>
	void LDR(tree_node_ptr root, Out &out){
		if(root->left != nullptr){
			LDR(root->left, out);
		}
		
		out<<root->value_filed.value;
		if(root->color == 1){
			out<<" r   ";
		}else{
			out<<" b   ";
		}
		
		if(root->right != nullptr){
			LDR(root->right, out);
		}
	}
	template<class Out>
	void DLR(tree_node_ptr root, Out &out){
		out<<root->value_filed.value;
		if(root->color == 1){
			out<<" r   ";
		}else{
			out<<" b   ";
		}
		if(root->left != nullptr){
			DLR(root->left, out);
		}
		if(root->right != nullptr){
			DLR(root->right, out);
		}
	}
	
};

template<class Key, class Value, class KeyOfValue, class KeyCompare, class alloc>
inline void swap(rb_tree<Key, Value, KeyOfValue, KeyCompare, alloc> &a,
 rb_tree<Key, Value, KeyOfValue, KeyCompare, alloc> &b){
 	a.swap(b);	
}



}
}
}
#endif
