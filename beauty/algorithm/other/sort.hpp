
#ifndef beauty__algorithm__other___sort_hpp
#define beauty__algorithm__other___sort_hpp

#include<./beauty/algorithm/algorithmbase/iter_swap.hpp>
#include<./beauty/algorithm/algorithmbase/copy_backward.hpp>
#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#include<./beauty/algorithm/other/partial_sort.hpp>
#include<./beauty/iterator/function/value_type.hpp>


namespace beauty{namespace algorithm{namespace other{
	
static const unsigned int threshold = 16;

template<class RandomAccessIter, class T>
inline void __unguarded_linear_insert(RandomAccessIter last,
T value){
	RandomAccessIter next = last;
	--next;
	while(value < *next){
		*last = *next;
		last = next;
		--next;
	}
	*last = value;
}
template<class RandomAccessIter, class T>
inline void __linear_insert(RandomAccessIter first,
RandomAccessIter last, T *){
	T value = *last;
	if(value < *first){
		beauty::algorithm::algorithmbase::
		copy_backward(first, last, last + 1);
		
		*first = value;
	}else{
		beauty::algorithm::other::
		__unguarded_linear_insert(last, value);
	}
}
template<class RandomAccessIter>
void __insertion_sort(RandomAccessIter first, RandomAccessIter last){
	if(first == last)return ;
	typedef typename beauty::iterator::iterator_traits::
	iterator_traits<RandomAccessIter>::value_type value_type;
	
	for(RandomAccessIter i = first + 1; i != last; ++i){
		beauty::algorithm::other::
		__linear_insert(first, i, reinterpret_cast<value_type*>(0));
	}
}

template<class RandomAccessIter, class T, class Compare>
inline void __unguarded_linear_insert(RandomAccessIter last,
T value, Compare comp){
	RandomAccessIter next = last;
	--next;
	while(comp(value, *next)){
		*last = *next;
		last = next;
		--next;
	}
	*last = value;
}
template<class RandomAccessIter, class T, class Compare>
inline void __linear_insert(RandomAccessIter first,
RandomAccessIter last, Compare comp, T *){
	T value = *last;
	
	if(comp(value, *first)){
		beauty::algorithm::algorithmbase::
		copy_backward(first, last, last + 1);
		
		*first = value;
	}else{
		beauty::algorithm::other::
		__unguarded_linear_insert(last, value, comp);
	}
}
template<class RandomAccessIter, class Compare>
void __insertion_sort(RandomAccessIter first, RandomAccessIter last,
Compare comp){
	if(first == last)return ;
	typedef typename beauty::iterator::iterator_traits::
	iterator_traits<RandomAccessIter>::value_type value_type;
	
	for(RandomAccessIter i = first + 1; i != last; ++i){
		
		beauty::algorithm::other::
		__linear_insert(first, i, comp, reinterpret_cast<value_type*>(0));
	}
}

template<class T>
inline const T& __median(const T &a, const T &b, const T &c){
	if(a < b){
		if(b < c){
			return b;
		}else{
			if(a < c){
				return c;
			}else{
				return a;
			}
		}
	}else{
		if(a < c){
			return a;
		}else{
			if(b < c){
				return c;
			}else{
				return b;
			}
		}
	}
}
template<class T, class Compare>
inline const T& __median(const T &a, const T &b, 
const T &c, Compare comp){
	if(comp(a, b)){
		if(comp(b, c)){
			return b;
		}else{
			if(comp(a, c)){
				return c;
			}else{
				return a;
			}
		}
	}else{
		if(comp(a, c)){
			return a;
		}else{
			if(comp(b, c)){
				return c;
			}else{
				return b;
			}
		}
	}
}
template<class RandomAccessIter, class T>
RandomAccessIter __unguarded_partition(RandomAccessIter first,
RandomAccessIter last, T pivot){
	while(1){
		while(*first < pivot){
			++first;
		}
		--last;
		while(pivot < *last){
			--last;
		}
		if(!(first < last))return first;
		beauty::algorithm::algorithmbase::iter_swap(first, last);
		++first;
	}
}
template<class RandomAccessIter, class T, class Compare>
RandomAccessIter __unguarded_partition(RandomAccessIter first,
RandomAccessIter last, T pivot, Compare comp){
	while(1){
		while(comp(*first, pivot)){
			++first;
		}
		--last;
		while(comp(pivot, *last)){
			--last;
		}
		if(!(first < last))return first;
		beauty::algorithm::algorithmbase::iter_swap(first, last);
		++first;
	}
}
template<class Size>
inline Size __lg(Size n){
	Size k;
	for(k = 0; n > 1; n >>= 1){
		++k;
	}
	return k;
}

template<class RandomAccessIter, class T, class Size>
inline void __introsort_loop(RandomAccessIter first,
RandomAccessIter last, T*, Size depth_limit){
	while(last - first > threshold){
		if(depth_limit == 0){
			beauty::algorithm::other::			
			partial_sort(first, last, last);
			
			return ;
		}
		--depth_limit;
		RandomAccessIter cut = 
		beauty::algorithm::other::
		__unguarded_partition(
		first, last, 
		
		T(beauty::algorithm::other::__median(*first,
		*(first + (last - first)/2), 
		*(last - 1) ) ));
		
		beauty::algorithm::other::
		__introsort_loop(cut, last, reinterpret_cast<T*>(0), depth_limit);
		last = cut;
	}
}
template<class RandomAccessIter, class T, class Size,
class Compare>
inline void __introsort_loop(RandomAccessIter first,
RandomAccessIter last, T*, Size depth_limit, Compare comp){
	while(last - first > threshold){
		if(depth_limit == 0){
			
			beauty::algorithm::other::
			partial_sort(first, last, last, comp);
			
			return ;
		}
		--depth_limit;
		RandomAccessIter cut = beauty::algorithm::other::
		__unguarded_partition(
		first, last, T(beauty::algorithm::other::__median(*first,
		*(first + (last - first)/2), 
		*(last - 1) ) ), comp);
		
		beauty::algorithm::other::
		__introsort_loop(cut, last, (T*)0, depth_limit, comp);
		
		last = cut;
	}
}
template<class RandomAccessIter>
inline void __unguarded_insertion_sort(RandomAccessIter first,
RandomAccessIter last){
	typedef typename beauty::iterator::iterator_traits::
	iterator_traits<RandomAccessIter>::value_type Type;
	
	for(RandomAccessIter i = first; i != last; ++i){
		
		beauty::algorithm::other::
		__unguarded_linear_insert(i, Type(*i));
	}
}
template<class RandomAccessIter>
inline void __final_insertion_sort(RandomAccessIter first,
RandomAccessIter last){
	if(last - first > threshold){
		beauty::algorithm::other::
		__insertion_sort(first, first + threshold);
		
		beauty::algorithm::other::
		__unguarded_insertion_sort(first + threshold, last);
		
	}else{
		beauty::algorithm::other::
		__insertion_sort(first, last);
	}
}
template<class RandomAccessIter, class Compare>
inline void __unguarded_insertion_sort(RandomAccessIter first,
RandomAccessIter last, Compare comp){
	typedef typename beauty::iterator::iterator_traits::
	iterator_traits<RandomAccessIter>::value_type Type;
	
	for(RandomAccessIter i = first; i != last; ++i){
		beauty::algorithm::other::
		__unguarded_linear_insert(i, Type(*i), comp);
	}
}
template<class RandomAccessIter, class Compare>
inline void __final_insertion_sort(RandomAccessIter first,
RandomAccessIter last, Compare comp){
	if(last - first > threshold){
		beauty::algorithm::other::
		__insertion_sort(first, first + threshold, comp);
		beauty::algorithm::other::
		__unguarded_insertion_sort(first + threshold, last, comp);
	}else{
		beauty::algorithm::other::
		__insertion_sort(first, last, comp);
	}
}
template<class RandomAccessIter>
inline void sort(RandomAccessIter first, RandomAccessIter last){
	if(first != last){
		beauty::algorithm::other::
		__introsort_loop(first, last,
		beauty::iterator::function::value_type(first),
		beauty::algorithm::other::__lg((last - first)*2));
		
		beauty::algorithm::other::
		__final_insertion_sort(first, last);
	}
}
template<class RandomAccessIter, class Compare>
inline void sort(RandomAccessIter first, RandomAccessIter last,
Compare comp){
	if(first != last){
		beauty::algorithm::other::
		__introsort_loop(first, last,
		beauty::iterator::function::value_type(first),
		beauty::algorithm::other::__lg((last - first)*2), comp);

		beauty::algorithm::other::
		__final_insertion_sort(first, last, comp);
	}
}

}
}
}
#endif
