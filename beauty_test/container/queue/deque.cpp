#include<iostream>
using namespace std;
#include<./beauty/container/queue/deque.hpp>
using namespace beauty::container;
int main(){
	typedef queue::deque<int,beauty::allocator::allocator, 10> DQ;
	DQ dq;
	DQ::iterator i ;
	DQ::iterator end;
	
	i = dq.begin();
	end = dq.end();
	for( ; i < end; ++i){ 
		cout<<*i<<" ";
	}
	cout<<endl;
	
	
	dq.push_front(1);
	i = dq.begin();
	end = dq.end();
	for( ; i < end; ++i){
		cout<<*i<<" ";
	}
	cout<<endl;
	
	dq.push_back(2);
	i = dq.begin();
	end = dq.end();
	for( ; i < end; ++i){
		cout<<*i<<" ";
	}
	cout<<endl;
	dq.push_front(3);
	i = dq.begin();
	end = dq.end();
	for( ; i < end; ++i){
		cout<<*i<<" ";
	}
	cout<<endl;
	dq.push_front(4);
	i = dq.begin();
	end = dq.end();
	for( ; i < end; ++i){
		cout<<*i<<" "; 
	}
	cout<<endl;
	
	
	return 0;
}
