/* 
 * File:   IllegalCallOrderException.h
 * Author: jpimentel
 *
 * Created on April 18, 2015, 9:23 AM
 */

#ifndef ILLEGALCALLORDEREXCEPTION_H
#define	ILLEGALCALLORDEREXCEPTION_H

#include <string>
#include <exception>

namespace util { 

class IllegalCallOrderException : public std::exception {

public:
    /** Constructor (C strings).
     *  @param message C-style string error message.
     *                 The string contents are copied upon construction.
     *                 Hence, responsibility for deleting the \c char* lies
     *                 with the caller. 
     */
    explicit IllegalCallOrderException(const char* message) : msg_(message) {
    }

    /** Constructor (C++ STL strings).
     *  @param message The error message.
     */
    explicit IllegalCallOrderException(const std::string& message) : msg_(message) {
    }

    /** Destructor.
     * Virtual to allow for subclassing.
     */
    virtual ~IllegalCallOrderException() throw () {
    }

    /** Returns a pointer to the (constant) error description.
     *  @return A pointer to a \c const \c char*. The underlying memory
     *          is in posession of the \c Exception object. Callers \a must
     *          not attempt to free the memory.
     */
    virtual const char* what() const throw () {
        return msg_.c_str();
    }

protected:
    /** Error message.
     */
    std::string msg_;
};

}

#endif	/* ILLEGALCALLORDEREXCEPTION_H */

