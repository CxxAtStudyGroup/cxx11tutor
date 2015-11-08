/*
 * File:   DeducingTypesTest.cpp
 * Author: jpimentel
 *
 * Created on Apr 30, 2015, 11:35:47 PM
 */
#include "utility_functions.h"
#include "DeducingTypesTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(DeducingTypesTest);

DeducingTypesTest::DeducingTypesTest() {
}

DeducingTypesTest::~DeducingTypesTest() {
}

void DeducingTypesTest::setUp() {
}

void DeducingTypesTest::tearDown() {
}

void DeducingTypesTest::testTemplateReceivingByRef() {
//    Deducing types example template function type deduction passing arguments by reference
//       template<typename T> ReturnStructure templateReceivingByRef(T& param) {...}
    int x = 27;         // x  is an int
    const int cx = x;   // cx is a const int
    const int& rx = x;  // rx is a reference to x as a const int
    
    ReturnStructure result = templateReceivingByRef(x);
    CPPUNIT_ASSERT(result.deducedTypeForT == "int");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "int&");
    
    result = templateReceivingByRef(cx);
    CPPUNIT_ASSERT(result.deducedTypeForT == "const int");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "const int&");
    
    result = templateReceivingByRef(cx);
    CPPUNIT_ASSERT(result.deducedTypeForT == "const int");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "const int&");
}

void DeducingTypesTest::testTemplateReceivingByRefToConst() {
//    Deducing types example template function type deduction passing arguments by reference
//       template<typename T> ReturnStructure templateReceivingByRef(T& param) {...}
    int x = 27;         // x  is an int
    ReturnStructure result = templateReceivingByRefToConst(x);
    CPPUNIT_ASSERT(result.deducedTypeForT == "int");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "const int&");
    
    const int cx = x;   // cx is a const int
    result = templateReceivingByRefToConst(cx);
    CPPUNIT_ASSERT(result.deducedTypeForT == "int");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "const int&");
    
    const int& rx = x;  // rx is a reference to x as a const int
    result = templateReceivingByRefToConst(cx);
    CPPUNIT_ASSERT(result.deducedTypeForT == "int");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "const int&");
}

void DeducingTypesTest::testTemplateReceivingByPointer() {
    int x = 27;         // x  is an int
    const int *px = &x; // px is a pointer to x as a const int 
    ReturnStructure result = templateReceivingByPointer(&x);
    CPPUNIT_ASSERT(result.deducedTypeForT == "int");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "int*");
    
    result = templateReceivingByPointer(px);
    CPPUNIT_ASSERT(result.deducedTypeForT == "const int");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "const int*");
    
}

void DeducingTypesTest::testTemplateReceivingByRvalue() {
    int x = 27;         // x  is an int
    const int cx = x;   // cx is a const int
    const int& rx = x;  // rx is a reference to x as a const int

    ReturnStructure result = templateReceivingByRvalue(x);
    CPPUNIT_ASSERT(result.deducedTypeForT == "int&");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "int&");

    result = templateReceivingByRvalue(cx);
    CPPUNIT_ASSERT(result.deducedTypeForT == "const int&");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "const int&");

    result = templateReceivingByRvalue(rx);
    CPPUNIT_ASSERT(result.deducedTypeForT == "const int&");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "const int&");

    result = templateReceivingByRvalue(27);
    CPPUNIT_ASSERT(result.deducedTypeForT == "int");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "int&&");
}

void DeducingTypesTest::testTemplateReceivingByValue() {
    int param;
    ReturnStructure result = templateReceivingByValue(param);
    CPPUNIT_ASSERT(result.deducedTypeForT == "int");
}

