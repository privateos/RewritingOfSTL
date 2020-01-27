
#ifndef beauty__container__heap__fibheap_hpp
#define beauty__container__heap__fibheap_hpp

#include<./beauty/container/heap/fibheap_detail/fibheap_node.hpp>
#include<./beauty/allocator/simple_allocator.hpp>
#include<./beauty/functor/less.hpp>
#include<./beauty/types.hpp>
#include<./beauty/allocator/function/construct.hpp>
#include<./beauty/allocator/function/destroy.hpp>
#include<./beauty/config.hpp>
#include<./beauty/container/array/vector.hpp>
#include<./beauty/header.hpp>
#include<./beauty/container/stack/stack.hpp>


namespace beauty{namespace container{namespace heap{

template<class T,
class Compare = beauty::functor::less<T>,
class alloc = beauty::allocator::allocator>

class fibheap{
	public:
	typedef void                                          iterator;
	typedef void                                    const_iterator;
	typedef T                                           value_type;
	typedef const value_type&                            reference;
	typedef const value_type&                      const_reference;
	typedef const value_type*                              pointer;
	typedef const value_type*                        const_pointer;
	typedef beauty::ptrdiff_t                      difference_type;
	typedef beauty::size_t                               size_type;
	
	
	protected:
	typedef beauty::container::heap::fibheap_detail::fibheap_node<T>
														      node;
	typedef node*                						 link_type;
	typedef fibheap<T, Compare, alloc>                        self;
	typedef beauty::allocator::simple_allocator<node, alloc>
					                        			 allocator;
					                        			

	link_type m_head;
	size_type m_size;
	size_type m_root_size;
	Compare m_compare;
	
	
	link_type create_node(const value_type &value){
		link_type p = allocator::allocate();
		beauty::allocator::function::construct(&(p->value), value);
		p->count = 0;
		p->mark = 0;
		return p;
	}
	
	void destroy_node(const link_type p){
		beauty::allocator::function::destroy(&(p->value));
		allocator::deallocate(p);
	}

	void link(link_type x, link_type y){
		y->right->left = y->left;
		y->left->right = y->right;
		
		y->mark = 0;
		if(x->count){
			y->right = x->child->right;
			x->child->right->left = y;
			x->child->right = y;
			y->left = x->child;
		}else{
			x->child = y;
			y->left = y;
			y->right = y;
		}
		y->parent = x;
		++(x->count);
	}
	
	void consolidate(){
		beauty::container::array::vector<link_type>
		a(1 + static_cast<size_type>(
		std::log(static_cast<double>(m_size))/std::log(1.6)), nullptr);
		
		link_type p = m_head;
		link_type s;
		size_type d, length;
		
		
		d = p->count;
		a[d] = p;
		p = p->right;
		--m_root_size;
		while(m_root_size){
			--m_root_size;
			d = p->count;
			while(a[d]){
				s = a[d];
				if(m_compare(s->value, p->value)){
					link(s, p);
					p = s;
				}else{
					link(p, s);
				}
				a[d] = nullptr;
				++d;
			}
			a[d] = p;
			p = p->right;
		}
		
		m_head = nullptr;
		length = a.size();
		
		for(d = 0; d < length; ++d){
			if(a[d]){
				m_head = a[d];
				m_head->left = m_head;
				m_head->right = m_head;
				++d;
				++m_root_size;
				break;
			}
		}
		for(; d < length; ++d){
			if(a[d]){
				++m_root_size;
				s = a[d];
				s->right = m_head->right;
				m_head->right->left = s;
				m_head->right = s;
				s->left = m_head;
					
				if(m_compare(s->value, m_head->value)){
					m_head = s;
				}
			}
		}
	}

	public:
	fibheap():m_size(0), m_root_size(0), m_head(nullptr){}
	
	fibheap(Compare cmp):m_size(0), m_root_size(0), m_head(nullptr), m_compare(cmp){}
	
	fibheap(const self &h);
	
	~fibheap(){
		clear();
	}
	
	void clear(){
		if(m_head){
			beauty::container::stack::stack<link_type> s;
			link_type p, r;
			s.push(m_head);
			
			do{
				p = s.top();
				s.pop();
				r = p->right;
				
				m_head = p;
				
				do{
					if(p->count){
						s.push(p->child);
					}
					destroy_node(p);

					//std::cout<<"a"<<std::endl;

					p = r;
					r = p->right;
				}while(p != m_head);
			}while(!s.empty());
			
			m_head = nullptr;
			m_size = 0;
			m_root_size = 0;
		}
	}
	
	size_type size()const{
		return m_size;
	}
	
	size_type max_size()const{
		return size_type(-1);
	}
	
	void swap(self &p){
		if(this != &p){
			size_type tmp_size = m_size;
			m_size = p.m_size;
			p.m_size = tmp_size;
			
			tmp_size = m_root_size;
			m_root_size = p.m_root_size;
			p.m_root_size = tmp_size;
			
			link_type tmp_head = m_head;
			m_head = p.m_head;
			p.m_head = tmp_head;
			
			Compare tmp_compare = m_compare;
			m_compare = p.m_compare;
			p.m_compare = tmp_compare;
		}
	}
	
	
	reference front()const{
		return m_head->value;
	}
	
	reference top()const{
		return m_head->value;
	}
	
	
	void pop(){
		link_type p;
		link_type p_child = m_head->child;
		
		if(p_child){
			p = m_head->right;
			p_child->right->left = m_head;
			m_head->right = p_child->right;
			p_child->right = p;
			p->left = p_child;
			
			while(p_child != m_head){
				++m_root_size;
				p_child->parent = nullptr;
				p_child = p_child->left;
			}
		}
		
		
		p = m_head;
		--m_root_size;
		if(m_size == 1){
			m_head = nullptr;
		}else{
			p_child = m_head->right;
			//p = m_head;
			p_child->left = p->left;
			p->left->right = p_child;
			m_head = p_child;
			consolidate();
		}
		
		destroy_node(p);
		--m_size;
	}
	
	void push(const value_type &value){
		link_type p = create_node(value);
		
		p->parent = nullptr;
		p->child = nullptr;
		
		if(m_head){
			p->right = m_head->right;
			m_head->right->left = p;
			p->left = m_head;
			m_head->right = p;
			
			if(m_compare(p->value, m_head->value)){
				m_head = p;
			}
		}else{
			p->left = p;
			p->right = p;
			m_head = p;
		}
		++m_root_size;
		++m_size;
	}
	
	void append(const value_type &value){
		push(value);
	}
	
	void insert(const value_type &value){
		push(value);
	}
	
	void jion(self &u){
		if(this == &u)return;
		
		if(u.m_head){
			if(m_head){
				link_type tmp = m_head->right;
				u.m_head->right->left = m_head;
				m_head->right = u.m_head->right;
				tmp->left = u.m_head;
				u.m_head->right = tmp;
				
				m_size += u.m_size;
				m_root_size += u.m_root_size;
				if(m_compare(u.m_head->value, m_head->value)){
					m_head = u.m_head;
				}
				u.m_size = 0;
				u.m_root_size = 0;
				u.m_head = nullptr;
			}else{
				m_head = u.m_head;
				m_size = u.m_size;
				m_root_size = u.m_root_size;
				//m_compare = u.m_compare;
				
				u.m_head = nullptr;
				u.m_size = 0;
				u.m_root_size = 0;
			}
		}
	}
	
};



}
}
}

#endif
