/*
namespace beauty{namespace algorithm{namespace numeric{

template <class _InputIterator, class _Tp>inline
_Tp accumulate(_InputIterator __first, _InputIterator __last, _Tp __init)
{
  for ( ; __first != __last; ++__first)
    __init = __init + *__first;
  return __init;
}

template <class _InputIterator, class _Tp, class _BinaryOperation>inline
_Tp accumulate(_InputIterator __first, _InputIterator __last, _Tp __init,
               _BinaryOperation __binary_op)
{
  for ( ; __first != __last; ++__first)
    __init = __binary_op(__init, *__first);
  return __init;
}

}
}
}
*/
#include<algorithm>
#include<iostream>
#include<./beauty/algorithm/numeric/accumulate.hpp>
int Compare(int a, int b){
	return a + b;
}
int main(){
	int b[] = {1,2,3,5,8,13};
	int bp = 0;
	int a[] = {1,2,3,5,8,13};
	int ap = 0;
//	ap = std::accumulate(a, a + sizeof(a)/sizeof(int), ap);
//
///	bp = beauty::algorithm::numeric::
//	accumulate(b, b + sizeof(b)/sizeof(int), bp);

	ap = std::accumulate(a, a + sizeof(a)/sizeof(int), ap, Compare);

	bp = beauty::algorithm::numeric::
	accumulate(b, b + sizeof(b)/sizeof(int), bp, Compare);
	if(bp != ap){
		std::cout<<"error !!"<<"bp = "<<bp<<"  ap = "<<ap<<std::endl;
	}else{
		std::cout<<"ap = "<<ap<<std::endl;
	}
	return 0;
}
