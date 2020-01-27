
#ifndef beauty__container__list___xorlist_hpp
#define beauty__container__list___xorlist_hpp

#include<./beauty/types.hpp>
#include<./beauty/config.hpp>
#include<./beauty/allocator/simple_allocator.hpp>
#include<./beauty/allocator/function/construct.hpp>
#include<./beauty/allocator/function/destroy.hpp>
#include<./beauty/container/list/xorlist_detail/xorlist_node.hpp>
#include<./beauty/container/list/xorlist_detail/xorlist_iterator.hpp>


namespace beauty{namespace container{namespace list{

template<class T, class alloc = beauty::allocator::allocator>
class xorlist{
	public:
	typedef beauty::container::list::xorlist_detail::
		xorlist_iterator<T, T&, T*>                     iterator;
	typedef beauty::container::list::xorlist_detail::
		xorlist_iterator<T, const T&, const T*>   const_iterator;
	typedef T                                         value_type;
	typedef value_type&                                reference;
	typedef const value_type&                    const_reference;
	typedef value_type*                                  pointer;
	typedef const value_type*                      const_pointer;
	typedef beauty::ptrdiff_t                    difference_type;
	typedef beauty::size_t                             size_type;
	
	protected:
	typedef beauty::container::list::xorlist_detail::
		xorlist_node<T>                                     node;
	typedef node*                                      link_type;
	typedef xorlist<T, alloc>                               self;
	typedef beauty::allocator::simple_allocator<node, alloc>
													   allocator;
													   
	link_type m_head;
	link_type m_tail;
	size_type m_count;
	
	link_type create_node(const value_type &v){
		link_type p = allocator::allocate();
		beauty::allocator::function::construct(&(p->value), v);
		return p;
	}
	
	void destroy_node(link_type p){
		beauty::allocator::function::destroy(&(p->value));
		allocator::deallocate(p);
	}
	
	
	public:
	
	xorlist():m_head(nullptr), m_tail(nullptr), m_count(0){}
	
	~xorlist(){
		clear();
	}
	
	void clear(){
		if(m_count){
			typename node::pointer_integer prev, cur, next;

			prev.integer = 0;
			cur.pointer = m_head;			
			next.integer = m_head->u.integer;
		
			while(true){
				--m_count;
				prev = cur;
				cur = next;
				if(m_count){
					destroy_node(prev.pointer);
					next.integer = (prev.integer)^(cur.pointer->u.integer);
				}else{
					destroy_node(prev.pointer);	
					break;
				}								
			}
			
			m_head = nullptr;
			m_tail = nullptr;
		}
	}
	
	iterator begin(){
		return iterator(0, m_head, m_head->u.pointer);
	}
	
	const_iterator begin()const{
		return const_iterator(0, m_head, m_head->u.pointer);
	}
	
	iterator end(){
		return iterator(0);
	}
	
	const_iterator end()const{
		return const_iterator(0);
	}
	
	iterator head(){
		return iterator(0, m_head, m_head->u.pointer);
	}
	
	const_iterator head()const{
		return const_iterator(0, m_head, m_head->u.pointer);
	}
	
	iterator tail(){
		return iterator(m_tail->u.pointer, m_tail, 0);
	}
	
	const_iterator tail()const{
		return const_iterator(m_tail->u.pointer, m_tail, 0);
	}
	
	size_type size()const{
		return m_count;
	}
	
	size_type max_size()const{
		return size_type(-1);
	}
	
	bool empty()const{
		return m_count == 0;
	}
	
	bool is_empty()const{
		return m_count == 0;
	}
	
	reference front(){
		return m_head->value;
	}
	
	const_reference front()const{
		return m_head->value;
	}
	
	reference back(){
		return m_tail->value;
	}
	
	const_reference back()const{
		return m_tail->value;
	}
	
	reference at(size_type index){
		if(index == 0){
			return front();
		}else{
			if(index == m_count - 1){
				return back();
			}else{
				typename node::pointer_integer prev, cur, next;
				if(index < (m_count>>1)){
					prev.integer = 0;
					cur.pointer = m_head;
					while(index){
						next.integer = (prev.integer)^(cur.pointer->u.integer);
						prev = cur;
						cur = next;
						--index;
					}
					return cur.pointer->value;
				}else{
					next.integer = 0;
					cur.pointer = m_tail;
					index = m_count - index - 1;
					while(index){
						prev.integer = (next.integer)^(cur.pointer->u.integer);
						next = cur;
						cur = prev;
						--index;
					}
					return cur.pointer->value;
				}
			}
		}
	}
	
