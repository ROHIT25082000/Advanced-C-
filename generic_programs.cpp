#include <iostream>   
using namespace std; 


template<typename ptr_t>  
void disp(ptr_t first , ptr_t last)
{
	while(first != last)
	{ 
		cout << *first << " ";  
		++first;  
	}
	cout << "\n"; 
}

/*Accumulate function just like the python3 reduce function */  

template<typename T, typename ptr_t, typename binary_op> 
T acc(ptr_t first , ptr_t last, T init, binary_op op)
{
	T temp = init;  
	while(first != last) 
	{
		temp = op(temp, *first);
		++first;
	}
	return temp;  
} 

template<typename T> 
T add(T a, T b)
{
	return a + b;
}

template<typename T>
T mul(T a, T b)
{
	return a * b; 
} 
  
int main() 
{ 
	int arr1[] = {1, 2, 3, 4, 5 ,6 ,7};  

	disp(arr1,arr1+7);  

	double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};  
	
	disp(arr2, arr2+5);  
	
	cout << "The int sum :" << acc(arr1,arr1+7,0,add<int>) << endl; 
	cout << "The int product :" << acc(arr1, arr1+7,1,mul<int>) << endl;  
	
	cout << "The double sum : " << acc(arr2, arr2+5, 0.0, add<double>) << endl;  
	cout << "The double product : " << acc(arr2, arr2+5, 1.0, mul<double>) << endl; 
		 	
	return 0; 
}

