//
//  main.cpp
//  Management
//
//  Created by Eren Özkacar on 27.01.21.
//

#include <iostream>
#include "Personnel Management.hpp"

int main(int argc, const char *argv[])
{
    PersonnelManagement pManagement("/Users/erenozkacar/Documents/Random Projects/Management/personnelmanagement.txt");
    pManagement.dialogue();
    return 0;
}
