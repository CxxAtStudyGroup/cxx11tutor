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

template<typename T>
ReturnStructure templateReceivingByRef(T& param) {
    using namespace std;
    ReturnStructure retStruct;
#if defined(__GNUC__)
    string pretty_function_result(__PRETTY_FUNCTION__);
#elif defined(_MSC_VER)
    string pretty_function_result(__FUNCSIG__);
#endif
    retStruct.deducedTypeForParamType = "";
    std::string typeIdentified = getType(typeid (param).name());
    deduce_type(pretty_function_result, 
                typeIdentified, 
                is_const<decltype(param)>::value, 
                is_lvalue_reference<decltype(param)>::value,
                is_rvalue_reference<decltype(param)>::value,
                retStruct);

    return retStruct;
}



template<typename T>
ReturnStructure templateReceivingByValue(T param) {
    using namespace std;
    ReturnStructure retStruct;
#if defined(__GNUC__)
    string pretty_function_result(__PRETTY_FUNCTION__);
#elif defined(_MSC_VER)
    string pretty_function_result(__FUNCSIG__);
#endif
    retStruct.deducedTypeForParamType = "";
    std::string typeIdentified = getType(typeid (param).name());
    deduce_type(pretty_function_result, 
                typeIdentified, 
                is_const<decltype(param)>::value, 
                is_lvalue_reference<decltype(param)>::value,
                is_rvalue_reference<decltype(param)>::value,
                retStruct);

    return retStruct;

}

template<typename T>
ReturnStructure templateReceivingByRvalue(T&& param) {
    using namespace std;
    ReturnStructure retStruct;
#if defined(__GNUC__)
    string pretty_function_result(__PRETTY_FUNCTION__);
#elif defined(_MSC_VER)
    string pretty_function_result(__FUNCSIG__);
#endif
    retStruct.deducedTypeForParamType = "";
    std::string typeIdentified = getType(typeid (param).name());
    deduce_type(pretty_function_result, 
                typeIdentified, 
                is_const<decltype(param)>::value, 
                is_lvalue_reference<decltype(param)>::value,
                is_rvalue_reference<decltype(param)>::value,
                retStruct);

    return retStruct;

}

void templateFunctionByValue() {
    /** 
     * In the expression bellow (int x =  27) 
     * x  is a lvalue [because you can take it's address]. 
     * 27 is an rvalue [you cannot take its address]
     */
    int x = 27; // x is an int 
    const int cx = x; // cx is a const int
    const int& rx = x; // rx is a read-only view of x
    int&& urx = 27;
    ReturnStructure result;
    
    cout << "==> Deducing types example template function type deduction passing arguments by Value\n"
         << "    template<typename T> ReturnStructure\n    templateReceivingByValue(T param) {...}\n" 
         << "    int x = 27;  // x is an int\n " 
         << "    const int cx = x; // cx is a const int\n"
         << "    const int& rx = x; // rx is a reference to x as a const int\n";

    cout << "... Calling templateReceivingByValue(int 27),        and return ";
    result = templateReceivingByValue(27);
    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";

    cout << "... Calling templateReceivingByValue(int x),         and return ";
    result = templateReceivingByValue(x);
    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    cout << "... Calling templateReceivingByValue(const int cx),  and return ";
    result = templateReceivingByValue(cx);
    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    cout << "... Calling templateReceivingByValue(const int& rx), and return ";
    result = templateReceivingByValue(rx);
    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    cout << "... Calling templateReceivingByValue(int&& urx),     and return ";
    result = templateReceivingByValue(urx);
    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n\n";    
}

void templateFunctionByURef() {
    /** 
     * In the expression bellow (int x =  27) 
     * x  is a lvalue [because you can take it's address]. 
     * 27 is an rvalue [you cannot take its address]
     */
    int x = 27; // x is an int 
    
    const int cx = x; // cx is a const int
    const int& rx = x; // rx is a read-only view of x
    int&& urx = 27;
    ReturnStructure result;
    
    cout << "==> Deducing types example template function type deduction passing arguments by rvalue\n"
         << "    template<typename T> ReturnStructure\n    templateReceivingByRvalue(T&& param) {...}\n";

    
    cout << "... Calling templateReceivingByRvalue(int 27),        and return ";
    result = templateReceivingByRvalue(27);
    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";

    cout << "... Calling templateReceivingByRvalue(int x),         and return ";
    result = templateReceivingByRvalue(x);
    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    cout << "... Calling templateReceivingByRvalue(const int cx),  and return ";
    result = templateReceivingByRvalue(cx);
    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    cout << "... Calling templateReceivingByRvalue(const int& rx), and return ";
    result = templateReceivingByRvalue(rx);
    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    cout << "... Calling templateReceivingByRvalue(int&& urx),     and return ";
    result = templateReceivingByRvalue(urx);
    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n\n";    
}

void templateFunctionByRef() {
    /** 
     * In the expression bellow (int x =  27) 
     * x  is a lvalue [because you can take it's address]. 
     * 27 is an rvalue [you cannot take its address]
     */
    int x = 27; // x is an int 
    
    const int cx = x; // cx is a const int
    const int& rx = x; // rx is a read-only view of x
    int&& urx = 27;
    ReturnStructure result;
    
    cout << "==> Case 1: ParamType is a Reference or Pointer, but not a Universal Reference \n"
         << "    Deducing types example template function type deduction passing arguments by rvalue\n"
         << "    template<typename T> ReturnStructure\n    templateReceivingByRef(T& param) {...}\n"
         << "    int x = 27;        // x  is an int\n"
         << "    const int cx = x;  // cx is a  const int\n"
         << "    const int& rx = x; // rx is a  reference to x as a const int\n";

//    cout << "... Calling templateReceivingByRef(int 27),        and return ";
//    result = templateReceivingByRef(27);
//    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";

    cout << "... Calling templateReceivingByRef --> f(x),         and ";
    result = templateReceivingByRef(x);
    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    cout << "... Calling templateReceivingByRef --> f(cx),        and ";
    result = templateReceivingByRef(cx);
    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    cout << "... Calling templateReceivingByRef --> f(rx),        and ";
    result = templateReceivingByRef(rx);
    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n\n";
    
//    cout << "... Calling templateReceivingByRef(int&& urx),     and return ";
//    result = templateReceivingByRef(urx);
//    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n\n";    
}

void deducing_types_01() {
    using namespace std;
    
    templateFunctionByRef();
    
    templateFunctionByValue();
    
    templateFunctionByURef();

}

/*
 * 
 */
int main(int argc, char** argv) {

    using namespace std;
    
    cout << "============================================" << endl;
    cout << "Deducing Types Tutorial" << endl;
    cout << "============================================" << endl << endl;
    
    deducing_types_01();

    return 0;
}

