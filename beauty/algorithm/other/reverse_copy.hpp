
#ifndef beauty__algorithm__other___reverse_copy_hpp
#define beauty__algorithm__other___reverse_copy_hpp

namespace beauty{namespace algorithm{namespace other{
	


template<class BidirectionalIter, class OutputIter>
OutputIter reverse_copy(BidirectionalIter first,
BidirectionalIter last, OutputIter result){
	while(first != last){
		*result = *--last;
		++result;
	}
	return result;
}	
}
}
}
#endif
