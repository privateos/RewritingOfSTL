
#ifndef beauty__container__list___skiplist_hpp
#define beauty__container__list___skiplist_hpp

#include<./beauty/header.hpp>
#include<./beauty/config.hpp>
#include<./beauty/types.hpp>
#include<./beauty/container/pair/pair.hpp>
#include<./beauty/container/array/vector.hpp>
#include<./beauty/allocator/simple_allocator.hpp>
#include<./beauty/allocator/function/construct.hpp> 
#include<./beauty/allocator/function/destroy.hpp> 
#include<./beauty/functor/less.hpp>
#include<./beauty/container/list/skiplist_detail/skiplist_node.hpp>
#include<./beauty/container/list/skiplist_detail/skiplist_iterator.hpp>

namespace beauty{namespace container{namespace list{

static beauty::ushort skiplist_default_height = 32;

template<
class Key,
class Value,
class KeyOfValue,
class KeyCompare = beauty::functor::less<Key>,
class alloc = beauty::allocator::allocator 
>
class skiplist{
	protected:
	typedef typename beauty::container
	::list::skiplist_detail::
	skiplist_node<Value, alloc>                         node;
	
	public:
	typedef typename beauty::container
	::list::skiplist_detail::skiplist_iterator
	<node, Value, Value&, Value*>                   iterator;
	typedef typename beauty::container
	::list::skiplist_detail::skiplist_iterator
	<node, Value, const Value&, const Value*> const_iterator;
	typedef Value                                 value_type;
	typedef value_type&                            reference;
	typedef const value_type&                const_reference;
	typedef value_type*                              pointer;
	typedef const value_type*                  const_pointer;
	typedef beauty::size_t                         size_type;
	typedef beauty::ptrdiff_t                difference_type;
	
	typedef Key                                     key_type;
	
	
	protected:
	typedef typename beauty::allocator
	::simple_allocator<node, alloc>                allocator;
	typedef skiplist
	<Key, Value, KeyOfValue, KeyCompare, alloc>         self;
	typedef typename node::inner_pair                  inner;
	typedef node*                                  link_type;
	typedef typename beauty::container::
		pair::pair<iterator, iterator>         iterator_pair;
	typedef typename beauty::container::
		pair::pair<const_iterator, const_iterator>
		                                 const_iterator_pair;
	typedef typename beauty::container::
		pair::pair<iterator, bool>        iterator_bool_pair;
	typedef typename beauty::container::
		pair::pair<size_type, size_type>      size_type_pair;
	
	size_type m_level;
	size_type m_size;
	link_type m_head;
	link_type m_tail; 
	
	KeyOfValue m_key_of_value;
	KeyCompare m_key_compare;
	
	size_type random_level()const{
		//std::srand(std::time(0));
		size_type level = 1;
		while((std::rand()&0xFFFF) < (0.25*0xFFFF)){
			++level;
		}
		return (level < skiplist_default_height) ? 
				level : skiplist_default_height;
	}
	
	link_type create_node(const_reference value){
		size_type len = random_level();
		link_type p = allocator::allocate();
		
		beauty::allocator::function::
			construct(&(p->value), value);
		beauty::allocator::function::
			construct(&(p->array), len);
		return p;
	}
	
	void destroy_node(link_type p){
		beauty::allocator::function::
			destroy(&(p->value));
		beauty::allocator::function::
			destroy(&(p->array));
		allocator::deallocate(p);
	}
	
	void initialize(size_type height){
		m_head = nullptr;
		m_head = allocator::allocate();
		beauty::allocator::function::
			construct(&(m_head->array), height);
		m_head->array[0].span = 0;
	}
	void destroy_head(){
		if(m_head){
			beauty::allocator::function::
			destroy(&(m_head->array));
			allocator::deallocate(m_head);
			m_head = nullptr;
		}
	}
	
	link_type index_at(size_type pos)const{
		size_type i = m_level - 1;
		link_type x = m_head;
		++pos;
		while(pos){
			do{
				if(pos < x->array[i].span){
					--i;
				}else{
					pos -= x->array[i].span;
					x = x->array[i].forward;
					break;
				}
			}while(true);
			i = x->array.size() - 1;
		}
		return x;
	}
	
