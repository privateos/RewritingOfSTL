
#ifndef beauty__container__list___slist_hpp
#define beauty__container__list___slist_hpp

#include<./beauty/container/list/slist_detail/slist_node.hpp>
#include<./beauty/container/list/slist_detail/slist_iterator.hpp>
#include<./beauty/allocator/simple_allocator.hpp>
#include<./beauty/allocator/function/construct.hpp>
#include<./beauty/allocator/function/destroy.hpp>
#include<./beauty/container/list/slist_detail/slist_make_link.hpp>
#include<./beauty/config.hpp>

namespace beauty{namespace container{namespace list{

template<class T, class alloc = 
	beauty::allocator::allocator>
class slist{
	public:
	typedef beauty::container::list::slist_detail::slist_iterator<T,T&,T*>
																iterator;
	typedef beauty::container::list::slist_detail::
				slist_iterator<T,const T&,const T*>
														  const_iterator;
	typedef T                                                 value_type;
	typedef value_type&                                        reference;
	typedef const value_type&                            const_reference;
	typedef T*                                                   pointer;
	typedef const value_type*                              const_pointer;
	typedef beauty::ptrdiff_t                            difference_type;
	typedef beauty::size_t                                     size_type;
	
	
	
	protected:
	typedef beauty::container::list::slist_detail::slist_node<T>
	                                                           list_node;
 	typedef beauty::container::list::slist_detail::slist_node_base
		                                                  list_node_base;
	typedef beauty::allocator::simple_allocator<list_node,alloc>       allocator;
	
	list_node_base m_head;
	//list_node_base m_tail;
	size_type m_size;
	
	list_node* create_node(const value_type &x){
		list_node *p = allocator::allocate();
		beauty::allocator::function::construct(&p->data, x);
		p->next = nullptr;
		return p;
	}
	
	void destroy_node(list_node *p){
		beauty::allocator::function::destroy(&p->data);
		allocator::deallocate(p);
	}
	
	public:
	slist():m_size(0){
		m_head.next = nullptr;
		//m_tail.next = 0;
	}
	
	~slist(){
		clear();
	}
	
	iterator begin(){
		return reinterpret_cast<list_node*>(m_head.next);
	}
	
	const_iterator begin()const{
		return reinterpret_cast<list_node*>(m_head.next);
	}
	
	
	void clear(){
		iterator first(reinterpret_cast<list_node*>(m_head.next));
		iterator last(reinterpret_cast<list_node*>(0));
		
		beauty::allocator::function::
			destroy(first, last);
		m_size = 0;
	}
		
	
	iterator end(){
		return nullptr;
	}
	
	const_iterator end()const{
		return nullptr;
	}
	

	size_type size()const{
		return m_size;
	}
	
	bool is_empty()const{
		return m_head.next == nullptr;
	}
	
	bool empty()const{
		return m_head.next == nullptr;
	}
	
	void swap(slist &x){
		list_node_base	*tmp = m_head.next;
		m_head.next = x.m_head.next;
		x.m_head.next = tmp;
			
		//tmp = m_tail.next;
		//m_tail.next = x.m_tail.next;
		//x.m_tail.next = tmp;
			
		size_type ts = m_size;
		m_size = x.m_size;
		x.m_size = ts;
	}
	
	reference front(){
		return (static_cast<list_node*>(m_head.next))->data;
	}
	
	const_reference front()const{
		return (static_cast<list_node*>(m_head.next))->data;
	}
	
	void push_front(const value_type &x){
		list_node *p = create_node(x);
		beauty::container::list::slist_detail::
			slist_make_link(&m_head, p);
		++m_size;
	}
	
	void pop_front(){
		list_node *p = reinterpret_cast<list_node*>(m_head.next);
		m_head.next = p->next;
		destroy_node(p);
		--m_size;
	}
	
	void erase_next(iterator p){
		if(p.node == nullptr){
			return ;
		}
		list_node_base *s = p.node->next;
		p.node->next = s->next;
		
		destroy_node(reinterpret_cast<list_node*>(s));
		--m_size;
	}

	void erase_next(const_iterator p){
		if(p.node == nullptr){
			return ;
		}
		list_node_base *s = p.node->next;
		p.node->next = s->next;

		destroy_node(reinterpret_cast<list_node*>(s));
		--m_size;
	}
	
	void insert_next(iterator position, const value_type &x){
		if(position.node == nullptr){
			return ;
		}
		
		list_node *p = create_node(x);
		beauty::container::list::slist_detail::
			slist_make_link(position.node, p);
		++m_size;
	}
	
	void insert_next(const_iterator position, const value_type &x){
		if(position.node == nullptr){
			return ;
		}

		list_node *p = create_node(x);
		beauty::container::list::slist_detail::
			slist_make_link(position.node, p);
		++m_size;
	}
};

template<class T, class alloc>
inline void swap(slist<T, alloc> &a, slist<T, alloc> &b){
	a.swap(b);
}


}
}
}
#endif
