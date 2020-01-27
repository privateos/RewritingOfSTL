
#ifndef beauty__container__list__xorlist___xorlist_iterator_hpp
#define beauty__container__list__xorlist___xorlist_iterator_hpp

#include<./beauty/types.hpp>
#include<./beauty/iterator/iterator_category/bidirectional_iterator_tag.hpp>
#include<./beauty/container/list/xorlist_detail/xorlist_node.hpp>


namespace beauty{namespace container{namespace list{namespace xorlist_detail{


template<class T, class Ref, class Ptr>
struct xorlist_iterator{
	typedef beauty::iterator::iterator_category::
		bidirectional_iterator_tag           iterator_category;
	typedef T                                       value_type;
	typedef Ref                                      reference;
	typedef Ptr                                        pointer;
	typedef beauty::ptrdiff_t                  difference_type;
	
	typedef beauty::container::list::xorlist_detail::
		xorlist_node<T>                                   node;
	typedef node*                                    link_type;
	typedef xorlist_iterator<T, Ref, Ptr>                 self;
	
	
	typename node::pointer_integer prev;
	typename node::pointer_integer cur;
	typename node::pointer_integer next;
	
	
	xorlist_iterator(){}
	
	xorlist_iterator(link_type Cur){
		cur.pointer = Cur;
	}
	
	xorlist_iterator(link_type Prev, link_type Cur, link_type Next){
		prev.pointer = Prev;
		cur.pointer = Cur;
		next.pointer = Next;
	}
	
	xorlist_iterator(const self &Ite):
	prev(Ite.prev), cur(Ite.cur), next(Ite.next){}
	
	template<class T0, class Ref0, class Ptr0>
	xorlist_iterator(const xorlist_iterator<T0, Ref0, Ptr0> &Ite):
	prev(Ite.prev), cur(Ite.cur), next(Ite.next){}
	
	
	self& operator ++(){
		prev = cur;
		cur = next;
		if(cur.integer){
			next.integer = (prev.integer)^(cur.pointer->u.integer);
		}
		
		return *this;
	}
	
	self operator ++ (int){
		self tmp(*this);
		++tmp;
		return tmp;
	}
	
	self& operator -- (){
		next = cur;
		cur = prev;
		if(cur.integer){
			prev.integer = (next.integer)^(cur.pointer->u.integer);
		}
		
		return *this;
	}
		
	self operator -- (int){
		self tmp(*this);
		--tmp;
		return tmp;
	}
	
	self& operator += (difference_type n){
		if(n > 0){
			while(n){
				prev = cur;
				cur = next;
				if(cur.integer){
					next.integer = (prev.integer)^(cur.pointer->u.integer);
				}				
				--n;
			}
		}else{
			while(n){
				next = cur;
				cur = prev;
				if(cur.integer){
					prev.integer = (next.integer)^(cur.pointer->u.integer);
				}
				
				++n;
			}
		}
		return *this;
	}
	
	self operator + (difference_type n){
		self tmp(*this);
		tmp += n;
		return tmp;
	}
	
	self& operator -= (difference_type n){
		if(n > 0){
			while(n){
				next = cur;
				cur = prev;
				if(cur.integer){
					prev.integer = (next.integer)^(cur.pointer->u.integer);
				}
				
				--n;
			}
		}else{
			while(n){
				prev = cur;
				cur = next;
				if(cur.integer){
					next.integer = (prev.integer)^(cur.pointer->u.integer);
				}
				
				++n;
			}
		}
		return *this;
	}
	
	self operator - (difference_type n){
		self tmp(*this);
		tmp -= n;
		return tmp;
	}
	
	reference operator * (){
		return (cur.pointer)->value;
	}
	
	pointer operator -> (){
		return &(cur.pointer->value);
	}
	
	bool operator == (const self &ite)const{
		return cur.integer == ite.cur.integer;
	}
	
	bool operator != (const self &ite)const{
		return cur.integer != ite.cur.integer;
	}
	
	template<class T0, class Ref0, class Ptr0>
	bool operator == (const xorlist_iterator<T0, Ref0, Ptr0> &ite)const{
		return cur.integer == ite.cur.integer;
	}
	
	template<class T0, class Ref0, class Ptr0>
	bool operator != (const xorlist_iterator<T0, Ref0, Ptr0> &ite)const{
		return cur.integer != ite.cur.integer;
	}
};

}
}
}
}
#endif
