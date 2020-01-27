//
//namespace beauty{
///*

#include<iostream>
using namespace std;

class A{
	public:
	A(){}
	
	A(const A &m):a(m.a){
		cout<<"A(const A &m)"<<endl;
	}
	
	A(A &&m):a(m.a){
		cout<<"A(A &&m)"<<endl;
	}
	
	
	A test_fun(){
		cout<<"test_fun"<<endl;
		A m;
		m.a = 1;
		++m.a;
		return m;
	}
	A& operator = (const A &m){
		cout<<"A operator = (const A &m)"<<endl;
		return *this;
	}
	A& operator = (A &&m){
		cout<<"A operator = (A &&m)"<<endl;
		a = m.a;
		return *this;
	}

	private:
		int a;
};

void fun(const int &){
	cout<<"void fun(const int &)"<<endl;
}
void fun(int &&){
	cout<<"void fun(int &&)"<<endl;
}
template<class T>
void fun0(T a){
	fun(a);
}


int main(){

	
	fun0<int&&>(1);
	return 0;
}

