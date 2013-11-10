/*
 * Avl.h
 *
 *  Created on: 10/11/2013
 *      Author: druida
 */

#ifndef AVL_H_
#define AVL_H_
#include "NodoAvl.h"
namespace EEDD {

template <typename T>
class Avl {
private:
	NodoAvl<T> *raiz;

	void rotdecha(NodoAvl<T>* &p);
	void rotizqda(NodoAvl<T>* &p);
	NodoAvl<T>* buscaClave(T &ele, NodoAvl<T> *p);
public:
	Avl();
	virtual ~Avl();
	bool insertarNR(NodoAvl<T>* &c, T& dato);
	bool insertarNR(T& dato);
	T *busquedaNR(T &dato);
};


template<typename T>
inline void EEDD::Avl<T>::rotdecha(NodoAvl<T>*& p) {
	NodoAvl<T> *q = p, *l;
	p = l = q->izq;
	q->izq = l->der;
	l->der = q;
	q->bal--;
	if (l->bal > 0) q->bal -= l->bal;
	l->bal--;
	if(q->bal < 0) l->bal -= -q->bal;
}

template<typename T>
inline void EEDD::Avl<T>::rotizqda(NodoAvl<T>* &p) {
	NodoAvl<T> *q = p, *r;
	p = r = q->der;
	q->der = r->izq;
	r->izq = q;
	q->bal++;
	if (r->bal < 0) q->bal += -r->bal;
	r->bal++;
	if(q->bal > 0) r->bal += q->bal;
}

template<typename T>
inline EEDD::Avl<T>::Avl() {
	raiz = 0;
}

template<typename T>
inline EEDD::Avl<T>::~Avl() {
}

template<typename T>
inline bool EEDD::Avl<T>::insertarNR(NodoAvl<T>* &c, T& dato) {
	NodoAvl<T> *p = c;
	bool deltaH = 0;
	if (!p){
		p = new NodoAvl<T>(dato);
		c = p; deltaH=1;
	}
	else if (dato > p->dato){
		if (insertarNR(p->der, dato)){
			p->bal--;
			if (p->bal == -1) deltaH=1;
			else if (p->bal == -2) {
				if (p->der->bal == 1) rotdecha(p->der);
				rotizqda(c);
			} } }
	else if (dato < p->dato){
		if (insertarNR(p->izq, dato)){
			p->bal++;
			if (p->bal==1) deltaH = 1;
			else if (p->bal == 2){
				if (p->izq->bal == -1) rotizqda(p->izq);
				rotdecha(c);
			} } }
	return deltaH;
}

template<typename T>
inline bool EEDD::Avl<T>::insertarNR(T& dato) {
	return insertarNR(raiz, dato);
}

template<typename T>
inline NodoAvl<T>* EEDD::Avl<T>::buscaClave(T &ele, NodoAvl<T> *p) {
	if (!p)
		return 0;
	else if (ele < p->dato)
		return buscaClave (ele, p->izq);
	else if (ele > p-> dato)
		return buscaClave (ele, p->der);
	else return p;
}


template<typename T>
inline T* EEDD::Avl<T>::busquedaNR(T& dato) {
	NodoAvl<T> *p = buscaClave(dato,raiz);
	if (p) {
		return &p->dato;
	}
	return 0;
}

#endif /* AVL_H_ */

} /* namespace EEDD */
