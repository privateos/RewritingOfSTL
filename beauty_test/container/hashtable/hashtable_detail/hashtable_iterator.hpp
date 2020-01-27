
#ifndef include___beauty__container__hashtable__hashtable_detail___hashtable_node_hpp
	#define include___beauty__container__hashtable__hashtable_detail___hashtable_node_hpp
	#include<./beauty/container/hashtable/hashtable_detail/hashtable_node.hpp>
#endif
#ifndef include___beauty__iterator__iterator_category___forward_iterator_tag_hpp
	#define include___beauty__iterator__iterator_category___forward_iterator_tag_hpp
	#include<./beauty/iterator/iterator_category/forward_iterator_tag.hpp>
#endif
#ifndef include___beauty___types_hpp
	#define include___beauty___types_hpp
	#include<./beauty/types.hpp>
#endif
#ifndef include___beauty___config_hpp
	#define include___beauty___config_hpp
	#include<./beauty/config.hpp>
#endif

namespace beauty{namespace container{namespace hashtable{namespace hashtable_detail{
template<class Value, class Ref, class Ptr, class HashTable>
struct hashtable_iterator{
	typedef beauty::iterator::iterator_category::
			forward_iterator_tag              iterator_category;
	typedef Value                                    value_type;
	typedef Ref                                  	  reference;
	typedef Ptr                                         pointer;
	typedef beauty::ptrdiff_t                   difference_type;
	
	friend class HashTable;
	
	typedef beauty::size_t                            size_type;
	typedef beauty::container::hashtable::hashtable_detail::
			hashtable_node<Value>                          node;
	typedef node*                                      node_ptr;
	typedef hashtable_iterator                             self;
	
	node_ptr nodecur;
	HashTable *ht;
	
	hashtable_iterator(node_ptr p, HashTable *h):
	nodecur(p), ht(h){}
  	
  	hashtable_iterator(const self &x):
  	nodecur(x.nodecur), ht(x.ht){}
  	
  	
  	
	reference operator * ()const{
		return nodecur->value;
	}
	
	pointer operator -> ()const{
		return &(nodecur->value);
	}
	
	self& operator ++ ()const{
		node_ptr p = nodecur;
		nodecur = nodecur->next;
		if(nodecur == nullptr){
			size_type n = ht->bkt_num(p->value);
			++n;
			while(nodecur == nullptr &&
		 		n < ht->num_elements){
		 		nodecur = (ht->array)[n];
				 ++n;	
 			} 			
		}
		return *this;
	}
	
	self operator ++ (int)const{
		self tmp = *this;
		++(*this)
		return tmp;
	}
	
	bool operator == (const self &x)const{
		return nodecur == x.nodecur;
	}
	
	bool operator != (const self &x)const{
		return nodecur != x.nodecur;
	}
	
	self& operator = (const self &x){
		nodecur = x.nodecur;
		ht = x.ht;		
	}
 	
 	
};


}
}
}
}