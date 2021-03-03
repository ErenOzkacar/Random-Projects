//
//  main.cpp
//  Search Files
//
//  Created by Eren Özkacar on 03.03.21.
//
//  Dateien mit dem Terminal und den main-Parametern im Verzeichnis "Random Projects" suchen
//  Im Terminal öffnen mit "cd ..." -> "clang++ -std=c++17 main.cpp -o main" -> "./main Datei"

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, const char * argv[]) {
    if (argc == 0) {
        std::cout << "Es wurde keine Datei eingegeben!\n";
        return 0;
    }
    std::string directory {"/Users/erenozkacar/Documents/Random Projects/"};
    for (size_t i = 1; i < argc; ++i) {
        std::string file = directory + argv[i];
        std::ifstream sFile {file};
        std::cout << "Datei " << argv[i] << " wurde im Verzeichnis " << directory;
        if (!sFile) {
            std::cout << " nicht gefunden!\n";
        } else {
            std::cout << " gefunden!\n";
        }
    }
    return 0;
}
