/* 
 * File:   utility_functions.h
 * Author: jpimentel
 *
 * Created on April 30, 2015, 11:41 PM
 */

#ifndef UTILITY_FUNCTIONS_H
#define	UTILITY_FUNCTIONS_H

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
};

template<typename T> 
std::string deduced_type_f(T) {
    
}

std::string getType(std::string type);

inline void deduce_type(const std::string& typePrettyFunction, 
                        const std::string& paramType, 
                        bool isConst, 
                        bool isLValue, 
                        bool isRValue, 
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

    if (isConst) {
        retStruct.deducedTypeForParamType += "const ";
    }
    retStruct.deducedTypeForParamType += paramType;
    if (isRValue) {
        retStruct.deducedTypeForParamType += "&&";
    } else if (isLValue) {
        retStruct.deducedTypeForParamType += "&";
    }
}


#endif	/* UTILITY_FUNCTIONS_H */

