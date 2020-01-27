
#ifndef beauty__container__tree__rb_tree_detail___rb_tree_iterator_hpp
#define beauty__container__tree__rb_tree_detail___rb_tree_iterator_hpp


#include<./beauty/container/tree/rb_tree_detail/rb_tree_node.hpp>
#include<./beauty/iterator/iterator_category/bidirectional_iterator_tag.hpp>
#include<./beauty/types.hpp>
#include<./beauty/config.hpp>


namespace beauty{namespace container{namespace tree{namespace rb_tree_detail{

template<class Value, class Ref, class Ptr>
struct rb_tree_iterator{
	typedef beauty::iterator::iterator_category::
		bidirectional_iterator_tag            iterator_category;
	typedef Value                                    value_type;
	typedef Ref                                       reference;
	typedef Ptr                                         pointer;
	typedef beauty::ptrdiff_t                   difference_type;
	
	
	typedef rb_tree_iterator<Value,Ref,Ptr>                self;
	typedef beauty::size_t                            size_type;
	typedef beauty::container::tree::rb_tree_detail::
		rb_tree_node<Value>                           tree_node;
	typedef tree_node                            *tree_node_ptr;
	
	tree_node_ptr node;
	
	
	rb_tree_iterator(tree_node_ptr x):node(x){}
	rb_tree_iterator(const self&x):node(x.node){}
	
	template<class V, class R, class P>
	rb_tree_iterator(const rb_tree_iterator<V, R, P> &x):node(x.node){}
	
	
	void increment(){
		if(node->right != nullptr){
			node = node->right;
			while(node->left != nullptr){
				node = node->left;
			}
		}else{
			tree_node_ptr p = node->parent;
			while(node == p->right){
				node = p;
				p = p->parent;
			}
			if(node->right != p){
				node = p;
			}
		}
	}
	
	void decrement(){
		if(node->left != nullptr){
			node = node->left;
			while(node->right != nullptr){
				node = node->right;
			}
		}else{
			tree_node_ptr p = node->parent;
			while(node = p->left){
				node = p;
				p = p->parent;
			}
			if(node->left != p){
				node = p;
			}
		}
	}
	
	self& operator = (const self &x){
		node = x.node;
		return *this;
	}
	
	reference operator * ()const{
		return node->value_filed;
	}
	
	pointer operator -> ()const{
		return &(node->value_filed);
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
	
	bool operator == (const self &x){
		return node == x.node;
	}
	
	bool operator != (const self &x){
		return node != x.node;
	}
	
	

};

	
}
}
}
}
#endif
