 
#include<iostream>
#include<./beauty/container/hashtable/hashtable.hpp>
// int int KeyOfValue Equal HashFunction

class Test{
	public:
	int key;
	int value;
	void print(){
		std::cout<<"key = "<<key<<"  value = "<<value<<std::endl;
	}
	~Test(){ 
		print();
	}
};
struct KeyOfValue{
	const int& operator ()(const Test &a)const{
		return a.key;
	}   
};    
struct Equal{
	bool operator () (const int &a, const int &b)const{
		return a == b;
	}
}; 
struct HashFunction{
	unsigned int operator () (const int &a)const{
		return a;
	}
};



typedef beauty::container::hashtable::
hashtable<int,Test,KeyOfValue,Equal,HashFunction> hash;
 
int main(){ 
	hash h; 
	Test t;
	t.key = 0;
	t.value = 0;


	int i;
	for(i = 0; i < 100; ++i){
		t.key = i;
		t.value = i;
		h.const_insert_unique(t);
		std::cout<<"size = "<<h.size()<<std::endl;
		std::cout<<"hashtable = "<<h.hashtable_size()<<std::endl;
	}	


	std::cout<<"for_each"<<std::endl;
	hash::iterator i0 = h.begin();
	hash::iterator end = h.end(); 
	while(i0 != end){
		i0->print();
		++i0;
	}
	

	std::cout<<"clear"<<std::endl;

	hash h1 = h; 
	std::cout<<"elements_size = "<<h1.elements_size()<<"hashtable_size = "<<h1.hashtable_size()<<std::endl;
	hash::iterator j = h1.begin();
	hash::iterator jend = h.end();
	for( ; j != jend; ++j){
		j->print();
	}
	std::cin>>i;
	return 0;
} 
