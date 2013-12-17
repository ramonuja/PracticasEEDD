/*
 * Aplicacion6.cpp
 *
 *  Created on: 17/11/2013
 *      Author: druida
 */

#include <ctime>
#include "Aplicacion6.h"

using namespace std;
namespace EEDD {

Aplicacion6::Aplicacion6() {

}

Aplicacion6::~Aplicacion6() {

}

void Aplicacion6::cargarTablaDispersion(Dispersion<StructPost> &disp) {
	cout << "Iniciando carga de la tabla de Dispersión." << endl;
	long int tIni = time(0);
	CargadorDatos cd;
	CodigoPost* d;
	unsigned long clave = 0;
	d=cd.siguienteDetalle();
	while(d != 0){
		clave = djb2(d->getCity());
		//si la ciudad no está aún en el árbol la creo.
		if (disp.buscar(clave) == 0){
			StructPost c;
			c.setNombreCiudad(d->getCity());
			disp.insertar(clave,c);
		}
		disp.buscar(clave)->getListadoCodigos().insertarFin(d);
		d=cd.siguienteDetalle();
	}
	long int tFin = time(0);
	cout << "Número máximo de colisiones: " << disp.maxI << endl;
	cout << "Tabla de dispersión cargada(" << (tFin-tIni) << " segs)."<< endl;
}

void Aplicacion6::mostrarDetallesCiudad(Dispersion<StructPost> &disp, string nombreCiudad) {
	unsigned long int clave;
	clave = djb2(nombreCiudad);
	StructPost* c = disp.buscar(clave);
	if(c == 0){
		cout << "Ciudad " << nombreCiudad<<" no encontrada." << endl;
		return;
	}
	EEDD::Iterador<CodigoPost*>* itLineas;
	itLineas = c->getListadoCodigos().iteradorIni();
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

unsigned long Aplicacion6::djb2(string s) {
	const char *str = s.c_str();
	unsigned long hash = 5381;
	int c;
	while ((c = *str++) != 0) hash = ((hash << 5) + hash) + c;
	return hash;
}

int Aplicacion6::ejecutar(int argc, char** argv) {
	cout << "Ejecutando la práctica 6..." << endl;
	string cadenaEntrada(argv[1]);
	int tamanoTabla = 26813;
	cout << "Creada tabla de dispersión con tamaño: " << tamanoTabla << endl;
	Dispersion<StructPost> disp(tamanoTabla);
	cargarTablaDispersion(disp);
	mostrarDetallesCiudad(disp,cadenaEntrada);
	return 0;
}

} /* namespace EEDD */
