/* 
 * File:   01DeclAndDef.cpp
 * @author: jpimentel
 *
 * @desc Move Semantics usage
 * @see http://thbecker.net/articles/rvalue_references/section_01.html for rvalue 
 * and move semantics understanding
 * Created on April 17, 2015, 11:44 PM
 */

#include <iostream>

#include "move_example.h"

/*
 * 
 */
int main(int argc, char** argv) {
    using namespace std;
    
    cout << "============================================" << endl;
    cout << "Move Semantics and rvalue reference Tutorial" << endl;
    cout << "============================================" << endl << endl;
    
    move_example_01();
    
    move_example_02();
    
    return 0;
}

