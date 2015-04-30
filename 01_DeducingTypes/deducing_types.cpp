/* 
 * File:   deducing_types.cpp
 * Author: jpimentel
 *
 * Created on April 19, 2015, 4:01 PM
 */

#include <iostream>
#include "deducing_types.h"

using namespace std;

// expre_typeid_Operator.cpp
// compile with: /GR /EHsc
#include <iostream>


struct ReturnStructure {
    // bool is_rvalue;
    string deducedTypeForT;
    string deducedTypeForParamType;
};

template<typename T>
ReturnStructure templateReceivingByRef(T& param) {
    using namespace std;
    static string  SEARCH_FOR = "with T = ";
    ReturnStructure retStruct;
    retStruct.deducedTypeForParamType = "";

    if (is_const<decltype(param)>::value == true) {
        retStruct.deducedTypeForParamType += "const ";
    }
    if (is_rvalue_reference<decltype(param)>::value == true) {
        retStruct.deducedTypeForParamType += "rvalue ref {";
    } else if (is_lvalue_reference<decltype(param)>::value == true) {
        retStruct.deducedTypeForParamType += "lvalue ref {";
    } else {
        retStruct.deducedTypeForParamType += "not a ref {";
    }
    retStruct.deducedTypeForParamType += typeid (param).name();
    retStruct.deducedTypeForParamType +=   "}";
    
    // retStruct.is_rvalue = false;
    
#if defined(__GNUC__)
    string pretty_function_result(__PRETTY_FUNCTION__);
#elif defined(_MSC_VER)
    string pretty_function_result(__FUNCSIG__);
#endif
    // pretty_function_result = ") &&"; // for test only
    size_t args_start_pos = pretty_function_result.find(SEARCH_FOR) + SEARCH_FOR.length(); // procura o final da descrição de parametros de pretty_function_result.
    if (args_start_pos!= string::npos) {
        // retStruct.is_rvalue   = (pretty_function_result.find("&&", args_start_pos)!=string::npos);
        string args = pretty_function_result.substr(args_start_pos);
        retStruct.deducedTypeForT = args.substr(0, args.length()-1); 
    }
    return retStruct;
}



template<typename T>
ReturnStructure templateReceivingByValue(T param) {
    using namespace std;
    static string  SEARCH_FOR = "with T = ";
    ReturnStructure retStruct;
    retStruct.deducedTypeForParamType = "";

    if (is_const<decltype(param)>::value == true) {
        retStruct.deducedTypeForParamType += "const ";
    }
    if (is_rvalue_reference<decltype(param)>::value == true) {
        retStruct.deducedTypeForParamType += "rvalue ref {";
    } else if (is_lvalue_reference<decltype(param)>::value == true) {
        retStruct.deducedTypeForParamType += "lvalue ref {";
    } else {
        retStruct.deducedTypeForParamType += "not a ref {";
    }
    retStruct.deducedTypeForParamType += typeid (param).name();
    retStruct.deducedTypeForParamType +=   "}";
    
    // retStruct.is_rvalue = false;
    
#if defined(__GNUC__)
    string pretty_function_result(__PRETTY_FUNCTION__);
#elif defined(_MSC_VER)
    string pretty_function_result(__FUNCSIG__);
#endif
    // pretty_function_result = ") &&"; // for test only
    size_t args_start_pos = pretty_function_result.find(SEARCH_FOR) + SEARCH_FOR.length(); // procura o final da descrição de parametros de pretty_function_result.
    if (args_start_pos!= string::npos) {
        // retStruct.is_rvalue   = (pretty_function_result.find("&&", args_start_pos)!=string::npos);
        string args = pretty_function_result.substr(args_start_pos);
        retStruct.deducedTypeForT = args.substr(0, args.length()-1); 
    }
    return retStruct;
}

template<typename T>
ReturnStructure templateReceivingByRvalue(T&& param) {
    using namespace std;
    static string  SEARCH_FOR = "with T = ";
    ReturnStructure retStruct;
    retStruct.deducedTypeForParamType = "";

    if (is_const<decltype(param)>::value == true) {
        retStruct.deducedTypeForParamType += "const ";
    }
    if (is_rvalue_reference<decltype(param)>::value == true) {
        retStruct.deducedTypeForParamType += "rvalue ref {";
    } else if (is_lvalue_reference<decltype(param)>::value == true) {
        retStruct.deducedTypeForParamType += "lvalue ref {";
    } else {
        retStruct.deducedTypeForParamType += "not a ref {";
    }
    retStruct.deducedTypeForParamType += typeid (param).name();
    retStruct.deducedTypeForParamType +=   "}";
    
    // retStruct.is_rvalue = false;
    
#if defined(__GNUC__)
    string pretty_function_result(__PRETTY_FUNCTION__);
#elif defined(_MSC_VER)
    string pretty_function_result(__FUNCSIG__);
#endif
    // pretty_function_result = ") &&"; // for test only
    size_t args_start_pos = pretty_function_result.find(SEARCH_FOR) + SEARCH_FOR.length(); // procura o final da descrição de parametros de pretty_function_result.
    if (args_start_pos!= string::npos) {
        // retStruct.is_rvalue   = (pretty_function_result.find("&&", args_start_pos)!=string::npos);
        string args = pretty_function_result.substr(args_start_pos);
        retStruct.deducedTypeForT = args.substr(0, args.length()-1); 
    }
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
         << "    template<typename T> ReturnStructure\n    templateReceivingByValue(T param) {...}\n";

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
    
    cout << "==> Deducing types example template function type deduction passing arguments by rvalue\n"
         << "    template<typename T> ReturnStructure\n    templateReceivingByRef(T& param) {...}\n";

//    cout << "... Calling templateReceivingByRef(int 27),        and return ";
//    result = templateReceivingByRef(27);
//    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";

    cout << "... Calling templateReceivingByRef(int x),         and return ";
    result = templateReceivingByRef(x);
    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    cout << "... Calling templateReceivingByRef(const int cx),  and return ";
    result = templateReceivingByRef(cx);
    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    cout << "... Calling templateReceivingByRef(const int& rx), and return ";
    result = templateReceivingByRef(rx);
    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n";
    
    cout << "... Calling templateReceivingByRef(int&& urx),     and return ";
    result = templateReceivingByRef(urx);
    cout << "T deduced type as [" << result.deducedTypeForT <<  "] and ParamType deduced type as [" << result.deducedTypeForParamType << "]\n\n";    
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

