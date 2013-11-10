/*
 * Lista.h
 *
 *  Created on: 20/10/2013
 *      Author: Ramón
 */

#ifndef LISTA_H_
#define LISTA_H_

namespace EEDD {
#include <string>

using namespace std;
template <class T>
	class Nodo {
	public:
	Nodo(T &aDato, Nodo<T> *aAnt, Nodo<T> *aSig):	dato(aDato), ant(aAnt), sig(aSig) {}
	T dato;
	Nodo<T> *ant, *sig;
};

template <class T>
class Iterador {
	Nodo<T> *nodo;
	public:
	Iterador(Nodo<T> *aNodo) : nodo(aNodo) {}
	bool hayAnterior() { return nodo != 0; }
	bool haySiguiente() { return nodo != 0; }
	void anterior() { nodo = nodo->ant; }
	void siguiente() { nodo = nodo->sig; }
	T& dato() { return nodo->dato; }
};


template <class T>
class Lista {
public:
	inline Lista(): cabecera(0),cola(0) {}
	virtual inline ~Lista(){
		if(cabecera == 0) return;

		Nodo<T> *rec;
		rec = cabecera;
		while(rec->sig!=0){
			rec = rec->sig;
			delete rec->ant;
		}
		delete rec;
	}

	inline int tam(){
		if (cabecera == 0) return 0;
		Nodo<T> *rec;
		rec = cabecera;
		int cont = 0;
		while (rec != 0){
			cont++;
			rec = rec->sig;
		}

		return cont;
	}
	inline Iterador<T>* iteradorIni(){return new Iterador<T>(cabecera);}
	inline Iterador<T>* iteradorFin(){return new Iterador<T>(cola);}

	inline void insertar(Iterador<T> &it, const T &dato){
		//TODO Todavía por implementar
		Nodo<T> *nuevo;

		// Caso especial: si la lista estaba
		// vacía, poner la cola apuntando al nodo
		if (cola == 0){
			nuevo = new Nodo<T>(dato, 0, 0);
			cola = nuevo;
			cabecera = nuevo;
			return;
		}

		//inserción al principio
		if(!it.hayAnterior()){
			nuevo = new Nodo<T>(dato, 0, cabecera);
			cabecera = nuevo;
			return;
		}
		//insercion al final
		if(!it.haySiguiente()){
			insertarFin(dato);
			return;
		}
		//inserción en medio
		Nodo<T> *temp = cabecera;
		while(temp != 0){
			if(&temp->dato == &it.dato()){
				nuevo = new Nodo<T>(dato,temp,temp->sig);
				temp->sig = nuevo;
				nuevo->sig->ant = nuevo;
			}//end if
		}//end while

	}

	inline void borrar(Iterador<T> &it){
		Nodo<T> *temp;
		//si el tamaño de la lista es 1, borramos el elemento y ponemos cabecera y cola a 0
		if(tam() == 1){
			delete cabecera;
			cabecera = 0;
			cola = 0;
			return;
		}
		//si vamos a borrar el primer elemento
		if(&it.dato() == cabecera ){
			temp = cabecera;
			cabecera = cabecera->next;
			delete temp;
			return;
		}

		//si vamos a borrar el último elemento...
		if (&it.dato() == cola){
			borrarFin();
			return;
		}
		//y si finalmente vamos a borrar un dato en el medio.
		temp = cabecera;
		while(temp != 0){
			if(&temp->dato == &it.dato()){
				temp->ant->sig = temp->sig;
				temp->sig->ant = temp->ant;
			}//end if
		}//end while
	}

	inline void insertarFin(T &dato){
		Nodo<T> *nuevo = new Nodo<T>(dato, cola, 0);
		//caso especial: si la lista estaba vacía,
		//poner la cola apuntando al nodo
		if (cabecera == 0)
			cabecera = nuevo;
		if (cola != 0)
			cola->sig = nuevo;
		cola = nuevo;
	}

	inline void borrarFin(){
		//caso especial, si la cola está vacía no hacemos nada
		if (cabecera == 0) return;
		//si queda mas de un elemento en la lista la cola apunta al elemento anterior
		if(cola->ant != 0){
			cola = cola->ant;
			delete cola->sig;
		}else{//si solo quedaba un elemento en la lista...
			delete cola;
			cola = 0;
			cabecera = 0;
		}
	}/*
	inline string toString(){
		if(tam()==0) return "";
		Iterador<T> it = iteradorIni();
		stringstream ss;
		while(it.haySiguiente()){
			ss << it.dato();
		}
		return "cadena de prueba";
	}*/
private:
	Nodo<T> *cabecera, *cola;
};



} /* namespace EEDD */
#endif /* LISTA_H_ */
