/*
 * Dispersion.h
 *
 *  Created on: 25/11/2013
 *      Author: ramon
 */

#ifndef DISPERSION_H_
#define DISPERSION_H_

namespace EEDD {
template<class T>
class Dispersion<T> {
public:
	Dispersion();
	virtual ~Dispersion();
};

} /* namespace EEDD */
template<class T>
inline EEDD::Dispersion(){

}
template<typename T>
inline EEDD::~Dispersion(){

}

#endif /* DISPERSION_H_ */
