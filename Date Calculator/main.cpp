//
//  main.cpp
//  Date Calculator
//
//  Created by Eren Özkacar on 29.12.20.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct date {
    unsigned int day;
    unsigned int month;
    unsigned int year;
};
vector<unsigned int> months {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

date stringToDate(string sDate);
unsigned int dateExists(date dDate);
unsigned int calculate(date start, date end);
unsigned int calculate0101toDate(date dDate);

int main(int argc, const char * argv[]) {
    char answer;
    string date;
    struct date start;
    struct date end;
    unsigned int days;
    do {
        cout << "Was möchten Sie berechnen?\nA: Tage zwischen zwei Daten\nB: Nummer des Tages im Jahr\noder drücken Sie X zum Abbrechen\n";
        cin >> answer;
        if (answer == 'A' || answer == 'a') {
            cout << "Geben Sie das Startdatum in der Form \"TT.MM.JJJJ\" an: ";
            cin >> date;
            start = stringToDate(date);
            cout << "Nun geben Sie das Enddatum ebenfalls in der Form \"TT.MM.JJJJ\" an: ";
            cin >> date;
            end = stringToDate(date);
            if (dateExists(start) && dateExists(end)) {
                days = calculate(start, end);
                cout << "Zwischen den beiden Daten liegen insgesamt " << days << " Tage\n";
            } else {
                cout << "Fehler bei der Datums Eingabe: Dieses Datum existiert nicht! Versuchen Sie es erneut\n";
                continue;
            }
        } else if (answer == 'B' || answer == 'b'){
            cout << "Geben Sie das Datum in der Form \"TT.MM.JJJJ\" an: ";
            cin >> date;
            start = stringToDate(date);
            if (dateExists(start) && dateExists(end)) {
                days = calculate0101toDate(start);
                cout << "Dieser Tag ist der " << days << ". Tag im Jahr\n";
            } else {
                cout << "Fehler bei der Datums Eingabe: Dieses Datum existiert nicht! Versuchen Sie es erneut\n";
                continue;
            }
        }
    } while (answer != 'X' && answer != 'x');
    cout << "Programm wurde beendet!\n";
    return 0;
}

date stringToDate(string sDate) {
    date dDate;
    dDate.day = stoi(sDate.substr(0, 2));
    dDate.month = stoi(sDate.substr(3, 2));
    dDate.year = stoi(sDate.substr(6, 4));
    return dDate;
}

unsigned int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    }
    return 0;
}

unsigned int amountOfLeapYears(unsigned int start, unsigned int end) {
    unsigned int leapYears {0};
    for (int i = start + 1; i < end; ++i) {
        leapYears += isLeapYear(i);
    }
    return leapYears;
}

unsigned int calculate0101toDate(date dDate) {
    if (isLeapYear(dDate.year)) {
        months.at(1) = 29;
    }
    unsigned int days {0};
    for (int i = 1; i < dDate.month ; ++i) {
        days += months.at(i - 1);
    }
    days += dDate.day;
    months.at(1) = 28;
    return days;
}

unsigned int dateExists(date dDate) {
    if (isLeapYear(dDate.year)) {
        months.at(1) = 29;
    }
    if (dDate.day <= months.at(dDate.month - 1)) {
        return 1;
    }
    months.at(1) = 28;
    return 0;
}

unsigned int calculate(date startingDate, date endingDate) {
    unsigned int days {0};
    if (startingDate.year == endingDate.year) {
        return calculate0101toDate(endingDate) - calculate0101toDate(startingDate) + 1;
    } else if (endingDate.year - startingDate.year == 1) {
        return calculate0101toDate(endingDate) + (365 + isLeapYear(startingDate.year) - calculate0101toDate(startingDate) + 1);
    } else if (endingDate.year - startingDate.year > 1) {
        return calculate0101toDate(endingDate) + (365 + isLeapYear(startingDate.year) - calculate0101toDate(startingDate) + 1) + (endingDate.year - startingDate.year - 1 - amountOfLeapYears(startingDate.year, endingDate.year)) * 365 + amountOfLeapYears(startingDate.year, endingDate.year) * 366;
    }
    return days;
}
