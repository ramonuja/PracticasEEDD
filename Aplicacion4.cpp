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
#include "Ciudad.h"
#include "Avl.h"
#include "CargadorDatos.h"
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
//	Lista<int> l;
//	cout << "Tamaño inicial de la lista: " << l.tam() << endl;
//	int x = 1;
//	l.insertarFin(x);
//	x = 2;
//	l.insertarFin(x);
//	x = 3;
//	l.insertarFin(x);
//	Iterador<int> *it = l.iteradorIni();
//	do{
//		cout << it->dato() << endl;
//		it->siguiente();
//	}while(it->haySiguiente());
//	delete it;
//	Ciudad c1,c2;
//	c1.setNombreCiudad("a");
//	c1.setNombreCiudad("b");
//	cout << (c1 > c2) << endl;
//	cout << "Testeando el árbol" << endl;
//	Avl<Ciudad> avl;
//	Ciudad c1,c2,c3,b;
//	c1.setNombreCiudad("Jaén");
//	c2.setNombreCiudad("Granada");
//	c3.setNombreCiudad("Sevilla");
//	b.setNombreCiudad("Lugo");
//	avl.insertarNR(c1);
//	avl.insertarNR(c2);
//	avl.insertarNR(c3);
//	cout << "Introduzco las ciudades Jaén, Granada y Sevilla." << endl;
//	cout << "Busco Lugo..." << endl;
//	Ciudad* r = avl.busquedaNR(b);
//	cout << "La dirección de memoria obtenida es: " << r << endl;
//	cout << "Busco Gra..." << endl;
//	b.setNombreCiudad("Gra");
//	r = avl.busquedaNR(b);
//	cout << "La dirección de memoria obtenida es: " << r << endl;
//	cout << "Busco Granada..." << endl;
//	b.setNombreCiudad("Granada");
//	r = avl.busquedaNR(b);
//	cout << "La dirección de memoria obtenida es: " << r << endl;
//	cout << "Y el contenido de la dirección: " << (*r).getNombreCiudad() << endl;
	CargadorDatos cd;
	cd.siguienteDetalle();
	return 0;
}

} /* namespace EEDD */
