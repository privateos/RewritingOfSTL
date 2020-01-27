
#ifndef beauty__container__hashtable__hashtable_detail___hashtable_iterator_hpp
#define beauty__container__hashtable__hashtable_detail___hashtable_iterator_hpp

#include<./beauty/container/hashtable/hashtable_detail/hashtable_node.hpp>
#include<./beauty/iterator/iterator_category/forward_iterator_tag.hpp>
#include<./beauty/types.hpp>
#include<./beauty/config.hpp>


namespace beauty{namespace container{namespace hashtable{namespace hashtable_detail{
template<class Value, class Ref, class Ptr, class HashTable>
struct hashtable_iterator{
	typedef beauty::iterator::iterator_category::
			forward_iterator_tag              iterator_category;
	typedef Value                                    value_type;
	typedef Ref                                  	  reference;
	typedef Ptr                                         pointer;
	typedef beauty::ptrdiff_t                   difference_type;
	
	
	
	typedef beauty::size_t                            size_type;
	typedef beauty::container::hashtable::hashtable_detail::
			hashtable_node<Value>                          node;
	typedef node*                                      node_ptr;
	typedef hashtable_iterator<Value,Ref,Ptr,HashTable>    self;
	
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
		 		n < ht->array_size){
		 		nodecur = (ht->array)[n];
				++n;	
 			} 			
		}
		return *this;
	}
	
	self operator ++ (int)const{
		self tmp = *this;
		++(*this);
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
#endif
