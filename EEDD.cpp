//============================================================================
// Name        : EEDD.cpp
// Author      : Ramón Díaz Valenzuela
// Version     :
// Copyright   : No hay copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Aplicacion4.h"
#include "Aplicacion5.h"
#include "Aplicacion6.h"

using namespace std;
using namespace EEDD;

int main(int argc, char** argv) {
	try{
	if (argc < 2){
		cout << "Introduzca la ciudad a buscar." << endl;
		return 0;
	}
	Aplicacion6 a;
	return a.ejecutar(argc, argv);
	}catch (...) {
		cout << "Excepción Lanzada." << endl;
	}
}
