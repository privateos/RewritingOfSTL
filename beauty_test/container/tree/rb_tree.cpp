#include<iostream>
#include<algorithm>
//using namespace std;
#include<./beauty/container/tree/rb_tree.hpp>

struct test{
	int value;
	~test(){
		std::cout<<"value = "<<value<<std::endl;
	}  
};
  
struct key_of_value{
	const int& operator () (const test &a)const{
		return a.value;
	}
};
struct key_compare{
	bool operator () (const int &a, const int &b)const{
		return a < b;
	}
};
typedef beauty::container::tree::
rb_tree<int,test,key_of_value,key_compare> tree;
struct out{
	void operator () (const test &v)const{
		std::cout<<v.value<<" ";
	}
};
void testfunction(){
	tree a;  
	test t;
	t.value = 1;
	int i;
	for(i = 0; i < 10; ++i){
		t.value = i;
		a.insert_equal(t);
	}
	

	t.value = 3; 
	a.insert_equal(t);
	
	std::cout<<"LDR:"<<std::endl;		
	a.LDR(a.get_root(), std::cout);
	std::cout<<std::endl;

	std::cout<<"DLR:"<<std::endl;
	a.DLR(a.get_root(), std::cout);
	std::cout<<std::endl<<std::endl;
	
	std::for_each(a.begin(), a.end(), out());
	std::cout<<std::endl;	
	
	
	
	std::cin>>i; 
	tree::iterator f = a.find(i);
	std::cout<<"f = "<<f->value<<std::endl;
	std::cout<<"erase"<<std::endl;
	a.erase(f);
	std::cout<<"LDR:"<<std::endl;		
	a.LDR(a.get_root(), std::cout);
	std::cout<<std::endl;
 
	std::cout<<"DLR:"<<std::endl;
	a.DLR(a.get_root(), std::cout);
	std::cout<<std::endl<<std::endl;
	
	
	std::for_each(a.begin(), a.end(), out());	
	std::cout<<std::endl;
	
	t.value = 100;
	std::cout<<"clear"<<std::endl;
	a.clear();
}
int main(){ 
	
	testfunction();
//	int m = 1;
//	auto f = [m](int a, int b)mutable noexcept->void{
//		++m;
//		std::cout<<"a = "<<a<<", b = "<<b<<", m = "<<m<<std::endl;
//	};
//	
//	f(1, 2);
//	f(1, 2);
	return 0;
}
