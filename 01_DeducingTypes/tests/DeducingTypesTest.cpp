/*
 * File:   DeducingTypesTest.cpp
 * Author: jpimentel
 *
 * Created on Apr 30, 2015, 11:35:47 PM
 */

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
    int& param;
    ReturnStructure result = templateReceivingByRef(param);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void DeducingTypesTest::testTemplateReceivingByRvalue() {
    int&& param;
    ReturnStructure result = templateReceivingByRvalue(param);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void DeducingTypesTest::testTemplateReceivingByValue() {
    int param;
    ReturnStructure result = templateReceivingByValue(param);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

