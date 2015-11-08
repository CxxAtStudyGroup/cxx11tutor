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

void DeducingTypesTest::item1Case1TemplateReceivingByRef() {
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

void DeducingTypesTest::item1Case1TemplateReceivingByRefToConst() {
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

void DeducingTypesTest::item1Case1TemplateReceivingByPointer() {
    int x = 27;         // x  is an int
    const int *px = &x; // px is a pointer to x as a const int 
    ReturnStructure result = templateReceivingByPointer(&x);
    CPPUNIT_ASSERT(result.deducedTypeForT == "int");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "int*");
    
    result = templateReceivingByPointer(px);
    CPPUNIT_ASSERT(result.deducedTypeForT == "const int");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "const int const*");
    
}

void DeducingTypesTest::item1Case2TemplateReceivingByRvalue() {
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

void DeducingTypesTest::item1Case3TemplateReceivingByValue() {
    int x = 27;         // x  is an int
    const int cx = x;   // cx is a const int
    const int& rx = x;  // rx is a reference to x as a const int
    ReturnStructure result = templateReceivingByValue(x);
    CPPUNIT_ASSERT(result.deducedTypeForT == "int");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "int");
    
    result = templateReceivingByValue(cx);
    CPPUNIT_ASSERT(result.deducedTypeForT == "int");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "int");
    
    result = templateReceivingByValue(rx);
    CPPUNIT_ASSERT(result.deducedTypeForT == "int");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "int");
    
    const char* const ptr = "Fun with pointers"; // ptr is const pointer to const object

    result = templateReceivingByValue(ptr);
    CPPUNIT_ASSERT(result.deducedTypeForT == "const char*");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "const char const*");
}

void DeducingTypesTest::item1Case3TemplateReceivingArrayByValue() {
    
    const char name[] = "J. P. Briggs"; // name's type is
                                        // const char[13]
    const char *ptrToName = name;      // array decays to pointer
    
    int intValues[] = { 1, 3, 7, 9, 11, 22, 35 };
    std::array<int, arraySize(intValues)> mappedVals;
    ReturnStructure result;
    
    result = templateReceivingByValue(name);
    CPPUNIT_ASSERT(result.deducedTypeForT == "const char*");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "const char const*");

    result = templateReceivingByValue(ptrToName);
    CPPUNIT_ASSERT(result.deducedTypeForT == "const char*");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "const char const*");

    result = templateReceivingByValue(intValues);
    CPPUNIT_ASSERT(result.deducedTypeForT == "int*");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "int*");    

    result = templateReceivingByValue(mappedVals);
    CPPUNIT_ASSERT(result.deducedTypeForT == "std::array<int, 7ul>");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "std::array<int, 7ul>");    

}

void DeducingTypesTest::item1Case3TemplateReceivingArrayByRef() {
    
    const char name[] = "J. P. Briggs"; // name's type is
                                        // const char[13]
    const char *ptrToName = name;      // array decays to pointer
    
    int intValues[] = { 1, 3, 7, 9, 11, 22, 35 };
    std::array<int, arraySize(intValues)> mappedVals;
    ReturnStructure result;
    
    result = templateReceivingByRef(name);
    CPPUNIT_ASSERT(result.deducedTypeForT == "const char [13]");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "const char [13]&");
    
    result = templateReceivingByRef(ptrToName);
    CPPUNIT_ASSERT(result.deducedTypeForT == "const char*");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "char const*&");
    
    result = templateReceivingByRef(intValues);
    CPPUNIT_ASSERT(result.deducedTypeForT == "int [7]");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "int [7]&");    

    result = templateReceivingByRef(mappedVals);
    CPPUNIT_ASSERT(result.deducedTypeForT == "std::array<int, 7ul>");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "std::array<int, 7ul>&");    
}

void func(int, double) {}  // someFunc is a function - type is void(int, double)

void DeducingTypesTest::item1Case3TemplateReceivingFuncByValue() {
    ReturnStructure result;
    
    result = templateReceivingByValue(func);
    CPPUNIT_ASSERT(result.deducedTypeForT == "void (*)(int, double)");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "void (*)(int, double)");
}

void DeducingTypesTest::item1Case3TemplateReceivingFuncByRef() {
    ReturnStructure result;
    
    result = templateReceivingByRef(func);
    CPPUNIT_ASSERT(result.deducedTypeForT == "void(int, double)");
    CPPUNIT_ASSERT(result.deducedTypeForParamType == "void (int, double)&");    
}
