
#include "Ordenacion.hpp"
#include <vector> 
#include <iostream>
using namespace std;

typedef int Tt;
int main(){
   vector<DNI> secuencia;
   ORDENACION<DNI> O;
   int modo,tam,pruebas;
   double cte;
    do{
        cout <<"_____________ Menu _____________"<<endl;
        cout << "1.Modo demostracion "<<endl;
        cout << "2.Modo estadistica"<<endl;
        cout << "0.Salir"<<endl;
        cout << "opcion: ";
        cin >> modo;
        
        switch(modo){
        /*__________________ Modo demostracion_________________________________________ */
            case 1:{
                    cout << "Modo demostracion"<<endl;
                    cout <<" Introduzca el tamaño de la secuencia a ordenar: ";
                    cin >> tam;
                
                    for(int i = 0; i < tam; i++){
                        int ndni = (rand()% (MAX - MIN)) + MIN;
                        DNI aux(ndni);
                        secuencia.push_back(aux);
                    }
                    cout << "Secuencia sin ordenar: " << endl << "[ ";
                    for(int i = 0; i < tam; i++){
                        cout << secuencia[i].get_dni() << " ";
                    } 
                    cout << "]" << endl;
                    cout << "1.Inserccion "<<endl;
                    cout << "2.Seleccion" <<endl;
                    cout << "3.Shellsort"<<endl;
                    cout << "4.Quicksort"<<endl;
                    cout << "5.Mergesort"<<endl;
                     cout << "6.Burbuja"<<endl;
                    cout << "Introduzca el algoritmo a ejecutar: ";
                    int opc;
                    cin >> opc;
                    switch(opc){
                        case 1:{
                            cout << " Ha elegido insercción..."<<endl;
                            O.inserccion(secuencia,tam);
                            cout << "Secuencia ordenada: " << endl << "[ ";
                            for(int i = 0; i < tam; i++){
                                cout << secuencia[i].get_dni() << " ";
                            } 
                            cout << "]" << endl;
                            cout << O.get_comparacion() << endl; 
                        }
                        break;
                        case 2:{
                            cout <<"Ha elegido selecion..."<<endl;
                            O.selecion(secuencia,tam);
                            cout << "Secuencia ordenada: " << endl << "[ ";
                            for(int i = 0; i < tam; i++){
                                cout << secuencia[i].get_dni() << " ";
                            } 
                            cout << "]" << endl;
                            cout << O.get_comparacion() << endl; 
                        }
                        break;
                        case 3:{
                            cout <<"Ha elegido shellsort..."<<endl;
                            cout << "introduzca la constante de reduccion: ";
                            cin >> cte;
                            O.shellsort(secuencia,tam,cte);
                            cout << "Secuencia ordenada: " << endl << "[ ";
                            for(int i = 0; i < tam; i++){
                                cout << secuencia[i].get_dni() << " ";
                            } 
                            cout << "]" << endl;
                            cout << O.get_comparacion() << endl; 
                        }
                        break;
                        case 4:{
                            cout <<"Ha elegido quicksort..."<<endl;
                            O.quicksort(secuencia,0,tam);
                            cout << "Secuencia ordenada: " << endl << "[ ";
                            for(int i = 0; i < tam; i++){
                                cout << secuencia[i].get_dni() << " ";
                            } 
                            cout << "]" << endl;
                            cout << O.get_comparacion() << endl; 
                        }
                        break;
                        case 5:{
                            cout <<"Ha elegido mergesort..."<<endl;
                            O.mergesort(secuencia,tam);
                            cout << "Secuencia ordenada: " << endl << "[ ";
                            for(int i = 0; i < tam; i++){
                                cout << secuencia[i].get_dni() << " ";
                            } 
                            cout << "]" << endl;
                            cout << O.get_comparacion() << endl; 
                        }
                        break;
                        case 6:{
                            cout <<"Ha elegido burbuja..."<<endl;
                            O.mergesort(secuencia,tam);
                            cout << "Secuencia ordenada: " << endl << "[ ";
                            for(int i = 0; i < tam; i++){
                                cout << secuencia[i].get_dni() << " ";
                            } 
                            cout << "]" << endl;
                            cout << O.get_comparacion() << endl; 
                        }
                        break;
            
                    }
            }
            break;
        /* ______________ Modo estadisitca ___________________________*/
            case 2:{
                    char s_shellsort[] = "shellsort";
                    char s_inserccion[] = "inserccion";
                    char s_selecion[] = "selecion";
                    char s_quicksort[] = "quicksort";
                    char s_mergesort[] = "mergesort";
                    char s_burbuja[] = "burbuja";
                    
                    cout << "Modo estadistica"<<endl;
                    cout <<" Introduzca el tamaño de la secuencia a ordenar: ";
                    cin >> tam;
                    cout << "Introduzca el numero de pruebas: ";
                    cin >> pruebas;
                    cout << "introduzca la constante de reduccion para el shellsort: ";
                    cin >> cte;
                    vector<vector<DNI> > banco_insert;
                    vector<vector<DNI> > banco_select;
                    vector<vector<DNI> > banco_shell;
                    vector<vector<DNI> > banco_quick;
                    vector<vector<DNI> > banco_merge;
                    vector<vector<DNI> > banco_burbuja;
                    for(int i = 0; i < pruebas ; i++){
                        vector<DNI> sec;
                        for(int j = 0; j < tam ; j++){
                            int ndni = (rand()% (MAX - MIN)) + MIN;
                            DNI aux(ndni);
                            sec.push_back(aux);
                        }
                        banco_insert.push_back(sec);
                        banco_merge.push_back(sec);
                        banco_quick.push_back(sec);
                        banco_select.push_back(sec);
                        banco_shell.push_back(sec);
                        banco_burbuja.push_back(sec);
                    }
                    //tabla:
                    cout << "Tabla de pruebas de los algoritmos para " << pruebas << " pruebas" << endl;
                    cout << "Metodo:    Minimo:    Medio:    Maximo:" << endl;
                    
                    //metodo inserccion
                    int min = 99999;
                    int acumulado = 0;
                    int max = 0;
                    for(int i = 0; i < pruebas; i++){
                        O.wrapper_metodos(banco_insert[i], tam, cte, s_inserccion);
                        if (min > O.get_comparacion())
                            min = O.get_comparacion();
                        if (max < O.get_comparacion())
                            max = O.get_comparacion();
                        acumulado += O.get_comparacion();
                    }
                    int medio = acumulado/pruebas;
                    cout << "inserccion   " << min << "     " << medio << "     " << max << endl;
                    
                    //metodo seleccion
                     min = 99999;
                     acumulado = 0;
                     max = 0;
                    for(int i = 0; i < pruebas; i++){
                         O.wrapper_metodos(banco_select[i], tam, cte, s_selecion);
                        if (min > O.get_comparacion())
                            min = O.get_comparacion();
                        if (max < O.get_comparacion())
                            max = O.get_comparacion();
                        acumulado += O.get_comparacion();
                    }
                    medio = acumulado/pruebas;
                    cout << "Seleccion   " << min << "     " << medio << "     " << max << endl;
                    
                    //metodo shellsort
                    min = 99999;
                    acumulado = 0;
                     max = 0;
                    for(int i = 0; i < pruebas; i++){
                        O.wrapper_metodos(banco_shell[i], tam, cte, s_shellsort);
                        if (min > O.get_comparacion())
                            min = O.get_comparacion();
                        if (max < O.get_comparacion())
                            max = O.get_comparacion();
                        acumulado += O.get_comparacion();
                    }
                    medio = acumulado/pruebas;
                    cout << "Shellsort   " << min << "     " << medio << "     " << max << endl;
                    
                    //metodo Quicksort
                     min = 99999;
                     acumulado = 0;
                     max = 0;
                    for(int i = 0; i < pruebas; i++){
                        O.wrapper_metodos(banco_quick[i], tam, cte, s_quicksort);
                        if (min > O.get_comparacion())
                            min = O.get_comparacion();
                        if (max < O.get_comparacion())
                            max = O.get_comparacion();
                        acumulado += O.get_comparacion();
                    }
                     medio = acumulado/pruebas;
                    cout << "Quicksort   " << min << "     " << medio << "     " << max << endl;
                    
                    //metodo Mergesort
                     min = 99999;
                     acumulado = 0;
                     max = 0;
                    for(int i = 0; i < pruebas; i++){
                        O.wrapper_metodos(banco_merge[i], tam, cte, s_mergesort);
                        if (min > O.get_comparacion())
                            min = O.get_comparacion();
                        if (max < O.get_comparacion())
                            max = O.get_comparacion();
                        acumulado += O.get_comparacion();
                    }
                    medio = acumulado/pruebas;
                    cout << "Mergesort   " << min << "     " << medio << "     " << max << endl;
                    //metodo burbuja
                     min = 99999;
                     acumulado = 0;
                     max = 0;
                    for(int i = 0; i < pruebas; i++){
                        O.wrapper_metodos(banco_burbuja[i], tam, cte, s_burbuja);
                        if (min > O.get_comparacion())
                            min = O.get_comparacion();
                        if (max < O.get_comparacion())
                            max = O.get_comparacion();
                        acumulado += O.get_comparacion();
                    }
                     medio = acumulado/pruebas;
                    cout << "Burbuja     " << min << "     " << medio << "     " << max << endl;
            }
            break;
        }
    }while(modo!= 0);
        




return 0;

}