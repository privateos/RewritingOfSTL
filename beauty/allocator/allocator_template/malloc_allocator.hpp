
#ifndef beauty__allocator__allocator_template___malloc_allocator_hpp
#define beauty__allocator__allocator_template___malloc_allocator_hpp

#include<./beauty/types.hpp>
#include<./beauty/config.hpp>
#include<./beauty/header.hpp>


namespace beauty{namespace allocator{namespace allocator_template{

template<int inst>
class malloc_allocator{//oom : out of memory
	private:
		static void (*malloc_alloc_oom_handler)();
		
		
		static void* oom_malloc(beauty::size_t n)noexcept{
			
			void (*my_malloc_alloc_oom_handler)();
			void *result;
			
			for( ; ; ){
				my_malloc_alloc_oom_handler = malloc_alloc_oom_handler;
				if(my_malloc_alloc_oom_handler == 0){
					return static_cast<void*>(0);//
				}
				(*my_malloc_alloc_oom_handler)();
				result = std::malloc(n);
				if(result){
					return result;
				}
			}
		}
		
		static void* oom_realloc(void *p, beauty::size_t n)noexcept{
			
			void (*my_malloc_alloc_oom_handler)();
			void *result;
			for( ; ; ){
				my_malloc_alloc_oom_handler = malloc_alloc_oom_handler;
				
				if(my_malloc_alloc_oom_handler == 0){
					return 0;
				}
				(*my_malloc_alloc_oom_handler)();
				
				result = std::realloc(p, n);
				if(result){
					return result;
				}
			}
		}
		
		
	public:
		static void* allocate(beauty::size_t n){
			void *result = std::malloc(n);
			if(result == 0){
				result = oom_malloc(n);
			}
			return result;
		}
		static void deallocate(void *p, beauty::size_t){
			free(p);
		}
		static void* reallocate(void *p, beauty::size_t old_size, beauty::size_t new_size){
			void *result = std::realloc(p, new_size);
			if(result == 0){
				result = oom_realloc(p, new_size);
			}
			return result;
		}
		static void (*set_malloc_handler(void (*f)()))(){
			void (*old)() = malloc_alloc_oom_handler;
			malloc_alloc_oom_handler = f;
			return old;
		}

};

template<int inst>
void (*malloc_allocator<inst>::malloc_alloc_oom_handler)() = 0;

typedef malloc_allocator<0> malloc_alloc;

}
}
}
#endif
