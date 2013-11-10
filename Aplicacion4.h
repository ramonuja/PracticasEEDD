/*
 * Aplicacion4.h
 *
 *  Created on: 07/11/2013
 *      Author: druida
 */

#ifndef APLICACION4_H_
#define APLICACION4_H_
#include <iostream>
#include <string>
#include "Ciudad.h"
#include "Avl.h"
#include "Lista.h"
using namespace std;
namespace EEDD {

class Aplicacion4 {
private:
	void cargarArbol(Avl<Ciudad> *avl);
	void mostrarDetallesCiudad(Avl<Ciudad> *avl,string nombreCiudad);
public:
	Aplicacion4();
	virtual ~Aplicacion4();
	int ejecutar(int argc, char** argv);
};

} /* namespace EEDD */
#endif /* APLICACION4_H_ */
