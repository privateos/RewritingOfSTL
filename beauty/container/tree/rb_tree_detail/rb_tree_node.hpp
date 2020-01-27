
#ifndef beauty__container__tree__rb_tree_detail___rb_tree_node_hpp
#define beauty__container__tree__rb_tree_detail___rb_tree_node_hpp

namespace beauty{namespace container{namespace tree{namespace rb_tree_detail{

typedef char rb_tree_node_color;//1 red 0 black


template<class Value>
struct rb_tree_node{
	typedef rb_tree_node<Value>      self;
	typedef rb_tree_node_color color_type;
	
	self *parent;
	self *left;
	self *right;
	color_type color;
	Value value_filed;
	
	
};


	
}
}
}
}
#endif
