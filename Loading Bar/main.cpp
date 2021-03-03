//
//  main.cpp
//  Loading Bar
//
//  Created by Eren Özkacar on 30.12.20.
//
//  Programm in Products/Loading Bar/Rechtsklick/Show in Finder öffnen, für optimale Darstellung

#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    for (int i = 0; i < 51; ++i) {
        cout.width(11);
        cout << ' ';
        for (int j = 0; j < 52; ++j) {
            cout.width(1);
            cout << "ˍ";
        }
        cout << '\n';
        if (i < 50) {
            cout.width(7);
            cout << "LOADING";
            if (i % 3 == 0) {
                cout.width(1);
                cout << '.';
                cout.width(3);
                cout << ' ';
                cout.width(1);
                cout << '|';
            } else if (i % 3 == 1){
                cout.width(2);
                cout << "..";
                cout.width(2);
                cout << ' ';
                cout.width(1);
                cout << '|';
            } else {
                cout.width(3);
                cout << "...";
                cout.width(1);
                cout << ' ';
                cout.width(1);
                cout << '|';
            }
        } else {
            cout.width(8);
            cout << "COMPLETE";
            cout.width(3);
            cout << ' ';
            cout.width(1);
            cout << '|';
        }
        for (int j = 0; j < 50; ++j) {
            if (j < i) {
                cout.width(1);
                cout << '|';
            } else {
                cout.width(1);
                cout << ' ';
            }
        }
        cout.width(1);
        cout << '|';
        cout.width(1);
        cout << ' ';
        cout.width(3);
        cout << i * 2;
        cout.width(1);
        cout << '%';
        cout << '\n';
        cout.width(11);
        cout << ' ';
        for (int j = 0; j < 52; ++j) {
            cout.width(1);
            cout << "ˉ";
        }
        cout << '\n';
        usleep(500000); // Mikrosekunden
        // cout << '\r';
        
        // Hier Konsole/Terminal löschen (nicht möglich auf MacOS)
        // Alternative Möglichkeit, jedoch ohne obere und untere Abgrenzung: Obere und untere Abgrenzung auskommentieren und dann mit \r an den Anfang der Zeile gehen (Auch nicht möglich auf MacOS)
    }
    return 0;
}
