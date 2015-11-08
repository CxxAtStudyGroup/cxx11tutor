/*
 * File:   DeducingTypesTest.h
 * Author: jpimentel
 *
 * Created on Apr 30, 2015, 11:35:46 PM
 */

#ifndef DEDUCINGTYPESTEST_H
#define	DEDUCINGTYPESTEST_H

#include <cppunit/extensions/HelperMacros.h>

class DeducingTypesTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(DeducingTypesTest);

    CPPUNIT_TEST(testTemplateReceivingByRef);
    CPPUNIT_TEST(testTemplateReceivingByRefToConst);
    CPPUNIT_TEST(testTemplateReceivingByPointer);
    CPPUNIT_TEST(testTemplateReceivingByRvalue);
    CPPUNIT_TEST(testTemplateReceivingByValue);

    CPPUNIT_TEST_SUITE_END();

public:
    DeducingTypesTest();
    virtual ~DeducingTypesTest();
    void setUp();
    void tearDown();

private:
    void testTemplateReceivingByRef();
    void testTemplateReceivingByRefToConst();
    void testTemplateReceivingByPointer();
    void testTemplateReceivingByRvalue();
    void testTemplateReceivingByValue();

};

#endif	/* DEDUCINGTYPESTEST_H */

