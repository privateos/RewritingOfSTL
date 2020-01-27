
#ifndef beauty__container__queue__deque_detail___deque_iterator_hpp
#define beauty__container__queue__deque_detail___deque_iterator_hpp

#include<./beauty/types.hpp>
#include<./beauty/iterator/iterator_category/random_access_iterator_tag.hpp>


namespace beauty{namespace container{namespace queue{namespace deque_detail{

template<class T, class Ref, class Ptr, beauty::size_t BufSiz = 0>
class deque_iterator{
	public:
	typedef beauty::iterator::iterator_category::
		random_access_iterator_tag						iterator_category;
	typedef T                                                  value_type;
	typedef Ref                                                 reference;
	typedef Ptr                                                   pointer;
	typedef beauty::ptrdiff_t                             difference_type;
	
	typedef deque_iterator<T, Ref, Ptr, BufSiz>                      self;
	typedef beauty::size_t                                      size_type;
	typedef value_type**                                      map_pointer;
	
	value_type *cur;
	value_type *first;
	value_type *last;
	map_pointer node;
	
	deque_iterator(){}
	
	template<class T1, class Ref1, class Ptr1, beauty::size_t BuffSiz1>
	deque_iterator(const deque_iterator<T1, Ref1, Ptr1, BuffSiz1> &x):
		cur(x.cur), first(x.first), last(x.last), node(x.node){}
	
	static size_type buffer_size(){
		return BufSiz != 0 ? BufSiz :((sizeof(T) < 512) ? 512/sizeof(T) : 1);
	}
	
	void set_node(map_pointer new_node){
		node = new_node;
		first = *node;
		last = first + buffer_size();
	}
	
	self& operator = (const self &x){
		if(this != &x){
			cur = x.cur;
			first = x.first;
			last = x.last;
			node = x.node;
		}
		return *this;
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
#endif
