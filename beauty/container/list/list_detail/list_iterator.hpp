
#ifndef beauty__container__list__list_detail___list_iterator_hpp
#define beauty__container__list__list_detail___list_iterator_hpp

#include<./beauty/iterator/iterator_category/bidirectional_iterator_tag.hpp>
#include<./beauty/types.hpp>
#include<./beauty/container/list/list_detail/list_node.hpp>


namespace beauty{namespace container{namespace list{namespace list_detail{

template<class T, class Ref, class Ptr>
class list_iterator{
	public:
	typedef beauty::iterator::iterator_category::
		bidirectional_iterator_tag				iterator_category;
	typedef T 										   value_type;
	typedef beauty::ptrdiff_t                     difference_type;
	typedef Ptr                                     	  pointer;
	typedef Ref                                     	reference;
	
	typedef beauty::size_t                              size_type;
	typedef list_iterator<T, Ref, Ptr>                       self;
	typedef beauty::container::list::list_detail::
		list_node<T>*									link_type;
	
	
	
	link_type node;
	
	list_iterator(){}

	list_iterator(link_type x):node(x){}
	
	list_iterator(const self &x):node(x.node){}
	
	template<class T1, class Ref1, class Ptr1>
	list_iterator(const list_iterator<T1, Ref1, Ptr1> &x):node(x.node){}
	
	
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
#endif
