/* 
 * File:   DetalleLinea.cpp
 * Author: macosx
 * 
 * Created on 4 de noviembre de 2013, 17:19
 */

#include "DetalleLinea.h"


DetalleLinea::DetalleLinea() {
}

DetalleLinea::DetalleLinea(const DetalleLinea& orig) {
}

DetalleLinea::~DetalleLinea() {
}

const string& DetalleLinea::getCity() const {
	return city;
}

void DetalleLinea::setCity(const string& city) {
	this->city = city;
}

bool DetalleLinea::isDecommisioned() const {
	return decommisioned;
}

void DetalleLinea::setDecommisioned(bool decommisioned) {
	this->decommisioned = decommisioned;
}

int DetalleLinea::getEstimatedPopulation() const {
	return estimatedPopulation;
}

void DetalleLinea::setEstimatedPopulation(int estimatedPopulation) {
	this->estimatedPopulation = estimatedPopulation;
}

double DetalleLinea::getLat() const {
	return lat;
}

void DetalleLinea::setLat(double lat) {
	this->lat = lat;
}

const string& DetalleLinea::getLocation() const {
	return location;
}

void DetalleLinea::setLocation(const string& location) {
	this->location = location;
}

const string& DetalleLinea::getLocationType() const {
	return locationType;
}

void DetalleLinea::setLocationType(const string& locationType) {
	this->locationType = locationType;
}

double DetalleLinea::getLon() const {
	return lon;
}

void DetalleLinea::setLon(double lon) {
	this->lon = lon;
}

const string& DetalleLinea::getState() const {
	return state;
}

void DetalleLinea::setState(const string& state) {
	this->state = state;
}

int DetalleLinea::getTaxReturnsFiled() const {
	return taxReturnsFiled;
}

void DetalleLinea::setTaxReturnsFiled(int taxReturnsFiled) {
	this->taxReturnsFiled = taxReturnsFiled;
}

int DetalleLinea::getTotalWages() const {
	return totalWages;
}

void DetalleLinea::setTotalWages(int totalWages) {
	this->totalWages = totalWages;
}

int DetalleLinea::getZipCode() const {
	return zipCode;
}

void DetalleLinea::setZipCode(int zipCode) {
	this->zipCode = zipCode;
}

const string& DetalleLinea::getZipCodeType() const {
	return zipCodeType;
}

void DetalleLinea::setZipCodeType(const string& zipCodeType) {
	this->zipCodeType = zipCodeType;
}