	const_reference at(size_type index)const{
		if(index == 0){
			return front();
		}else{
			if(index == m_count - 1){
				return back();
			}else{
				typename node::pointer_integer prev, cur, next;
				if(index < (m_count>>1)){
					prev.integer = 0;
					cur.pointer = m_head;
					while(index){
						next.integer = (prev.integer)^(cur.pointer->u.integer);
						prev = cur;
						cur = next;
						--index;
					}
					return cur.pointer->value;
				}else{
					next.integer = 0;
					cur.pointer = m_tail;
					index = m_count - index - 1;
					while(index){
						prev.integer = (next.integer)^(cur.pointer->u.integer);
						next = cur;
						cur = prev;
						--index;
					}
					return cur.pointer->value;
				}
			}
		}	
	}

	void push_front(const value_type &v){
		
		typename node::pointer_integer p;
		p.pointer = create_node(v);
		
		if(m_count){
			m_head->u.integer = (m_head->u.integer)^(p.integer);
			p.pointer->u.pointer = m_head;
			m_head = p.pointer;			
		}else{
			m_head = p.pointer;
			m_tail = p.pointer;
			p.pointer->u.integer = 0;
		}
		++m_count;
	}
	
	void pop_front(){
		--m_count;
		if(m_count){
			typename node::pointer_integer p = m_head->u;
			m_head->u.pointer = m_head;
			p.pointer->u.integer = (p.pointer->u.integer)^(m_head->u.integer);
			destroy_node(m_head);
			m_head = p.pointer;
		}else{
			destroy_node(m_head);
			m_head = nullptr;
			m_tail = nullptr;
		}
	}
	
	void push_back(const value_type &v){
		typename node::pointer_integer p;
		p.pointer = create_node(v);
		
		if(m_count){
			m_tail->u.integer = (m_tail->u.integer)^(p.integer);
			p.pointer->u.pointer = m_tail;
			m_tail = p.pointer;
		}else{
			m_head = p.pointer;
			m_tail = p.pointer;
			p.pointer->u.integer = 0;
		}
		++m_count;
	}
	
	void pop_back(){
		--m_count;
		if(m_count){
			typename node::pointer_integer p = m_tail->u;
			m_tail->u.pointer = m_tail;
			p.pointer->u.integer = (p.pointer->u.integer)^(m_tail->u.integer);
			destroy_node(m_tail);
			m_tail = p.pointer;
		}else{
			destroy_node(m_head);
			m_head = nullptr;
			m_tail = nullptr;
		}
	}
	
	void append(const value_type &v){
		push_back(v);
	}
	
	void insert(size_type index, const value_type &v){
		if(index == 0){
			push_front(v);
		}else{
			if(index == m_count){
				push_back(v);
			}else{
				typename node::pointer_integer prev, cur, next;
				
				if(index < (m_count>>1)){
					prev.integer = 0;
					cur.pointer = m_head;
					while(index){
						next.integer = (prev.integer)^(cur.pointer->u.integer);
						prev = cur;
						cur = next;
						--index;
					}
					
				}else{
					next.integer = 0;
					cur.pointer = m_tail;
					index = m_count - index - 1;
					while(index){
						prev.integer = (next.integer)^(cur.pointer->u.integer);
						next = cur;
						cur = prev;
						--index;
					}
					prev.integer = (next.integer)^(cur.pointer->u.integer);
				}
				next.pointer = create_node(v);
				
				next.pointer->u.integer = (prev.integer)^(cur.integer);
				prev.pointer->u.integer = (prev.pointer->u.integer)^(cur.integer)^(next.integer);
				cur.pointer->u.intger = (cur.pointer->u.integer)^(prev.integer)^(next.integer);
				
				++m_count;
			}
		}
	}
	
