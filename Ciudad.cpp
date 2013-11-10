/*
 * Ciudad.cpp
 *
 *  Created on: 10/11/2013
 *      Author: druida
 */

#include "Ciudad.h"

namespace EEDD {

Ciudad::Ciudad() {
	// TODO Auto-generated constructor stub

}

Lista<DetalleLinea>& Ciudad::getListadoCodigos() {
	return listadoCodigos;
}

void Ciudad::setListadoCodigos(Lista<DetalleLinea>& listadoCodigos) {
	this->listadoCodigos = listadoCodigos;
}

const string& Ciudad::getNombreCiudad() const {
	return nombreCiudad;
}

void Ciudad::setNombreCiudad(const string& nombreCiudad) {
	this->nombreCiudad = nombreCiudad;
}

Ciudad::~Ciudad() {
	// TODO Auto-generated destructor stub
}

bool Ciudad::operator <(Ciudad& ci) {
	return nombreCiudad < ci.getNombreCiudad();
}

bool Ciudad::operator >(Ciudad& ci) {
	return nombreCiudad > ci.getNombreCiudad();
}

} /* namespace EEDD */
