
#ifndef beauty__container__list__slist_detail___slist_make_link_hpp
#define beauty__container__list__slist_detail___slist_make_link_hpp

#include<./beauty/container/list/slist_detail/slist_node_base.hpp>


	
namespace beauty{namespace container{namespace list{namespace slist_detail{

inline beauty::container::list::slist_detail::slist_node_base*
slist_make_link(beauty::container::list::slist_detail::slist_node_base
	*prev, beauty::container::list::slist_detail::slist_node_base *new_node){
	
	new_node->next = prev->next;
	prev->next = new_node;
	return new_node;		
}

}
}
}
}
#endif