	void erase(size_type index){
		if(index == 0){
			pop_front();
		}else{
			if(index == m_count - 1){
				pop_back();
			}else{
				typename node::pointer_integer prev, cur, next;
				if(index < (m_count>>1)){
					prev.integer = 0;
					cur.pointer = m_head;
					while(index){
						next.integer = (prev.intger)^(cur.pointer->u.integer);
						prev = cur;
						cur = next;
						--index;
					}
					
				}else{
					next.integer = 0;
					cur.pointer = m_tail;
					index = m_count - index - 1;
					while(index){
						prev.integer = (next.intger)^(cur.pointer->u.intger);
						next = cur;
						cur = prev;
						--index;
					}
					
				}
				
				prev.pointer->u.integer = (prev.pointer->u.integer)^
					(cur.integer)^(next.integer);
				next.pointer->u.intger = (next.pointer->u.intger)^
					(cur.integer)^(prev.integer);
				destroy_node(cur.pointer);
				--m_count;
			}
		}
	}
	
	iterator insert(iterator pos, const value_type &v){
		if(pos.cur.pointer == m_head){
			push_front(v);
			return head();
		}else{
			if(pos.cur.pointer == nullptr){
				push_back(v);
				return tail();
			}else{
				pos.next = pos.cur;
				pos.cur.pointer = create_node(v);
				
				pos.cur.pointer->u.integer = 
					(pos.prev.integer)^(pos.next.integer);
				pos.prev.pointer->u.integer = 
					(pos.prev.pointer->u.integer)^(pos.next.integer)^(pos.cur.integer);
				pos.next.pointer->u.integer = 
					(pos.next.pointer->u.integer)^(pos.prev.integer)^(pos.cur.integer);
				++m_count;
				return pos;						
			}
		}
	}
	
	iterator erase(iterator pos){
		if(pos.cur.pointer == m_head){
			pop_front();
			return head();
		}else{
			if(pos.cur.pointer == m_tail){
				pop_back();
				return tail();
			}else{
				pos.prev.pointer->u.integer = 
					(pos.prev.pointer->u.integer)^(pos.cur.integer)^(pos.next.integer);
				pos.next.pointer->u.integer =
					(pos.next.pointer->u.integer)^(pos.cur.integer)^(pos.prev.integer);
				destroy_node(pos.cur);
				pos.cur = pos.next;
				pos.next.integer = (pos.prev.integer)^(pos.cur.pointer->u.integer);
				return pos;
			}
		}
	}
	
	const_iterator insert(const_iterator pos, const value_type &v){
		if(pos.cur.pointer == m_head){
			push_front(v);
			return head();
		}else{
			if(pos.cur.pointer == nullptr){
				push_back(v);
				return tail();
			}else{
				pos.next = pos.cur;
				pos.cur.pointer = create_node(v);
				
				pos.cur.pointer->u.integer = 
					(pos.prev.integer)^(pos.next.integer);
				pos.prev.pointer->u.integer = 
					(pos.prev.pointer->u.integer)^(pos.next.integer)^(pos.cur.integer);
				pos.next.pointer->u.integer = 
					(pos.next.pointer->u.integer)^(pos.prev.integer)^(pos.cur.integer);
				++m_count;
				return pos;						
			}
		}		
	}
	
	const_iterator erase(const_iterator pos){
		if(pos.cur.pointer == m_head){
			pop_front();
			return head();
		}else{
			if(pos.cur.pointer == m_tail){
				pop_back();
				return tail();
			}else{
				pos.prev.pointer->u.integer = 
					(pos.prev.pointer->u.integer)^(pos.cur.integer)^(pos.next.integer);
				pos.next.pointer->u.integer =
					(pos.next.pointer->u.integer)^(pos.cur.integer)^(pos.prev.integer);
				destroy_node(pos.cur);
				pos.cur = pos.next;
				pos.next.integer = (pos.prev.integer)^(pos.cur.pointer->u.integer);
				return pos;
			}
		}		
	}
	
	void reverse(){
		if(m_count > 1){
			link_type tmp = m_head;
			m_head = m_tail;
			m_tail = tmp;
		}
	}
	
	void swap(self &L){
		if(this != &L){
			link_type tmp_link = m_head;
			m_head = L.m_head;
			L.m_head = tmp_link;
			
			tmp_link = m_tail;
			m_tail = L.m_tail;
			L.m_tail = tmp_link;
			
			size_type tmp_count = m_count;
			m_count = L.m_count;
			L.m_count = tmp_count;
		}
	}
	
};

template<class T, class alloc>
void swap(xorlist<T, alloc> &a, xorlist<T, alloc> &b){
	a.swap(b);
}

}
}
}
#endif
