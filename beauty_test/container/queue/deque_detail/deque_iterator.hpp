

#ifndef include___beauty__types_hpp
	#define include___beauty__types_hpp
	#include<./beauty/types.hpp>
#endif
#ifndef include___beauty__iterator__iterator_category___random_access_iterator_tag_hpp
	#define include___beauty__iterator__iterator_category___random_access_iterator_tag_hpp
	#include<./beauty/iterator/iterator_category/random_access_iterator_tag.hpp>
#endif

namespace beauty{namespace container{namespace queue{namespace deque_detail{

template<class T, class beauty::size_t BufSiz = 0>
class deque_iterator{
	public:
	typedef beauty::iterator::iterator_category::
		random_access_iterator_tag						iterator_category;
	typedef T                                                  value_type;
	typedef value_type&                                         reference;
	typedef value_type*                                           pointer;
	typedef beauty::ptrdiff_t                             difference_type;
	
	typedef deque_iterator                                           self;
	typedef beauty::size_t                                      size_type;
	typedef value_type**                                      map_pointer;
	
	value_type *cur;
	value_type *first;
	value_type *last;
	map_pointer node;
	
	
	
	static size_type buffer_size(){
		return BufSiz != 0 ? BufSiz :((sizeof(T) < 512) ? 512/sizeof(T) : 1);
	}
	
	void set_node(map_pointer new_node){
		node = new_node;
		first = *node;
		last = first + buffer_size();
	}
	
	reference operator * ()const{
		return *cur;
	}
	
	pointer operator -> ()const{
		return cur;
	}
	
	difference_type operator - (const self &x){
		return static_cast<difference_type>(
			buffer_size() * (node - x.node - 1) +
			(cur - first) + (x.last - x.cur)
				);
	}
	
	self& operator ++ (){
		++cur;
		if(cur == last){
			set_node(node + 1);
			cur = first;
		}
		return *this;
	}
	
	self operator ++ (int){
		self tmp(*this);
		++(*this);
		return tmp;
	}
	
	self& operator -- (){
		if(cur == first){
			set_node(node - 1);
			cur = last;
		}
		--cur;
		return *this;
	}
	
	self operator -- (int){
		self tmp(*this);
		--(*this);
		return tmp;
	}
	
	self& operator += (difference_type n){
		difference_type offset = n + (cur - first);
		if(!(offset < 0) && n < buffer_size()){
			cur += n;
		}else{
			difference_type node_offset = 
				offset > 0 ? offset/buffer_size() :
					-((-offset - 1)/buffer_size()) - 1;
					
			set_node(node + node_offset);
			cur = first + (offset - node_offset*buffer_size());
		}
		return *this;
	}
	
	self operator + (difference_type n){
		self tmp = *this;
		tmp += n;
		return tmp;
	}
	
	self& operator -= (difference_type n){
		return (*this) += -n;
	}
	
	self operator - (difference_type n){
		self tmp = *this;
		tmp -= n;
		return tmp;
	}
	
	reference operator [] (difference_type n){
		return *((*this) + n);
	}
	
	bool operator == (const self &x)const{
		return node == x.node && cur == x.cur;
	}
	
	bool operator != (const self &x)const{
		return !(*this == x);
	}
	
	bool operator < (const self &x)const{
		return (node < x.node) ||
			(node == x.node && cur < x.cur);
	}
	
	bool operator > (const self &x)const{
		return x < *this;
	}
	
	bool operator <= (const self &x)const{
		return !(*this > x);
	}
	
	bool operator >= (const self &x)const{
		return !(*this < x);
	}
};






	
}
}
}
}