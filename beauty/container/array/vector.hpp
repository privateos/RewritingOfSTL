
#ifndef beauty__container__array___vector_hpp
#define beauty__container__array___vector_hpp

#include<./beauty/config.hpp>
#include<./beauty/types.hpp>
#include<./beauty/allocator/simple_allocator.hpp>
#include<./beauty/allocator/function/uninitialized_fill_n.hpp>
#include<./beauty/allocator/function/construct.hpp>
#include<./beauty/allocator/function/destroy.hpp>
#include<./beauty/allocator/function/uninitialized_copy.hpp>
#include<./beauty/algorithm/algorithmbase/copy.hpp>
#include<./beauty/algorithm/algorithmbase/copy_backward.hpp>
#include<./beauty/algorithm/algorithmbase/fill.hpp>
#include<./beauty/algorithm/algorithmbase/fill_n.hpp>

namespace beauty{namespace container{namespace array{

template<class T, class alloc = beauty::allocator::allocator>
class vector{
	public:
	typedef T*            						           iterator;
	typedef const T*                                 const_iterator;
	typedef T         							       	 value_type;
	typedef value_type&       					          reference;
	typedef const value_type&                       const_reference;
	typedef value_type*   					                pointer;
	typedef const value_type*                         const_pointer;
	typedef beauty::ptrdiff_t  						difference_type;
	typedef beauty::size_t           					  size_type;
	
	protected:	
	typedef beauty::container::array::vector<T,alloc>          self;
	typedef beauty::allocator::simple_allocator<T, alloc> allocator;
	iterator start;// value start
	iterator finish;// value end
	iterator end_of_storage;//memory end
	
	protected:
	iterator allocate_and_fill(size_type n, const T &x){
		iterator result = allocator::allocate(n);
		beauty::allocator::function::uninitialized_fill_n(result, n, x);
		return result;
	}
	
	void insert_aux(iterator position, const T &value){
		if(finish != end_of_storage){
			beauty::allocator::function::
				construct(finish, *(finish - 1));
				
			++finish;
			T x_copy = value;
			
			beauty::algorithm::algorithmbase::
				copy_backward(position, finish - 2, finish - 1);
				
			*position = x_copy;	
					
		}else{
			const size_type old_size = 
				static_cast<size_type>(finish - start);
				
			const size_type len = ((old_size == 0) ? 1 : (2*old_size));
			
			iterator new_start = allocator::allocate(len);
			iterator new_finish = new_start;
			
			new_finish = beauty::allocator::function::
				uninitialized_copy(start, position, new_finish);
				
			beauty::allocator::function::
				construct(new_finish, value);
				
			++new_finish;
			new_finish = beauty::allocator::function::
				uninitialized_copy(position, finish, new_finish);
			
			beauty::allocator::function::
				destroy(start, finish);
				
			deallocate();
			
			start = new_start;
			finish = new_finish;
			end_of_storage = start + len;
		}
	}
	
	void deallocate(){
		if(start){
			allocator::deallocate(start, end_of_storage - start);
			start = nullptr;
			finish = nullptr;
			end_of_storage = nullptr;
		}
	}
	
	void fill_initialize(size_type n, const T &value){
		start = allocate_and_fill(n, value);
		finish = start + n;
		end_of_storage = finish;
	}
	
	
	
	public:
	
	vector():start(0), finish(0),end_of_storage(0){}
	
	explicit vector(size_type n){
		fill_initialize(n, T());
	}
	
	vector(size_type n, const T &value){
		fill_initialize(n, value);
	}
	
	vector(int n, const T &value){
		fill_initialize(n, value);
	}
	
	vector(long n, const T &value){
		fill_initialize(n, value);
	}
	
