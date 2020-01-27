#include<iostream>
#include<./beauty/container/list/xorlist.hpp>
using namespace std;

using namespace beauty::container::list;
int main(){
	typedef xorlist<int> List;
	List a;
	
	cout<<a.size()<<endl;
	a.push_front(1); 
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);	
	
	a.reverse();
	//a.pop_back();
	List::iterator first = a.begin();
	List::iterator last = a.end();

	for(; first != last; ++first){
		cout<<*first<<" ";
	}
	cout<<endl;
	//cout<<a.front()<<endl; 
	cout<<"at = "<<a.at(3)<<endl;
	a.clear();
	return 0;
}
