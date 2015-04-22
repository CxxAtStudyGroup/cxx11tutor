/* 
 * File:   Chronometer.cpp
 * Author: jpimentel
 * 
 * Created on April 18, 2015, 9:08 AM
 */

#include "Chronometer.h"

namespace util { 
    
Chronometer::Chronometer() 
    : m_Start(std::chrono::system_clock::now()),
      m_End(std::chrono::system_clock::now()) {
}

Chronometer::~Chronometer() {
}

void Chronometer::Start() {
    m_Start = std::chrono::system_clock::now();
    m_End = std::chrono::system_clock::now();
}

void Chronometer::End() {
    m_End = std::chrono::system_clock::now();
}

double Chronometer::GetElapsedSeconds() {
    std::chrono::duration<double> elapsed_seconds = m_End-m_Start;
    if (elapsed_seconds.count() < 0) {
        throw IllegalCallOrderException("You have to call End() after Start() to obtain the Elapsed Seconds from the Chronometer");
    }
    return elapsed_seconds.count();
}

const char* Chronometer::GetEndCtime() {
    std::time_t end_time = std::chrono::system_clock::to_time_t(m_End);
    return std::ctime(&end_time);
}

}