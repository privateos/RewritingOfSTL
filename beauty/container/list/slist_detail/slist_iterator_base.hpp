
#ifndef beauty__container__list__slist_detail___slist_iterator_base_hpp
#define beauty__container__list__slist_detail___slist_iterator_base_hpp

#include<./beauty/iterator/iterator_category/forward_iterator_tag.hpp>
#include<./beauty/types.hpp>
#include<./beauty/container/list/slist_detail/slist_node_base.hpp>

	
namespace beauty{namespace container{namespace list{namespace slist_detail{

struct slist_iterator_base{
	typedef beauty::iterator::iterator_category::forward_iterator_tag
														iterator_category;
	typedef beauty::ptrdiff_t                             difference_type;
	typedef beauty::size_t                                      size_type;
	
	typedef beauty::container::list::slist_detail::slist_node_base
															    node_base;
 
	node_base *node;
	
	
	slist_iterator_base(node_base *x):
		node(x){}
	
	void incr(){
		node = node->next;
	}
	
	bool operator == (slist_iterator_base &x)const{
		return node == x.node;
	}
	
	bool operator != (slist_iterator_base &x)const{
		return node != x.node;
	}
	
};

}
}
}
}
#endif
