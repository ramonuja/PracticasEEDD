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
#include "CodigoPost.h"
using namespace std;
namespace EEDD {

class StructPost {
private:
	string nombreCiudad;
	Lista<CodigoPost*> listadoCodigos;
public:
	StructPost();
	virtual ~StructPost();

	const string& getNombreCiudad() const;
	void setNombreCiudad(const string& nombreCiudad);
	bool operator < (StructPost &ci);
	bool operator > (StructPost &ci);
	 Lista<CodigoPost*>& getListadoCodigos() ;
	void setListadoCodigos( Lista<CodigoPost*>& listadoCodigos);
};

} /* namespace EEDD */
#endif /* CIUDAD_H_ */
