
#ifndef beauty__container__tree__avl_tree_detail___avl_tree_node_hpp
#define beauty__container__tree__avl_tree_detail___avl_tree_node_hpp


namespace beauty{namespace container{namespace tree{namespace avl_tree_detail{

template<class Value>
struct avl_tree_node{
	typedef avl_tree_node<Value> self;
	self *parent;
	self *left;
	self *right;
	signed char balance;
	Value value;
};



	
}
}
}
}
#endif
