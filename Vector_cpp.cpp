#include <iostream> 

using namespace std; 

template<typename T> 
class Vector
{
    private:
        T * arr; 
        int size; 
    public:   
        explicit Vector(int size)
        : arr(new T[size]), size(size){ 
        }
        Vector(int size, T default_value)
        :arr(new T[size]), size(size){ 
            for(int i = 0; i < size ; ++i){ 
                this->arr[i] = default_value;
            } 
        } 
        ~Vector(){
            delete [] this->arr;
        }
        Vector(const Vector<T> & source); 
        Vector<T> & operator=(const Vector<T> rhs);
        
        class Iterator{ 
            private:
                T * ptr;
            public:
                Iterator(T * ptr_t)
                :ptr(ptr_t){
                }
                Iterator operator++(){ 
                    ++this->ptr;
                    return *this;
                }
                Iterator operator++(int){ 
                    T temp {*this}; 
                    ++*this;
                    return *temp;
                }
                bool operator==(const Iterator & source){ 
                    return this->ptr == source.ptr;
                } 
                bool operator!=(const Iterator & source) { 
                    return !(*this == source); 
                }
                T operator*() { 
                    return *this->ptr;
                }
                ~Iterator(){} 
        };      
        Iterator begin(){ 
            return Iterator(this->arr); 
        }
        Iterator end(){ 
            return Iterator(this->arr + this->size); 
        }
}; 

int main() 
{
    Vector<double>vc(10,12.03); 
    //Vector<int>vc(10);
    for(auto it = vc.begin(); it != vc.end(); ++it){
        cout << *it << "\t"; 
    } 
    cout << "\n";
}