	~vector(){
		beauty::allocator::function::destroy(start, finish);
		deallocate();
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
	

	size_type size()const{
		return static_cast<size_type>(finish - start);
	}
	
	size_type capacity()const{
		return static_cast<size_type>(end_of_storage - start);
	}
	
	bool empty()const{
		return start == finish;
	}
	
	bool is_empty()const{
		return start == finish;
	}
	
	reference operator[](size_type n){
		return *(start + n);
	}


	const_reference operator[](size_type n)const{
		return *(start + n);
	}
	
	
	reference front(){
		return *start;
	}

	const_reference front()const{
		return *start;
	}
	
	reference back(){
		return *(finish - 1);
	}

	const_reference back()const{
		return *(finish - 1);
	}

	void push_back(const T &x){
		if(finish != end_of_storage){
			beauty::allocator::function::construct(finish, x);
			++finish;
		}else{
			insert_aux(finish, x);
		}
	}
	
	void pop_back(){
		--finish;
		beauty::allocator::function::destroy(finish);
	}
	
	iterator erase(iterator position){
		if(position + 1 != finish){
			beauty::algorithm::algorithmbase::copy(position + 1, finish, position);
		} 
		--finish;
		beauty::allocator::function::destroy(finish);
		return position;
	}

	const_iterator erase(const_iterator position){
		if(position + 1 != finish){
			beauty::algorithm::algorithmbase::copy(position + 1, finish, position);
		}
		--finish;
		beauty::allocator::function::destroy(finish);
		return position;
	}
	
	iterator erase(iterator first, iterator last){
		iterator i = beauty::algorithm::algorithmbase::
			copy(last, finish, first);
		
		beauty::allocator::function::
			destroy(i, finish);
		
		finish -= last - first;
		return first;
	}

	const_iterator erase(const_iterator first, const_iterator last){
		iterator i = beauty::algorithm::algorithmbase::
			copy(last, finish, first);

		beauty::allocator::function::
			destroy(i, finish);

		finish -= last - first;
		return first;
	}
	
	iterator insert(iterator position, size_type n, const T &x){
		if(n != 0){
			if(static_cast<size_type>(end_of_storage - finish)
		    	>= n){
	    		T x_copy = x;
	    		const size_type elems_after = 
					static_cast<size_type>(finish - position);
				
				iterator old_finish = finish;
				
				if(elems_after	> n){
					finish = beauty::allocator::function::
						uninitialized_copy(finish - n, finish, finish);
						
					finish += n;
					beauty::algorithm::algorithmbase::
						copy_backward(position, old_finish - n, old_finish);
					
					beauty::algorithm::algorithmbase::
						fill(position, position + n, x_copy);
				}else{
					finish = beauty::allocator::function::
						uninitialized_copy(position, finish, finish + 
							(elems_after - n));
					
					beauty::allocator::function::
						uninitialized_fill_n(old_finish, 
							(elems_after - n), x_copy);
					
					beauty::algorithm::algorithmbase::
						fill(position, old_finish, x_copy);
					
				}	
 		    }else{
    		 	const size_type old_size = finish - start;
    		 	const size_type new_size = old_size + 
    		 		((old_size > n) ? old_size : n);
   		 		
   		 		iterator new_start = allocator::allocate(new_size);
   		 		iterator new_finish = start;
   		 		new_finish = beauty::allocator::function::
					uninitialized_copy(start, position, new_finish);
				
				new_finish = beauty::allocator::function::
					uninitialized_fill_n(new_finish, n, x);
				
				new_finish = beauty::allocator::function::
					uninitialized_copy(position, finish, new_finish);
				
				beauty::allocator::function::
					destroy(start, finish);
				
				deallocate();
				start = new_start;
				finish = new_finish;
				end_of_storage = new_start + new_size;
    		 }
		}
	}

	const_iterator insert(const_iterator position, size_type n, const T &x){
		if(n != 0){
			if(static_cast<size_type>(end_of_storage - finish)
		    	>= n){
	    		T x_copy = x;
	    		const size_type elems_after =
					static_cast<size_type>(finish - position);

				iterator old_finish = finish;

				if(elems_after	> n){
					finish = beauty::allocator::function::
						uninitialized_copy(finish - n, finish, finish);

					finish += n;
					beauty::algorithm::algorithmbase::
						copy_backward(position, old_finish - n, old_finish);

					beauty::algorithm::algorithmbase::
						fill(position, position + n, x_copy);
				}else{
					finish = beauty::allocator::function::
						uninitialized_copy(position, finish, finish +
							(elems_after - n));

					beauty::allocator::function::
						uninitialized_fill_n(old_finish,
							(elems_after - n), x_copy);

					beauty::algorithm::algorithmbase::
						fill(position, old_finish, x_copy);

				}
 		    }else{
    		 	const size_type old_size = finish - start;
    		 	const size_type new_size = old_size +
    		 		((old_size > n) ? old_size : n);

   		 		iterator new_start = allocator::allocate(new_size);
   		 		iterator new_finish = start;
   		 		new_finish = beauty::allocator::function::
					uninitialized_copy(start, position, new_finish);

				new_finish = beauty::allocator::function::
					uninitialized_fill_n(new_finish, n, x);

				new_finish = beauty::allocator::function::
					uninitialized_copy(position, finish, new_finish);

				beauty::allocator::function::
					destroy(start, finish);

				deallocate();
				start = new_start;
				finish = new_finish;
				end_of_storage = new_start + new_size;
    		 }
		}
	}

	
	void resize(size_type new_size, const T &x){
		if(new_size < finish - start){
			erase(start + new_size, finish);
		}else{
			insert(finish, new_size - (finish - start), x);
		}
	}
	
	void resize(size_type new_size){
		resize(new_size, T());
	}
	
	void clear(){
		erase(start, finish);
	}
	
	void swap(self &x){
		iterator tmp = start;
		start = x.start;
		x.start = tmp;
		
		tmp = finish;
		finish = x.finish;
		x.finish = tmp;
		
		tmp = end_of_storage;
		end_of_storage = x.end_of_storage;
		x.end_of_storage = tmp;
	}
	
};

}
}
}
#endif
