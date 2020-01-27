
#ifndef beauty__container__list__skiplist_detail___skiplist_iterator_hpp
#define beauty__container__list__skiplist_detail___skiplist_iterator_hpp

#include<./beauty/container/list/skiplist_detail/skiplist_node.hpp>
#include<./beauty/config.hpp>
#include<./beauty/iterator/iterator_category/bidirectional_iterator_tag.hpp> 
#include<./beauty/types.hpp>


namespace beauty{namespace container{namespace list{namespace skiplist_detail{

template<class Node, class Val, class Ref, class Ptr>
struct skiplist_iterator{
	typedef typename beauty::iterator::iterator_category
	::bidirectional_iterator_tag            iterator_category;
	typedef Val                                    value_type;
	typedef Ref                                     reference;
	typedef Ptr                                       pointer;
	typedef beauty::ptrdiff_t                 difference_type;
	
	typedef beauty::size_t                          size_type; 
	typedef Node*                                   link_type;
	typedef skiplist_iterator
		<Node, Val, Ref, Ptr>                            self;
	
	link_type cur;
	
	skiplist_iterator():cur(nullptr){}
	
	explicit skiplist_iterator(link_type c):cur(c){}
	
	skiplist_iterator(const self &s):cur(s.cur){}
	
	template<class Node0, class Val0, class Ref0, class Ptr0>
	skiplist_iterator(const skiplist_iterator<
	Node0, Val0, Ref0, Ptr0> &s):cur(s.cur){}
	
	self& operator = (const self &s){
		cur = s.cur;
		return *this;
	}
	
	template<class Node0, class Val0, class Ref0, class Ptr0>
	self& operator = (const skiplist_iterator
		<Node0, Val0, Ref0, Ptr0> &s){
		cur = s.cur;
		return *this;
	}
	
	reference operator * (){
		return cur->value;
	}
	
	pointer operator -> (){
		return &(cur->value);
	}
	
	self& operator ++ (){
		if(cur){
			cur = cur->array[0].forward;
		}
		return *this;
	}
	
	self operator ++ (int){
		self tmp(*this);
		++(*this);
		return tmp;
	}
	
	self& operator -- (){
		if(cur){
			cur = cur->prev;
		}
		return *this;
	}
	
	self operator -- (int){
		self tmp(*this);
		--(*this);
		return tmp;
	}
	
	bool operator == (const self &s)const{
		return cur == s.cur;
	}
	
	template<class Node0, class Val0, class Ref0, class Ptr0>
	bool operator == (const skiplist_iterator
		<Node0, Val0, Ref0, Ptr0> &s)const{
		return cur == s.cur;
	}
	
	bool operator != (const self &s)const{
		return cur != s.cur;
	}
	
	template<class Node0, class Val0, class Ref0, class Ptr0>
	bool operator != (const skiplist_iterator
		<Node0, Val0, Ref0, Ptr0> &s)const{
		return cur != s.cur;
	}
};


}
}
}
}





#endif

