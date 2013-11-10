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

const string& DetalleLinea::getDecommisioned() const {
	return decommisioned;
}

void DetalleLinea::setDecommisioned(const string& decommisioned) {
	this->decommisioned = decommisioned;
}

const string& DetalleLinea::getEstimatedPopulation() const {
	return estimatedPopulation;
}

void DetalleLinea::setEstimatedPopulation(const string& estimatedPopulation) {
	this->estimatedPopulation = estimatedPopulation;
}

const string& DetalleLinea::getLat() const {
	return lat;
}

void DetalleLinea::setLat(const string& lat) {
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

const string& DetalleLinea::getLon() const {
	return lon;
}

void DetalleLinea::setLon(const string& lon) {
	this->lon = lon;
}

const string& DetalleLinea::getState() const {
	return state;
}

void DetalleLinea::setState(const string& state) {
	this->state = state;
}

const string& DetalleLinea::getTaxReturnsFiled() const {
	return taxReturnsFiled;
}

void DetalleLinea::setTaxReturnsFiled(const string& taxReturnsFiled) {
	this->taxReturnsFiled = taxReturnsFiled;
}

const string& DetalleLinea::getTotalWages() const {
	return totalWages;
}

void DetalleLinea::setTotalWages(const string& totalWages) {
	this->totalWages = totalWages;
}

const string& DetalleLinea::getZipCode() const {
	return zipCode;
}

void DetalleLinea::setZipCode(const string& zipCode) {
	this->zipCode = zipCode;
}

const string& DetalleLinea::getZipCodeType() const {
	return zipCodeType;
}

void DetalleLinea::setZipCodeType(const string& zipCodeType) {
	this->zipCodeType = zipCodeType;
}
