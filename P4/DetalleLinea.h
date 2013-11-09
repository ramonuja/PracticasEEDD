/* 
 * File:   DetalleLinea.h
 * Author: macosx
 *
 * Created on 4 de noviembre de 2013, 17:19
 */

#ifndef DETALLELINEA_H
#define	DETALLELINEA_H
#include <string>
using namespace std;
class DetalleLinea {
public:
    DetalleLinea();
    DetalleLinea(const DetalleLinea& orig);
    virtual ~DetalleLinea();
	const string& getCity() const;
	void setCity(const string& city);
	bool isDecommisioned() const;
	void setDecommisioned(bool decommisioned);
	int getEstimatedPopulation() const;
	void setEstimatedPopulation(int estimatedPopulation);
	double getLat() const;
	void setLat(double lat);
	const string& getLocation() const;
	void setLocation(const string& location);
	const string& getLocationType() const;
	void setLocationType(const string& locationType);
	double getLon() const;
	void setLon(double lon);
	const string& getState() const;
	void setState(const string& state);
	int getTaxReturnsFiled() const;
	void setTaxReturnsFiled(int taxReturnsFiled);
	int getTotalWages() const;
	void setTotalWages(int totalWages);
	int getZipCode() const;
	void setZipCode(int zipCode);
	const string& getZipCodeType() const;
	void setZipCodeType(const string& zipCodeType);

private:
    int zipCode;
    string zipCodeType;
    string city;
    string state;
    string locationType;
    double lat;
    double lon;
    string location;
    bool decommisioned;
    int taxReturnsFiled;
    int estimatedPopulation;
    int totalWages;
    
};

#endif	/* DETALLELINEA_H */

