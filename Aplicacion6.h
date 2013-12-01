/*
 * Aplicacion5.h
 *
 *  Created on: 17/11/2013
 *      Author: druida
 */

#ifndef APLICACION6_H_
#define APLICACION6_H_
#include <iostream>
#include <string>
#include "StructPost.h"
#include "Lista.h"
#include "CargadorDatos.h"
#include "Dispersion.h"
namespace EEDD {

class Aplicacion6 {
private:
	unsigned long djb2(string s);
	void cargarTablaDispersion(Dispersion<StructPost> &disp);
	void mostrarDetallesCiudad(Dispersion<StructPost> &disp, string nombreCiudad);
public:
	Aplicacion6();
	virtual ~Aplicacion6();
	int ejecutar(int argc, char** argv);
};

} /* namespace EEDD */
#endif /* APLICACION5_H_ */
