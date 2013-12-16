/*
 * MallaRegular.h
 *
 *  Created on: 15/12/2013
 *      Author: druida
 */

#ifndef MALLAREGULAR_H_
#define MALLAREGULAR_H_

#include <vector>
#include <list>
using namespace std;

namespace EEDD {

template <class U>
class Casilla{
	list<U> puntos;
public:
	friend class MallaRegular<U>;
	Casilla(): puntos(){}
	void inserta (U &dato) { puntos.push_back(dato); }
	const list<U>* getPuntos() {return &puntos;}
	bool busca (U &dato);
	bool borra (U &dato);

};

template <class U>
bool Casilla<U>::busca(U& dato){
	typename list<U>::iterator it;
	it = puntos.begin();
	while (it != puntos.end()){
		if (*it == dato)
			return true;
	}
	return false;
}

template <class U>
bool Casilla<U>::borra(U& dato){
	typename list<U>::iterator it;
	it = puntos.begin();
	while (it != puntos.end()){
		if (*it == dato)
			puntos.erase(it);
		return true;
	}
	return false;
}
template <class T>
class MallaRegular {
	float xMin, yMin, xMax, yMax; //tamaño real global
	float tamaCasillaX, tamaCasillaY; //tamaño real de cada casilla
	vector<vector<Casilla<T> > > mr; //vector 2D de casillas
	Casilla<T> *obtenerCasilla(float x, float y);
public:
	MallaRegular(float aXMin, float aYMin, float aXMax, float aYMax, int
			aNDiv);
	void insertarDato(float x, float y, T &dato);
	Casilla<T> *borrarDato(float x, float y, T& dato);
	vector<T> buscarRango(float rxmin, float rymin, float rxmax, float rymax);
	float getRXMin(int i){return xMin+(tamaCasillaX * i);}
	float getRXMax(int i){return xMin+(tamaCasillaX * (1+i));}
	float getRYMin(int j){return xMin+(tamaCasillaY * j);}
	float getRYMax(int j){return xMin+(tamaCasillaY * (1+j));}
};

template <class T>
MallaRegular<T>::MallaRegular(float aXMin, float aYMin, float aXMax, float
		aYMax, int aNDiv) : xMin(aXMin), yMin(aYMin), xMax(aXMax), yMax(aYMax){
	tamaCasillaX = (xMax-xMin)/aNDiv;
	tamaCasillaY = (yMax-yMin)/aNDiv;
}
template <class T>
Casilla<T> *MallaRegular<T>::obtenerCasilla (float x, float y){
	int i = (x - xMin) / tamaCasillaX;
	int j = (y - yMin) / tamaCasillaY;
	return &mr[i][j];
}
template<class T>
inline vector<T> EEDD::MallaRegular<T>::buscarRango(float rxmin,
		float rymin, float rxmax, float rymax) {
	//		float posicionXActual = rxmin;
//		float posicionYActual = rymin;
//		int i = (rxmin - xMin) / tamaCasillaX;
//		int j = (rymin - yMin) / tamaCasillaY;
//		while(true){//iteración sobre el eje y
//			while(getRXMin(i) < ){//iteración sobre el eje x
//				// chequeamos si la casilla está completamente incluida en la selección.
//				if	((rxmin >= getRXMin(i)) &&
//					(rxmax <= getRXMax(i)) &&
//					(rymin >= getRYMin(j)) &&
//					(rxmin >= getRYMax(j))){
//
//				}//end_if
//			}//end_iteración sobre x
//		}//end_iteración sobre y
	for (vector<vector<Casilla<T>>>::iterator it = mr.begin() ; it != mr.end(); ++it){
		it
//		for (std::vector<Casilla<T> >::iterator it2 = it.; it2 != mr.end(); ++it2){
//
//		}
	}
}
template <class T>
void MallaRegular<T>::insertarDato(float x, float y, T& dato){
	Casilla<T> *c = obtenerCasilla(x,y);
	c->inserta(dato);
}

template <class T>
Casilla<T> *MallaRegular<T>::borrarDato(float x, float y, T& dato){
	Casilla<T> *c = obtenerCasilla(x,y);
	if (c->borra(dato))
		return c;
	return 0;
}



} /* namespace EEDD */

#endif /* MALLAREGULAR_H_ */
