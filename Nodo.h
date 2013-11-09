/* 
 * File:   Nodo.h
 * Author: Jose
 *
 * Created on 19 de octubre de 2013, 13:03
 */

#ifndef NODO_H
#define	NODO_H


template<class T> class Iterador;
template<class T> class Lista;


template<class T>
class Nodo {
    
private:
    T dato;
    Nodo<T> *ant, *sig;
    friend class Iterador<T>;
    friend class Lista<T>;
    
    
public:
     Nodo(){}
    // Constructor que pasándole un dato crea un nodo entre dos nodos pasados también. 
    Nodo(T &_dato, Nodo<T> *_ant, Nodo<T> *_sig):dato(_dato), ant(_ant), sig(_sig){}
    // Constructor de copia. 
    Nodo(const Nodo<T> &orig):dato(orig.dato), ant(orig.ant), sig(orig.sig){}
    // Destructor de la clase. 
    ~Nodo(){}
    
};


#endif	/* NODO_H */