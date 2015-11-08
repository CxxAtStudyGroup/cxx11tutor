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
#include <cxxabi.h>
// #include <boost/typeindex.h> // Needs boost 1.57+

static std::string  SEARCH_FOR_PARAMTYPE("with T = ");

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
    
    /* Needs boost 1.57+ */
// // show T
// cout << "T = " << type_id_with_cvr<T>().pretty_name() << '\n';
// // show param's type
// cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << '\n';
    
    // procura o final da descrição de parametros de pretty_function_result.
    size_t args_start_pos = typePrettyFunction.find(SEARCH_FOR_PARAMTYPE) + SEARCH_FOR_PARAMTYPE.length(); 
    if (args_start_pos!= std::string::npos) {
        // retStruct.is_rvalue   = (pretty_function_result.find("&&", args_start_pos)!=string::npos);
        std::string args = typePrettyFunction.substr(args_start_pos);
        retStruct.deducedTypeForT = args.substr(0, args.length()-1); 
    } else {
        retStruct.deducedTypeForT = typePrettyFunction;
    }
    std::string deducedParamType = paramType;
    if (retStruct.isConst && 
        !retStruct.isRValueRef) { // rvalues are const by definition
        retStruct.deducedTypeForParamType += "const ";
        size_t positionOfConstInParamType = paramType.find(" const"); 
        if (positionOfConstInParamType != std::string::npos) {
            deducedParamType.erase(positionOfConstInParamType, 6);
        }
    }

    retStruct.deducedTypeForParamType += deducedParamType;
    if (retStruct.isRValueRef) {
        retStruct.deducedTypeForParamType += "&&";
    } else if (retStruct.isLValueRef) {
        retStruct.deducedTypeForParamType += "&";
//    } else if (retStruct.isPointer) {
//        retStruct.deducedTypeForParamType += "*";
    }
} 

bool hasConstInPrettyFunctionResultParamType(std::string prettyFunction);

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
    std::string identifiedType = getType(typeid (param).name());
    retStruct.isConst = is_const<T>::value;
    retStruct.isLValueRef = is_lvalue_reference<decltype(param)>::value; 
    retStruct.isRValueRef = is_rvalue_reference<decltype(param)>::value; 
    retStruct.isPointer = is_pointer<decltype(param)>::value;
    deduce_type(pretty_function_result, 
                identifiedType, 
                retStruct);
    return retStruct;
}

template<typename T>
ReturnStructure templateReceivingFuncByRef(T& param) {
    using namespace std;
    ReturnStructure retStruct;
#if defined(__GNUC__)
    string pretty_function_result(__PRETTY_FUNCTION__);
#elif defined(_MSC_VER)
    string pretty_function_result(__FUNCSIG__);
#endif
    retStruct.deducedTypeForParamType = "";
    std::string identifiedType = getType(typeid (param).name());
    retStruct.isConst = false;
    retStruct.isLValueRef = is_lvalue_reference<decltype(param)>::value; 
    retStruct.isRValueRef = is_rvalue_reference<decltype(param)>::value; 
    retStruct.isPointer = is_pointer<decltype(param)>::value;
    deduce_type(pretty_function_result, 
                identifiedType, 
                retStruct);
    return retStruct;
}

template<typename T>
ReturnStructure templateReceivingByRefToConst(const T& param) {
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

template<typename T>
ReturnStructure templateReceivingArrayByRef(T& param)  {
    using namespace std;
    // T x[sizeof(param)];
    ReturnStructure retStruct;
#if defined(__GNUC__)
    string pretty_function_result(__PRETTY_FUNCTION__);
#elif defined(_MSC_VER)
    string pretty_function_result(__FUNCSIG__);
#endif
    retStruct.deducedTypeForParamType = "";
    std::string identifiedType = getType(typeid (param).name());
    retStruct.isConst = !is_const<decltype(param)>::value;
    retStruct.isLValueRef = is_lvalue_reference<decltype(param)>::value; 
    retStruct.isRValueRef = is_rvalue_reference<decltype(param)>::value; 
    retStruct.isPointer = is_pointer<decltype(param)>::value;
    deduce_type(pretty_function_result, 
                identifiedType, 
                retStruct);
    return retStruct;
}

// return size of an array as a compile-time constant. (The
// array parameter has no name, because we care only about
// the number of elements it contains.)
template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept { // see info below on and constexpr 
    return N;
}
 


#endif	/* UTILITY_FUNCTIONS_H */

