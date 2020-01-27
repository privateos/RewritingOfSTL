#ifndef include___beauty__container__pair___pair_hpp
	#define include___beauty__container__pair___pair_hpp
	#include<./beauty/container/pair/pair.hpp>
#endif

namespace beauty{namespace container{namespace pair{


template<class T1, class T2>
inline bool operator == (const beauty::container::pair::pair<T1,T2> &a,
						 const beauty::container::pair::pair<T1,T2> &b){
	return a.first == b.first && a.second == b.second;
}
template<class T1, class T2>
inline bool operator < (const beauty::container::pair::pair<T1,T2> &a,
					 const beauty::container::pair::pair<T1,T2> &b){
	return a.first < b.first ||
	(!(b.first < a.first) && a.second < b.second);
}
template<class T1, class T2>
inline bool operator != (const beauty::container::pair::pair<T1,T2> &a,
					 const beauty::container::pair::pair<T1,T2> &b){
	return !(a == b);
}
template<class T1, class T2>
inline bool operator >
	(const beauty::container::pair::pair<T1,T2> &a,
	 const beauty::container::pair::pair<T1,T2> &b){
	return b < a;
}
template<class T1, class T2>
inline bool operator >=
	(const beauty::container::pair::pair<T1,T2> &a,
	 const beauty::container::pair::pair<T1,T2> &b){
	return !(a < b);
}
template<class T1, class T2>
inline bool operator <=
	(const beauty::container::pair::pair<T1,T2> &a,
	 const beauty::container::pair::pair<T1,T2> &b){
	return !(a > b);
}


}
}
}