	link_type find_first_in_range_help(const key_type &k0, const key_type &k1)const{
		link_type x;
		difference_type i;
		
		x = m_head;
		i = m_level - 1;
		for( ; i >= 0; --i){
			while(x->array[i].forward &&
				m_key_compare(m_key_of_value(x->array[i].forward->value), k0)
				){
				x = x->array[i].forward;	
			}
		}
		x = x->array[0].forward;
		if(x){
			if(!m_key_compare(m_key_of_value(x->value), k0) &&
				m_key_of_value(m_key_of_value(x->value), k1)){
				return x;	
			}
			x = nullptr;
		}
		return x;
	}
	
	link_type find_last_in_range_help(const key_type &k0, const key_type &k1)const{
		link_type x;
		difference_type i;
		
		x = m_head;
		i = m_level - 1;
		for( ; i >= 0; --i){
			while(x->array[i].forward &&
				m_key_compare(m_key_of_value(x->array[i].forward->value), k1)
				){
				x = x->array[i].forward;	
			}
		}
		if(!m_key_compare(m_key_of_value(x->value), k0)){
			return x;
		}
		return nullptr;
	}
	
	link_type find_first_of_help(const key_type &key)const{
		link_type x;
		difference_type i;
		
		x = m_head;
		i = m_level - 1;
		for( ; i >= 0; --i){
			while(x->array[i].forward &&
				m_key_compare(m_key_of_value(x->array[i].forward->value), key)
				){
				x = x->array[i].forward;	
			}
		}
		x = x->array[0].forward;
		if(x){
			if(m_key_compare(key, m_key_of_value(x->value))){
				x = nullptr;
			}
		}
		return x;
	}
	
	link_type find_last_of_help(const key_type &key)const{
		link_type x, y;
		difference_type i;
		
		x = m_head;
		i = m_level - 1;
		for( ; i >= 0; --i){
			while(x->array[i].forward &&
				m_key_compare(m_key_of_value(x->array[i].forward->value), key)
				){
				x = x->array[i].forward;	
			}
		}
		x = x->array[0].forward;
		y = x;
		
		if(y && m_key_compare(key, m_key_of_value(y->value))){
			return nullptr;
		}
		y = x->array[0].forward;
		
		while(y){
			if(m_key_compare(key, m_key_of_value(y->value))){
				break;
			}
			x = y;
			y = x->array[0].forward;
		}	
		return x;
	}
	
	void equal_range_help(const key_type &key, link_type &first, link_type last)const{
		link_type x, y;
		difference_type i;
		
		x = m_head;
		i = m_level - 1;
		for( ; i >= 0; --i){
			while(x->array[i].forward &&
				m_key_compare(m_key_of_value(x->array[i].forward->value), key)
				){
				x = x->array[i].forward;	
			}
		}
		x = x->array[0].forward;
		y = x;
		
		if(y && m_key_compare(key, m_key_of_value(y->value))){
			first = nullptr;
			last = nullptr;
			return;
		}
		first = x;
		y = x->array[0].forward;
		last = y;
		
		while(y){
			if(m_key_compare(key, m_key_of_value(y->value))){
				break;
			}
			x = y;
			y = x->array[0].forward;
			last = y;
		}
	}
	

	public:
	skiplist():m_level(1), m_size(0), 
		m_tail(nullptr){
		initialize(skiplist_default_height);	
	}
	
	skiplist(const self &s){
		initialize(skiplist_default_height);
		link_type x = s.m_head;
		x = x->array[0].forward;
		while(x){
			insert_equal(x->value);
			x = x->array[0].forward;
		}
	}
	
	~skiplist(){
		clear();
		destroy_head();
	}
	
	void clear(){
		if(m_size){
			link_type x = m_head->array[0].forward;
			link_type next;
			while(x){
				next = x->array[0].forward;
				destroy_node(x);
				x = next;
			}
			m_size = 0;
			m_tail = nullptr;
			m_level = 1;
			m_head->array[0].forward = nullptr;
			m_head->array[0].span = 0;
			for(size_type i = 1, len = m_head->array.size(); i < len; ++i){
				m_head->array[i].forward = nullptr;
			}
		}
	}
	
