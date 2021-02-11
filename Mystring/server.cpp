#include <iostream>  
#include <cstring>  
#include "mystring.h"   

using namespace std; 

String::String()
    : str(new char){  
        *str = '\0';
        cout << "no args ctor called " << endl;   
}  

String::String(const char * string_t)
    :str(new char[strlen(string_t)+1]){
        strcpy(str,string_t);   
        cout << "one args ctor is called " << endl; 
}

String::String(const String & source)
    :str(new char[strlen(source.str)+1]){  
        strcpy(str,source.str);  
        cout << "Copy ctor is called " << endl; 
}

String & String::operator=(const String & rhs){ 
    if(this != &rhs){ 
        delete [] this->str;  
        this->str = new char[strlen(rhs.str)+1];  
        strcpy(this->str,rhs.str); 
        cout << "Copy assignment is called " << endl;  
    }
    return *this;
}

String::String(String && source)
    :str(source.str){
        source = nullptr;  
        cout << "Move ctor is called " << endl; 
}

String & String::operator=(String && rhs){  
    if(this != &rhs){ 
        this->str = rhs.str;  
        rhs.str = nullptr;  
        cout << "Move assigment is called" << endl; 
    }
    return *this;
}

int String::get_len(){ 
    return strlen(this->str);
}

const char * String::get_String(){ 
    return this->str; 
}

std::ostream & operator<<(std::ostream & os, const String & rhs){ 
    os << rhs.str;  
    return os;
}