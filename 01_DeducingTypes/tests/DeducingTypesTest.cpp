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
    int x = 123;
    int& param = x;
    ReturnStructure result = templateReceivingByRef(param);
    CPPUNIT_ASSERT(result.deducedTypeForT == "int");
}

void DeducingTypesTest::testTemplateReceivingByRvalue() {
    int&& param = 123;
    ReturnStructure result = templateReceivingByRvalue(param);
    CPPUNIT_ASSERT(result.deducedTypeForT == "int&");
}

void DeducingTypesTest::testTemplateReceivingByValue() {
    int param;
    ReturnStructure result = templateReceivingByValue(param);
    CPPUNIT_ASSERT(result.deducedTypeForT == "int");
}

