
#ifndef beauty__container__stack___stack_hpp
#define beauty__container__stack___stack_hpp

#include<./beauty/container/queue/deque.hpp>

namespace beauty{namespace container{namespace stack{

template<class T, class Sq = beauty::container::queue::deque<T> >
class stack{
	public:
	typedef typename Sq::value_type           value_type;
	typedef typename Sq::pointer                 pointer;
	typedef typename Sq::const_pointer     const_pointer;
	typedef typename Sq::reference             reference;
	typedef typename Sq::const_reference const_reference;
	typedef typename Sq::difference_type difference_type;
	
	typedef typename Sq::size_type             size_type;
	
	
	protected:
	Sq c;
	
	
	public:
	
	
	bool is_empty()const{
		return c.is_empty();
	}
	
	bool empty()const{
		return c.empty();
	}
	
	size_type size()const{
		return c.size();
	}
	
	reference top(){
		return c.back();
	}
	
	void push(const value_type &x){
		c.push_back(x);
	}
	
	void pop(){
		c.pop_back();
	}
	
	
};


}
}
}
#endif
