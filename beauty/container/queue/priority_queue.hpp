
#ifndef beauty__container__queue___priority_queue_hpp
#define beauty__container__queue___priority_queue_hpp

#include<./beauty/container/queue/deque.hpp>
#include<./beauty/functor/less.hpp>
#include<./beauty/algorithm/heap/make_heap.hpp>
#include<./beauty/algorithm/heap/push_heap.hpp>
#include<./beauty/algorithm/heap/pop_heap.hpp>

namespace beauty{namespace container{namespace queue{


template<class T, class Sq = beauty::container::queue::deque<T>, 
		class Compare = beauty::functor::less<typename Sq::value_type> >
class priority_queue{
	public:
	typedef typename Sq::value_type              value_type;
	typedef typename Sq::pointer                    pointer;
	typedef typename Sq::const_pointer        const_pointer;
	typedef typename Sq::reference                reference;
	typedef typename Sq::const_reference    const_reference;
	typedef typename Sq::difference_type    difference_type;
	
	typedef typename Sq::size_type                size_type;
	
	protected:
	Sq c;
	Compare comp;
	
	
	public:
	priority_queue():c(){}
	
	template<class InputIterator>
	priority_queue(InputIterator first, InputIterator last):
		c(first, last){
		beauty::algorithm::heap::
			make_heap(c.begin(), c.end(), comp);
	}
	
	bool empty()const{
		return c.empty();
	}
	
	bool is_empty()const{
		return c.is_empty();
	}
	
	size_type size()const{
		return c.size();
	}
	
	reference top(){
		return c.front();
	}
	
	void push(const value_type &x){
		c.push_back(x);
		beauty::algorithm::heap::push_heap(c.begin(), c.end(), comp);
	}
	
	void pop(){
		beauty::algorithm::heap::pop_heap(c.begin(), c.end(), comp);
		c.pop_back();
	}
};

}
}
}
#endif
