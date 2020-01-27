
#ifndef beauty__container__list__slist_detail___slist_node_hpp
#define beauty__container__list__slist_detail___slist_node_hpp

#include<./beauty/container/list/slist_detail/slist_node_base.hpp>


namespace beauty{namespace container{namespace list{namespace slist_detail{

template<class T>
struct slist_node:
	public beauty::container::list::slist_detail::slist_node_base{
	
	T data;
};

}
}
}
}
#endif
