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

    CPPUNIT_TEST(item1Case1TemplateReceivingByRef);
    CPPUNIT_TEST(item1Case1TemplateReceivingByRefToConst);
    CPPUNIT_TEST(item1Case1TemplateReceivingByPointer);
    CPPUNIT_TEST(item1Case2TemplateReceivingByRvalue);
    CPPUNIT_TEST(item1Case3TemplateReceivingByValue);
    CPPUNIT_TEST(item1Case3TemplateReceivingArrayByValue);
    CPPUNIT_TEST(item1Case3TemplateReceivingArrayByRef);
    CPPUNIT_TEST(item1Case3TemplateReceivingFuncByValue);
    CPPUNIT_TEST(item1Case3TemplateReceivingFuncByRef);

    CPPUNIT_TEST_SUITE_END();

public:
    DeducingTypesTest();
    virtual ~DeducingTypesTest();
    void setUp();
    void tearDown();

private:
    void item1Case1TemplateReceivingByRef();
    void item1Case1TemplateReceivingByRefToConst();
    void item1Case1TemplateReceivingByPointer();
    void item1Case2TemplateReceivingByRvalue();
    void item1Case3TemplateReceivingByValue();
    void item1Case3TemplateReceivingArrayByValue();
    void item1Case3TemplateReceivingArrayByRef();
    void item1Case3TemplateReceivingFuncByValue();
    void item1Case3TemplateReceivingFuncByRef();

};

#endif	/* DEDUCINGTYPESTEST_H */

