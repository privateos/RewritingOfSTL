
#ifndef beauty__container__hashtable__hashtable_detail___hashtable_node_hpp
#define beauty__container__hashtable__hashtable_detail___hashtable_node_hpp

namespace beauty{namespace container{namespace hashtable{namespace hashtable_detail{

template<class Value>
struct hashtable_node{
	hashtable_node<Value> *next;
	Value value;
};



}
}
}
}
#endif
