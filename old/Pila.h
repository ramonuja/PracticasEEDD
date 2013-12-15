/*
 * Pila.h
 *
 *  Created on: 11/11/2013
 *      Author: druida
 */

#ifndef PILA_H_
#define PILA_H_
#include "Lista.h"
namespace EEDD {
template <class S>
class Pila {
private:
	Lista<S> lista;
public:
	S& dato();
	S& pop();
	void push(S& dato);
	Pila();
	virtual ~Pila();
};

} /* namespace EEDD */

template<class S>
inline S& EEDD::Pila<S>::pop() {
	Iterador<S>* it = lista.iteradorFin();
		if(it->haySiguiente()){
			S t = it->dato();
			lista.borrarFin();
			return t;
		}
		return 0;
}

template<class S>
inline void EEDD::Pila<S>::push(S& dato) {
	lista.insertarFin(dato);
}

template<class S>
inline EEDD::Pila<S>::Pila() {

}

template<class S>
inline S& EEDD::Pila<S>::dato() {
	return lista.iteradorFin()->dato();
}

template<class S>
inline EEDD::Pila<S>::~Pila() {
}

#endif /* PILA_H_ */
