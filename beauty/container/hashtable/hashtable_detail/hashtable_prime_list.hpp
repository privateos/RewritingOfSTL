
#ifndef beauty__container__hashtable__hashtable_detail___hashtable_prime_list_hpp
#define beauty__container__hashtable__hashtable_detail___hashtable_prime_list_hpp

#include<./beauty/types.hpp>
#include<./beauty/algorithm/other/lower_bound.hpp>


namespace beauty{namespace container{namespace hashtable{namespace hashtable_detail{
static const unsigned int num_primes = 28;
static const unsigned long prime_list[num_primes] = 
{
53,       97,       193,     389,     769,
1543,     3079,     6151,    12289,   24593,
49157,    98317,    196613,   393241,  786433,
1572869,  3145739,   6291469,  12582917, 25165843,
50331653, 100663319, 201326611, 402653189, 805306457,
1610612741,3221225473ul,4294967291ul 
};

inline unsigned long next_prime(unsigned long n){
	const unsigned long *pos;
	const unsigned long *first = prime_list;
	const unsigned long *last = prime_list + num_primes;
	pos = beauty::algorithm::other::
		lower_bound(first, last, n);
	
	return pos == last ? *(last - 1) : *pos;
}

inline beauty::size_t max_bucket_count(){
	return prime_list[num_primes - 1];
}


}
}
}
}
#endif