	self& operator = (const self &s){
		if(this != &s){
			clear();
			link_type x = s.m_head;
			x = x->array[0].forward;
			while(x){
				insert_equal(x->value);
				x = x->array[0].forward;
			}
		}
		return *this;
	}
	
	iterator begin(){
		return iterator(m_head->array[0].forward);
	}
	
	const_iterator begin()const{
		return const_iterator(m_head->array[0].forward);
	}
	
	iterator end(){
		return iterator(nullptr);
	}
	
	const_iterator end()const{
		return iterator(nullptr);
	}
	
	iterator head(){
		return iterator(m_head->array[0].forward);
	}
	
	const_iterator head()const{
		return const_iterator(m_head->array[0].forward);
	}
	
	iterator tail(){
		return iterator(m_tail);
	}
	
	const_iterator tail()const{
		return const_iterator(m_tail);
	}
	
	bool is_empty()const{
		return m_size == 0;
	}
	
	bool empty()const{
		return m_size == 0;
	}
	
	size_type size()const{
		return m_size;
	}
	
	size_type max_size()const{
		return size_type(-1);
	}
	
	size_type level()const{
		return m_level;
	}
	
	size_type level(iterator pos)const{
	//check pos.cur if pos.cur == nullptr throw exception
		return pos.cur->array.size();
	}
	
	size_type level(const_iterator pos)const{
	//check pos.cur if pos.cur == nullptr throw exception
		return pos.cur->array.size();
	}
	
	iterator rank(size_type pos){
		// check pos if pos >= m_size throw exception;
		
		return iterator(index_at(pos));
	}
	
	const_iterator rank(size_type pos)const{
		// check pos if pos >= m_size throw exception;		
		
		return const_iterator(index_at(pos));
	}
	
	size_type get_rank_of_first(const key_type &k)const{
		//check m_head->array[0].forward->value and m_tail->value out of key throw exception
		
		link_type x;
		difference_type i;
		size_type ran = 0;
		
		i = m_level - 1;
		x = m_head;
		for( ; i >=0; --i){
			while(x->array[i].forward &&
				m_key_compare(m_key_of_value(x->array[i].forward->value),
				k)	){
				ran += x->array[i].span;
				x = x->array[i].forward;	
			}
		}
		x = x->array[0].forward;
		//++ran;
		if(x){
			if(!m_key_compare(k, m_key_of_value(x->value))){
				return ran;
			}
		}
		return m_size;
	}
	
	size_type get_rank_of_last(const key_type &k)const{
		//check m_head->array[0].forward->value and m_tail->value out of key throw exception
		
		link_type x, y;
		difference_type i;
		size_type ran = 0;
		bool has;
		
		i = m_level - 1;
		x = m_head;
		for( ; i >=0; --i){
			while(x->array[i].forward &&
				m_key_compare(m_key_of_value(x->array[i].forward->value),
				k)	){
				ran += x->array[i].span;
				x = x->array[i].forward;	
			}
		}
		y = x->array[0].forward;
		if(y){
			has = false;
			do{
				if(m_key_compare(k,
					m_key_of_value(y->value)) ){
					break;	
				}
				if(m_key_compare(
					m_key_of_value(y->value), k) ){
					break;	
				}
				has = true;
				++ran;
				x = y;
				y = x->array[0].forward;
			}while(y);
			
			--ran;
			if(has){
				return ran;
			}
		}	
		return m_size;	
	}
	
