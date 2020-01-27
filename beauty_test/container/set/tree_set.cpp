#include<iostream>   
#include<./beauty/container/set/tree_set.hpp>
typedef beauty::container::set::tree_set<int> int_set;
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
	a.erase(f);
	f = a.begin();
	for( ; f != end; ++f){
		std::cout<<*f<<std::endl;
	}
	return 0;
}
