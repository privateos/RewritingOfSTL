#include<iostream>
#include<./beauty/container/set/hash_set.hpp>
using namespace std;

struct hashfun{
	const int operator () (const int &a)const{
		return a;
	}
};

typedef beauty::container::set::hash_set<int> int_set;

int main(){
	int_set a;
	
	a.insert(1); 
	a.insert(2);
	a.insert(3);
	int_set::iterator f = a.begin();
	int_set::iterator end = a.end();
	
	for( ; f != end; ++f){
		std::cout<<*f<<std::endl;
	} 
	
	f = a.find(2);
	
	
	std::cout<<*f<<std::endl;
	std::cout<<"erase"<<std::endl;
	a.erase(f);
	
	f = a.begin();
	for( ; f != end; ++f){
		std::cout<<*f<<std::endl;
	}

	std::cout<<"size = "<<a.size()<<std::endl;
	return 0;
}
