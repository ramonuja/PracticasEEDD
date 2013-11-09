/*
 * Lista.h
 *
 *  Created on: 20/10/2013
 *      Author: druida
 */

#ifndef LISTA_H_
#define LISTA_H_

namespace EEDD {
template <class T>
	class Nodo {
	public:
	T dato;
	Nodo *ant, *sig;
	Nodo(T &aDato, Nodo *aAnt, Nodo *aSig):	dato(aDato), ant(aAnt), sig(aSig) {}
};

template <class T>
class Iterador {
	Nodo<T> *nodo;
	public:
	Iterador(Nodo *aNodo) : nodo(aNodo) {}
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
	inline Iterador<T>& iteradorIni(){return new Iterador<T>(cabecera);}
	inline Iterador<T>& iteradorFin(){return new Iterador<T>(cola);}

	inline void insertar(Iterador<T> &it, const T &dato){
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


	}

	inline void borrar(Iterador<T> &it){

	}

	inline void insertarFin(const T &dato){

	}

	inline void borrarFin(){

	}

private:
	Nodo *cabecera, *cola;
};



} /* namespace EEDD */
#endif /* LISTA_H_ */
