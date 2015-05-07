/* 
 * File:   deducing_types.cpp
 * Author: jpimentel
 *
 * Created on April 19, 2015, 4:01 PM
 */

#include <iostream>
#include "utility_functions.h"
#include "deducing_types.h"

using namespace std;

void case1ParamIsRefOrPointer() {
    /** 
     * In the expression bellow (int x =  27) 
     * x  is a lvalue [because you can take it's address]. 
     * 27 is an rvalue [you cannot take its address]
     */
    int x = 27; // x is an int 
    const int cx = x; // cx is a const int
    const int& rx = x; // rx is a read-only view of x

    ReturnStructure result;
    
    cout << "==> Case 1: ParamType is a Reference or Pointer, but not a Universal Reference \n"
         << "    int x = 27;        // x  is an int\n"
         << "    const int cx = x;  // cx is a const int\n"
         << "    const int& rx = x; // rx is a reference to x as a const int\n"
         << "    const int *px = &x;\n\n"
         << "    Deducing types example template function type deduction passing arguments by reference\n"
         << "       template<typename T> ReturnStructure templateReceivingByRef(T& param) {...}\n";

    /** Passing by Reference */
    result = templateReceivingByRef(x);
    cout << "... Calling templateReceivingByRef --> f(x),   T deduced type as [" << result.deducedTypeForT
         << "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    result = templateReceivingByRef(cx);
    cout << "... Calling templateReceivingByRef --> f(cx),  T deduced type as [" << result.deducedTypeForT 
         <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    result = templateReceivingByRef(rx);
    cout << "... Calling templateReceivingByRef --> f(rx),  T deduced type as [" << result.deducedTypeForT
         <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n\n";


    /** Passing by Const Reference */
    cout << "    Deducing types example template function type deduction passing arguments by constant reference\n";
    result = templateReceivingByConstRef(x);
    cout << "       template<typename T> ReturnStructure templateReceivingByConstRef(const T& param) {...}\n"
         << "... Calling templateReceivingByConstRef --> f(x),  T deduced type as [" << result.deducedTypeForT 
         <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    result = templateReceivingByConstRef(cx);
    cout << "... Calling templateReceivingByConstRef --> f(cx), T deduced type as [" << result.deducedTypeForT  
         << "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    result = templateReceivingByConstRef(rx);
    cout << "... Calling templateReceivingByConstRef --> f(rx), T deduced type as [" << result.deducedTypeForT
         << "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n\n";

    /** Passing by Pointer*/
    cout << "    Deducing types example template function type deduction passing arguments by pointer\n"
         << "       template<typename T> ReturnStructure templateReceivingByPointer(T* param) {...}\n";
    
    result = templateReceivingByPointer(&x);
    cout << "... Calling templateReceivingByConstPointer --> f(&x), T deduced type as [" << result.deducedTypeForT 
         <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    const int *px = &x;
    result = templateReceivingByPointer(px);
    cout << "... Calling templateReceivingByConstPointer --> f(px), T deduced type as [" << result.deducedTypeForT
         << "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n\n";
    
}

void case2ParamIsURef() {
    /** 
     * In the expression bellow (int x =  27) 
     * x  is a lvalue [because you can take it's address]. 
     * 27 is an rvalue [you cannot take its address]
     */
    int x = 27; // x is an int 
    const int cx = x; // cx is a const int
    const int& rx = x; // rx is a read-only view of x

    ReturnStructure result;
    
    cout << "==> Case 2: ParamType is an Universal Reference\n"
         << "    Deducing types example template function type deduction passing arguments by universal reference\n"
         << "       template<typename T> ReturnStructure templateReceivingByRvalue(T&& param) {...}\n"
         << "    int x = 27;        // x  is an int\n"
         << "    const int cx = x;  // cx is a const int\n"
         << "    const int& rx = x; // rx is a reference to x as a const int\n\n";

    result = templateReceivingByRvalue(x);
    cout << "... Calling templateReceivingByRvalue(x),  T deduced type as [" << result.deducedTypeForT 
         <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    result = templateReceivingByRvalue(cx);
    cout << "... Calling templateReceivingByRvalue(cx), T deduced type as [" << result.deducedTypeForT
         <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    result = templateReceivingByRvalue(rx);
    cout << "... Calling templateReceivingByRvalue(rx), T deduced type as [" << result.deducedTypeForT
         <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    result = templateReceivingByRvalue(27);
    cout << "... Calling templateReceivingByRvalue(27), T deduced type as [" << result.deducedTypeForT 
         <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n\n";
}

void case3ParamIsValue() {
    /** 
     * In the expression bellow (int x =  27) 
     * x  is a lvalue [because you can take it's address]. 
     * 27 is an rvalue [you cannot take its address]
     */
    int x = 27; // x is an int 
    const int cx = x; // cx is a const int
    const int& rx = x; // rx is a read-only view of x
    
    ReturnStructure result;

    cout << "==> Case 3: ParamType is neither a Pointer nor a Reference\n"
         << "    int x = 27;        // x  is an int\n"
         << "    const int cx = x;  // cx is a const int\n"
         << "    const int& rx = x; // rx is a reference to x as a const int\n\n"
         << "    Deducing types example template function type deduction passing arguments by value\n"
         << "       template<typename T> ReturnStructure templateReceivingByValue(T param) {...}\n";

    result = templateReceivingByValue(x);
    cout << "... Calling templateReceivingByValue(x),  T deduced type as [" << result.deducedTypeForT 
         <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    result = templateReceivingByValue(cx);
    cout << "... Calling templateReceivingByValue(cx), T deduced type as [" << result.deducedTypeForT 
         <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    result = templateReceivingByValue(rx); 
    cout << "... Calling templateReceivingByValue(rx), T deduced type as [" << result.deducedTypeForT
          <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n\n";
    
}

//void arrayArguments() {
//    using namespace std;
//    
//    const char name[] = "J. P. Briggs"; // name's type is
//                                        // const char[13]
//    const char * ptrToName = name;      // array decays to pointer
//    
//    ReturnStructure result;
//
//    cout << "==> Case Array Arguments: ParamType is an Array\n"
//         << "    const char name[] = \"J. P. Briggs\"; // name's type is\n                           // const char[13]\n"
//         << "    const char * ptrToName = name;      // array decays to pointer\n"
//         << "    Deducing types example template function type deduction passing arguments by value\n"
//         << "       template<typename T> ReturnStructure templateReceivingByValue(T param) {...}\n";
//
//    result = templateReceivingByValue(name);
//    cout << "... Calling templateReceivingByValue(name),  T deduced type as [" << result.deducedTypeForT 
//         <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
//    
//    cout << "    Deducing types example template function type deduction passing arguments by reference\n"
//         << "       template<typename T> ReturnStructure templateReceivingByRef(T& param) {...}\n";
//
//    /** Passing by Reference */
//    result = templateReceivingByRef(name);
//    cout << "... Calling templateReceivingByRef --> f(name),   T deduced type as [" << result.deducedTypeForT
//         << "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
//    
//}

/*
 * 
 */
int main(int argc, char** argv) {

    using namespace std;
    
    cout << "============================================" << endl;
    cout << "Deducing Types Tutorial" << endl;
    cout << "============================================" << endl << endl;
    
    case1ParamIsRefOrPointer();
   
    case2ParamIsURef();
    
    case3ParamIsValue();

//    arrayArguments();

    return 0;
}

