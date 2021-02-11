#include <iostream>  

using namespace std; 

#ifndef MY_STRING  
#define MY_STRING  

class String {
private: 
    char * str;  
public:  
    
    String(); // no args constructor 
    String(const char * string_t);  // one arg constructor 
    String(const String & source);  // copy constructor   
    String & operator=(const String & rhs); // copy assignment operator 

    String(String && source);  // move constructor 
    String & operator=(String && rhs); // move assignment   

    int get_len();  
    const char * get_String();  

    friend std::ostream & operator<<(std::ostream & os , const String & rhs);
};  

#endif  