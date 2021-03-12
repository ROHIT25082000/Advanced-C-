#include<stdio.h>  
#include "rect.h"  

static int peri(rect_t * ptr){ 
    return 2 *(ptr->length + ptr->breadth); 
}

static int area(rect_t * ptr){
    return  ptr->length * ptr->breadth; 
}

static void disp(rect_t * ptr)
{
    printf("length : %d , breadth : %d\n",ptr->length, ptr->breadth);  
}  


static struct vtable vtable_t = { 
    peri,
    area,
    disp
}; 

void init(rect_t * ptr, int length, int breadth){
    ptr->length = length; 
    ptr->breadth = breadth; 
    ptr->ptr_vtable = &vtable_t; 
}


