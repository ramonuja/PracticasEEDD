/* 
 * File:   Lista.h
 * Author: Jose
 *
 * Created on 19 de octubre de 2013, 13:02
 */

#ifndef LISTA_H
#define	LISTA_H

#include<iostream>
#include "Nodo.h"
#include "Iterador.h"

using namespace std;


template<class T>
class Lista {
private:    
Nodo<T> *cabecera, *cola;

public:
Lista() : cabecera(0), cola(0) {}
~Lista();
Lista(const Lista &l);

                //Lista &operator=(Lista &l);
  // Operador de asignación. 
    T &operator=(const Lista &lis1);

Iterador<T> iteradorInicio() { return Iterador<T>(cabecera); }
Iterador<T> iteradorFinal() { return Iterador<T>(cola); }
void insertarInicio(T &dato);
void insertarFinal(T &dato);
void insertar(Iterador<T> &i, T &dato);
void borrarInicio();
void borrarFinal();
void borrar(Iterador<T> &i);
T &inicio() { return cabecera->dato; }
T &final() { return cola->dato; }

int tam();//Devuelve el tamaño de la lista.
Lista(Iterador<T> &it1, Iterador<T> &it2);

void transferirDesde (Iterador<T> &it1, Iterador<T> &it2, Lista &l);
/*
   // Mueve los datos de la lista comprendidos entre los iteradores a la lista que llama a la función, siendo it1<=it2. 
    void transferirDesde(Iterador<T> it1, Iterador<T> it2, Lista<T> &lista);
 
 */


void insertaOrdenado (T &dato);
bool insertaOrdenadoNoRepe (T &dato);
bool ordenada();
void vaciar();
void merge (Lista<T> &l1); //mezcla instancia de la lista con l1 como parametro

};




template<class T>
T &Lista<T>::operator =(const Lista<T> &lis1){
    Iterador<T> it(lis1.cabecera);
    vaciar();
    
    while(it.haySiguiente()){
        insertarFinal(it.dato());
        it.siguiente();
    }
    insertarFinal(it.dato());
}


 
template<class T>
Lista<T>::Lista(const Lista<T> &orig):cabecera(0), cola(0){
    Iterador<T> it(orig.cabecera);
    
    while(it.haySiguiente()){
        insertarFinal(it.dato());
        it.siguiente();
        if(!it.haySiguiente())
            insertarFinal(it.dato());
    }
}

/*
template<class T>
Lista<T>::Lista(Iterador<T> it1, Iterador<T> it2):cabecera(0), cola(0){
    
    if(it1==it2)
        insertarFinal(it1.dato());
    else if(it1<=it2){
        while(it1!=it2){
            insertarFinal(it1.dato());
            it1.siguiente();
            if(it1==it2)
                insertarFinal(it1.dato());
        }
    }else
        throw "FalloIteradores";
}*/

/*
template<class T>
Lista<T>::Lista(Iterador<T>& it1, Iterador<T>& it2){
    //Crea una lista a partir de los iteradores it1 e it2 asociados a otra lista "l"
    Iterador<int> p;
    cabecera=0;
    cola=0;
    p=it1.nodo;
    while(p.nodo!=it2.nodo){
        insertarFinal(p.dato());
        p.siguiente();
    }
}
*/




template<class T>
void Lista<T>::transferirDesde (Iterador<T> &it1, Iterador<T> &it2, Lista &l) {
    if(it1<=it2){
        tam()==0?cabecera=it1.nodo:cola->sig=it1.nodo;
        
        cola = it2.nodo;
        l.cabecera = 0;
        l.cola = 0;
    }else
        throw "FalloIteradores";
}




template<class T>
bool Lista<T>::insertaOrdenadoNoRepe (T &dato){
    //if(ordenada()){
        Iterador<T> it(cabecera);
        if(cabecera!=0){
            while(it.haySiguiente())
                if(it.dato()==dato)
                    return false;
                else{
                    if(dato>this->cola->dato){
                        insertarFinal(dato);
                        return true;
                    }else if(dato<this->cabecera->dato){
                        insertarInicio(dato);
                        return true;
                    }else{
                        it.siguiente();
                        if(!it.haySiguiente() && it.dato()==dato)
                            return false;
                    }
                }
        }
        insertaOrdenado(dato);
        return true;
    //}else  //throw ListaDesordenada();
    
/*
    //Mismo proceso de insercion que la funcion insertarOrdenado pero NO datos repetidos.
    Nodo<T> *nuevo;
    Iterador<T> it1=0;
    Iterador<T> i;
    nuevo=i.nodo;
    while(it1.haySiguiente()){
        i.siguiente();
    if(i.nodo==it1.nodo){
        return false;  }else{  insertar(i,it1.dato());
    }
  }
    return true;
*/
}