	size_type_pair get_rank(const key_type &k)const{
		size_type ran0, ran1;
		difference_type i;
		link_type x, y;
		
		x = m_head;
		i = m_level - 1;
		ran0 = 0;
		
		for( ; i >= 0; --i){
			while(x->array[i].forward &&
				m_key_compare(
					m_key_of_value(x->array[i].forward->value), k)
				){
				ran0 += x->array[i].span;
				x = x->array[i].forward;	
			}
		}
		
		y = x->array[0].forward;
		if(y){
			if(!m_key_compare(k, m_key_of_value(y->value))){
				ran1 = ran0 + 1;
				x = y;
				y = x->array[0].forward;
				while(y){
					if(m_key_compare(k, m_key_of_value(y->value))){
						break;
					}
					if(m_key_compare(m_key_of_value(y->value), k)){
						break;
					}
					++ran1;
					x = y;
					y = x->array[0].forward;
				}
				return size_type_pair(ran0, ran1);
			}
		}
		return size_type_pair(m_size, m_size);
	}
	
	reference at(size_type n){
		// check pos if pos >= m_size throw exception;		
		
		return index_at(n)->value;
	}
	
	const_reference at(size_type n)const{
		// check pos if pos >= m_size throw exception;
		return index_at(n)->value;	
	}
	
	iterator_bool_pair insert_unique(const_reference value){
		link_type update[skiplist_default_height];
		size_type ran[skiplist_default_height];
		difference_type i;
		size_type lev;
		link_type x;
		
		
		x = m_head;
		i = m_level - 1;
		ran[i] = 0;
		while(x->array[i].forward &&
			m_key_compare(
				m_key_of_value(x->array[i].forward->value),
				m_key_of_value(value)
			)
		){
			ran[i] += x->array[i].span;
			x = x->array[i].forward;
		}
		update[i] = x;
		--i;
		
		for( ; i >= 0; --i){
			ran[i] = ran[i + 1];
			while(x->array[i].forward &&
				m_key_compare(
					m_key_of_value(x->array[i].forward->value),
					m_key_of_value(value) )	
				){
				ran[i] += x->array[i].span;
				x = x->array[i].forward;
			}
			update[i] = x;
		}
		
		if(x->array[0].forward && 
			!m_key_compare(m_key_of_value(value),
			m_key_of_value(x->array[0].forward->value))){
			return iterator_bool_pair(x->array[0].forward, false);
		}
		
		x = create_node(value);
		lev = x->array.size(); 
		if(lev > m_level){
			for(i = m_level; i < lev; ++i){
				ran[i] = 0;
				update[i] = m_head;
				update[i]->array[i].span = m_size;
			}
			m_level = lev;
		}
		
		
		++m_size;
		for(i = 0; i < lev; ++i){
			x->array[i].forward = update[i]->array[i].forward;
			update[i]->array[i].forward = x;
			
			x->array[i].span = update[i]->array[i].span - (ran[0] - ran[i]);
			update[i]->array[i].span = ran[0] - ran[i] + 1;
		}
		
		for(i = lev; i < m_level; ++i){
			++update[i]->array[i].span;
		}
		x->prev = (update[0] == m_head) ? nullptr : update[0];
		
		if(x->array[0].forward){
			x->array[0].forward->prev = x;
		}else{
			m_tail = x;
		}
		return iterator_bool_pair(iterator(x), false);
	}
	
	iterator insert_equal(const_reference value){
		link_type update[skiplist_default_height];
		size_type ran[skiplist_default_height];
		difference_type i;
		size_type lev;
		link_type x;
		
		i = m_level - 1;
		ran[i] = 0;
		x = m_head;
		while(x->array[i].forward &&
			m_key_compare(
				m_key_of_value(x->array[i].forward->value),
				m_key_of_value(value))
			){
			ran[i] += x->array[i].span;
			x = x->array[i].forward;	
		}
		update[i] = x;
		--i;
		for( ; i >= 0; --i){
			ran[i] = ran[i + 1];
			while(x->array[i].forward &&
				m_key_compare(
					m_key_of_value(x->array[i].forward->value),
					m_key_of_value(value))
				){
				ran[i] += x->array[i].span;
				x = x->array[i].forward;
			}
			update[i] = x;
		}
		
		x = create_node(value);
		lev = x->array.size();
		x->prev = (update[0] == m_head) ? nullptr : update[0];
		++m_size;
		if(lev > m_level){
			for(i = m_level; i < lev; ++i){
				ran[i] = 0;
				update[i] = m_head;
				update[i]->array[i].span = m_size;
			}
			m_level = lev;
		}
		
		for(i = 0; i < lev; ++i){
			x->array[i].forward = update[i]->array[i].forward;
			update[i]->array[i].forward = x;
			
			x->array[i].span = update[i]->array[i].span - (ran[0] - ran[i]);
			update[i]->array[i].span = ran[0] - ran[i] + 1;
		}
		
		for(i = lev; i < m_level; ++i){
			++update[i]->array[i].span;
		}
		
		if(x->array[0].forward){
			x->array[0].forward->prev = x;
		}else{
			m_tail = x;
		}
		return iterator(x);
	}
	
