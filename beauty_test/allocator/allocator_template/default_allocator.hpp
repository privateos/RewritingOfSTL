
#ifndef include___beauty___types_hpp
	#define include___beauty___types_hpp
	#include<./beauty/types.hpp>
#endif
#ifndef include___beauty__allocator__allocator_template___malloc_allocator_hpp
	#define include___beauty__allocator__allocator_template___malloc_allocator_hpp
	#include<./beauty/allocator/allocator_template/malloc_allocator.hpp>
#endif
#ifndef include___beauty___congfig_hpp
	#define include___beauty___congfig_hpp
	#include<./beauty/config.hpp>
#endif
#ifndef include___std___cstdlib
	#define include___std___malloc_h
	#include<cstdlib>
#endif
#ifndef include___std___cstring
	#define include___std___cstring
	#include<cstring>
#endif

namespace beauty{namespace allocator{namespace allocator_template{


enum{ALIGN = 8};
enum{MAX_BYTES = 128};
enum{FREELISTS = MAX_BYTES/ALIGN};

template<bool threads, int inst>
class default_allocator{
	private:
		typedef beauty::size_t size_t;
		typedef beauty::allocator::allocator_template::malloc_alloc malloc_alloc;
		
		union obj{
			union obj *free_list_link;
			char client_data[1];
		};
		
		static obj * volatile free_list[FREELISTS];
		static char *start_free;
		static char *end_free;
		static size_t heap_size;
		
		
		static size_t round_up(size_t bytes){
			return (   (bytes + reinterpret_cast<size_t>(ALIGN) - 1)
			&(~ (reinterpret_cast<size_t>(ALIGN) - 1) )    );
		}
		
		static size_t freelist_index(size_t bytes){
			return (bytes + reinterpret_cast<size_t>(ALIGN) - 1)
					/reinterpret_cast<size_t>(ALIGN) - 1;
		}
		
		static char* chunk_alloc(size_t size, int &nobjs){
			char *result;
			size_t total_bytes = size*nobjs;
			size_t bytes_left = end_free - start_free;
			
			if(bytes_left >= total_bytes){
				result = start_free;
				start_free += total_bytes;
				return result;
			}else{
				if(bytes_left >= size){
					nobjs = bytes_left/size;
					total_bytes = nobjs*size;
					result = start_free;
					start_free += total_bytes;
					return result;
				}else{
					size_t bytes_to_get = 2*total_bytes + round_up(heap_size>>4);
					if(bytes_left > 0){
						obj * volatile *my_free_list = free_list + freelist_index(bytes_left);
						(reinterpret_cast<obj*>(start_free))->free_list_link =
							*my_free_list;
						*my_free_list = reinterpret_cast<obj*>(start_free);
					}
					start_free = reinterpret_cast<char*>(std::malloc(bytes_to_get));
					if(start_free == 0){
						int i;
						obj * volatile *my_free_list, *p;
						for(i = size; i <= reinterpret_cast<size_t>(MAX_BYTES); i += size){
							my_free_list = free_list + freelist_index(i);
							p = *my_free_list;
							if(p != 0){
								*my_free_list = p->free_list_link;
								start_free = reinterpret_cast<char*>(p);
								end_free = start_free + i;
								return chunk_alloc(size, nobjs);
							}
						}
						end_free = 0;
						start_free =
							reinterpret_cast<char*>(malloc_alloc::allocate(bytes_to_get));
							//need throw Exception
					}
					heap_size += bytes_to_get;
					end_free = start_free + bytes_to_get;
					return chunk_alloc(size, nobjs);

				}
			}
		}
		static void* refill(size_t n){
			int nobjs = 20;
			char *chunk = chunk_alloc(n,  nobjs);
			if(nobjs == 1){
				return reinterpret_cast<void*>(chunk);
			}
			
			obj * volatile *my_free_list;
			obj *result;
			obj *current, *next;
			int i;
			
			my_free_list = free_list + freelist_index(n);
			result = reinterpret_cast<obj*>(chunk);
			
			current = reinterpret_cast<obj*>(chunk + n);
			
			--nobjs;
			*my_free_list = current;
			for(i = 1; i < nobjs; ++i){
				next = reinterpret_cast<obj*>(reinterpret_cast<char*>(current) + n);
				current->free_list_link = next;
				current = next;
			}
			current->free_list_link = nullptr;
			return reinterpret_cast<void*>(result);
		}
		
		
		
	public:
		static void* allocate(size_t n){
			obj * volatile * my_free_list;
			obj *result;
			if(n > reinterpret_cast<size_t>(MAX_BYTES)){
				return malloc_alloc::allocate(n);
			}
			
			my_free_list = free_list + freelist_index(n);
			result = *my_free_list;
			if(result == 0){
				void *r = refill(round_up(n));
				return r;
			}
			
			*my_free_list = result->free_list_link;
			
			return reinterpret_cast<void*>(result);
		}
		
		static void* reallocate(void *p, size_t old_size, size_t new_size){
			if(old_size > reinterpret_cast<size_t>(MAX_BYTES) &&
			  new_size > reinterpret_cast<size_t>(MAX_BYTES)){
			  	
				return malloc_alloc::reallocate(p, old_size, new_size);
			}
			if(old_size == new_size){
				return p;
			}
			int copy_size = old_size > new_size ? new_size : old_size;
			void *result = allocate(new_size);
			std::memcpy(result, p, copy_size);
			deallocate(p, old_size);
			return result;
			  
		}
		static void deallocate(void *p, size_t n){
			obj * volatile * my_free_list;
			obj *q = reinterpret_cast<obj*>(p);
			
			if(n > reinterpret_cast<size_t>(MAX_BYTES)){
				malloc_alloc::deallocate(p, n);
				return;
			}
			
			my_free_list = free_list + freelist_index(n);
			q->free_list_link = *my_free_list;
			*my_free_list = q;
		}
		
};

template<bool threads, int inst>
char* default_allocator<threads,inst>::start_free = 0;
template<bool threads, int inst>
char* default_allocator<threads,inst>::end_free = 0;
template<bool threads, int inst>
typename default_allocator<threads,inst>::size_t
default_allocator<threads,inst>::heap_size = 0;


template<bool threads, int inst>
typename default_allocator<threads,inst>::obj
* volatile default_allocator<threads,inst>::free_list[FREELISTS]={
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,};
	

typedef default_allocator<false,0> alloc;

}
}
}
