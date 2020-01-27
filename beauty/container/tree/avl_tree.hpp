
#ifndef beauty__container__tree___avl_tree_hpp
#define beauty__container__tree___avl_tree_hpp

#include<./beauty/allocator/simple_allocator.hpp>
#include<./beauty/allocator/function/construct.hpp>
#include<./beauty/allocator/function/destroy.hpp>
#include<./beauty/container/tree/avl_tree_detail/avl_tree_node.hpp>
#include<./beauty/container/tree/avl_tree_detail/avl_tree_iterator.hpp>
#include<./beauty/container/pair/pair.hpp>
#include<./beauty/container/pair/make_pair.hpp>
#include<./beauty/container/pair/pair_operator_function.hpp>
#include<./beauty/algorithm/algorithmbase/lexicographical_compare.hpp>
#include<./beauty/iterator/function/distance.hpp>
#include<./beauty/algorithm/algorithmbase/equal.hpp>

namespace beauty{namespace container{namespace tree{

template<class Key, class Value, class KeyOfValue,
class KeyCompare, class alloc = beauty::allocator::allocator>
class avl_tree{
	public:
	typedef beauty::container::tree::avl_tree_detail::
		avl_tree_iterator<Value, Value&, Value*>    iterator;
	typedef beauty::container::tree::avl_tree_detail::
		avl_tree_iterator<Value, const Value&, const Value*>    
					                          const_iterator;
	typedef Value                                 value_type;
	typedef Value&                                 reference;
	typedef const Value&                     const_reference;
	typedef Value*                                   pointer;
	typedef const Value*                       const_pointer;
	typedef beauty::ptrdiff_t                difference_type;
	typedef beauty::size_t                         size_type;
	
	protected:
	typedef beauty::container::tree::avl_tree_detail::
		avl_tree_node<Value>                           node;
	typedef node*                                  node_ptr;
	typedef Key                                    key_type;
	typedef signed char                        balance_type;
	typedef beauty::allocator::
		simple_allocator<node, alloc>             allocator;
	typedef beauty::container::pair::
		pair<iterator,bool>              pair_iterator_bool;
	typedef beauty::container::pair::
		pair<iterator,iterator>      pair_iterator_iterator;
	typedef beauty::container::pair::
		pair<iterator,bool>        pair_const_iterator_bool;
	typedef beauty::container::pair::
		pair<iterator,iterator>      
		                 pair_const_iterator_const_iterator;
	typedef avl_tree<Key, Value, KeyOfValue, KeyCompare,
	 alloc>                                            self;
	
	node_ptr header;
	KeyOfValue get_key;
	KeyCompare compare;
	size_type num_node;
	
	
	node_ptr create_node(const value_type &x){
		node_ptr p = allocator::allocate();
		p->balance = 0;
		p->left = nullptr;
		p->right = nullptr;
		beauty::allocator::function::
			construct(&(p->value), x);
		return p;
	}

	void destroy_node(node_ptr p){
		beauty::allocator::function::destroy(&(p->value));
		allocator::deallocate(p);
	}

	void left_rotate(node_ptr y){
		node_ptr x = y->right;
		y->right = x->left;
		if(x->left != nullptr){
			x->left->parent = y;
		}
		x->parent = y->parent;
		x->left = y;
		y->parent= x;
		
		if(x->parent != header){
			if(x->parent->left == y){
				x->parent->left = x;
			}else{
				x->parent->right = x;
			}
		}else{
			header->parent = x;
		}
	}
	
	void right_rotate(node_ptr y){
		node_ptr x = y->left;
		y->left = x->right;
		if(x->right != nullptr){
			x->right->parent = y;
		}
		x->parent = y->parent;
		x->right = y;
		y->parent = x;
		if(x->parent != header){
			if(x->parent->left == y){
				x->parent->left = x;
			}else{
				x->parent->right = x;
			}
		}else{
			header->parent = x;
		}
	}
	
