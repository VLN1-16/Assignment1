#ifndef HEROS_H
#define HEROS_H

/*
* Hero's class Assignment1b
*/
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Superhero.h"

#define DEFDATAFILE "datafile.txt"

class Heros{
    public:        
        Heros();
        // Initialize Heros with a datafile
        Heros(std::string Datafile);
        // Addahero, should return a false if adding failed
        bool Addahero(Superhero hero);
        friend std::ostream& operator <<(std::ostream &out, Heros& heros);
        std::vector<Superhero> heros;
    private:
        // Initializes the list, if the Datafile exists. Read from it. Otherwise create it.
        void loadFromDatafile();
        // Write the updated hero list into text files
        bool writeIntoDatafile();
        std::string datafile;
};

#endif
