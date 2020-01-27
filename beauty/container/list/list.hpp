
#ifndef beauty__container__list___list_hpp
#define beauty__container__list___list_hpp

#include<./beauty/container/list/list_detail/list_iterator.hpp>
#include<./beauty/container/list/list_detail/list_node.hpp>
#include<./beauty/allocator/simple_allocator.hpp>
#include<./beauty/types.hpp>
#include<./beauty/allocator/function/construct.hpp>
#include<./beauty/allocator/function/destroy.hpp>
#include<./beauty/config.hpp>


namespace beauty{namespace container{namespace list{

template<class T, class alloc = beauty::allocator::allocator>
class list{
	protected:
	typedef beauty::container::list::list_detail::
		list_node<T>                                list_node;
	typedef list_node*                              link_type;
	typedef beauty::allocator::
		simple_allocator<list_node,alloc>			allocator;	
		
	link_type node;
//	beauty::size_t m_size;
	
	
	
	public:
	typedef beauty::container::list::list_detail::
		list_iterator<T, T&, T*>                     iterator;
 	typedef beauty::container::list::list_detail::
		list_iterator<T, const T&, const T*>   const_iterator;
	typedef beauty::size_t                          size_type;
	typedef beauty::ptrdiff_t                 difference_type; 
	typedef T                                      value_type;
	typedef value_type&                             reference;
	typedef const value_type&                 const_reference;
	typedef value_type*                               pointer;
	typedef const value_type*                   const_pointer;
	
	protected:
	void empty_initialize(){
		node = allocator::allocate();
		node->prev = node;
		node->next = node;
	}
	
	link_type create_node(const T &x){
		link_type p = allocator::allocate();
		beauty::allocator::function::
			construct(&p->data, x);
			
		return p;
	}
	
	void destroy_node(link_type p){
		beauty::allocator::function::destroy(&p->data);
		allocator::deallocate(p);
	}
	
	void transfer(iterator position, iterator first, iterator last){
		if(position != last){
			link_type p = position.node->prev;
			
			last.node->prev->next = position.node;
			position.node->prev = last.node->prev;
			
			first.node->prev->next = last.node;
			last.node->prev = first.node->prev;
			
			first.node->prev = p;
			p->next = first.node;
		}
	}
	
	
	public:
	list(){
		empty_initialize();
	}
	
	~list(){
		link_type p = node->next;
		link_type temp;
		while(p != node){
			temp = p;
			p = temp->next;
			destroy_node(temp);
		}
		allocator::deallocate(node);
		node = nullptr;
	}
	
	iterator begin(){
		return node->next ;
	}
	
	const_iterator begin()const{
		return node->next;
	}
	
	iterator end(){
		return node;
	}
	
	const_iterator end()const{
		return node;
	}
	
	bool is_empty()const{
		return node->next == node;
	}
	
	size_type size()const{
		size_type n = 0;
		link_type p = node->next;
		while(p != node){
			++n;
			p = p->next;
		}
		return n;
	}
	
	reference front(){
		return *(node->next);
	}

	const_reference front()const{
		return *(node->next);
	}
	
	reference back(){
		return *(node->prev);
	}

	const_reference back()const{
		return *(node->prev);
	}
	
	void push_back(const T &x){
		insert(iterator(node), x);
	}
	
	void push_front(const T &x){
		insert(iterator(node->next), x);
	}
	
	void pop_back(){
		erase(iterator(node->prev));
	}
	
	void pop_front(){
		erase(iterator(node->next));
	}
	
	iterator erase(iterator position){
		link_type next_node = position.node->next;
		link_type prev_node = position.node->prev;
		next_node->prev = prev_node;
		prev_node->next = next_node;
		//--m_size;
		return next_node;
	}
	
	const_iterator erase(const_iterator position){
		link_type next_node = position.node->next;
		link_type prev_node = position.node->prev;
		next_node->prev = prev_node;
		prev_node->next = next_node;
		//--m_size;
		return next_node;
	}
	
	void clear(){
		link_type cur = node->next;
		link_type temp;
		while(cur != node){
			temp = cur;
			cur = temp->next;
			destroy_node(temp);
		}
		//m_size = 0;
		node->prev = node;
		node->next = node;
	}
	
	void remove(const T &value){
		iterator first = node->next;
		iterator last = node;
		iterator temp;
		while(first != last){
			temp = first;
			++temp;
			if(*first == value){
				erase(first);
			}
			first = temp;
		}
	}
	
	void unique(const T &value){
		if(node->next == node || node->next->next == node){
			return ;
		}
		iterator first = node->next;
		iterator last = node;
		iterator next = first;
		while(++next != last){
			if(*next == *first){
				erase(next);
			}else{
				first = next;
			}
			next = first;
		}
	}
	
	void splice(iterator position, list &x){
		if(x.node != x.node->next){
			transfer(position, iterator(x.node->next), iterator(x.node));
		}
	}
	
	void splice(iterator position, list&, iterator i){
		iterator j = i;
		++j;
		if(position == i || position == j){
			return;
		}
		transfer(position, i, j);
	}
	
	void merge(list &x){
		iterator first1 = node->next;
		iterator last1 = node;
		iterator first2 = x.node->next;
		iterator last2 = x.node;
		iterator next;
		while(first1 != last1 && first2 != last2){
			if(*first2 < *first1){
				next = first2;
				++next;
				transfer(first1, first2, next);
				first2 = next;
			}else{
				++first1;
			}
		}
		if(first2 != last2){
			transfer(first1, first2, last2);
		}
	}
	
	void reverse(){
		if(node->next == node || node->next->next == node){
			return ;
		}
		
		iterator first = node->next;
		iterator old;
		++first;
		while(first.node != node){
			old = first;
			++first;
			transfer(iterator(node->next), iterator(old), iterator(first));
		}
	}
	
	void swap(list &x){
		link_type p = node;
		node = x.node;
		x.node = p;
	}
	
	void sort(){
		if(node->next == node || node->next->next == node){
			return;
		}
		
		list carray;
		list counter[64];
		size_type i = 0;
		size_type fill = 0;
		while(node->next != node){
			splice(iterator(carray.node->next), *this, iterator(node->next));
			while(i < fill && counter[i].node->next != counter[i].node){
				counter[i].merge(carray);
				carray.swap(counter[i]);
				++i;
			}
			carray.swap(counter[i]);
			if(i == fill){
				++fill;
			}
		}
		for(i = 1; i < fill; ++i){
			counter[i].merge(counter[i - 1]);
		}
		swap(counter[i - 1]);
	}
	
	iterator insert(iterator position, const T &x){
		link_type p = create_node(x);
		p->next = position.node;
		p->prev = position.node->prev;
		
		p->prev->next = p;
		position.node->prev = p;
		//++m_size;
		return p;
	}

	const_iterator insert(const_iterator position, const T &x){
		link_type p = create_node(x);
		p->next = position.node;
		p->prev = position.node->prev;

		p->prev->next = p;
		position.node->prev = p;
		//++m_size;
		return p;
	}
	
};

template<class T, class alloc>
inline void swap(list<T, alloc> &a, list<T, alloc> &b){
	a.swap(b);
}


}
}
}
#endif
