/*
 * NodoAvl.h
 *
 *  Created on: 10/11/2013
 *      Author: druida
 */

#ifndef NODOAVL_H_
#define NODOAVL_H_

namespace EEDD {
template <class T>
class NodoAvl {
public:
	NodoAvl<T> *izq;
	NodoAvl<T> *der;
	T dato;
	char bal;
	NodoAvl(T &ele):izq(0),der(0),dato(ele),bal(0),balancearPendiente(0){}
	virtual ~NodoAvl(){}
	char balancearPendiente;
};

} /* namespace EEDD */
#endif /* NODOAVL_H_ */
