/*
 * Tests.cpp
 *
 *  Created on: 09/11/2013
 *      Author: druida
 */

#include "Tests.h"

namespace EEDD {

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

void Tests::testLista() {
	Lista<int> lista;
	lista.insertarFin(1);
	lista.insertarFin(2);
	lista.insertarFin(3);
	cout << lista.toString() << endl;
}

} /* namespace EEDD */