template<class T>
void Lista<T>::insertaOrdenado(T& dato){
     //if(ordenada()){
        Iterador<T> it(cabecera);
        //if(tam()==0) insertarFinal(dato);
        if(this->cola==0) insertarFinal(dato);
        //else if(tam()==1){
        else if(this->cola==this->cabecera){
            if(it.dato()<=dato) insertarFinal(dato);
            else insertarInicio(dato);
        }else{
            if(dato>=this->cola->dato) insertarFinal(dato);
            else if(dato<=this->cabecera->dato) insertarInicio(dato);
            else{
                while(it.haySiguiente())
                    if(dato<=it.dato()){
                        insertar(it, dato);
                        break;
                    }else{
                        it.siguiente();
                        if(!it.haySiguiente()){
                            if(it.dato()<=dato) insertarFinal(dato);
                            else insertar(it,dato);
                            break;
                        }
                    }
            }
        }
    //}else   throw ListaDesordenada();
   
/*
    //Inserta dato ordenando la lista ( de menor a mayor) 
     Iterador<T> it =0;
        while(it.nodo!=0 && it.dato() < dato){
                it.siguiente();
        }
        if(it.nodo!=0)
            insertar(it, dato);
        else
            insertarFinal(dato);
*/
}




template<class T>
bool Lista<T>::ordenada(){
 Iterador<T> it(cabecera);
    if(tam()==0 || tam()==1)
        return true;
    else{
        while(it.haySiguiente()){
            if(it.dato()<=it.nodo->sig->dato)
                it.siguiente();
            else
                return false;
        }
    }
    return true;
    
 /*
    //Dice si la lista esta o no ordenada ( menor a mayor) 
    Iterador<T> *it1=iteradorInicio();
    Iterador<T> *it2=iteradorInicio();

    while (it2.haySiguiente()&& true){
        if(it1->dato()<it2->dato()){
            return false;
        }
        else{
            it1->siguiente();
            it2->siguiente();
            return true;
        }
    }
*/
}





template<class T>
void Lista<T>::vaciar(){
    Iterador<T> it(cabecera);
    if(tam()!=0){
        while(it.haySiguiente()){
            it.siguiente();
            delete it.nodo->ant;
        }
        delete it.nodo;
    }
    cabecera = 0;
    cola = 0;
    
/*
    //Vaciar lista
     while(cola != 0){ 
         borrarInicio(); 
     }
     cabecera,cola=0;
*/
}





template<class T>
void Lista<T>::insertarInicio(T &dato){
    Nodo<T> *nodo;
    nodo = new Nodo<T>(dato, 0, cabecera);
    
    if(cola==0) cola = nodo;
    if(cabecera!=0) cabecera->ant = nodo;    
    cabecera = nodo;
}



template<class T>
void Lista<T>::insertarFinal(T &dato){
    Nodo<T> *nodo;
    nodo = new Nodo<T>(dato, cola, 0);
    
    if(cabecera==0) cabecera = nodo;
    if(cola!=0) cola->sig = nodo;
    cola = nodo;
}



template<class T>
void Lista<T>::insertar(Iterador<T> &it, T &dato){
    Nodo<T> *nodo;
    nodo = new Nodo<T>(dato, it.nodo->ant, it.nodo);
    
    if(nodo->ant!=0)
        nodo->ant->sig = nodo;
    else
        cabecera = nodo;
    
    if(nodo->sig!=0)
        nodo->sig->ant = nodo;
    else
        cola = nodo;
    
    /*
     Nodo<T> *nuevo;
    nuevo = new Nodo<T>(dato, i.nodo->ant, i.nodo);
    i.nodo->ant->sig=nuevo ;
    i.nodo->ant=nuevo;
    if(cabecera==0) cabecera=cola=nuevo;
     */
    
}



template<class T>
void Lista<T>::borrarInicio() {
    cabecera = cabecera->sig;
    delete cabecera->ant;
    cabecera!=0?cabecera->ant=0:cola=0;
}


template<class T>
void Lista<T>::borrarFinal() {
    cola = cola->ant;
    delete cola->sig;
    cola!=0?cola->sig=0:cabecera=0;
}



template<class T>
void Lista<T>::borrar(Iterador<T> &it) {
    if(it.nodo->ant!=0)
        it.nodo->ant->sig = it.nodo->sig;
    else
        cabecera = it.nodo->sig;
    
    if(it.nodo->sig!=0)
        it.nodo->sig->ant = it.nodo->ant;
    else
        cola = it.nodo->ant;
    
    it = 0;
    /*
Nodo<T> *borrado;
borrado = it->nodo;
    borrado->ant->sig=borrado->sig;
    borrado->sig->ant=borrado->ant;
                delete borrado;
*/
}



template<class T>
int Lista<T>::tam(){
    if(cabecera==0) return 0;
    Iterador<T> it(cabecera);
    int i=1;
    while(it.haySiguiente()){
        i++;
        it.siguiente();
    }
    return i;
}



template<class T>
Lista<T>::~Lista(){
    vaciar();
    delete cabecera;
    delete cola;
}



#endif	/* LISTA_H */
