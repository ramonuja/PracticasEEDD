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
class CodigoPost {
public:
    CodigoPost();
    CodigoPost(const CodigoPost& orig);
    virtual ~CodigoPost();
	const string& getCity() const;
	void setCity(const string& city);
	const string& getDecommisioned() const;
	void setDecommisioned(const string& decommisioned);
	const string& getEstimatedPopulation() const;
	void setEstimatedPopulation(const string& estimatedPopulation);
	const string& getLat() const;
	void setLat(const string& lat);
	const string& getLocation() const;
	void setLocation(const string& location);
	const string& getLocationType() const;
	void setLocationType(const string& locationType);
	const string& getLon() const;
	void setLon(const string& lon);
	const string& getState() const;
	void setState(const string& state);
	const string& getTaxReturnsFiled() const;
	void setTaxReturnsFiled(const string& taxReturnsFiled);
	const string& getTotalWages() const;
	void setTotalWages(const string& totalWages);
	const string& getZipCode() const;
	void setZipCode(const string& zipCode);
	const string& getZipCodeType() const;
	void setZipCodeType(const string& zipCodeType);

private:
    string zipCode;
    string zipCodeType;
    string city;
    string state;
    string locationType;
    string lat;
    string lon;
    string location;
    string decommisioned;
    string taxReturnsFiled;
    string estimatedPopulation;
    string totalWages;
    
};

#endif	/* DETALLELINEA_H */
