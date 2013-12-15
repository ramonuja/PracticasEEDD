/* 
 * File:   DetalleLinea.cpp
 * Author: macosx
 * 
 * Created on 4 de noviembre de 2013, 17:19
 */

#include "CodigoPost.h"


CodigoPost::CodigoPost() {
}

CodigoPost::CodigoPost(const CodigoPost& orig) {
}

CodigoPost::~CodigoPost() {
}

const string& CodigoPost::getCity() const {
	return city;
}

void CodigoPost::setCity(const string& city) {
	this->city = city;
}

const string& CodigoPost::getDecommisioned() const {
	return decommisioned;
}

void CodigoPost::setDecommisioned(const string& decommisioned) {
	this->decommisioned = decommisioned;
}

const string& CodigoPost::getEstimatedPopulation() const {
	return estimatedPopulation;
}

void CodigoPost::setEstimatedPopulation(const string& estimatedPopulation) {
	this->estimatedPopulation = estimatedPopulation;
}

const string& CodigoPost::getLat() const {
	return lat;
}

void CodigoPost::setLat(const string& lat) {
	this->lat = lat;
}

const string& CodigoPost::getLocation() const {
	return location;
}

void CodigoPost::setLocation(const string& location) {
	this->location = location;
}

const string& CodigoPost::getLocationType() const {
	return locationType;
}

void CodigoPost::setLocationType(const string& locationType) {
	this->locationType = locationType;
}

const string& CodigoPost::getLon() const {
	return lon;
}

void CodigoPost::setLon(const string& lon) {
	this->lon = lon;
}

const string& CodigoPost::getState() const {
	return state;
}

void CodigoPost::setState(const string& state) {
	this->state = state;
}

const string& CodigoPost::getTaxReturnsFiled() const {
	return taxReturnsFiled;
}

void CodigoPost::setTaxReturnsFiled(const string& taxReturnsFiled) {
	this->taxReturnsFiled = taxReturnsFiled;
}

const string& CodigoPost::getTotalWages() const {
	return totalWages;
}

void CodigoPost::setTotalWages(const string& totalWages) {
	this->totalWages = totalWages;
}

const string& CodigoPost::getZipCode() const {
	return zipCode;
}

void CodigoPost::setZipCode(const string& zipCode) {
	this->zipCode = zipCode;
}

const string& CodigoPost::getZipCodeType() const {
	return zipCodeType;
}

void CodigoPost::setZipCodeType(const string& zipCodeType) {
	this->zipCodeType = zipCodeType;
}
