#include <iostream>   

using namespace std;   
/*
    Hello ! I'm Rohit and I will be explaining argument to parameter passing .  

*/




/* 
    Six rules to completely understand the argument to parameter passing in c++ .

    (i) Look for exact match in the function prototype (OR) Do a trivial conversion. 
        Trivial conversion :  

            1.) array to pointer conversion     
            2.) variable to const 
            3.) derived class object to base class object.    

        Ex : If it is defined in the function declaration the type mentioned and the type passed is same 
        then Exact match but if array is passed to pointer parameter  

        I pass int arr1[] to the below function .

        int display1(int * arr, int n)  // Trivial conversion.  

        int display2(const int * arr , int n) // Trivial conversion .  

  
    (ii) Look for generic function if defined . 


    (iii) Do promotion 

            int is the prefered integral type and  double is the prefered float type    

            1.) float to double happens 
            2.) char , short to int happens  
    
    (iv) Standard Conversion 
            This is the numeric conversion that happens    

            float to int , int to double etc.    
            but not pointer conversion.   

    (v) User defined conversion .  

        Single argument constructor   
        type conversion operator   
    
    (vi) Type unsafe conversion.   
            Eg suppose I have the a int * pointer and I cast it to void * 
            Then again casting this void * pointer to some type like double is unsafe .   

*/  

// int square(int x)
// {
//     cout << "Int called " << endl; 
//     return x*x;
// }  

double square(double x)
{
    cout << "Double called" << endl;
    return x*x;
}    

float square(float x)
{
    cout << "float called " << endl; 
    return x*x;  
}

int main() 
{  
    #if 0 // set to 1 run this portion 
    //line 1
    cout << square(12.3) << endl; // double is called and it is exact match . 
   
   // line 2
    cout << square('d') << endl; // We see no exact match and no generic function defined so point number (iii)
                                // (iii) promotion of char to integer takes place. 

    // line 3
    cout << square(12.3f) << endl; // the float is again exact match   

    // Now I comment  square function with float and I again run it again .   
    // No exact match and no generic functions also thus look for promotion and it promote to double.  
    #endif 

    #if 0 // set to 1 run this portion 
    // Now firstly comment this square(int) function and run this  
    square('a');
    // Lets discuss the above line 
    // we have no exact match 
    // No generic function written
    // No promotion can also happen  
    // So std conversion will take place . 
    // but since there is a possiblity of char to float or char to double and there is no 
    // preference and hence this will give ambiguity error .   
    
    // Now uncomment the square(int) function we see now as per rules promotion occurs .  

    // The bottomline is type is a compile time and value is a run time mechanisms. 
    #endif  

}






