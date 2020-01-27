
#ifndef beauty__container__queue___deque_hpp
#define beauty__container__queue___deque_hpp

#include<./beauty/config.hpp>
#include<./beauty/iterator/function/distance.hpp>
#include<./beauty/container/queue/deque_detail/deque_iterator.hpp>
#include<./beauty/allocator/simple_allocator.hpp>
#include<./beauty/algorithm/algorithmbase/max.hpp>
#include<./beauty/algorithm/algorithmbase/copy.hpp>
#include<./beauty/algorithm/algorithmbase/copy_backward.hpp>
#include<./beauty/allocator/function/uninitialized_fill.hpp>
#include<./beauty/allocator/function/construct.hpp>
#include<./beauty/allocator/function/destroy.hpp>

namespace beauty{namespace container{namespace queue{

template<class T, class alloc = beauty::allocator::allocator,
	beauty::size_t BufSiz = 0>
class deque{	
	public:
	typedef T                              			value_type;
	typedef value_type*                                pointer;
	typedef const value_type*                    const_pointer;
	typedef value_type&                              reference;
	typedef const value_type&                  const_reference;
	typedef beauty::container::queue::deque_detail::
		deque_iterator<T, T&, T*, BufSiz>		      iterator;
	typedef beauty::container::queue::deque_detail::
		deque_iterator<T, const T&, const T*, BufSiz>
		                                        const_iterator;
	typedef beauty::size_t                           size_type;
	typedef beauty::ptrdiff_t                  difference_type;
	
	
	protected:
	typedef pointer*                               map_pointer;
	typedef beauty::allocator::simple_allocator<T,alloc>
 												data_allocator;
 	typedef beauty::allocator::simple_allocator<pointer,alloc>
		                                         map_allocator;
  	
	                                                  

	iterator start;
	iterator finish;
	map_pointer map;
	size_type map_size;
	static const size_type init_map_size;
	
	
	protected:	
	void create_map_and_nodes(size_type num_elements){
		size_type buffer = iterator::buffer_size();
		size_type num_nodes = num_elements/buffer + 1;
		map_size = beauty::algorithm::algorithmbase::
			max(init_map_size, num_nodes + 2);
		
		map = map_allocator::allocate(map_size);
		map_pointer nstart = map + (map_size - num_nodes)/2;
		map_pointer nfinish = nstart + num_nodes;
		map_pointer cur;
		
		for(cur = nstart; cur < nfinish; ++cur){
			*cur = data_allocator::allocate(buffer);
		}
		
		start.set_node(nstart);
		finish.set_node(nfinish - 1);
		start.cur = start.first;
		finish.cur = finish.first + num_elements%buffer;
	}
	
	void fill_initialize(size_type n, const value_type &value){
		create_map_and_nodes(n);
		map_pointer cur;
		size_type buffer = iterator::buffer_size();
		
		for(cur = start.node; cur < finish.node; ++cur){
			beauty::allocator::function::
				uninitialized_fill(*cur, (*cur) + buffer, value);
		}
		beauty::allocator::function::
			uninitialized_fill(finish.first, finish.cur, value);
		
	}
	
	void fill_initialize(size_type n, iterator first, iterator last){
		create_map_and_nodes(n);
		iterator m_first = start;
		while(first != last){
			beauty::allocator::function::
				construct(m_first.cur, *first);
			++first;
			++m_first;
		}
	}
	
