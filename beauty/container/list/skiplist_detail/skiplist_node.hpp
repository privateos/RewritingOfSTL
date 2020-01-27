
#ifndef beauty__container__list__skiplist_detail___skiplist_node_hpp
#define beauty__container__list__skiplist_detail___skiplist_node_hpp

#include<./beauty/container/array/vector.hpp>
#include<./beauty/types.hpp>

namespace beauty{namespace container{namespace list{namespace skiplist_detail{



template<class Val, class alloc>
struct skiplist_node{
	Val value;
	
	skiplist_node<Val, alloc> *prev;
	struct inner_pair{
		skiplist_node<Val, alloc>* forward;
		beauty::size_t span;
		
		inner_pair():forward(nullptr){}		
	};
	beauty::container::array::vector<
	inner_pair>               		array;
	
};




}
}
}
}



#endif
