
#ifndef beauty__algorithm__algorithmbase___fill_hpp
#define beauty__algorithm__algorithmbase___fill_hpp

#include<./beauty/header.hpp>


namespace beauty{namespace algorithm{namespace algorithmbase{



template<class ForwardIterator, class T>
inline void fill(ForwardIterator first, ForwardIterator last, const T &value){
	for( ; first != last; ++first){
		*first = value;
	}
}

inline void fill(unsigned char* __first, unsigned char* __last,
                 const unsigned char& __c) {
  unsigned char __tmp = __c;
  std::memset(__first, __tmp, __last - __first);
}

inline void fill(signed char* __first, signed char* __last,
                 const signed char& __c) {
  signed char __tmp = __c;
  std::memset(__first, static_cast<unsigned char>(__tmp), __last - __first);
}
inline void fill(char* __first, char* __last, const char& __c) {
  char __tmp = __c;
  std::memset(__first, static_cast<unsigned char>(__tmp), __last - __first);
}

}
}
}
#endif
