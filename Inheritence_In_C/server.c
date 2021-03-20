#include <stdio.h> 
#include <stdlib.h>
#include "header.h" 

static void foo() { 
    printf("I am foo in base \n"); 
}
static void bar() { 
    printf("I am bar in base \n");
}
static void foo1() { 
    printf("I am in foo1 of Derived \n");
}

static vtable_Base base_v = {
    foo,
    bar
}; 

static vtable_Derived derived_v = { 
    foo1, 
    bar
};



void init_Base(Base * p, int a , int b)
{ 
    p->ptr_t = &base_v; 
    p->a = a; 
    p->b = b; 
}

void init_Derived(Derived * p, int a, int b, int c, int d)
{
    p->ptr_t = &derived_v; 
    init_Base(&p->base,a,b); 
    p->c = c;
    p->d = d;  
}


