/* 
 * File:   rvalue_example.h
 * Author: jpimentel
 *
 * Created on April 18, 2015, 12:14 AM
 */

#ifndef MOVE_EXAMPLE_H
#define	MOVE_EXAMPLE_H

#include <iostream>
#include <string>

#include <Chronometer.h>
#include "SomeClass.h"

/**
 * No padrão C++03 (e anteriormente), temporários (chamados "rvalues", uma vez que residem do lado direito da atribuição)
 * foram idealizados para nunca serem modificáveis - como em C - e eram considerados para ser indistiguíveis de tipos const T&;
 * ainda assim, em alguns casos, temporários poderiam ser modificados, um comportamento que era sempre considerado uma brecha.
 * C++11 adicionou um novo tipo de referência não-constante chamado referência "rvalue", identificada por T&&. Isto refere-se a
 * temporários que são permitidos serem modificados após sua inicialização, para o propósito de permitir "move semantics".
 */
inline void move_example_01() {
    using namespace std;
    
    static const long ITERATIONS_NO = 100000000;
    
    cout << "==> Move semantic example 01\n"
         << "... This example compares the use of the std::move (that uses rvalue reference to receive it's arguments) and \n"
         << "    traditional swap approach.\n\n";
    string source = "Source";
    string dest   = "Destination";
    
    cout << "--> Using move to assign source value to a destination \n"
         << "... before std::move, source value is [" << source << "], and destination value is [" << dest << "]\n" 
         << "... now I will move it ...\n";
    
    dest = std::move(source);
    
    cout << "... after  std::move, source value is [" << source << "], and destination value is [" << dest << "]\n\n"
    
         << "--> Now let us see a performance comparision between std::move and the traditional swap approach.\n"
    
         << "... Will do " << ITERATIONS_NO << " iterations using traditional swap approach:\n";    
    util::Chronometer chronometer;  
    cout << "... Start    at: " << chronometer.GetEndCtime();    
    for (auto count = 0; count < ITERATIONS_NO; count++) {
        auto aux = dest;
        dest = source;
        source = aux;
    }
    chronometer.End();
    cout << "... Finisted at: " << chronometer.GetEndCtime() 
         << "... Elapsed seconds : " << chronometer.GetElapsedSeconds() << "\n\n" 
    
         << "--> Will do " << ITERATIONS_NO << " iterations using std::move():\n";
    chronometer.Start();  
    cout << "... Start    at: " << chronometer.GetEndCtime();    
    for (auto count = 0; count < ITERATIONS_NO; count++) {
        dest = std::move(source);
    }
    chronometer.End();
    cout << "... Finisted at: " << chronometer.GetEndCtime()    
         << "... Elapsed seconds : " << chronometer.GetElapsedSeconds() << "\n\n";
}

inline void move_example_02() {
    using namespace std;
    
    static const long ITERATIONS_NO = 100000000;

    // Set debug to true, but don't forget to set it to false before the loops;
    SomeClass::SetDebug(true);
    
    cout << "==> Move semantic example 02, using a moveable class\n"
         << "... This example compares the use of the move constructor (that uses rvalue reference to receive it's arguments) and \n"
         << "    traditional swap approach.\n\n";
    
    
    cout << "--> Using Default Constructor to create instances of SomeClass \n";
    
    cout << "... Initializing source from \"Source\"\n";
    SomeClass source("Source");
    cout << "... Initializing aux from \"Destination\"\n";
    SomeClass aux("Destination");
    cout << "... Initializing dest from aux \n";
    //SomeClass dest(aux); - Should not need to cast to a rvalue reference --- strange?????
    SomeClass dest((SomeClass&&)aux);
    
    cout << "--> Using move to assign source value to a destination \n"
         << "... before std::move, source value is [" << source.GetContent() << "], and destination value is [" << dest.GetContent() << "]\n" 
         << "... now I will move it ...\n";
    
    //dest =  source; - Should not need to cast to a rvalue reference --- strange?????
    dest = (SomeClass&&) source;
    
    cout << "... after  std::move, source value is [" << source.GetContent() 
         << "], and destination value is [" << dest.GetContent() << "]\n\n"
    
         << "--> Now let us see a performance comparision between move assignment operator=and the traditional swap approach.\n"
         << "... Will do " << ITERATIONS_NO << " iterations using traditional swap approach:\n";    
    
    // Avoid to print debug messages during the loops
    SomeClass::SetDebug(false);
    
    util::Chronometer chronometer;  
    cout << "... Start    at: " << chronometer.GetEndCtime();    
    for (auto count = 0; count < ITERATIONS_NO; count++) {
        auto aux = dest;
        dest = source;
        source = aux;
    }
    chronometer.End();
    cout << "... Finisted at: " << chronometer.GetEndCtime() 
         << "... Elapsed seconds : " << chronometer.GetElapsedSeconds() << "\n\n" 
    
         << "--> Will do " << ITERATIONS_NO << " iterations using move assignment operator=:\n";
    chronometer.Start();  
    cout << "... Start    at: " << chronometer.GetEndCtime();    
    for (auto count = 0; count < ITERATIONS_NO; count++) {
        //dest =  source; - Should not need to cast to a rvalue reference --- strange?????
        dest = (SomeClass&&) source;
    }
    chronometer.End();
    cout << "... Finisted at: " << chronometer.GetEndCtime()    
         << "... Elapsed seconds : " << chronometer.GetElapsedSeconds() << "\n\n";
}

#endif	/* MOVE_EXAMPLE_H */

