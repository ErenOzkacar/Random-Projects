//
//  Person.hpp
//  Management
//
//  Created by Eren Özkacar on 27.01.21.
//

#ifndef Person_hpp
#define Person_hpp

#include <string>

class Person {
private:
    std::string sName;
    std::string sPersonnelnumber;
public:
    Person(const std::string& pName, const std::string& pPersonnelnumber)
    : sName {pName}, sPersonnelnumber {pPersonnelnumber}{
    }
    std::string getName() const;
    std::string getPersonnelnumber() const;
};

inline std::string Person::getName() const {
    return sName;
}

inline std::string Person::getPersonnelnumber() const {
    return sPersonnelnumber;
}

#endif /* Person_hpp */