	void remove_node(link_type x, link_type *update){
		size_type i;
		for(i = 0; i < m_level; ++i){
			if(update[i]->array[i].forward == x){
				update[i]->array[i].forward = x->array[i].forward;
				update[i]->array[i].span += x->array[i].span - 1;
			}else{
				--update[i]->array[i].span;
			}
		}
		if(x->array[0].forward){
			x->array[0].forward->prev = x->prev;
		}else{
			m_tail = x->prev;
		}
		
		while(m_level > 1 && 
			m_head->array[m_level - 1].forward == nullptr){
			--m_level;
		}
		--m_size;
		destroy_node(x);
	}
	
	size_type remove(const key_type &key){
		difference_type i;
		size_type count = 0;
		link_type update[skiplist_default_height];
		link_type x, y;
		
		i = m_level - 1;
		x = m_head;
		for( ; i >= 0; --i){
			while(x->array[i].forward &&
				m_key_compare(
					m_key_of_value(x->array[i].forward->value),
					key)){
				x = x->array[i].forward;		
			}
			update[i] = x;
		}
		
		x = x->array[0].forward;
		while(x){
			if(m_key_compare(key, m_key_of_value(x->value))){
				break;
			}
			if(m_key_compare(m_key_of_value(x->value), key)){
				break;
			}
			y = x->array[0].forward; 
			++count;
			remove_node(x, update);
			x = y;
		}
		return count;
	}
	
	size_type erase_by_key(const key_type &key){
		return remove(key);
	}
	
	void erase_by_rank(size_type pos){
		//check pos if pos >= m_size throw exception
		
		link_type x;
		link_type update[skiplist_default_height];
		difference_type i;
		
		++pos;
		i = m_level - 1;
		x = m_head;
		for( ; i >= 0; --i){
			while(x->array[i].forward &&
				x->array[i].span < pos
				){
				pos -= x->array[i].span;
				x = x->array[i].forward;					
			}
			update[i] = x;
		}
		x = x->array[0].forward;
		remove_node(x, update);
	}

	iterator erase(iterator pos){
		//check pos.cur if pos.cur == nullptr throw exception
		
		link_type x = m_head;
		link_type update[skiplist_default_height];
		difference_type i = m_level - 1;
		for( ; i >= 0; --i){
			while(x->array[i].forward &&
				(m_key_compare(
					m_key_of_value(x->array[i].forward->value),
					m_key_of_value(pos.cur->value) ))){
				x = x->array[i].forward;
			}
			update[i] = x;
		}
		x = x->array[0].forward;
		while(x && x != pos.cur){
			x = x->array[0].forward;
		}
	
		if(x){
			pos.cur = pos.cur->array[0].forward;
			remove_node(x, update);
		}
		return pos;
	}
	
	const_iterator erase(const_iterator pos){
		//check pos.cur if pos.cur == nullptr throw exception
		
		link_type x = m_head;
		link_type update[skiplist_default_height];
		difference_type i = m_level - 1;
		for( ; i >= 0; --i){
			while(x->array[i].forward &&
				(m_key_compare(
					m_key_of_value(x->array[i].forward->value),
					m_key_of_value(pos.cur->value) ) )){
				x = x->array[i].forward;
			}
			update[i] = x;
		}
		x = x->array[0].forward;
		while(x && x != pos.cur){
			x = x->array[0].forward;
		}
	
		if(x){
			pos.cur = pos.cur->array[0].forward;
			remove_node(x, update);
		}
		return pos;		
	}
	
