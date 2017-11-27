#ifndef HEROS_H
#define HEROS_H

/*
* Hero's class Assignment1b
*/
#include <string>
#include <iostream>
#include <fstream>
#include "Superhero.h"

#define DEFDATAFILE "datafile.obj"
class Heros{
    public:        
        Heros();
        // Initialize Heros with a datafile
        Heros(std::string Datafile);
        // Addahero, should return a false if adding failed
        bool Addahero(Superhero* hero);
        friend std::ostream& operator <<(std::ostream &out, Heros& heros);
        Superhero* heros; 
    private:
        // how many heros have we added so far
        unsigned int size = 2;
        unsigned int at = 0;
        // Initializes the list, if the Datafile exists. Read from it. Otherwise create it.
        void loadFromDatafile();
        // Write the updated hero list into text files
        bool writeIntoDatafile();
        std::string datafile;
        void resize();
};

#endif
