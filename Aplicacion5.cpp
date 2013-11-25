/*
 * Aplicacion5.cpp
 *
 *  Created on: 17/11/2013
 *      Author: druida
 */

#include "Aplicacion5.h"
using namespace std;
namespace EEDD {

Aplicacion5::Aplicacion5() {

}

Aplicacion5::~Aplicacion5() {
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

void Aplicacion5::cargarArbol(map<string,StructPost*> *avl) {
	CargadorDatos cd;
	CodigoPost* d;
	while(0!=(d=cd.siguienteDetalle())){
		StructPost c;
		c.setNombreCiudad(d->getCity());
		//si la ciudad no está aún en el árbol la creo.
		if(avl->find(c.getNombreCiudad()) == avl->end()){
			StructPost *c1 = new StructPost();
			ciudades.insertarFin(c1);
			c1->setNombreCiudad(d->getCity());
			avl->insert(pair<string,StructPost*>(d->getCity(),c1));
		}
		map<string,StructPost*>::iterator it;
		it = avl->find(c.getNombreCiudad());
		it->second->getListadoCodigos().insertarFin(d);
		lineas.insertarFin(d);
	}
}

void Aplicacion5::mostrarDetallesCiudad(map<string,StructPost*> *avl,string nombreCiudad) {
	StructPost c;
	c.setNombreCiudad(nombreCiudad);
	map<string,StructPost*>::iterator itMap;
	itMap = avl->find(nombreCiudad);
	if(itMap == avl->end()){
		cout << "Ciudad " << nombreCiudad<<" no encontrada." << endl;
		return;
	}
	EEDD::Iterador<CodigoPost*>* itLineas;
	itLineas = itMap->second->getListadoCodigos().iteradorIni();
	cout << "Zipcode\tZipCodeType\tCity\t\tState\tLocationType\tLat\tLong\tLocation\tDecommisioned\tTaxReturnsFiled\tEstimatedPopulation\tTotalWages" << endl;
	while(itLineas->haySiguiente()){
		cout << itLineas->dato()->getZipCode() << "\t";
		cout << itLineas->dato()->getZipCodeType() << "\t";
		cout << itLineas->dato()->getCity() << "\t\t";
		cout << itLineas->dato()->getState() << "\t";
		cout << itLineas->dato()->getLocationType() << "\t";
		cout << itLineas->dato()->getLat() << "\t";
		cout << itLineas->dato()->getLon() << "\t";
		cout << itLineas->dato()->getLocation() << "\t";
		cout << itLineas->dato()->getDecommisioned() << "\t";
		cout << itLineas->dato()->getTaxReturnsFiled() << "\t";
		cout << itLineas->dato()->getEstimatedPopulation() << "\t";
		cout << itLineas->dato()->getTotalWages() << endl;
		itLineas->siguiente();
	}
}

int Aplicacion5::ejecutar(int argc, char** argv) {
	cout << "Ejecutando la práctica 5..." << endl;
	string cadenaEntrada(argv[1]);
	map<string,StructPost*>* avl = new map<string,StructPost*>();
	cargarArbol(avl);
	mostrarDetallesCiudad(avl,cadenaEntrada);
	return 0;
}

} /* namespace EEDD */
