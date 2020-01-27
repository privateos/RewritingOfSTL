
#include<locate.h>
#include<new>
#include<iostream>
#include<beauty.hpp>
using namespace std;

class test{
	public:
		test(){
			cout<<"test()"<<endl;
		}
		test(int a){
			cout<<"test(int a)"<<endl;
		}
		~test(){
			cout<<"~test()"<<endl;
		}
		
		int b, c, d, e;
		
		static void* operator new (size_t a){
			cout<<"a = "<<a<<endl;
			return beauty::allocator::allocator::allocate(a);
			//return malloc(a);
		}
		
		static void operator delete(void *p){
			cout<<"p = "<<p<<endl;
			beauty::allocator::allocator::deallocate(p, sizeof(test));
		}
		
		static void* operator new[] (size_t n){
			cout<<"n = "<<n<<endl;
			size_t *p;
			p = (size_t*)beauty::allocator::allocator::allocate(n);
			cout<<"p = "<<p<<endl;
			//*p = (n - sizeof(size_t))/size
			//*p = n;
			return p;
		}
		static void operator delete[] (void *p){
			cout<<"P = "<<p<<endl;
			cout<<(*((size_t*)p))<<endl;
			
		}
		static size_t array_size(const test *p){
			return *((size_t*)p - 1);
		}
		
};


int main(){
	
	//test *p = new test[6];
	test *r = new test(2);
	
	//cout<<"p_size = "<<array_size(p)<<endl;
	
	//delete[] p;
	delete r;
	return 0;
}

