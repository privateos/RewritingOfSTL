#include<iostream>
#include<./beauty/container/map/tree_multimap.hpp>
typedef beauty::container::map::tree_multimap<int,int> int_map;
typedef int_map::value_type value_type;
int main(){

	int_map a;

	value_type v(1,1);

	a.insert(v);


	v.first = 2;
	v.second = 2;
	a.insert(v);

	v.first = 3;
	v.second = 3;
	a.insert(v);
	int_map::const_iterator f = a.begin();
	int_map::const_iterator end = a.end();

	for( ; f != end; ++f){
		std::cout<<f->second<<std::endl;
	}

	//f = a.find(2);
	//std::cout<<f->second<<std::endl;
	//a.erase(f);
	a[1] = 100;
	f = a.begin();
	for( ; f != end; ++f){
		std::cout<<f->second<<std::endl;
	}
	return 0;
}