	void insert_balance(node_ptr x){
		node_ptr xp;
		node_ptr y;
		while(x != header->parent){
			xp = x->parent;
			if(x == xp->left){
				if(xp->balance == 1){
					if(x->balance == 1){
						right_rotate(xp);
						x->balance = 0;
						xp->balance = 0;
					}else{
						y = x->right;
						left_rotate(x);
						right_rotate(xp);
						if(y->balance == 1){
							x->balance = 0;
							xp->balance = -1;
							y->balance = 0;
						}else{
							if(y->balance == 0){
								x->balance = 0;
								xp->balance = 0;
							}else{
								x->balance = 1;
								xp->balance = 0;
								y->balance = 0;
							}
						}
					}
					break;
				}else{
					++xp->balance;
					if(xp->balance == 0){
						break;
					}
					x = xp;
				}
			}else{
				if(xp->balance == -1){
					if(x->balance == -1){
						left_rotate(xp);
						x->balance = 0;
						xp->balance = 0;
					}else{
						y = x->left;
						right_rotate(x);
						left_rotate(xp);
						if(y->balance == -1){
							x->balance = 0;
							xp->balance = 1;
							y->balance = 0;
						}else{
							if(y->balance == 0){
								x->balance = 0;
								xp->balance = 0;
							}else{
								x->balance = -1;
								xp->balance = 0;
								y->balance = 0;
							}
						}
					}
					break;
				}else{
					--xp->balance;
					if(xp->balance == 0){
						break;
					}
					x = xp;
				}
			}
		}
	}

	
	node_ptr insert(node_ptr y, const value_type &v){
		node_ptr x = create_node(v);
		if(y == header){
			y->parent = x;
			y->left = x;
			y->right = x;
			x->parent = header;
		}else{
			if(compare(get_key(v), get_key(y->value))){
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
			x->parent = y;
			insert_balance(x);
		}
		return x;
	}	

	
	void erase_balance(node_ptr x, bool is_left){
		node_ptr xp;
		node_ptr xr;
		while(x != header){
			
			xp = x->parent;
			
			if(is_left){
				if(x->balance == -1){
					xr = x->right;
					if(xr->balance == 1){
						right_rotate(xr);
						left_rotate(x);
						if(x->parent->balance == 1){
							x->balance = 0;
							xr->balance = -1;
							x->parent->balance = 0;
						}else{
							if(x->parent->balance == 0){
								x->balance = 0;
								xr->balance = 0;
							}else{
								x->balance = 1;
								xr->balance = 0;
								x->parent->balance = 0;
							}
						}
						x = x->parent;
						if(x == x->parent->right){
							is_left = false;
						}
						x = x->parent;
					}else{
						left_rotate(x);
						if(xr->balance == 0){
							x->balance = -1;
							xr->balance = 1;
							break;
						}else{
							x->balance = 0;
							xr->balance = 0;
							x = xr->parent;
							if(xr == xr->parent->right){
								is_left = false;
							}
						}
					}
				}else{
					--x->balance;
					if(x->balance == -1){
						break;
					}
					if(x == xp->right){
						is_left = false;
					}
					x = xp;
				}
			}else{
				if(x->balance == 1){
					xr = x->left;
					if(xr->balance == -1){
						left_rotate(xr);
						right_rotate(x);
						if(x->parent->balance == -1){
							x->balance = 0;
							xr->balance = 1;
							x->parent->balance = 0;
						}else{
							if(x->parent->balance == 0){
								x->balance = 0;
								xr->balance = 0;
							}else{
								x->balance = -1;
								xr->balance = 0;
								x->parent->balance = 0;
							}
						}
						x = x->parent;
						if(x == x->parent->left){
							is_left = true;
						}
						x = x->parent;
					}else{
						right_rotate(x);
						if(xr->balance == 0){
							x->balance = 1;
							xr->balance = -1;
							break;
						}else{
							x->balance = 0;
							xr->balance = 0;
							x = xr->parent;
							if(xr == xr->parent->left){
								is_left = true;
							}
						}
					}
				}else{
					++x->balance;
					if(x->balance == 1){
						break;
					}
					if(x == xp->left){
						is_left = true;
					}
					x = xp;
				}
			}
		}
	}
	
	void erase_has_left(node_ptr p){
		node_ptr pl = p->left;
		node_ptr pt;
		bool is_left;
		
		if(pl->right != nullptr){
			pl = pl->right;
			while(pl->right != nullptr){
				pl = pl->right;
			}
			
			if(pl->left != nullptr){
				pl->left->parent = pl->parent;
			}
			pl->parent->right = pl->left;
			
			is_left = false;
			pt = pl->parent;
			
			
			
			pl->left = p->left;
			p->left->parent = pl;
			
			p->right->parent = pl;
			pl->right = p->right;
			
			pl->parent = p->parent;
			if(p->parent != header){
				if(p->parent->left == p){
					p->parent->left = pl;
				}else{
					p->parent->right = pl;
				}
			}else{
				header->parent = pl;
			}
			pl->balance = p->balance;
			
		}else{
			pl->right = p->right;
			if(p->right != nullptr){
				p->right->parent = pl;
			}else{
				if(p == header->right){
					header->right = pl;
				}
			}

			pl->parent = p->parent;
			if(p->parent != header){
				if(p->parent->left == p){
					p->parent->left = pl;
				}else{
					p->parent->right = pl;
				}
			}else{
				header->parent = pl;
			}
			pl->balance = p->balance;
			
			is_left = true;
			pt = pl;
		}
		erase_balance(pt, is_left);
		destroy_node(p);
	}
	
	void erase_no_left_has_right(node_ptr p){
		node_ptr pl = p->right;
		node_ptr pt;
		bool is_left;
		
		if(pl->left != nullptr){
			pl = pl->left;
			while(pl->left != nullptr){
				pl = pl->left;
			}
			
			
			pl->parent->left = pl->right;
			if(pl->right != nullptr){
				pl->right->parent = pl->parent;
			}
			pt = pl->parent;
			is_left = true;
			
			pl->left = nullptr;
			pl->right = p->right;
			p->right->parent = pl;
			
			pl->parent = p->parent;
			if(p->parent != header){
				if(p->parent->left == p){
					p->parent->left = pl;
				}else{
					p->parent->right = pl;
				}
			}else{
				header->parent = pl;
			}
			pl->balance = p->balance;
			
		}else{
			pl->parent = p->parent;
			
			if(p == header->left){
				header->left = pl;
			}

			
			if(p->parent != header){
				if(p->parent->left == p){
					p->parent->left = pl;
				}else{
					p->parent->right = pl;
				}
			}else{
				header->parent = pl;
			}
			pl->balance = p->balance;
			
			is_left = false;
			pt = pl;
		}
		destroy_node(p);
		erase_balance(pt, is_left);
	}
	
	void erase_no_left_no_right(node_ptr p){
		node_ptr pt = p->parent;
		bool is_left;
		if(pt != header){
			if(pt->left == p){
				pt->left = nullptr;
				is_left = true;
				if(p == header->left){
					header->left = pt;
				}
			}else{
				pt->right = nullptr;
				is_left = false;
				if(p == header->right){
					header->right = pt;
				}
			}
			erase_balance(pt, is_left);
		}else{
			header->parent = nullptr;
			header->left = nullptr;
			header->right = nullptr;
		}
		destroy_node(p);
	}

	node_ptr lower_bound_help(const key_type &key)const{
		node_ptr p = header->parent;
		node_ptr ps = nullptr;
		
		while(p != nullptr){
			if(!compare(get_key(p->value), key)){
				ps = p;
				p = p->left;
			}else{
				p = p->right;
			}
		}
		
		return (ps == nullptr ||
			compare(get_key(ps->value), key)) ?
			header : ps;
	}
	
	node_ptr insert_equal_help(const value_type &v){
		node_ptr y = header;
		node_ptr p = y->parent;
		
		while(p != nullptr){
			y = p;
			p = compare(get_key(v), get_key(p->value)) ?
			p->left : p->right;
		}
		++num_node;
		return insert(y, v);
	}

	void erase_help(node_ptr pos){
		if(pos->left != nullptr){
			erase_has_left(pos);
		}else{
			if(pos->right != nullptr){
				erase_no_left_has_right(pos);
			}else{
				erase_no_left_no_right(pos);
			}
		}
		--num_node;		
	}
	
	node_ptr find_help(const key_type &key)const{
		node_ptr p = header->parent;
		node_ptr ps = nullptr;
		
		while(p != nullptr){
			if(!compare(get_key(p->value), key)){
				ps = p;
				p = p->left;
			}else{
				p = p->right;
			}
		}
		
		return (ps == nullptr ||
			compare(get_key(ps->value), key)) ?
			header : ps;
	}
			
	void initialize(){
		header = allocator::allocate();
		header->parent = nullptr;
		header->left = nullptr;
		header->right = nullptr;
	}	
	

	
	
	public:	
	avl_tree():num_node(0){
		initialize();
	}
	
	
	void clear(){
		if(num_node != 0){
			node_ptr p = header->left, y;						
			bool is_left = true;
			header->parent->parent = nullptr;
			
			while(true){
				while(p->left != nullptr){
					p = p->left;
					is_left = true;
				}
				if(p->right != nullptr){
					p = p->right;
					is_left = false;
				}else{
					y = p->parent;
					destroy_node(p);
					if(y != nullptr){
						if(is_left){
							y->left = nullptr;
						}else{
							y->right = nullptr;
						}
						if(y->parent != nullptr){
							is_left = (y->parent->left == y);
						}
					}else{
						break;
					}
					p = y;
				}
			}
			header->parent = nullptr;
			header->left = nullptr;
			header->right = nullptr;
			num_node = 0;
		}
	}

	~avl_tree(){
		clear();
		allocator::deallocate(header);
	}
	
	
	iterator begin(){
		return num_node == 0 ? header : header->left;
	}
	
	const_iterator const_begin()const{
		return num_node == 0 ? header : header->right;
	}
	
	iterator end(){
		return header;
	}
	
	const_iterator const_end()const{
		return header;
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
	
	bool empty()const{
		return num_node == 0;
	}
	
	bool is_empty()const{
		return num_node == 0;
	}
	
	size_type size()const{
		return num_node;
	}
	
	size_type max_size()const{
		return size_type(-1);
	}
	
	iterator leftmost()const{
		return num_node == 0 ? header : header->left;
	}
	
	iterator leftmost(iterator p){
		while(p.cur->next != nullptr){
			p.cur = p.cur->next;
		}
		return p;
	}
	
	const_iterator const_leftmost()const{
		return num_node == 0 ? header : header->left;
	}
	
	const_iterator const_leftmost(const_iterator p)const{
		while(p.cur->next != nullptr){
			p.cur = p.cur->next;
		}
		return p;
	}
	
	iterator rightmost()const{
		return num_node == 0 ? header : header->right;
	}
	
	iterator rightmost(iterator p){
		while(p.cur->right != nullptr){
			p.cur = p.cur->right;
		}
		return p;
	}
	
	const_iterator const_rightmost()const{
		return num_node == 0 ? header : header->right;
	}
	
	const_iterator const_rightmost(const_iterator p)const{
		while(p.cur->right != nullptr){
			p.cur = p.cur->right;
		}
		return p;
	}
	
	iterator root(){
		return num_node == 0 ? header : header->parent;
	}
	
	const_iterator const_root()const{
		return num_node == 0 ? header : header->parent;
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
	
	pair_iterator_bool insert_unique(const value_type &v){
		node_ptr y = header;
		node_ptr p = header->parent;
		bool is_left = true;
		
		while(p != nullptr){
			y = p;
			is_left = compare(get_key(v), get_key(p->value));
			p = is_left ? p->left : p->right;
		}
		iterator i(y);
		if(is_left){
			if(y == header || y == header->left){
				++num_node;
				return pair_iterator_bool(insert(y, v), true);
			}else{
				--i;
			}
		}
		if(compare(get_key(i.cur->value), get_key(v))){
			++num_node;
			return pair_iterator_bool(insert(y, v), true);
		}else{
			return pair_iterator_bool(i.cur, false);
		}
	}

	pair_const_iterator_bool const_insert_unique(const value_type &v){
		node_ptr y = header;
		node_ptr p = header->parent;
		bool is_left = true;
		
		while(p != nullptr){
			y = p;
			is_left = compare(get_key(v), get_key(p->value));
			p = is_left ? p->left : p->right;
		}
		const_iterator i(y);
		if(is_left){
			if(y == header || y == header->left){
				++num_node;
				return pair_const_iterator_bool(insert(y, v), true);
			}else{
				--i;
			}
		}
		if(compare(get_key(i.cur->value), get_key(v))){
			++num_node;
			return pair_const_iterator_bool(insert(y, v), true);
		}else{
			return pair_const_iterator_bool(i.cur, false);
		}
	}

	template<class InputIter>
	void insert_unique(InputIter first, InputIter last){
		while(first != last){
			insert_unique(*first);
			++first;
		}
	}
	
	

	void erase(iterator pos){
		erase_help(pos.cur);	
	}
	
	
	void erase(const_iterator pos){
		erase_help(pos.cur);
	}
	
	void erase(iterator first, iterator last){
		while(first != last){
			erase(*first++);
		}
	}
	
	void erase(const_iterator first, const_iterator last){
		while(first != last){
			const_erase(*first++);
		}
	}
	
	size_type erase(const key_type &key){
		pair_iterator_iterator p = equal_range(key);
		size_type n = 0;
		
		while(p.first != p.second){
			erase(p.first++);
			++n;
		}
		return n;
	}
	
	void erase(const key_type *first, const key_type *last){
		while(first != last){
			erase_help(*first);
			++first;
		}
	}
	

	
	iterator find(const key_type &key){
		return find_help(key);
	}
	
	const_iterator find(const key_type &key)const{
		return find_help(key);
	}
	

	
	iterator lower_bound(const key_type &key){
		return lower_bound_help(key);
	}
	
	const_iterator const_lower_bound(const key_type &key)const{
		return lower_bound_help(key);
	}

	node_ptr upper_bound_help(const key_type &key)const{
		node_ptr p = header->parent;
		node_ptr ps = nullptr;
		
		while(p != nullptr){
			if(compare(key, get_key(p->value))){
				ps = p;
				p = p->left;
			}else{
				p = p->right;
			}
		}
		
		return ((ps == nullptr) ? header : ps);
	}

	iterator upper_bound(const key_type &key){
		return upper_bound_help(key);
	}

	const_iterator const_upper_bound(const key_type &key)const{
		return upper_bound_help(key);
	}
	
	pair_iterator_iterator equal_range(const key_type &key){
		return pair_iterator_iterator(
			lower_bound(key), upper_bound(key));
	}
	
	pair_const_iterator_const_iterator const_equal_range(const key_type &key)const{
		return pair_const_iterator_const_iterator(
			const_lower_bound(key), const_upper_bound(key));
	}
	
	size_type count(const key_type &key)const{
		pair_iterator_iterator p = equal_range(key);
		return beauty::iterator::function::
		distance(p.first, p.second);
	}

	void swap(self &x){
		if(this == &x){
			return ;
		}
		node_ptr tp = header;
		header = x.header;
		x.header = tp;
		
		size_type ts = num_node;
		num_node = x.num_node;
		x.num_node = ts;
		
		KeyOfValue tk = get_key;
		get_key = x.get_key;
		x.get_key = tk;
		
		KeyCompare tkc = compare;
		compare = x.compare;
		x.compare = tkc;
	}
	
	self& operator = (self &x){
		if(this != &x){
			size_type ts = num_node;
			num_node = x.num_node;
			x.num_node = ts;
			
			KeyOfValue tk = get_key;
			get_key = x.get_key;
			x.get_key = tk;
			
			KeyCompare tc = compare;
			compare = x.compare;
			x.compare = tc;
			
			node_ptr tn = header;
			header = x.header;
			x.header = tn;
		}
		return *this;
	}
	
	bool operator == (const self &x)const{
		return num_node == x.num_node && 
		beauty::algorithm::algorithmbase::
		equal(
		begin(), end(), x.begin());
	}
	
	bool operator != (const self &x)const{
		return !((*this) == x);
	}
	
	bool operator < (const self &x)const{
		return beauty::algorithm::algorithmbase::
		lexicographical_compare(
		begin(), end(), x.begin(), x.end());
	}
	
	bool operator >= (const self &x)const{
		return !((*this) < x);
	}
	
	bool operator > (const self &x)const{
		return x < (*this);
	}
	
	bool operator <= (const self &x)const{
		return !(x < (*this));
	}
	



//////////////////////////////	
//	void LDR(node_ptr p){
//		if(p->left != nullptr){
//			LDR(p->left);
//		}
//		p->value.print();
//		cout<<"  balance = "<<(int)p->balance<<endl;
//		
//		if(p->right != nullptr){
//			LDR(p->right);
//		}
//	}
//	
//	void DLR(node_ptr p){
//		p->value.print();
//		cout<<"  balance = "<<(int)p->balance<<endl;
//		
//		if(p->left != nullptr){
//			DLR(p->left);
//		}
//		if(p->right != nullptr){
//			DLR(p->right);
//		}
//	}
	
};





}
}
}
#endif
