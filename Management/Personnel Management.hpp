//
//  Personnel Management.hpp
//  Management
//
//  Created by Eren Özkacar on 27.01.21.
//

#ifndef Personnel_Management_hpp
#define Personnel_Management_hpp

#include <vector>
#include "Person.hpp"

class PersonnelManagement {
private:
    std::vector<Person> vPersonList;
    void addPerson(const std::string& name, const std::string& personnelnumber);
    void deletePerson(const std::string& pPersonnelnumber);
    void print() const;
    void write() const;
public:
    PersonnelManagement(const std::string& filename);
    void dialogue();
};

#endif /* Personnel_Management_hpp */
