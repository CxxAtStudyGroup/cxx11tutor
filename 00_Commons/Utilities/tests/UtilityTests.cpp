/*
 * File:   UtilityTests.cpp
 * Author: jpimentel
 *
 * Created on Apr 30, 2015, 11:55:29 PM
 */

#include "UtilityTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(UtilityTests);

UtilityTests::UtilityTests() {
}

UtilityTests::~UtilityTests() {
}

void UtilityTests::setUp() {
}

void UtilityTests::tearDown() {
}

std::string getType(std::string type);

void UtilityTests::testGetTypeOnChar() {
    char var(0);
    std::string type = typeid (var).name();

    std::string typeFromGetType = getType(type);
    std::string expected("char");
    CPPUNIT_ASSERT_EQUAL(typeFromGetType, expected);
}

void UtilityTests::testGetTypeOnUnsignedChar() {
    unsigned char var(0);
    std::string type = typeid (var).name();
    
    std::string typeFromGetType = getType(type);
    std::string expected("unsigned char");
    CPPUNIT_ASSERT_EQUAL(typeFromGetType, expected);
}

void UtilityTests::testGetTypeOnShort() {
    short var(0);
    std::string type = typeid (var).name();

    std::string typeFromGetType = getType(type);
    std::string expected("short");
    CPPUNIT_ASSERT_EQUAL(typeFromGetType, expected);
}

void UtilityTests::testGetTypeOnUnsignedShort() {
    unsigned short var(0);
    std::string type = typeid (var).name();
    
    std::string typeFromGetType = getType(type);
    std::string expected("unsigned short");
    CPPUNIT_ASSERT_EQUAL(typeFromGetType, expected);
}

void UtilityTests::testGetTypeOnInt() {
    int var(0);
    std::string type = typeid (var).name();

    std::string typeFromGetType = getType(type);
    std::string expected("int");
    CPPUNIT_ASSERT_EQUAL(typeFromGetType, expected);
}

void UtilityTests::testGetTypeOnUnsignedInt() {
    unsigned int var(0);
    std::string type = typeid (var).name();
    
    std::string typeFromGetType = getType(type);
    std::string expected("unsigned int");
    CPPUNIT_ASSERT_EQUAL(typeFromGetType, expected);
}

void UtilityTests::testGetTypeOnLong() {
    long var(0);
    std::string type = typeid (var).name();

    std::string typeFromGetType = getType(type);
    std::string expected("long");
    CPPUNIT_ASSERT_EQUAL(typeFromGetType, expected);
}

void UtilityTests::testGetTypeOnUnsignedLong() {
    unsigned long var(0);
    std::string type = typeid (var).name();
    
    std::string typeFromGetType = getType(type);
    std::string expected("unsigned long");
    CPPUNIT_ASSERT_EQUAL(typeFromGetType, expected);
}

void UtilityTests::testGetTypeOnFloat() {
    float var(0.0);
    std::string type = typeid (var).name();
    
    std::string typeFromGetType = getType(type);
    std::string expected("float");
    CPPUNIT_ASSERT_EQUAL(typeFromGetType, expected);
}

void UtilityTests::testGetTypeOnDouble() {
    double var(0.0);
    std::string type = typeid (var).name();
    
    std::string typeFromGetType = getType(type);
    std::string expected("double");
    CPPUNIT_ASSERT_EQUAL(typeFromGetType, expected);
}

void UtilityTests::testGetTypeOnStruct() {
    struct MyStruct {
        int filler;
    } ;
    MyStruct var;
    std::string type = typeid (var).name();
    
    std::string typeFromGetType = getType(type);
    std::string expected("UtilityTests::testGetTypeOnStruct()::MyStruct");
    CPPUNIT_ASSERT_EQUAL(typeFromGetType, expected);
}

void UtilityTests::testGetTypeOnClass() {
    struct MyClass {
        int filler;
    } ;
    MyClass var;
    std::string type = typeid (var).name();
    
    std::string typeFromGetType = getType(type);
    std::string expected("UtilityTests::testGetTypeOnClass()::MyClass");
    CPPUNIT_ASSERT_EQUAL(typeFromGetType, expected);
}

/*
     MyClass myclass;
    MyOtherClass myotherclass;
    MySuperDuperCalifragilistikEpialitousousOtherClass xp;
    
    std::cout << "\nMyClass=" << typeid(myclass).name() << "\n";
    std::cout << "\nMyOtherClass=" << typeid(myotherclass).name() << "\n";
    std::cout << "\nMySuperDuperCalifragilistikEpialitousousOtherClass=" << typeid(xp).name() << "\n";
    
MyClass=7MyClass

MyOtherClass=12MyOtherClass

MySuperDuperCalifragilistikEpialitousousOtherClass=50MySuperDuperCalifragilistikEpialitousousOtherClass

 */
