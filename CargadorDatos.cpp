/*
 * CargadorDatos.cpp
 *
 *  Created on: 10/11/2013
 *      Author: druida
 */

#include "CargadorDatos.h"

namespace EEDD {

CargadorDatos::CargadorDatos() {
	fichero = new ifstream(RUTA_FICHERO);
	if (fichero->is_open())
	{
		string line;
		getline(*fichero,line);
	}
}

CargadorDatos::~CargadorDatos() {
	fichero->close();
}

int* CargadorDatos::fromString(string s) {
	int* lista = new int[12];
	unsigned int x,token;
	token = 0;
	for (x = 0; x < s.length(); ++x) {
		if(s[x] == ','){
			lista[token++] =x;
		}else if(s[x] == '\n'){
			lista[token] =x;
			break;
		}
	}
	return lista;

}

DetalleLinea* CargadorDatos::siguienteDetalle() {
	if (fichero->is_open())
	{
		string line;
		if(!getline(*fichero,line)) return 0;
		DetalleLinea* dl = new DetalleLinea();
		int inicio,fin;
		inicio = 0;
		fin = 0;
		int* lista;
		lista = fromString(line);
		//ZipCode - Number
		inicio = 0;
		fin = lista[0];
		//cout << "el código zip es:" << line.substr(inicio,fin) << endl;
		dl->setZipCode(line.substr(inicio,fin));
		//ZipcodeType - String
		inicio = lista[0];
		fin = lista[1];
		//cout << "el código zip es:" << line.substr(inicio+1,fin-inicio-1) << endl;
		dl->setZipCodeType(line.substr(inicio+1,fin-inicio-1));
		//City -String
		inicio = lista[1];
		fin = lista[2];
		//cout << "el código zip es:" << line.substr(inicio+1,fin-inicio-1) << endl;
		dl->setCity(line.substr(inicio+1,fin-inicio-1));
		//State - String
		inicio = lista[2];
		fin = lista[3];
		//cout << "el código zip es:" << line.substr(inicio+1,fin-inicio-1) << endl;
		dl->setState(line.substr(inicio+1,fin-inicio-1));
		//LocationType - String
		inicio = lista[3];
		fin = lista[4];
		//cout << "el código zip es:" << line.substr(inicio+1,fin-inicio-1) << endl;
		dl->setLocationType(line.substr(inicio+1,fin-inicio-1));
		//Lat - Double
		inicio = lista[4];
		fin = lista[5];
		//cout << "el código zip es:" << line.substr(inicio+1,fin-inicio-1) << endl;
		dl->setLat(line.substr(inicio+1,fin-inicio-1));
		//Lon - Double
		inicio = lista[5];
		fin = lista[6];
		//cout << "el código zip es:" << line.substr(inicio+1,fin-inicio-1) << endl;
		dl->setLon(line.substr(inicio+1,fin-inicio-1));
		//Location - String
		inicio = lista[6];
		fin = lista[7];
		//cout << "el código zip es:" << line.substr(inicio+1,fin-inicio-1) << endl;
		dl->setLocation(line.substr(inicio+1,fin-inicio-1));
		//Decommisioned - bool
		inicio = lista[7];
		fin = lista[8];
		//cout << "el código zip es:" << line.substr(inicio+1,fin-inicio-1) << endl;
		dl->setDecommisioned(line.substr(inicio+1,fin-inicio-1));
		//TaxReturnsFiled - Int
		inicio = lista[8];
		fin = lista[9];
		//cout << "el código zip es:" << line.substr(inicio+1,fin-inicio-1) << endl;
		dl->setTaxReturnsFiled(line.substr(inicio+1,fin-inicio-1));
		//EstimatedPopulation - int
		inicio = lista[9];
		fin = lista[10];
		//cout << "el código zip es:" << line.substr(inicio+1,fin-inicio-1) << endl;
		dl->setEstimatedPopulation(line.substr(inicio+1,fin-inicio-1));
		// TotalWages - Int
		inicio = lista[10];
		fin = lista[11];
		//cout << "el código zip es:" << line.substr(inicio+1,fin-inicio-1) << endl;
		dl->setTotalWages(line.substr(inicio+1,fin-inicio-1));
		return dl;
	}
	return 0;
}
} /* namespace EEDD */
