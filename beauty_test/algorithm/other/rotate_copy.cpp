/*



#ifndef include___beauty__algorithm__algorithmbase___copy_hpp
	#define include___beauty__algorithm__algorithmbase___copy_hpp
	#include<./beauty/algorithm/algorithmbase/copy.hpp>
#endif

namespace beauty{namespace algorithm{namespace other{
	
template<class ForwardIter, class OutputIter>
OutputIter rotate_copy(ForwardIter first, ForwardIter middle,
ForwardIter last, OutputIter result){
	return beauty::algorithm::algorithmbase::
		copy(first, middle, 
		beauty::algorithm::algorithmbase::copy(middle, last, result));
}	
}
}
}*/
#include<./beauty/algorithm/other/rotate_copy.hpp>
int main(){
	return 0;
}