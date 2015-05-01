/*
 * File:   UtilityTests.h
 * Author: jpimentel
 *
 * Created on Apr 30, 2015, 11:55:29 PM
 */

#ifndef UTILITYTESTS_H
#define	UTILITYTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class UtilityTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(UtilityTests);

    CPPUNIT_TEST(testGetTypeOnChar);
    CPPUNIT_TEST(testGetTypeOnUnsignedChar);
    CPPUNIT_TEST(testGetTypeOnShort);
    CPPUNIT_TEST(testGetTypeOnUnsignedShort);
    CPPUNIT_TEST(testGetTypeOnInt);
    CPPUNIT_TEST(testGetTypeOnUnsignedInt);
    CPPUNIT_TEST(testGetTypeOnLong);
    CPPUNIT_TEST(testGetTypeOnUnsignedLong);
    CPPUNIT_TEST(testGetTypeOnFloat);
    CPPUNIT_TEST(testGetTypeOnDouble);
    CPPUNIT_TEST(testGetTypeOnStruct);
    CPPUNIT_TEST(testGetTypeOnClass);

    CPPUNIT_TEST_SUITE_END();

public:
    UtilityTests();
    virtual ~UtilityTests();
    void setUp();
    void tearDown();
    void callTestGetTypeOnStruct();

private:
    void testGetTypeOnChar();
    void testGetTypeOnUnsignedChar();
    void testGetTypeOnShort();
    void testGetTypeOnUnsignedShort();
    void testGetTypeOnInt();
    void testGetTypeOnUnsignedInt();
    void testGetTypeOnLong();
    void testGetTypeOnUnsignedLong();
    void testGetTypeOnFloat();
    void testGetTypeOnDouble();
    void testGetTypeOnStruct();
    void testGetTypeOnClass();
    

};

#endif	/* UTILITYTESTS_H */

