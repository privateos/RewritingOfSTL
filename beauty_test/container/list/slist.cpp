#include<iostream>
using namespace std;
#include<./beauty/container/list/slist.hpp>
using namespace beauty::container;
class A{
	public:
	explicit A(char *s0 = 0 ):s(s0){
		
	} 
	~A(){
		cout<<"~A() :"<<s<<endl;
	}
	char *s;
};
int main(){ 

	A b("abc");
	list::slist<A> a;
	
	b.s = "1";
	
	a.push_front(b);
	//cout<<"a"<<endl;
	b.s = "2";
	a.push_front(b);
	b.s = "3";
	a.push_front(b);
	list::slist<A>::iterator first = a.begin();
	b.s = "4";
	a.insert_next(first, b);
	
	//a.pop_front();
 
	
	//a.pop_front();
 
 	first = a.begin();
 	a.erase_next(first);
	return 0; 
}
