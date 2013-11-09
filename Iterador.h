/* 
 * File:   Iterador.h
 * Author: Jose
 *
 * Created on 19 de octubre de 2013, 13:03
 */

#ifndef ITERADOR_H
#define	ITERADOR_H

#include "Lista.h"
#include "Nodo.h"



template<class T>
class Iterador {
private:
    //friend class Lista;
    //friend class Lista<T>;  este o el de arriba??

public:
    Nodo<T> *nodo;
Iterador(Nodo<T> *aNodo) : nodo(aNodo) {} // Constructor que crea un iterador en el nodo pasado. 
bool hayAnterior() { return nodo != 0; }
bool haySiguiente() { return nodo != 0; }
void anterior() { nodo = nodo->ant; }  //retrocede nodo
void siguiente() { nodo = nodo->sig; }  //avanza nodo

bool fin(){return nodo==0;}  //comprueba si el nodo es el ultimo

void Siguiente(){  //Desplaza el actual al nodo siguiente
    nodo=nodo->sig;
}


T &dato() { return nodo->dato; }  //Asocia a cada nodo un dato. Devuelve el dato del nodo actual



//Operadores

// Operador de comparación. 
bool operator==(const Iterador &it1){ return nodo==it1.nodo?true:false; }
// Operador distinto. 
bool operator!=(const Iterador &it1){ return nodo!=it1.nodo?true:false; }
// Operador menor o igual. 
bool operator<=(const Iterador &it1);


Iterador(const Iterador& orig);
~Iterador();
    
};


template<class T>
bool Iterador<T>::operator <=(const Iterador& it1){
    Iterador<T> iAux(nodo);
    
    while(iAux.haySiguiente() && iAux!=it1){
        iAux.siguiente();
    }
    
    return iAux==it1?true:false;
}



/*
// escribir 0 en todas las posiciones de la lista
Iterador<int> i = lista.iterador();
while(!i.fin()){
    i.dato()=0;
    i.siguiente();
}
*/


#endif	/* ITERADOR_H */

