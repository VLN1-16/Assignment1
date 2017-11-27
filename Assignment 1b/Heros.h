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
        // Initialize Heros with a datafile ( other than default )
        Heros(std::string Datafile);
        bool Addahero(Superhero hero);
        friend std::ostream& operator <<(std::ostream &out, Heros& heros);
        std::vector<Superhero> heros;
    private:
        // Initializes the list, if the Datafile exists. Read from it. Otherwise create it.
        bool writeIntoDatafile();
        void loadFromDatafile();
        std::string datafile;
};

#endif
