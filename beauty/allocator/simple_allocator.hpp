
#ifndef beauty__allocator___simple_allocator_hpp
#define beauty__allocator___simple_allocator_hpp

#include<./beauty/allocator/allocator_template/default_allocator.hpp>
#include<./beauty/allocator/allocator_template/malloc_allocator.hpp>
#include<./beauty/types.hpp>


namespace beauty{namespace allocator{

typedef beauty::allocator::allocator_template::malloc_alloc allocator;


template<class T, class alloc = allocator>
class simple_allocator{
	public:
		static T* allocate(void){
			return reinterpret_cast<T*>(alloc::allocate(sizeof(T)));
		}
		static T* allocate(beauty::size_t n){
			return n == 0 ? reinterpret_cast<T*>(0) :
				reinterpret_cast<T*>(alloc::allocate(sizeof(T)*n));
		}
		static void deallocate(T *p){
			alloc::deallocate(p, sizeof(T));
		}
		static void deallocate(T *p, beauty::size_t n){
			if(n != 0){
				alloc::deallocate(p, sizeof(T)*n);
			}
		}
};

}
}
#endif
