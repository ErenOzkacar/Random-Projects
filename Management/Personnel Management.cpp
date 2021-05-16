//
//  Personnel Management.cpp
//  Management
//
//  Created by Eren Özkacar on 27.01.21.
//

#include <iostream>
#include <fstream>
#include "Personnel Management.hpp"

std::string sFilename;

PersonnelManagement::PersonnelManagement(const std::string &filename)
{
    sFilename = filename;
    std::ifstream fFile(sFilename);
    while (!fFile.eof())
    {
        std::string name;
        getline(fFile, name);
        std::string personnelnumber;
        getline(fFile, personnelnumber);
        vPersonList.push_back(Person(name, personnelnumber));
    }
    fFile.close();
}

void PersonnelManagement::addPerson(const std::string &name, const std::string &personnelnumber)
{
    vPersonList.push_back(Person(name, personnelnumber));
    write();
}

void PersonnelManagement::deletePerson(const std::string &pPersonnelnumber)
{
    for (unsigned int i = 0; i < vPersonList.size(); ++i)
    {
        if (vPersonList.at(i).getPersonnelnumber() == pPersonnelnumber)
        {
            vPersonList.erase(vPersonList.begin() + i);
        }
    }
    write();
}

void PersonnelManagement::print() const
{
    for (Person pPerson : vPersonList)
    {
        std::cout << pPerson.getName() << '\n'
                  << pPerson.getPersonnelnumber() << '\n';
    }
}

void PersonnelManagement::write() const
{
    std::ofstream fFile(sFilename, std::ios::out | std::ios::trunc);
    for (Person pPerson : vPersonList)
    {
        fFile << pPerson.getName() << '\n'
              << pPerson.getPersonnelnumber() << '\n';
    }
    fFile.close();
}

void PersonnelManagement::dialogue()
{
    std::string iInput;
    do
    {
        std::cout << "A: Person hinzufügen\nB: Person entfernen\nC: Liste ausgeben\nD: Programm beenden\n";
        getline(std::cin, iInput);
        if (iInput == "A" || iInput == "a")
        {
            std::cout << "Geben Sie den Namen an:\n";
            std::string sName;
            getline(std::cin, sName);
            std::cout << "Geben Sie nun die Personalnummer ein:\n";
            std::string sPersonnelnumber;
            getline(std::cin, sPersonnelnumber);
            addPerson(sName, sPersonnelnumber);
            std::cout << "Person wurde erfolgreich hinzugefügt!\n";
        }
        else if (iInput == "B" || iInput == "b")
        {
            std::cout << "Geben Sie die Personalnummer ein:\n";
            std::string sPersonnelnumber;
            getline(std::cin, sPersonnelnumber);
            deletePerson(sPersonnelnumber);
            std::cout << "Person ist nun nicht mehr in der Liste!\n";
        }
        else if (iInput == "C" || iInput == "c")
        {
            print();
        }
        else if (iInput != "D" && iInput != "d")
        {
            std::cout << "Ungültige Eingabe!\n";
        }
    } while (iInput != "D" && iInput != "d");
    std::cout << "Programm wurde beendet!\n";
}
