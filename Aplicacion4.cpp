/*
 * Aplicacion4.cpp
 *
 *  Created on: 07/11/2013
 *      Author: druida
 */

#include "Aplicacion4.h"

#include <iostream>
#include <string>

#include "CargadorDatos.h"
using namespace std;
namespace EEDD {

Aplicacion4::Aplicacion4() {

}

Aplicacion4::~Aplicacion4() {
	Iterador<CodigoPost*>* it2;
	it2 = lineas.iteradorIni();
	while(it2->haySiguiente()){
		delete it2->dato();
		it2->siguiente();
	}
	Iterador<StructPost*>* it;
	it = ciudades.iteradorIni();
	while(it->haySiguiente()){
		delete it->dato();
		it->siguiente();
	}
}

void Aplicacion4::cargarArbol(Avl<StructPost>* avl) {
	CargadorDatos cd;
	CodigoPost* d;
	while(0!=(d=cd.siguienteDetalle())){
		StructPost c;
		c.setNombreCiudad(d->getCity());
		//si la ciudad no está aún en el árbol la creo.
		if(avl->busquedaNR(c) == 0){
			StructPost *c1 = new StructPost();
			ciudades.insertarFin(c1);
			c1->setNombreCiudad(d->getCity());
			avl->insertarNR(*c1);
		}
		avl->busquedaNR(c)->getListadoCodigos().insertarFin(d);
		lineas.insertarFin(d);
	}
}

void Aplicacion4::mostrarDetallesCiudad(Avl<StructPost>* avl, string nombreCiudad) {
	StructPost c;
	c.setNombreCiudad(nombreCiudad);
	StructPost* c2 = avl->busquedaNR(c);
	if(c2 == 0){
		cout << "Ciudad " << nombreCiudad<<" no encontrada." << endl;
		return;
	}
	EEDD::Iterador<CodigoPost*>* it;
	it = c2->getListadoCodigos().iteradorIni();
	cout << "Zipcode\tZipCodeType\tCity\t\tState\tLocationType\tLat\tLong\tLocation\tDecommisioned\tTaxReturnsFiled\tEstimatedPopulation\tTotalWages" << endl;
	while(it->haySiguiente()){
		cout << it->dato()->getZipCode() << "\t";
		cout << it->dato()->getZipCodeType() << "\t";
		cout << it->dato()->getCity() << "\t\t";
		cout << it->dato()->getState() << "\t";
		cout << it->dato()->getLocationType() << "\t";
		cout << it->dato()->getLat() << "\t";
		cout << it->dato()->getLon() << "\t";
		cout << it->dato()->getLocation() << "\t";
		cout << it->dato()->getDecommisioned() << "\t";
		cout << it->dato()->getTaxReturnsFiled() << "\t";
		cout << it->dato()->getEstimatedPopulation() << "\t";
		cout << it->dato()->getTotalWages() << endl;
		it->siguiente();
	}
}

int Aplicacion4::ejecutar(int argc, char** argv) {
	string cadenaEntrada(argv[1]);
	Avl<StructPost>* avl = new Avl<StructPost>();
	cargarArbol(avl);
	mostrarDetallesCiudad(avl,cadenaEntrada);
	return 0;
}

} /* namespace EEDD */
