#include <iostream>
#include "sorts.cpp"
using namespace std;

template<class T>
void print_vector(vector<T> * v){
    for(auto i : *v){
        cout<<i<<',';
    }
}

int main() {
    auto *Vector_Prueba = new vector<int>();
    *Vector_Prueba = {3,8,5,1,6};
    Sorting V1(Vector_Prueba);
    V1.Merge_Sort(0, Vector_Prueba->size() - 1);
    print_vector(Vector_Prueba);
    return 0;
}

