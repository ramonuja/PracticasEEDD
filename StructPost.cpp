/*
 * Ciudad.cpp
 *
 *  Created on: 10/11/2013
 *      Author: druida
 */

#include "StructPost.h"

namespace EEDD {

StructPost::StructPost() {

}


const string& StructPost::getNombreCiudad() const {
	return nombreCiudad;
}

void StructPost::setNombreCiudad(const string& nombreCiudad) {
	this->nombreCiudad = nombreCiudad;
}

StructPost::~StructPost() {
}

bool StructPost::operator <(StructPost& ci) {
	return nombreCiudad < ci.getNombreCiudad();
}

 Lista<CodigoPost*>& StructPost::getListadoCodigos()  {
	return listadoCodigos;
}

void StructPost::setListadoCodigos( Lista<CodigoPost*>& listadoCodigos) {
	this->listadoCodigos = listadoCodigos;
}

bool StructPost::operator >(StructPost& ci) {
	return nombreCiudad > ci.getNombreCiudad();
}

} /* namespace EEDD */
