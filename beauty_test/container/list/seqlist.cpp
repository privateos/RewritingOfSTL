#include<iostream>
#include<./beauty/container/list/seqlist.hpp>
using namespace std;
using namespace beauty::container::list;

int main(){
	seqlist<int> a;
	int i = 0;
	while(!a.full()){
		++i;
		a.push_back(i);
	}
	int m = a.size();
	for(i = 0; i < m; ++i){
		cout<<a.at(i)<<" ";
	}
	cout<<endl;
	return 0;
}

