#include <iostream>  
#include "date.h"

using namespace std; 


// a generic display function for any type   

template<typename T> 
void my_swap(T& a, T& b)
{
    T temp = a; a = b; b = temp; 
}

template<typename ptr_t>
void display(ptr_t first, ptr_t last){ 
    while (first != last) 
    {
        cout << *first << " "; 
        ++first;
    }
    cout << "\n";
}

// a generic function for sorting any type   

template<typename T>
void my_sort(T arr[] , int n)   // sorting function for any generic type if it has the < operator defined . 
{ 
    for(int i = 0; i < n-1 ; ++i){ 
        for(int j = i+1 ; j < n; ++j)
        {
            if(arr[j] < arr[i])
            { 
                my_swap(arr[i],arr[j]);
            }
        }
    }
} 


int main() 
{ 
    Date d1{1,2,2001}; 
    cout << d1; 
    cout << "\n"; 
    Date d2{d1}; 
    cout << ++d2 << endl;
    cout << d2++ << endl;

    Date arr_dates[] = { 
        {26,1,2000}, 
        {7,3,2017}, 
        {4,4,2003}, 
        {31,1,2004},
        {25,8,2020}
    };
    cout << "Before sorting " << endl; 
    display(arr_dates , arr_dates + 5);  
    my_sort(arr_dates, 5); 
    cout << "after sorting " << endl;
    display(arr_dates, arr_dates + 5);

    Date riddhi{31,7,2007};  
    Date rohit{25,8,2000};

    cout << boolalpha; 
    cout << (riddhi > rohit);

    return 0;
}