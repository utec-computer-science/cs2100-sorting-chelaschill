#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

template<class T>

class Sorting{
private:

    vector<T>* v = new vector<T>();
public:

    Sorting(vector<T>* v){this->v = v;}

    void Insertion_Sort() {
        for (int i = 1; i < v->size(); i++) {
            T base = v->at(i);
            int j = i - 1;
            while (j >= 0 && v->at(j) > base) {
                v->at(j + 1) = v->at(j);
                j = j - 1;

            }
            v->at(j + 1) = base;
        }
    }

    void Swap(int *x, int *y){
            int temp = *x;
            *x = *y;
            *y = temp;
        }

    void Selection_Sort(){

            int min;

            for (int i = 0; i < v->size()-1; i++)
            {
                min = i;
                for (int j = i+1; j < v->size(); j++)
                    if (v->at(j) < v->at(min))
                        min = j;

                Swap(&v->at(min), &v->at(i));
            }
        }

    void Bubble_Sort(){

        for (int i = 0; i < v->size()-1; i++){
            for (int j = 0; j < v->size()-i-1; j++){
                if (v->at(j) > v->at(j+1))
                    Swap(&v->at(j),&v->at(j+1));
            }
        }

    }

    void Merge(T l, T m, T r)
    {
        T i, j, k;
        T n1 = m - l + 1;
        T n2 =  r - m;
        auto * L = new vector<T>(), *R = new vector<T>();
        for (i = 0; i < n1; i++)
            L->push_back(v->at(l+i));
        for (j = 0; j < n2; j++)
            R->push_back(v->at(m + 1 + j));
        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2)
        {
            if (L->at(i) <= R->at(j)){
                v->at(k) = L->at(i);
                i++;
            }
            else{
                v->at(k) = R->at(j);
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            v->at(k) = L->at(i);
            i++;
            k++;
        }
        while (j < n2)
        {
            v->at(k) = R->at(j);
            j++;
            k++;
        }
    }

    void Merge_Sort(T l , T r) {
        if (l < r)
        {
            T m = l+(r-l)/2;
            Merge_Sort(l, m);
            Merge_Sort(m+1, r);

            Merge(l, m, r);
        }
    }

    void Hippy(int n, int raiz){

        T mayor = raiz;
        T izq = 2*raiz + 1;
        T der = 2*raiz + 2;

        if(izq < n and v->at(izq) > v->at(mayor))
            mayor = izq;
        if(der < n and v->at(der) > v->at(mayor))
            mayor =  der;
        if(mayor != raiz)
        {
            Swap(&v->at(raiz), &v->at(mayor));
            Hippy(n, mayor);
        }
    }

    void Heap_Sort(){

        for(int i = v->size() / 2 - 1; i >= 0; i--)
            Hippy(v->size(), i);

        for(int i = v->size() - 1; i >= 0; i--) {
            Swap(&v->at(0), &v->at(i));
            Hippy(i,0);
        }
    }


    int DivideyVenceras(int prim, int ult){

        int pivote = v->at(ult);
        int i = prim - 1;

        for(int j = prim; j <= ult - 1; j++){

            if(v->at(j) < pivote){
                i++;
                Swap(&v->at(i), &v->at(j));
            }
        }

        Swap(&v->at(i+1), &v->at(ult));

        return (i+1);
    }

    void Quick_Sort(int prim, int ult){

        if(prim < ult){

            int indice = DivideyVenceras(prim, ult);
            Quick_Sort(prim, indice - 1);
            Quick_Sort(indice + 1, ult);
        }
    }

    void Shell_Sort(){

        for(int dif = v->size()/2; dif > 0; dif /= 2){
            for(int i = dif; i < v->size(); i += 1){
                T temp = v->at(i);
                int j;
                for(j = i; j >= dif and v->at(j-dif) > temp; j -= dif )
                    v->at(j) = v->at(j-dif);
                v->at(j) = temp;
            }
        }
    }
};
