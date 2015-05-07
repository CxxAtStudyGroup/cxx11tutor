#include <typeinfo>

#include <boost/lexical_cast.hpp>

#include "utility_functions.h"

std::string decomposeComplexType(std::string typeName) {
        std::string retString;
        std::string num;
        size_t len = 0;
        size_t idx = 0;
        if (typeName.substr(0,3)=="EvE") {
           return decomposeComplexType(typeName.substr(3));
        } 
        while (isdigit(typeName[idx])) { // Compute size of the next name part
            if (isdigit(typeName[idx])) {
                num += typeName[idx++];
            }
        }
        
        try {
            len = boost::lexical_cast<size_t>(num);
        } catch (std::bad_cast &bce) {
            return retString;
        }
        if (len > 0 ) {
            if (idx+len <= typeName.size()) {
                retString += typeName.substr(idx, len);
                if (idx+len < typeName.size() && 
                    (isdigit(typeName[idx+len]) || typeName.substr(idx+len).substr(0,3)=="EvE")
                   ) {
                    retString += "::" + decomposeComplexType(typeName.substr(idx+len));
                } else {
                    return retString;
                }
            } else { 
                return "";
            }
        }
        return retString;
}

std::string getType(std::string type) {
    std::string returnType;
    // std::cout << "\nreceived type: " << type << "\n";
    if (type[0] == 'P') {
        type = type.substr(1);
    }
    if (type[0] == 'K') {
        type = type.substr(1);
    }
    if (type == "i") {
        returnType = "int" ;
    } else if (type == "j") {
        returnType = "unsigned int";
    } else if (type == "l") {
        returnType = "long";
    } else if (type == "m") {
        returnType = "unsigned long";
    } else if (type == "f") {
        returnType = "float";
    } else if (type == "d") {
        returnType = "double";
    } else if (type == "s") {
        returnType = "short";
    } else if (type == "t") {
        returnType = "unsigned short";
    } else if (type == "c") {
        returnType = "char";
    } else if (type == "h") {
        returnType = "unsigned char";
    } else if (isdigit(type[0]) || // simple type
               type.substr(0,2) == "ZN" || // inside function type ?
               (type[0] == 'N' && isdigit(type[1])) // namespaced type ?
              ) {
        // size_t idx = type.find_last_not_of("012345678", type.size());
        size_t idx = 0;
        if (type.substr(0,2) == "ZN") {
           type = type.substr(2);
        } else if (type[0] == 'N' && isdigit(type[1])) {
           type = type.substr(1);
        } else { 
            std::cout << "\nType identified is : " << type << "\n";
            returnType = "Unidentified Type";
        }
        returnType = decomposeComplexType(type);
    } else {
        // std::cout << "\nType identified is : " << type << "\n";
        returnType = "Unidentified Type";
    }
    return returnType;
}

bool hasConstInPrettyFunctionResultParamType(std::string prettyFunction) {
    bool hasConst = false;
    size_t iniPos = prettyFunction.find_first_of('[');
    if (iniPos != std::string::npos) {
        if (prettyFunction.find("const", iniPos) != std::string::npos) {
            hasConst = true;
        } 
    }
    return hasConst;
}