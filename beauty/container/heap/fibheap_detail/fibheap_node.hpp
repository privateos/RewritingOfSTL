
#ifndef beauty__container__heap__fibheap_detail___fibheap_node_hpp
#define beauty__container__heap__fibheap_detail___fibheap_node_hpp

#include<./beauty/types.hpp>


namespace beauty{namespace container{namespace heap{namespace fibheap_detail{


template<class T>
struct fibheap_node{
	T value;
	beauty::size_t count;
	char mark;
	fibheap_node<T> *parent;
	fibheap_node<T> *child;
	fibheap_node<T> *left, *right;
};






}
}
}
}

#endif
