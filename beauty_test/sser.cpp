#include<sser>
//#include<iostream>

int main(){
	int a = 1, b = 2;
	
	future::swap(a, b);
	std::cout<<a<<" "<<b<<std::endl;
	
	
	future::swap(a, b);
	std::cout<<a<<" "<<b<<std::endl;
	 
	return 0;
}
