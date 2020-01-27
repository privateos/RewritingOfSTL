
#ifndef beauty__container__tree__avl_tree_detail___avl_tree_iterator_hpp
#define beauty__container__tree__avl_tree_detail___avl_tree_iterator_hpp

#include<./beauty/container/tree/avl_tree_detail/avl_tree_node.hpp>
#include<./beauty/iterator/iterator_category/bidirectional_iterator_tag.hpp>
#include<./beauty/types.hpp>
#include<./beauty/config.hpp>


namespace beauty{namespace container{namespace tree{namespace avl_tree_detail{

template<class Value, class Ref, class Ptr>
struct avl_tree_iterator{
	typedef beauty::container::tree::avl_tree_detail::
		avl_tree_node<Value>                      node;
	typedef node*                             node_ptr;
	typedef avl_tree_iterator<Value, Ref, Ptr>
	                                              self;
	
	typedef beauty::iterator::iterator_category::
		bidirectional_iterator_tag   iterator_category;
	typedef Value                           value_type;
	typedef Ref                              reference;
	typedef Ptr                                pointer;
	typedef beauty::ptrdiff_t          difference_type;
	
	node_ptr cur;
	
	avl_tree_iterator(node_ptr p):cur(p){}
	
	avl_tree_iterator(const self &x):cur(x.cur){}
	
	template<class _value, class _ref, class _ptr>
	avl_tree_iterator(avl_tree_iterator<_value, _ref, _ptr> &x):cur(x.cur){}
	
	
	void increment(){
		
		if(cur->right != nullptr){
			cur = cur->right;
			while(cur->left != nullptr){
				cur = cur->left;
			}
		}else{
			node_ptr p = cur->parent;
			
			while(cur == p->right){
				cur = p;
				p = cur->parent;
			}
			if(cur->right != p){
				cur = p;
			}
		}
	}
	
	void decrement(){
	
		if(cur->left != nullptr){
			cur = cur->left;
			while(cur->right != nullptr){
				cur = cur->right;
			}
		}else{
			node_ptr p = cur->parent;
			while(cur == p->left){
				cur = p;
				p = cur->parent;
			}
			if(cur->left != p){
				cur = p;
			}
		}
	}
	
	self& operator ++ (){
		increment();
		return *this;
	}
	
	self operator ++ (int){
		self tmp = *this;
		increment();
		return tmp;
	}
	
	self& operator -- (){
		decrement();
		return *this;
	}
	
	self operator -- (int){
		self tmp = *this;
		decrement();
		return tmp;
	}
	
	reference operator * ()const{
		return cur->value;
	}
	
	pointer operator -> ()const{
		return &(cur->value);
	}
	
	bool operator == (const self &x)const{
		return cur == x.cur;
	}
	
	bool operator != (const self &x)const{
		return cur != x.cur;
	}
	
	self& operator = (const self &x)const{
		cur = x.cur;
		return *this;
	}
	
};



	
}
}
}
}
#endif
