
#ifndef include___beauty__allocator__allocator_template___malloc_allocator_hpp
	#define include___beauty__allocator__allocator_template___malloc_allocator_hpp
	#include<./beauty/allocator/allocator_template/malloc_allocator.hpp>
#endif
#ifndef include___beauty___types_hpp
	#define include___beauty___types_hpp
	#include<./beauty/types.hpp>
#endif

namespace beauty{namespace allocator{

template<class T, class alloc = beauty::allocator::allocator_template::malloc_alloc>
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
