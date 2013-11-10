/*
 * Aplicacion4.cpp
 *
 *  Created on: 07/11/2013
 *      Author: druida
 */

#include "Aplicacion4.h"
#include "Lista.h"
#include <iostream>
#include <string>
using namespace std;
namespace EEDD {

Aplicacion4::Aplicacion4() {
	// TODO Auto-generated constructor stub

}

Aplicacion4::~Aplicacion4() {
	// TODO Auto-generated destructor stub
}

int Aplicacion4::ejecutar(int argc, char** argv) {
	cout << "Ejecutando la aplicación 4." << endl;
	cout << "Testeando la lista..." << endl;
	Lista<int> l;
	cout << "Tamaño inicial de la lista: " << l.tam() << endl;
	int x = 1;
	l.insertarFin(x);
	x = 2;
	l.insertarFin(x);
	x = 3;
	l.insertarFin(x);
	Iterador<int> *it = l.iteradorIni();
	do{
		cout << it->dato() << endl;
		it->siguiente();
	}while(it->haySiguiente());
	delete it;
	return 0;
}

} /* namespace EEDD */
