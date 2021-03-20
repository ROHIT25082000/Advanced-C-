#include <stdio.h>
#include <stdlib.h>
#include "header.h" 

int main(){ 

    Base * p = (Base *)malloc(sizeof(Base)); 
    init_Base(p,12,23); 
    p->ptr_t->foo(); 
    p->ptr_t->bar();  


    // base class pointer pointing to a derived class object 
    // Liskovs substitution principle . 
    Base * q = (Base *)malloc(sizeof(Derived)); 
    init_Derived((Derived *)q,12,23,34,45);
    q->ptr_t->foo(); 
    q->ptr_t->bar(); 
}