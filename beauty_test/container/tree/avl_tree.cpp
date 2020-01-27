#include<iostream>
using namespace std;
#include<./beauty/container/tree/avl_tree.hpp>
using namespace beauty::container::tree;
class test{
	public:
	int key;
	int value;
	void print()const{
		cout<<"key = "<<key<<" value = "<<value;
	}
	~test(){
		print();
		cout<<endl;
	}
};
struct KeyOfValue{
	const int& operator ()(const test &p)const{
		return p.key;
	}
};
struct KeyCompare{
	bool operator () (const int &a, const int &b)const{
		return a < b;
	}
};
struct Print{
	void operator ()(const test &a)const{
		a.print();
		cout<<endl;
	}
};
typedef avl_tree<int,test,KeyOfValue,KeyCompare> tree;
void fun(tree &a){
	tree::iterator f = a.header->right;
	tree::iterator end = a.end();
	while( f != end){
		f.cur->value.print();
		cout<<"\n";
		--f;
	}
	cout<<endl; 
}
int main(){

	test t;
	t.key = 1;
	t.value = 1;
	tree a; 
	int i;
	int j;
	for(i = 0; i < 10; ++i){
		//cin>>j;
		t.key = i;
		t.value = i;
		 
		a.insert_equal(t);
		
	}
	cout<<"LDR"<<endl;
	a.LDR(a.header->parent);
	cout<<"LDR end"<<endl;
	
	cout<<"DLR"<<endl;
	a.DLR(a.header->parent);
	cout<<"DLR end"<<endl;
	
	cout<<"for_each"<<endl;
	for_each(a.begin(), a.end(), Print() );
	cout<<"for_each end"<<endl<<endl;
	
	for(i = 0; i < 10; ++i){
		cin>>j;
		tree::iterator s = a.find(j);
		cout<<"search = "<<s->key<<endl;
		cout<<"delete "<<endl;
		a.erase(s);
		cout<<"delete end"<<endl;

 
	cout<<"LDR"<<endl;
	a.LDR(a.header->parent);
	cout<<"LDR end"<<endl;
	
	cout<<"DLR"<<endl;
	a.DLR(a.header->parent);
	cout<<"DLR end"<<endl;
	
	cout<<"for_each"<<endl;
	for_each(a.begin(), a.end(), Print());
	cout<<"for_each end"<<endl<<endl;		
		
	}	




	
	
	
	
	 
	cout<<"clear"<<endl;
	a.clear();     
	cout<<"clear end"<<endl;
	return 0;
}
