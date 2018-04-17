#pragma once 
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int  MIN = 30000000;
const int  MAX = 80000000;

class DNI{
    
    int dni;
   
public:

DNI(int dn){
    if((dn < MIN )|| (dn > MAX))
     cout << "error en dni"<<endl;
    else
     dni = dn;

     
}
 
DNI(){
     
   srand(time(NULL));
   int dn = MIN + rand() % (MAX - MIN);
   dni = dn;

     
}

~DNI(){
}
  

int get_dni(){

    return dni;
}


void set_dni(int dn){
    dni = dn;
}


bool operator==(const DNI& b){
    
    if(dni == b.dni)
        return true;
    else
        return false;
}


bool operator<(const DNI& b){
    if(dni < b.dni)
        return true;
    else
        return false;
}


bool operator>(const DNI& b){
        if(dni > b.dni)
        return true;
    else
        return false;
}
bool operator<=(const DNI& b){
        if(dni <= b.dni)
        return true;
    else
        return false;
}

bool operator>=(const DNI& b){
         if(dni >= b.dni)
        return true;
    else
        return false;
}

};