	size_type erase_range_by_rank(size_type first, size_type last){
		// check first and last reset it; or throw exception
		
		link_type x, y;
		link_type update[skiplist_default_height];
		difference_type i;
		size_type pos;
		
		x = m_head;
		i = m_level - 1;
		pos = first + 1;
		
		for( ; i >= 0; --i){
			while(x->array[i].forward &&
				x->array[i].span < pos){
				pos -= x->array[i].span;
				x = x->array[i].forward;	
			}
			update[i] = x;
		}
		
		y = x->array[0].forward;
		pos = first;
		while(pos < last){
			++pos;
			remove_node(y, update);
			y = x->array[i].forward;
		}
		return last - first;
	}
	
	size_type erase_range_by_key(const key_type &k0, const key_type &k1){
		if(m_size){
			if(m_key_compare(k1, m_key_of_value(m_head->array[0].forward->value))){
				return 0;
			}
			if(m_key_compare(m_key_of_value(m_tail->value, k0))){
				return 0;
			}
			
			link_type x, y;
			link_type update[skiplist_default_height];
			size_type count = 0;
			difference_type i;
			
			i = m_level - 1;
			x = m_head;
			for( ; i >= 0; --i){
				while(x->array[i].forward &&
					m_key_compare(m_key_of_value(x->array[i].forward->value),
					k0)){
					x = x->array[i].forward;	
				}
				update[i] = x;
			}
			y = x->array[0].forward;
			while(y){
				if(!m_key_compare(m_key_of_value(y->value), k0) &&
					m_key_compare(m_key_of_value(y->value), k1) ){
					remove_node(y, update);	
					y = x->array[0].forward;
					++count;
				}else{
					break;
				}
			}
			return count;
		}
		return 0;
	}
	
	iterator find(const key_type &key){
		return iterator(find_first_of_help(key));
	}
	
	const_iterator find(const key_type &key)const{
		return const_iterator(find_first_of_help(key));
	}
		
	iterator find_first_in_range(const key_type &k0, const key_type &k1){
		return iterator(find_first_in_range_help(k0, k1));
	}
	
	const_iterator find_first_in_range(const key_type &k0, const key_type &k1)const{
		return const_iterator(find_first_in_range_help(k0, k1));
	}
	
	iterator find_last_in_range(const key_type &k0, const key_type &k1){
		return iterator(find_last_in_range_help(k0, k1));
	}
	
	const_iterator find_last_in_range(const key_type &k0, const key_type &k1)const{
		return const_iterator(find_last_in_range_help(k0, k1));
	}
	
	iterator find_first_of(const key_type &k){
		return iterator(find_first_of_help(k));
	}
	
	const_iterator find_first_of(const key_type &k)const{
		return const_iterator(find_first_of_help(k));
	}
	
	iterator find_last_of(const key_type &k){
		return iterator(find_last_of_help(k));
	}
	
	const_iterator find_last_of(const key_type &k)const{
		return const_iterator(find_last_of_help(k));
	}
	
	iterator_pair equal_range(const key_type &key){
		link_type x, y;
		equal_range_help(key, x, y);
		return iterator_pair(x, y);
	}
	
	const_iterator_pair equal_range(const key_type &key)const{
		link_type x, y;
		equal_range_help(key, x, y);
		return const_iterator_pair(x, y);		
	}
	
	
	beauty::sbyte compare(const self &s)const{
		if(this != &s){
			link_type x, y;
			size_type i, lev;
			x = m_head->array[0].forward;
			y = s.m_head->array[0].forward;
			i = 0;
			lev = (m_size < s.m_size) ? m_size : s.m_size;
			
			while(i < lev){
				++i;
				if(m_key_compare(
					m_key_of_value(x->value),
					m_key_of_value(y->value) )){
					return -1;	
				}else{
					if(m_key_compare(
						m_key_of_value(y->value),
						m_key_of_value(x->value) )){
						return 1;	
					}else{
						x = x->array[0].forward;
						y = y->array[0].forward;
					}
				}
			}
			if(m_size < s.m_size){
				return -1;
			}else{
				if(s.m_size < m_size){
					return 1;
				}else{
					return 0;
				}
			}
		}
		return 0;
	}
	
