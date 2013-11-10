/*
 * Ciudad.h
 *
 *  Created on: 10/11/2013
 *      Author: druida
 */

#ifndef CIUDAD_H_
#define CIUDAD_H_
#include <string>
#include "Lista.h"
#include "DetalleLinea.h"
using namespace std;
namespace EEDD {

class Ciudad {
private:
	string nombreCiudad;
	Lista<DetalleLinea> listadoCodigos;
public:
	Ciudad();
	virtual ~Ciudad();
	Lista<DetalleLinea>& getListadoCodigos() ;
	void setListadoCodigos( Lista<DetalleLinea>& listadoCodigos);
	const string& getNombreCiudad() const;
	void setNombreCiudad(const string& nombreCiudad);
	bool operator < (Ciudad &ci);
	bool operator > (Ciudad &ci);
};

} /* namespace EEDD */
#endif /* CIUDAD_H_ */