	void initialize(size_type Map_size){
		
		size_type buffer = iterator::buffer_size();
		map_size = beauty::algorithm::algorithmbase::
			max(Map_size, init_map_size);
			
		map = map_allocator::allocate(map_size);
		start.node = map + map_size/2;
		*start.node = data_allocator::allocate(buffer);
		
		start.first = *start.node;
		start.last = start.first + buffer;
		start.cur = start.first + buffer/2;
		finish = start;
	}
	
	
	void reallocate_map(size_type nodes_to_add,
				bool add_at_front){
		size_type old_num_nodes = finish.node - start.node + 1;
		size_type new_num_nodes = old_num_nodes + nodes_to_add;
		
		map_pointer new_nstart;
		if(map_size > 2*new_num_nodes){
			new_nstart = map + (map_size - new_num_nodes)/2
							+ (add_at_front ? nodes_to_add : 0);
			if(new_nstart < start.node){
				beauty::algorithm::algorithmbase::
					copy(start.node, finish.node + 1, new_nstart);
			}else{
				beauty::algorithm::algorithmbase::
					copy_backward(start.node, finish.node + 1,
						new_nstart + old_num_nodes);
			}
		}else{
			size_type new_map_size = map_size + 2 +
				beauty::algorithm::algorithmbase::
					max(map_size, nodes_to_add);
			map_pointer new_map = map_allocator::allocate(new_map_size);
			new_nstart = new_map + (new_map_size - new_num_nodes)/2
							+ (add_at_front ? nodes_to_add : 0);
							
			beauty::algorithm::algorithmbase::
				copy(start.node, finish.node + 1, new_nstart);
				
			map_allocator::deallocate(map, map_size);
			map = new_nstart;
			map_size = new_map_size;
			
		}	
		
		start.set_node(new_nstart);
		finish.set_node(new_nstart + old_num_nodes - 1);		
	}
	
	void reverse_map_at_back(size_type nodes_to_add = 1){
		if(nodes_to_add + 1 > map_size - (finish.node - map)){
			reallocate_map(nodes_to_add, false);
		}
	}
	
	void push_back_aux(const value_type &value){
		value_type t_copy = value;
		reverse_map_at_back();
		*(finish.node + 1) = data_allocator::
			allocate(iterator::buffer_size());
		
		beauty::allocator::function::
			construct(finish.cur, t_copy);
		
		finish.set_node(finish.node + 1);
		finish.cur = finish.first;
	}
	
	void reverse_map_at_front(size_type n = 1){
		if(n > start.node - map){
			reallocate_map(n, true);
		}
	}
	
	void push_front_aux(const value_type &value){
		
		value_type t_copy = value;
		reverse_map_at_front();
		*(start.node - 1) = data_allocator::
			allocate(iterator::buffer_size());
			
		start.set_node(start.node - 1);
		start.cur = start.last - 1;
		
		beauty::allocator::function::
			construct(start.cur, t_copy);		
	}
	
	void pop_back_aux(){
		data_allocator::
			deallocate(*finish.node, iterator::buffer_size());
		
		finish.set_node(finish.node - 1);
		finish.cur = finish.last - 1;
		
		beauty::allocator::function::
			destroy(finish.cur);
	}
	
	void pop_front_aux(){
		beauty::allocator::function::
			destroy(start.cur);
		
		data_allocator::
			deallocate(*start.node, iterator::buffer_size());
		
		start.set_node(start.node + 1);
		start.cur = start.first;
	}
	
	void insert_aux(iterator pos, const value_type &x){
		difference_type index = pos - start;
		value_type x_copy = x;
		if(index < (size() - index)/2){
			push_front(*start);
			beauty::algorithm::algorithmbase::
				copy(start + 2, pos, start + 1);
		}else{
			push_back(*(finish - 1));
			beauty::algorithm::algorithmbase::
				copy_backward(pos, finish - 2, finish - 1);
		}
		
		*pos = x_copy;
		return pos;
	}
	
	
	
	public:
	deque(){
		initialize(init_map_size);
	}
	
	deque(size_type	Map_size){
		initialize(Map_size);
	}
	
	deque(size_type n, const value_type &value):
		start(), finish(), map(0), map_size(0){
		fill_initialize(n, value);
	}
	deque(iterator first, iterator last){
		size_type n = beauty::iterator::function::distance(first, last);
		fill_initialize(n, first, last);
	}
	
	~deque(){
		clear();
		data_allocator::
			deallocate(start.first, iterator::buffer_size());
		
		map_allocator::deallocate(map, map_size);
		map = nullptr;
		map_size = 0;
	}
	
	void push_back(const value_type &value){
		if(finish.cur != finish.last - 1){
			beauty::allocator::function::
				construct(finish.cur, value);
			++finish.cur;
		}else{
			push_back_aux(value);
		}
	}
	
