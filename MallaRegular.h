/*
 * MallaRegular.h
 *
 *  Created on: 15/12/2013
 *      Author: druida
 */

#ifndef MALLAREGULAR_H_
#define MALLAREGULAR_H_

#include "CodigoPost.h"
#include <vector>
#include <list>
namespace EEDD {

using namespace std;

template <class U>
class Casilla{
private:
//	template <class T> friend class MallaRegular;
	list<U> puntos;
public:
	inline Casilla(): puntos(){}
	inline void inserta (U &dato) { puntos.push_back(dato); }
	const list<U>* getPuntos() {return &puntos;}
	bool busca (U &dato);
	bool borra (U &dato);

};

template <class U>
inline bool EEDD::Casilla<U>::busca(U& dato){
	class list<U>::iterator it;
	it = puntos.begin();
	while (it != puntos.end()){
		if (*it == dato)
			return true;
	}
	return false;
}

template <class U>
inline bool EEDD::Casilla<U>::borra(U& dato){
	class list<U>::iterator it;
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
private:
	double xMin, yMin, xMax, yMax; //tamaño real global
	double tamaCasillaX, tamaCasillaY; //tamaño real de cada casilla
	vector<vector<Casilla<T> > > mr; //vector 2D de casillas
	Casilla<T>* obtenerCasilla(double x, double y);
public:
	MallaRegular(double aXMin, double aYMin, double aXMax, double aYMax, int
			aNDiv);
	void insertarDato(double x, double y, T &dato);
	Casilla<T>* borrarDato(double x, double y, T& dato);
	vector<T> buscarRango(double rxmin, double rymin, double rxmax, double rymax);
//	double getXMin(int i){return xMin+(tamaCasillaX * i);}
//	double getXMax(int i){return xMin+(tamaCasillaX * (1+i));}
//	double getYMin(int j){return xMin+(tamaCasillaY * j);}
//	double getYMax(int j){return xMin+(tamaCasillaY * (1+j));}
};

template <class T>
inline EEDD::MallaRegular<T>::MallaRegular(double aXMin, double aYMin, double aXMax, double
		aYMax, int aNDiv) : xMin(aXMin), yMin(aYMin), xMax(aXMax), yMax(aYMax){
	tamaCasillaX = (xMax-xMin)/aNDiv;
	tamaCasillaY = (yMax-yMin)/aNDiv;
}
template <class T>
inline Casilla<T>* EEDD::MallaRegular<T>::obtenerCasilla (double x, double y){
	int i = (x - xMin) / tamaCasillaX;
	int j = (y - yMin) / tamaCasillaY;
	return &mr[i][j];
}
template<class T>
inline vector<T> EEDD::MallaRegular<T>::buscarRango(double rxmin,
		double rymin, double rxmax, double rymax) {
//	vector<T> puntos;
//	int i = (rxmin - xMin) / tamaCasillaX;
//	int j = (rymin - yMin) / tamaCasillaY;
//	int iaux = i;
//	while(getYMin(j) <= rxmax){//iteración sobre el eje y
//		while(getXMin(i) <= rxmax ){//iteración sobre el eje x
//			// chequeamos si la casilla está completamente incluida en la selección.
//			if	((rxmin <= getXMin(i)) &&
//					(rxmax >= getXMax(i)) &&
//					(rymin <= getYMin(j)) &&
//					(rxmin >= getYMax(j))){
//				//si esto se cumple añadimos todos los puntos de la casilla al vector
//				//TODO Añadir todos los puntos al vector.
//			//en caso contrario hacemos un test de inclusión de la casilla e insertamos aquellos puntos dentro de la selección.
//			}else{
//				list <T> pCas = mr[i][j].puntos;
//				list<T>::const_iterator it;
//				for (iterator = pCas.begin(); it != pCas.end(); ++it) {
//				    double lat = (static_cast<CodigoPost*>(*it))->getLat();
//				    double lon = (static_cast<CodigoPost*>(*it))->getLon();
//				}
//			}
//			i++;
//		}//end_iteración sobre x
//		i = iaux;
//		j++;
//	}//end_iteración sobre y
	throw "";
}
template <class T>
inline void MallaRegular<T>::insertarDato(double x, double y, T& dato){
	Casilla<T> *c = obtenerCasilla(x,y);
	c->inserta(dato);
}

template <class T>
inline Casilla<T>* EEDD::MallaRegular<T>::borrarDato(double x, double y, T& dato){
	Casilla<T> *c = obtenerCasilla(x,y);
	if (c->borra(dato))
		return c;
	return 0;
}



} /* namespace EEDD */

#endif /* MALLAREGULAR_H_ */
