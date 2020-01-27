
#ifndef include___beauty__iterator__iterator_category___bidirectional_iterator_tag_hpp
	#define include___beauty__iterator__iterator_category___bidirectional_iterator_tag_hpp
	#include<./beauty/iterator/iterator_category/bidirectional_iterator_tag.hpp>
#endif
#ifndef include___beauty___types_hpp
	#define include___beauty___types_hpp
	#include<./beauty/types.hpp>
#endif
#ifndef include___beauty__container__list__list_detail___list_node_hpp
	#define include___beauty__container__list__list_detail___list_node_hpp
	#include<./beauty/container/list/list_detail/list_node.hpp>
#endif

namespace beauty{namespace container{namespace list{namespace list_detail{

template<class T>
class list_iterator{
	public:
	typedef beauty::iterator::iterator_category::
		bidirectional_iterator_tag				iterator_category;
	typedef T 										   value_type;
	typedef beauty::ptrdiff_t                     difference_type;
	typedef value_type*                              	  pointer;
	typedef value_type&                                	reference;
	
	typedef beauty::size_t                              size_type;
	typedef list_iterator<T>                                 self;
	typedef beauty::container::list::list_detail::
		list_node<T>*									link_type;
	
	
	
	link_type node;
	
	list_iterator(){
	}
	
	list_iterator(link_type x):node(x){
	}
	
	list_iterator(list_iterator &x):node(x.node){
	}
	
	bool operator == (const self &x)const{
		return node == x.node;
	}
	
	bool operator != (const self &x)const{
		return node != x.node;
	}
	
	reference operator *(){
		return node->data;
	}
	
	pointer operator -> (){
		return &(node->data);
	}
	
	self& operator ++ (){
		node = node->next;
		return *this;
	}
	
	self operator ++ (int){
		self temp = *this;
		node = node->next;
		return temp;
	}
	
	self& operator -- (){
		node = node->prev;
		return *this;
	}
	
	self operator -- (int){
		self temp = *this;
		node = node->prev;
		return temp;
	}	
};


}
}
}
}