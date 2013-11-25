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
#include "StructPost.h"
#include "Lista.h"
#include "CargadorDatos.h"
namespace EEDD {

class Aplicacion5 {
private:
	void cargarArbol(map<string,StructPost*> *avl);
	void mostrarDetallesCiudad(map<string,StructPost*> *avl,string nombreCiudad);
	Lista<StructPost*> ciudades;
	Lista<CodigoPost*> lineas;
public:
	Aplicacion5();
	virtual ~Aplicacion5();
	int ejecutar(int argc, char** argv);
};

} /* namespace EEDD */
#endif /* APLICACION5_H_ */
