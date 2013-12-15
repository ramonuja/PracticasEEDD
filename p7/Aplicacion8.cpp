/*
 * Aplicacion8.cpp
 *
 *  Created on: 15/12/2013
 *      Author: druida
 */

#include "Aplicacion8.h"
#include <fstream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <string.h>
#include "img.h"

namespace EEDD {

Aplicacion8::Aplicacion8() {
	// TODO Auto-generated constructor stub

}

Aplicacion8::~Aplicacion8() {
	// TODO Auto-generated destructor stub
}



int Aplicacion8::exec ()
{
	Img img(1, 1);

	try {
		img = Img("/home/druida/workspace/EEDD/Debug/mapaUsa.ppm");
	}
	catch(ErrorLecturaFichero &e) {
		cout << "Error al leer imagen de entrada" << endl;
		return 1;
	}

	cout << "Imagen leida" << endl;

	int nfilas = img.numFilas();
	int ncol = img.numColumnas();

	int r = 0; // azul
	int g = 255;
	int b = 0;

	double minlat = 9e99;
	double maxlat = 0;
	double minlon = 9e99;
	double maxlon = 0;

	vector<double> vlat, vlon;

	fstream fs ("/home/druida/workspace/EEDD/Debug/free-zipcode-database-Primary.csv",fstream::in | fstream::out);
	int nlineas = 0;
	char linea[250];
	fs.getline(linea, 250); //la primera no la cuento
	while (!fs.eof()){
		fs.getline(linea, 250);
		nlineas++;

		string lin (linea);
		double numlat, numlon;

		size_t poscoma = lin.find (",", 0);
		string codigo = lin.substr(0, poscoma );
		if (codigo.size() > 2) codigo = codigo.substr(1,poscoma-2);
		//cout << codigo << endl;
		lin = lin.substr (poscoma+1,255);


		poscoma = lin.find (",", 0);
		string tipo = lin.substr(0, poscoma );
		if (tipo.size() > 2) tipo = tipo.substr(1,poscoma-2);
		//cout << tipo << endl;
		lin = lin.substr (poscoma+1,255);

		poscoma = lin.find (",", 0);
		string city = lin.substr(0, poscoma );
		if (city.size() > 2 ) city = city.substr(1,poscoma-2);
		//cout << city << endl;
		lin = lin.substr (poscoma+1,255);

		poscoma = lin.find (",", 0);
		string state = lin.substr(0, poscoma );
		if (state.size()>2) state = state.substr(1,poscoma-2);
		//cout << state << endl;
		lin = lin.substr (poscoma+1,255);

		poscoma = lin.find (",", 0);
		string tipo2 = lin.substr(0, poscoma );
		if (tipo2.size()>2) tipo2 = tipo2.substr(1,poscoma-2);
		//cout << tipo2 << endl;
		lin = lin.substr (poscoma+1,255);

		poscoma = lin.find (",", 0);
		string lon = lin.substr(0, poscoma );
		if (lon.size() > 2) {
			char * cslon = new char [lon.length()+1];
			strcpy (cslon, lon.c_str());
			numlon = atof(cslon);
			vlon.push_back(numlon);
			//cout << numlon << endl;
			if (numlon < minlon ) minlon = numlon;
			if (numlon > maxlon ) maxlon = numlon;

		}
		lin = lin.substr (poscoma+1,255);


		poscoma = lin.find (",", 0);
		string lat = lin.substr(0, poscoma );
		if (lat.size() > 2){
			char * cslat = new char [lat.length()+1];
			strcpy (cslat, lat.c_str());
			numlat = atof(cslat);
			vlat.push_back(numlat);
			//cout << numlat << endl;
			if (numlat < minlat) minlat = numlat;
			if (numlat > maxlat) maxlat = numlat;

		}
		lin = lin.substr (poscoma+1,255);


	} // fin fichero


	cout << "lat: xmin = " << minlat <<  ", " << "xmax = " << maxlat << endl;
	cout << "lon: ymin = " << minlon <<  ", " << "ymax = " << maxlon << endl;

	double rangox = maxlat - minlat;
	double rangoy = maxlon - minlon;

	cout << "rango x = " << rangox << endl;
	cout << "rango y = " << rangoy << endl;

	cout << "nfilas = " << nfilas << endl;
	cout << "ncol = " << ncol << endl;

	double pixelPorGradoX = (double) (nfilas - 1) / rangox;
	double pixelPorGradoY = (double) (ncol - 1) / rangoy;

	for (unsigned int i=0; i< vlon.size(); i++){
		int posX = (vlat[i] - minlat) * pixelPorGradoX;
		int posY = ncol - 1 - ((vlon[i]-minlon) * pixelPorGradoY);
		//img.pintarPixelGrande(posX,posY,r,g,b);
		img.pintarPixel(posX,posY,r,g,b);
	}


	double lat1 = -120.0;
	double lon1 = 43.0;

	double lat2 = -110.0;
	double lon2 = 44.0;

	img.pintarRecuadro((lat1 - minlat) * pixelPorGradoX, ncol - 1 - ((lon1 - minlon) * pixelPorGradoY),
			(lat2 - minlat) * pixelPorGradoX, ncol - 1 - ((lon2 - minlon) * pixelPorGradoY), 255, 0, 0);

	// aqui se realiza el test del modo:
	// vector<CodigoPost> buscarRango (lat1, lon1, lat2, lon2);

	// luego se recorre dicho vector, y para las coordenadas de cada CodigoPost se vuelven a pintar
	//fichero en color verde

	try {
		img.guardar("./mapaUsaResult.ppm");
	}
	catch(ErrorEscrituraFichero &e) {
		cout << "Error al escribir fichero" << endl;
		return 1;
	}

	cout << "Operación realizada con exito" << endl;

	return 0;
}

int Aplicacion8::ejecutar(int argc, char** argv) {
	exec();
	return 0;
}

} /* namespace EEDD */
