/*
 * Dispersion.h
 *
 *  Created on: 25/11/2013
 *      Author: ramon
 */

#ifndef DISPERSION_H_
#define DISPERSION_H_

namespace EEDD {
template<class T>
class ElementoDisperso {
private:
	unsigned long clave;
	T dato;
	bool disponible;
public:
	ElementoDisperso();
	~ElementoDisperso();
	T& getDato();
	bool estaDisponible();
	unsigned long getClave();

	void setClave(unsigned long clave) {
		this->clave = clave;
	}

	void setDato(T &dato) {
		this->dato = dato;
	}

	bool isDisponible() const {
		return disponible;
	}

	void setDisponible(bool disponible) {
		this->disponible = disponible;
	}
};
template<class T>
class Dispersion {
private:
	ElementoDisperso<T> *datos;
	/*función de dispersión*/
	int h(unsigned long clave, int i);
	/**función de dispersión 1*/
	int h1(unsigned long clave);
	/**función de dispersión 2*/
	int h2(unsigned long clave);
	int tam;
public:
	int maxI;
	/** Crear la tabla con un tamaño dado*/
	Dispersion(int tam);
	/** Insertar el dato indicado. Devuelve false si el dato existe o el dato no ha podido ser insertado en menos de 5 intentos */
	bool insertar(unsigned long clave, T &dato);
	/** Buscar el dato indicado. Devuelve un puntero nulo si no existe */
	T* buscar(unsigned long clave);
	~Dispersion();
};


} /* namespace EEDD */

template<class T>
inline EEDD::Dispersion<T>::Dispersion(int tam):tam(tam),maxI(0) {
	datos = new ElementoDisperso<T>[tam];
}

template<class T>
inline bool EEDD::Dispersion<T>::insertar( unsigned long clave, T &dato) {
	int i = 0;
	int indice = 0;
	for (i = 0; i < 1000; ++i) {
		indice = h(clave, i);
		if (datos[indice].isDisponible()){
			datos[indice].setDisponible(false);
			datos[indice].setClave(clave);
			datos[indice].setDato(dato);
			break;
		}
	}//end for
	if (i > maxI) maxI = i;
	return i==0 ? true : false;
}

template<class T>
inline T* EEDD::Dispersion<T>::buscar(const unsigned long clave) {
	int i = 0;
		int indice = 0;
		for (i = 0; i < 1000; ++i) {
			indice = h(clave, i);
			if (!datos[indice].isDisponible()){
				if(datos[indice].getClave()==clave){
					return &(datos[indice].getDato());
				}
			}
		}//end for
		return 0;
}

template<class T>
inline int EEDD::Dispersion<T>::h(unsigned long clave, int i) {
	return (h1(clave) + i * h2(clave))%tam;
}

template<class T>
inline int EEDD::Dispersion<T>::h1(unsigned long clave) {
	return clave%tam;
}

template<class T>
inline int EEDD::Dispersion<T>::h2(unsigned long clave) {
	return (clave%(tam-2)) + 1;
}

template<class T>
inline EEDD::Dispersion<T>::~Dispersion() {
	delete [] datos;
}

template<class T>
inline EEDD::ElementoDisperso<T>::ElementoDisperso():clave(0),disponible(true) {
}

template<class T>
inline EEDD::ElementoDisperso<T>::~ElementoDisperso() {
}

template<class T>
inline T& EEDD::ElementoDisperso<T>::getDato() {
	return dato;
}

template<class T>
inline bool EEDD::ElementoDisperso<T>::estaDisponible() {
	return disponible;
}

template<class T>
inline unsigned long EEDD::ElementoDisperso<T>::getClave() {
	return clave;
}

#endif /* DISPERSION_H_ */