	beauty::sbyte key_compare(const key_type &k0, const key_type &k1)const{
		if(m_key_compare(k0, k1)){
			return -1;
		}else{
			if(m_key_compare(k1, k0)){
				return 1;
			}else{
				return 0;
			}
		}
	}
	
	beauty::sbyte value_compare(reference a, reference b)const{
		return key_compare(m_key_of_value(a), m_key_of_value(b));
	}
	
	beauty::sbyte value_compare(const_reference a, const_reference b)const{
		return key_compare(m_key_of_value(a), m_key_of_value(b));
	}
	
	key_type& get_key(const_reference value){
		return m_key_of_value(value);
	}
	
	key_type& get_key(iterator pos){
		//check pos.cur if pos.cur == nullptr throw exception
		return pos.cur->value;
	}
	
	const key_type& get_key(const_reference value)const{
		return m_key_of_value(value);
	}
	
	const key_type& get_key(const_iterator pos)const{
		//check pos.cur if pos.cur == nullptr throw exception
		return pos.cur->value;
	}
	
	reference get_value(iterator pos){
		// check pos.cur if pos.cur == nullptr throw exception
		return pos.cur->value;
	}
	
	const_reference get_value(const_iterator pos)const{
		//check pos.cur if pos.cur == nullptr throw exception
		return pos.cur->value;
	}
	
	void swap(self &s){
		if(this != &s){
			link_type tmp_head = m_head;
			m_head = s.m_head;
			s.m_head = tmp_head;
			
			tmp_head = m_tail;
			m_tail = s.m_tail;
			s.m_tail = tmp_head;
			
			size_type tmp_size = m_size;
			m_size = s.m_size;
			s.m_size = tmp_size;
			
			tmp_size = m_level;
			m_level = s.m_level;
			s.m_level = tmp_size;
		}
	}
	
	reference operator [] (size_type n){
		return at(n);
	}
	
	const_reference operator [] (size_type n)const{
		return at(n);
	}
	
	bool operator == (const self &s)const{
		if(this != &s){
			if(m_size == s.m_size){
				link_type x, y;
				x = m_head->array[0].forward;
				y = s.m_head->array[0].forward;
				while(x){
					if(m_key_compare(
						m_key_of_value(x->value),
						m_key_of_value(y->value) )){
						return false;
					}else{
						if(m_key_compare(
							m_key_of_value(y->value),
							m_key_of_value(x->value) )){
							return false;
						}else{
							x = x->array[0].forward;
							y = y->array[0].forward;
						}
					}
					
				}
				return true;
			}else{
				return false;
			}
		}
		return true;
		
	}
	
	bool operator != (const self &s)const{
		return !((*this) == s);
	}
	
	bool operator < (const self &s)const{
		if(this != &s){
			link_type x, y;
			size_type i, lev;
			x = m_head->array[0].forward;
			y = s.m_head->array[0].forward;
			i = 0;
			lev = (m_size < s.m_size) ? m_size : s.m_size;
			while(i < lev){
				++i;
				if(m_key_compare(
					m_key_of_value(x->value),
					m_key_of_value(y->value) )){
					return true;	
				}else{
					if(m_key_compare(
						m_key_of_value(y->value),
						m_key_of_value(x->value) )){
						return false;	
					}else{
						x = x->array[0].forward;
						y = y->array[0].forward;
					}
				}
			}
			return m_size < s.m_size;
		}
		return false;
	}

	bool operator >= (const self &s)const{
		return !((*this) < s);
	}

	bool operator > (const self &s)const{
		return s < (*this);
	}

	bool operator <= (const self &s)const{
		return !(s < (*this));
	}
	
};


template<class Key, class Value, 
class KeyOfValue, class KeyCompare, class alloc>
inline void swap(
skiplist<Key, Value, KeyOfValue, KeyCompare, alloc> &a,
skiplist<Key, Value, KeyOfValue, KeyCompare, alloc> &b){
	a.swap(b);
}



}
}
}

#endif
