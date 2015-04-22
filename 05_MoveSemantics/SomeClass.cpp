/* 
 * File:   Moveable.cpp
 * Author: jpimentel
 * 
 * Created on April 18, 2015, 9:13 PM
 */

#include <iostream>
#include "SomeClass.h"

using namespace std; 
bool SomeClass::debug = false;

SomeClass::SomeClass() : m_Content("") {
    cout << "    At Default SomeClass::Constructor\n";
}

SomeClass::SomeClass(const string &content) {
    cout << "    At SomeClass::Constructor from const string& \n";
    this->m_Content = content;
}

/**
 * Move constructor
 * @param orig - rvalue reference copy constructor
 */
SomeClass::SomeClass(SomeClass &&orig) :
    m_Content(std::move(orig.m_Content)) {
    if (debug) cout << "    At Move SomeClass::Constructor\n";
}

/**
 * Copy constructor
 * @param orig - rvalue reference copy constructor
 */
SomeClass::SomeClass(const SomeClass &orig) :
    m_Content(orig.m_Content) {
    if (debug) cout << "    At Copy SomeClass::Constructor\n";
}

SomeClass::~SomeClass() {
}

SomeClass& SomeClass::operator=(const SomeClass& rhs) {
    if (debug) cout << "    At Copy SomeClass::operator=\n";
    this->m_Content = rhs.m_Content;
    return *this;
}

SomeClass& SomeClass::operator=(SomeClass&& rhs) {
    if (debug) cout << "    At move SomeClass::operator=\n";
    this->m_Content = move(rhs.m_Content);
    return *this;
}

void SomeClass::SetContent(string Content) {
    m_Content = Content;
}

string SomeClass::GetContent() const {
    return m_Content;
}

/*static*/ void SomeClass::SetDebug(const bool debug) {
    SomeClass::debug = debug;
}

/*static*/ bool SomeClass::IsDebug() {
    return debug;
}

