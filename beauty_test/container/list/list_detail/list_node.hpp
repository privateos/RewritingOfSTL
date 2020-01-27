

namespace beauty{namespace container{namespace list{namespace list_detail{

template<class T>
class list_node{
	public:
	typedef list_node<T>*  node_pointer;
	node_pointer prev;
	node_pointer next;
	T data;
};



}
}
}
}