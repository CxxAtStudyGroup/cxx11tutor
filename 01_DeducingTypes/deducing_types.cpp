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


template<typename T>
void f1(T&& param) {
    using namespace std;

    cout << "    parameter received is of type: IS NOT WORKING AS EXPECTED yet!!!!";
    if (is_const<decltype(param)>::value == true) {
        cout << "const ";
    }
    if (is_rvalue_reference<decltype(param)>::value == true) {
        cout << " rvalue ref ";
    } else if (is_lvalue_reference<decltype(param)>::value == true) {
        cout << " lvalue ref ";
    }
    if (typeid(param) == typeid (T)) {
        cout << typeid (T).name();
    } 
    cout << "\n";
#if defined(__GNUC__)
    cout << __PRETTY_FUNCTION__ << '\n';
#elif defined(_MSC_VER)
    cout << __FUNCSIG__ << '\n';
#endif

}

void deducing_types_01() {
    using namespace std;

    int x = 27; // x is an int
    const int cx = x; // cx is a const int
    const int& rx = x; // rx is a read-only view of x
    int&& urx = 27;

    cout << "==> Deducing types example 01\n"
            << "... This example shows template type deduction \n\n"
            << "... Calling template function f with a parameter of type: " << typeid (x).name() << "\n";
    f1(x);
    cout << "\n... Calling template function f with a parameter of type: " << typeid (cx).name() << "\n";
    f1(cx);
    cout << "\n... Calling template function f with a parameter of type: " << typeid (rx).name() << "\n";
    f1(rx);
    cout << "\n... Calling template function f with a parameter of type: " << typeid (urx).name() << "\n";
    f1(urx);
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
//    main2();
    return 0;
}

