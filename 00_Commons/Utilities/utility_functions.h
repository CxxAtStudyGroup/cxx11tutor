/* 
 * File:   utility_functions.h
 * Author: jpimentel
 *
 * Created on April 30, 2015, 11:41 PM
 */

#ifndef UTILITY_FUNCTIONS_H
#define	UTILITY_FUNCTIONS_H

#include <typeinfo>       // operator typeid
#include <type_traits>
#include <iostream>
#include <string>

static std::string  SEARCH_FOR("with T = ");

class MyClass {
    
};

class MyOtherClass {
    
};

class MySuperDuperCalifragilistikEpialitousousOtherClass {
    
};

struct ReturnStructure {
    // bool is_rvalue;
    std::string deducedTypeForT;
    std::string deducedTypeForParamType;
    bool isConst;
    bool isLValueRef; 
    bool isRValueRef; 
    bool isPointer;
};

template<typename T> 
std::string deduced_type_f(T) {
    
}

std::string getType(std::string type);

inline void deduce_type(const std::string& typePrettyFunction, 
                        const std::string& paramType, 
                        ReturnStructure& retStruct) {

    retStruct.deducedTypeForParamType = "";
    
    // procura o final da descrição de parametros de pretty_function_result.
    size_t args_start_pos = typePrettyFunction.find(SEARCH_FOR) + SEARCH_FOR.length(); 
    if (args_start_pos!= std::string::npos) {
        // retStruct.is_rvalue   = (pretty_function_result.find("&&", args_start_pos)!=string::npos);
        std::string args = typePrettyFunction.substr(args_start_pos);
        retStruct.deducedTypeForT = args.substr(0, args.length()-1); 
    } else {
        retStruct.deducedTypeForT = typePrettyFunction;
    }

    if (retStruct.isConst) {
        retStruct.deducedTypeForParamType += "const ";
    }
    retStruct.deducedTypeForParamType += paramType;
    if (retStruct.isRValueRef) {
        retStruct.deducedTypeForParamType += "&&";
    } else if (retStruct.isLValueRef) {
        retStruct.deducedTypeForParamType += "&";
    } else if (retStruct.isPointer) {
        retStruct.deducedTypeForParamType += "*";
    }
} 

bool hasConstInPrettyFunctionResultParamType(std::string prettyFunction);

template<typename T>
ReturnStructure templateReceivingByRef(T& param) {
    using namespace std;
    const T x(param);
    ReturnStructure retStruct;
#if defined(__GNUC__)
    string pretty_function_result(__PRETTY_FUNCTION__);
#elif defined(_MSC_VER)
    string pretty_function_result(__FUNCSIG__);
#endif
    retStruct.deducedTypeForParamType = "";
    std::string identifiedType = getType(typeid (param).name());
    retStruct.isConst = !is_assignable<decltype(param), decltype(x)>::value;
    retStruct.isLValueRef = is_lvalue_reference<decltype(param)>::value; 
    retStruct.isRValueRef = is_rvalue_reference<decltype(param)>::value; 
    retStruct.isPointer = is_pointer<decltype(param)>::value;
    deduce_type(pretty_function_result, 
                identifiedType, 
                retStruct);
    return retStruct;
}

template<typename T>
ReturnStructure templateReceivingByConstRef(const T& param) {
    using namespace std;
    const T x(param);
    ReturnStructure retStruct;
#if defined(__GNUC__)
    string pretty_function_result(__PRETTY_FUNCTION__);
#elif defined(_MSC_VER)
    string pretty_function_result(__FUNCSIG__);
#endif
    retStruct.deducedTypeForParamType = "";
    std::string identifiedType = getType(typeid (param).name());
    retStruct.isConst = !is_assignable<decltype(param), decltype(x)>::value;
    retStruct.isLValueRef = is_lvalue_reference<decltype(param)>::value; 
    retStruct.isRValueRef = is_rvalue_reference<decltype(param)>::value; 
    retStruct.isPointer = is_pointer<decltype(param)>::value;
    deduce_type(pretty_function_result, 
                identifiedType, 
                retStruct);
    return retStruct;
}

template<typename T>
ReturnStructure templateReceivingByPointer(T* param) {
    using namespace std;
    const T* x = new T(*param);
    ReturnStructure retStruct;
#if defined(__GNUC__)
    string pretty_function_result(__PRETTY_FUNCTION__);
#elif defined(_MSC_VER)
    string pretty_function_result(__FUNCSIG__);
#endif
    retStruct.deducedTypeForParamType = "";
    std::string identifiedType = getType(typeid (param).name());
    /* Por motivo não identificado esta função não está funcionando adequadamente e por isto será substituída para ponteiros 
     bool isConst = !is_assignable<decltype(param), decltype(x)>::value;
     */
    retStruct.isConst = hasConstInPrettyFunctionResultParamType(pretty_function_result);
    retStruct.isLValueRef = is_lvalue_reference<decltype(param)>::value;
    retStruct.isRValueRef = is_rvalue_reference<decltype(param)>::value;
    retStruct.isPointer = is_pointer<decltype(param)>::value;
    deduce_type(pretty_function_result,
                identifiedType,
                retStruct);
    return retStruct;
}

template<typename T>
ReturnStructure templateReceivingByValue(T param) {
    using namespace std;
    const T x(param);
    ReturnStructure retStruct;
#if defined(__GNUC__)
    string pretty_function_result(__PRETTY_FUNCTION__);
#elif defined(_MSC_VER)
    string pretty_function_result(__FUNCSIG__);
#endif
    retStruct.deducedTypeForParamType = "";
    std::string identifiedType = getType(typeid (param).name());
    /* Por motivo não identificado esta função não está funcionando adequadamente e por isto será substituída para ponteiros 
     bool isConst = !is_assignable<decltype(param), decltype(x)>::value;
     */
    retStruct.isConst = hasConstInPrettyFunctionResultParamType(pretty_function_result);
    retStruct.isLValueRef = is_lvalue_reference<decltype(param)>::value; 
    retStruct.isRValueRef = is_rvalue_reference<decltype(param)>::value; 
    retStruct.isPointer = is_pointer<decltype(param)>::value;
    deduce_type(pretty_function_result, 
                identifiedType, 
                retStruct);
    return retStruct;

}

template<typename T>
ReturnStructure templateReceivingByRvalue(T&& param) {
    using namespace std;
    const T x(param);
    ReturnStructure retStruct;
#if defined(__GNUC__)
    string pretty_function_result(__PRETTY_FUNCTION__);
#elif defined(_MSC_VER)
    string pretty_function_result(__FUNCSIG__);
#endif
    retStruct.deducedTypeForParamType = "";
    std::string identifiedType = getType(typeid (param).name());
    retStruct.isConst = !is_assignable<decltype(param), decltype(x)>::value;
    retStruct.isLValueRef = is_lvalue_reference<decltype(param)>::value; 
    retStruct.isRValueRef = is_rvalue_reference<decltype(param)>::value; 
    retStruct.isPointer = is_pointer<decltype(param)>::value;
    deduce_type(pretty_function_result, 
                identifiedType, 
                retStruct);

    return retStruct;
}


#endif	/* UTILITY_FUNCTIONS_H */

