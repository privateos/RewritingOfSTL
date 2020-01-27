
#ifndef beauty__algorithm__other___rotate_copy_hpp
#define beauty__algorithm__other___rotate_copy_hpp

#include<./beauty/algorithm/algorithmbase/copy.hpp>


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
}
#endif
