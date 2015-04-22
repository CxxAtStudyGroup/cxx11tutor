/* 
 * File:   deducing_types.h
 * Author: jpimentel
 *
 * Created on April 19, 2015, 4:03 PM
 */

#ifndef DEDUCING_TYPES_H
#define	DEDUCING_TYPES_H

#include <iostream>
#include <typeinfo>       // operator typeid
#include <type_traits>

template<typename T> void f1(T&& param);

void deducing_types_01(void);


#endif	/* DEDUCING_TYPES_H */

