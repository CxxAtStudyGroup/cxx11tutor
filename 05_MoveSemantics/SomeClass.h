/* 
 * File:   Moveable.h
 * Author: jpimentel
 *
 * Created on April 18, 2015, 9:13 PM
 */

#ifndef SOME_CLASS_H
#define	SOME_CLASS_H
#include <string>

class SomeClass {
public:
    SomeClass();
    
    explicit SomeClass(const std::string& content);
    
    SomeClass(const SomeClass &orig); 
    SomeClass(SomeClass &&orig);
    
    SomeClass& operator=(const SomeClass& rhs); 
    
    SomeClass& operator=(SomeClass&& rhs); 
    
    
    virtual ~SomeClass();
    
    void SetContent(std::string Content);
    std::string GetContent() const;
    
    static void SetDebug(bool debug);
    static bool IsDebug();
    
private:
    static bool debug;
    
    std::string m_Content;
};

#endif	/* SOME_CLASS_H */

