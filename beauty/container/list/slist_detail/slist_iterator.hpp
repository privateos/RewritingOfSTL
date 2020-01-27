
#ifndef beauty__container__list__slist_detail___slist_iterator_hpp
#define beauty__container__list__slist_detail___slist_iterator_hpp

#include<./beauty/container/list/slist_detail/slist_iterator_base.hpp>
#include<./beauty/container/list/slist_detail/slist_node.hpp>


namespace beauty{namespace container{namespace list{namespace slist_detail{

template<class T, class Ref, class Ptr>
struct slist_iterator:
	public beauty::container::list::slist_detail::slist_iterator_base{
	typedef slist_iterator<T,T&,T*>                      iterator;
	typedef T                                          value_type;
	typedef Ref                                         reference;
	typedef Ptr                                           pointer;
	typedef slist_iterator<T,Ref,Ptr>                        self;
	
	typedef beauty::container::list::slist_detail::slist_node<T>
												        list_node;
	typedef beauty::container::list::slist_detail::slist_node_base
												   list_node_base;
	slist_iterator():
		beauty::container::list::slist_detail::
			slist_iterator_base(0){}
		
	slist_iterator(list_node *x):
		beauty::container::list::slist_detail::
			slist_iterator_base(x){}
	
	slist_iterator(const iterator &x):
		beauty::container::list::slist_detail::
			slist_iterator_base(x.node){}
	
	reference operator * (){
		return (static_cast<list_node*>(node))->data;
	}
	
	pointer operator -> (){
		return &((static_cast<list_node*>(node))->data);
	}
	
	self& operator ++ (){
		incr();
		return *this;
	}
	
	self operator ++ (int){
		self tmp = *this;
		//++(*this);
		incr();
		return tmp;
	}
	
};

}
}
}
}
#endif
