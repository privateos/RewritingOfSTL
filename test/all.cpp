#include<iostream>
#include<algorithm>
//#include<iterator.hpp>
//#include<functional.hpp>
//#include<algorithm.hpp>
//#include<container.hpp>


#include<beauty.hpp>

struct Compare{
	bool operator () (const int &a, const int &b)const{
		return a < b;
	}
};

int main(){
	
	int a[11] = {22, 30, 30, 17, 33, 40, 17, 23, 22, 12, 20};
	int b[11];
	for(int i = 0; i < 11; ++i){
		b[i] = a[i];
	}
	
	future::nth_element(a, a + 5, a + 11, Compare());
	std::nth_element(b, b + 5, b + 11, Compare());

	//future::nth_element(a, a + 3, a + 11);
	//std::nth_element(b, b + 3, b + 11);
//	future::sort(a, a + 11);
//	std::sort(b, b + 11);

	for(int i = 0; i < 11; ++i){
		std::cout<<a[i]<<" ";
	}
	std::cout<<std::endl;
	
	for(int i = 0; i < 11; ++i){
		std::cout<<b[i]<<" ";
	}
	std::cout<<std::endl;
	
	
	
	future::exception a0;
	
	try{
		throw a0;
	}catch(future::exception &p0){
		p0.print();
		throw p0;
	}

	future::sint64_t sint = 1;

	return 0;
}

