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
	// TODO Auto-generated constructor stub

}

Aplicacion4::~Aplicacion4() {
	// TODO Auto-generated destructor stub
}

void Aplicacion4::cargarArbol(Avl<Ciudad>* avl) {
	CargadorDatos cd;
	DetalleLinea* d;
	while(0!=(d=cd.siguienteDetalle())){
		Ciudad c;
		c.setNombreCiudad(d->getCity());
		//si la ciudad no está aún en el árbol la creo.
		if(avl->busquedaNR(c) == 0){
			Ciudad *c1 = new Ciudad();
			c1->setNombreCiudad(d->getCity());
			avl->insertarNR(*c1);
		}
		avl->busquedaNR(c)->getListadoCodigos().insertarFin(d);
	}
}

void Aplicacion4::mostrarDetallesCiudad(Avl<Ciudad>* avl, string nombreCiudad) {
	Ciudad c;
	c.setNombreCiudad(nombreCiudad);
	Ciudad* c2 = avl->busquedaNR(c);
	if(c2 == 0){
		cout << "Ciudad " << nombreCiudad<<" no encontrada." << endl;
		return;
	}
	EEDD::Iterador<DetalleLinea*>* it;
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
	Avl<Ciudad>* avl = new Avl<Ciudad>();
	cargarArbol(avl);
	mostrarDetallesCiudad(avl,cadenaEntrada);
	return 0;
}

} /* namespace EEDD */
