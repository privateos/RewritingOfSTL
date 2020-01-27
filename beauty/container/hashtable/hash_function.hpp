
#ifndef beauty__container__hashtable___hash_function_hpp
#define beauty__container__hashtable___hash_function_hpp

#include<./beauty/types.hpp>
#include<./beauty/config.hpp>


namespace beauty{namespace container{namespace hashtable{

inline beauty::size_t hash_string(const char *s){
	beauty::size_t h = 0;
	while(*s){
		h = 5*h + (*s);
	}
	return h;
}

template<class Key>
struct hash{};

TEMPLATE_NULL struct hash<char*>{
	beauty::size_t operator () (const char *s)const{
		return hash_string(s);
	}
};

TEMPLATE_NULL struct hash<const char*>{
	beauty::size_t operator () (const char *s)const{
		return hash_string(s);
	}
};

TEMPLATE_NULL struct hash<char>{
	beauty::size_t operator () (const char s)const{
		return s;
	}
};

TEMPLATE_NULL struct hash<unsigned char>{
	beauty::size_t operator () (const unsigned char s)const{
		return s;
	}
};

TEMPLATE_NULL struct hash<signed char>{
	beauty::size_t operator () (const signed char s)const{
		return s;
	}
};

TEMPLATE_NULL struct hash<short>{
	beauty::size_t operator () (const short s)const{
		return s;
	}
};

TEMPLATE_NULL struct hash<unsigned short>{
	beauty::size_t operator () (const unsigned short s)const{
		return s;
	}
};

TEMPLATE_NULL struct hash<int>{
	beauty::size_t operator () (const int s)const{
		return s;
	}
};

TEMPLATE_NULL struct hash<unsigned int>{
	beauty::size_t operator () (const unsigned int s)const{
		return s;
	}
};

TEMPLATE_NULL struct hash<long>{
	beauty::size_t operator () (const long s)const{
		return s;
	}
};

TEMPLATE_NULL struct hash<unsigned long>{
	beauty::size_t operator () (const unsigned long s)const{
		return s;
	}
};

}
}
}
#endif
