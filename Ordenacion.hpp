#pragma once 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include "Dni.hpp"
#include <vector>
#include <cstring>

using namespace std;

template<class T>
class ORDENACION{
    private:
        int comparaciones;
    public:
    ORDENACION();
    ~ORDENACION();
    int get_comparacion();
    int wrapper_metodos(vector<T> &secuencia, int tam, int delta, char* metodo);
    void selecion(vector<T> &secuencia, int tam);
    void inserccion(vector<T> &secuencia, int tam);
    void burbuja(vector<T> &secuencia, int tam);
    void quicksort(vector<T> &secuencia, int p, int q);
    void shellsort(vector<T> &secuencia, int tam, double delta);
    void mergesort(vector<T> &secuencia, int tam);
    void merge(vector<T> &resultado,vector<T> secuencia1,int izq, vector<T> secuencia2, int dcha);
    
    
    
};


template<class T>
ORDENACION<T>::ORDENACION(){
    comparaciones = 0;
}

template<class T>
ORDENACION<T>::~ORDENACION(){}

template<class T>
int ORDENACION<T>::get_comparacion(){
    return comparaciones;
}

template<class T>
int ORDENACION<T>::wrapper_metodos(vector<T> &secuencia, int tam, int delta, char* metodo){
    comparaciones = 0;
    char s_shellsort[] = "shellsort";
    char s_inserccion[] = "inserccion";
    char s_selecion[] = "selecion";
    char s_quicksort[] = "quicksort";
    char s_mergesort[] = "mergesort";
    char s_burbuja[] = "burbuja";
    if(strcmp(metodo, s_shellsort) == 0) {
        shellsort(secuencia, tam, delta);
        return comparaciones;
    } else if(strcmp(metodo, s_inserccion) == 0) {
        inserccion(secuencia, tam);
        return comparaciones;
    } else if(strcmp(metodo, s_selecion) == 0) {
        selecion(secuencia, tam);
        return comparaciones;
    } else if(strcmp(metodo, s_quicksort) == 0) {
        quicksort(secuencia,0 ,tam);
        return comparaciones;
    } else  if(strcmp(metodo, s_mergesort) == 0) {
        mergesort(secuencia, tam);
        return comparaciones;
    }
    else  if(strcmp(metodo, s_burbuja) == 0) {
        burbuja(secuencia, tam);
        return comparaciones;
    }
}


template<class T>
void ORDENACION<T>::inserccion(vector<T> &secuencia, int tam){
    int j;
    T temp;
    comparaciones = 0;
    for( int i = 1; i < tam; i++){
        j = i;
        while((j > 0) && (secuencia[j]< secuencia[j-1])){
            temp = secuencia[j];
            secuencia[j] = secuencia[j-1];
            secuencia[j-1] = temp;
            j--;
            comparaciones++;
            
        }
    }
}

template<class T>
void ORDENACION<T>::selecion(vector<T> &secuencia, int tam){
    comparaciones = 0;
    int pos_min;
    T temp;
    for(int i = 0; i < tam-1; i++){
        pos_min = i;
        for( int j = i+1; j < tam; j++){
            if(secuencia[j] < secuencia[pos_min]){
                pos_min = j;
                comparaciones++;
            }    
                
        }
        if(pos_min != i){
            temp = secuencia[i];
            secuencia[i] = secuencia[pos_min];
            secuencia[pos_min] = temp;
            
        }
    }
}


template<class T>
void ORDENACION<T>::burbuja(vector<T> &secuencia, int tam){
    comparaciones = 0;
    T temp;
    for(int i = 1; i < tam; i ++){
        for(int j = 0; j < tam - 1; j++){
            if(secuencia[j] > secuencia[j + 1]){
                temp = secuencia[j];
                secuencia[j] = secuencia[j + 1];
                secuencia[j + 1] = temp;
                comparaciones++;
            }
        }
    }
}


template<class T>
void ORDENACION<T>::quicksort(vector<T> &secuencia, int p,int q) {
   
    int r;
    if(p < q) {
        
        T x = secuencia[p];
        int r = p;
        int j;

        for(j=p+1; j<q; j++) {
            if(secuencia[j] <= x) {
                r=r+1;
                swap(secuencia[r],secuencia[j]);
             
            }
           comparaciones++;
        }

        swap(secuencia[r],secuencia[p]);
        
        quicksort(secuencia,p,r);  
        quicksort(secuencia,r+1,q);
    }
}



template<class T>
void ORDENACION<T>::shellsort(vector<T> &secuencia, int tam, double delta){
    comparaciones = 0;
    int  i, j;
    double d;
    for(d = delta * tam; d > 0; d/= 2 ){
        for(i = d; i < tam; i++)
            for(j = i - d; j >= 0 && secuencia[j] > secuencia[j + d]; j -= d){
	     
                T temp = secuencia[j];
                secuencia[j] = secuencia[j + d];
                secuencia[j + d] = temp;
                comparaciones++;
            }
            
    }
        
}
template<class T>
void ORDENACION<T>::merge(vector<T> &resultado,vector<T> secuencia1,int izq, vector<T> secuencia2, int dcha){
    comparaciones = 0;
    int p = 0;
    int p1 = 0;
    int p2 = 0;
    while(p1 < izq && p2 < dcha){
        comparaciones++;
        if(secuencia1[p1] < secuencia2[p2])
            resultado[p++] = secuencia1[p1++];
        else
            resultado[p++] = secuencia2[p2++];
    }
    while( p1 < izq){
        resultado[p++] = secuencia1[p1++];
    }
    while(p2 < dcha){
        resultado[p++] = secuencia2[p2++];
    }
}

template<class T>
void ORDENACION<T>::mergesort(vector<T> &secuencia,int tam){
    
    if(tam == 1)
    return;
    int mid = tam/2;
    int izq = mid;
    int dcha = tam - mid;
    vector<T> secuencia1;
    secuencia1.resize(izq);
    vector<T> secuencia2;
    secuencia2.resize(dcha);
    
    for(int i = 0; i < tam; i++){
        if(i < mid)
            secuencia1[i] = secuencia[i];
        else
            secuencia2[ i - mid] = secuencia[i];
    }
    mergesort(secuencia1,izq);
    mergesort(secuencia2,dcha);
    merge(secuencia,secuencia1,izq,secuencia2,dcha);
    
}