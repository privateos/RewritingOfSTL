/*


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
}*/
#include<./beauty/algorithm/other/reverse_copy.hpp>
int main(){
	return 0;
}