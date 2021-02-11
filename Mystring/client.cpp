#include <iostream>  
#include "mystring.h"


using namespace std;  

int main() 
{ 

    String s; // no args ctor is called 
    s = "Rohit"; // move assignment must be called  

    String st1("Mohit");  

    cout << s << "\n"; 

    cout << st1 << "\n";
}