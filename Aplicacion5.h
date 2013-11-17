/*
 * Aplicacion5.h
 *
 *  Created on: 17/11/2013
 *      Author: druida
 */

#ifndef APLICACION5_H_
#define APLICACION5_H_
#include <map>
#include <iostream>
#include <string>
#include "Ciudad.h"
#include "Lista.h"
#include "CargadorDatos.h"
namespace EEDD {

class Aplicacion5 {
private:
	void cargarArbol(map<string,Ciudad*> *avl);
	void mostrarDetallesCiudad(map<string,Ciudad*> *avl,string nombreCiudad);
	Lista<Ciudad*> ciudades;
	Lista<DetalleLinea*> lineas;
public:
	Aplicacion5();
	virtual ~Aplicacion5();
	int ejecutar(int argc, char** argv);
};

} /* namespace EEDD */
#endif /* APLICACION5_H_ */
