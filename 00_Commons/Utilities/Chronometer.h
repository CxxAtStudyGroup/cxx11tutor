/* 
 * File:   Chronometer.h
 * Author: jpimentel
 *
 * Created on April 18, 2015, 9:08 AM
 */

#ifndef CHRONOMETER_H
#define	CHRONOMETER_H

#include <iostream>
#include <chrono>
#include <ctime>

#include "IllegalCallOrderException.h"

namespace util { 
    
class Chronometer {
public:
    
    Chronometer();
    
    Chronometer(const Chronometer& orig) = delete; // to avoid the copy constructor usage;
    
    virtual ~Chronometer();
    
    void Start();
    
    void End();
    
    double GetElapsedSeconds();

    const char* GetEndCtime();    
    
private:
    std::chrono::time_point<std::chrono::system_clock> m_Start;
    std::chrono::time_point<std::chrono::system_clock> m_End;

};

}

#endif	/* CHRONOMETER_H */

