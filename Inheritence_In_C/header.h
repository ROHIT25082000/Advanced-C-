#include <stdio.h> 
#include <stdlib.h>


typedef struct vtable_Base vtable_Base;  

struct vtable_Base 
{   
    void (*foo)(); 
    void (*bar)();
}; 

typedef struct vtable_Derived vtable_Derived;  

struct vtable_Derived
{
    void (*foo)(); 
    void (*bar)(); 
};


typedef struct Base Base;  
struct Base 
{ 
    vtable_Base * ptr_t;  
    int a;
    int b; 
}; 


typedef struct Derived Derived; 

struct Derived 
{
    vtable_Derived * ptr_t; 
    Base base;
    int c; 
    int d;  
};


void init_Base(Base * p, int a , int b); 
void init_Derived(Derived * p, int a, int b, int c, int d); 

