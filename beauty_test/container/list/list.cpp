#include<iostream>
//#include<list>

#include<./beauty/container/list/list.hpp>
using namespace beauty::container;
using namespace std; 
int main(){
	list::list<int> ilist;
	
	ilist.push_back(0);
	ilist.push_back(1);
	ilist.push_back(2);
	ilist.push_front(4);
	list::list<int>::iterator i = ilist.begin();
	list::list<int>::iterator end = ilist.end();
	for( ; i != end; ++i){
		cout<<*i<<" ";
	}
	cout<<endl;
	return 0;
}