	void push_front(const value_type &value){
		if(start.cur != start.first){
			--start.cur;
			
			beauty::allocator::function::
				construct(start.cur, value);

		}else{
			push_front_aux(value);
		}
	}
	
	void pop_back(){
		if(finish.cur != finish.first){
			--finish.cur;
			beauty::allocator::function::
				destroy(finish.cur);
		}else{
			pop_back_aux();
		}
	}
	
	void pop_front(){
		if(start.cur != start.last - 1){
			beauty::allocator::function::
				destroy(start.cur);
			++start.cur;
		}else{
			pop_front_aux();
		}
	}
	
	void clear(){
		size_type buffer = iterator::buffer_size();
		map_pointer p;
		for(p = start.node + 1; p < finish.node; ++p){
			beauty::allocator::function::
				destroy(*p, *p + buffer);
			data_allocator::deallocate(*p, buffer);
		}
		
		if(start.node != finish.node){
			beauty::allocator::function::
				destroy(start.cur, start.last);
			
			beauty::allocator::function::
				destroy(finish.first, finish.cur);
			
			data_allocator::deallocate(finish.first, buffer);
			
		}else{
			beauty::allocator::function::
				destroy(start.cur, finish.cur);
		}
		finish = start;
	}
	
	iterator erase(iterator pos){
		iterator next = pos;
		++next;
		difference_type index = next - start;
		if(index < (size()>>1)){
			beauty::algorithm::algorithmbase::
				copy_backward(start, pos, next);
			
			pop_front();
		}else{
			beauty::algorithm::algorithmbase::
				copy(next, finish, pos);
				
			pop_back();
		}
		return start + index;
	}
	
	iterator erase(iterator first, iterator last){
		if(first == start && last == finish){
			clear();
			return finish;
		}else{
			difference_type n = last - first;
			difference_type elems_before = first - start;
			size_type buffer = iterator::buffer_size();
			
			if(elems_before < (size() - n)/2){
				beauty::algorithm::algorithmbase::
					copy_backward(start, first, last);
				
				iterator new_start = start + n;
				beauty::allocator::function::
					destroy(start, new_start);
				map_pointer p;
				for(p = start.node; p < new_start; ++p){
					data_allocator::deallocate(p, buffer);
				}
				start = new_start;
			}else{
				beauty::algorithm::algorithmbase::
					copy(last, finish, first);
				
				iterator new_finish = finish - n;
				beauty::allocator::function::
					destroy(new_finish, finish);
				
				map_pointer p;
				for(p = new_finish.node + 1; p <= finish.node; ++p){
					data_allocator::deallocate(p, buffer);
				}
				
				finish = new_finish;
				
			}
			return start + elems_before;
		}
	}
	
	iterator insert(iterator pos, const value_type &x){
		if(pos.cur == start.cur){
			push_front(x);
			return start;
		}else{
			if(pos.cur == finish.cur){				
				push_back(x);
				iterator tmp = finish;
				--tmp;
				return tmp;
			}else{
				return insert_aux(pos, x);
			}
		}
	}
	
	
	iterator begin(){
		return start;
	}
	
	const_iterator begin()const{
		return start;
	}
	
	iterator end(){
		return finish;
	}
	
	const_iterator end()const{
		return finish;
	}
	
	reference operator [] (size_type n){
		return start[n];
	}
	
	const_reference operator [] (size_type n)const{
		return start[n];
	}
	
	reference front(){
		return *start;
	}
	
	const_reference front()const{
		return *start;
	}
	
	reference back(){
		iterator tmp = finish;
		--tmp;
		return *tmp;
	}
	
	const_reference back()const{
		iterator tmp = finish;
		--tmp;
		return *tmp;
	}
	
	size_type size()const{
		return finish - start;
	}
	
	size_type max_size()const{
		return size_type(-1);
	}
	
	bool is_empty()const{
		return start == finish;
	}
	
	bool empty()const{
		return start == finish;
	}
	
	
};
template<class T, class alloc, beauty::size_t BufSiz>
const beauty::size_t deque<T,alloc,BufSiz>::init_map_size = 8;

}
}
}
#endif
