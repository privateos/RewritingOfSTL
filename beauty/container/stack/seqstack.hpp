
#ifndef beauty__container__stack___seqstack_hpp
#define beauty__container__stack___seqstack_hpp

#include<./beauty/types.hpp>
#include<./beauty/container/list/seqlist.hpp>


namespace beauty{namespace container{namespace stack{


static const beauty::size_t seqstack_default_size = 16;


template<class T, class alloc = beauty::allocator::allocator>
class seqstack{
	protected:
	typedef beauty::container::list::seqlist<T, alloc>   List;
	typedef seqstack<T, alloc>                           self;
	List L;
	
	public:
	//typedef typename List::iterator                 iterator;
	//typedef typename List::const_iterator     const_iterator;
	typedef typename List::value_type             value_type;
	typedef typename List::reference               reference;
	typedef typename List::const_reference   const_reference;
	//typedef typename List::pointer                   pointer;
	//typedef typename List::const_pointer       const_pointer;
	typedef typename List::difference_type   difference_type;
	typedef typename List::size_type               size_type;
	
	
	
	public:
	seqstack():L(seqstack_default_size){}
	
	seqstack(size_type n):L(n){}
	
	seqstack(const self &s):L(s.L){}
	
	~seqstack(){}
	
	void clear(){
		L.clear();
	}
	
	size_type size()const{
		return L.size();
	}
	
	size_type max_size()const{
		return L.max_size();
	}
	
	bool is_emtpy()const{
		return is_emtpy();
	}
	
	bool empty()const{
		return L.empty();
	}
	
	bool is_full()const{
		return L.is_full();
	}
	
	bool full()const{
		return L.full();
	}
	
	reference top(){
		return L.back();
	}
	
	const_reference top()const{
		return L.back();
	}
		
	void push(const value_type &v){
		L.push_back(v);
	}	
	
	void pop(){
		L.pop_back();
	}
	
	void swap(self &s){
		L.swap(s.L);
	}								
};

template<class T, class alloc>
inline void swap(seqstack<T, alloc> &a, seqstack<T, alloc> &b){
	a.swap(b);
}


}
}
}
#endif
