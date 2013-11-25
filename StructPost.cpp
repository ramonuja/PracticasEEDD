/*
 * Ciudad.cpp
 *
 *  Created on: 10/11/2013
 *      Author: druida
 */

#include "StructPost.h"

namespace EEDD {

StructPost::StructPost() {
	// TODO Auto-generated constructor stub

}


const string& StructPost::getNombreCiudad() const {
	return nombreCiudad;
}

void StructPost::setNombreCiudad(const string& nombreCiudad) {
	this->nombreCiudad = nombreCiudad;
}

StructPost::~StructPost() {
	// TODO Auto-generated destructor stub
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
