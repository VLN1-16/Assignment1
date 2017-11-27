#ifndef SUPERHERO_H
#define SUPERHERO_H

/*
* Superhero class Assignment1b
*/
#include <string>
#include <iostream>
#include <fstream>

class Superhero{
    public:        
        // Initialize a hero with sane defaults (name = "", age = 0, power = 'n')
        Superhero();
        // User totally controls what the initial values are
        Superhero(std::string Name, int Age, char Superpower);
        // overwrite the output stream, Each value is printed in a seperate line
        friend std::ostream& operator <<(std::ostream &out, Superhero& hero);
        // Print hero information as specified
        void print(std::ostream &out);
        // input stream is overwritten, each value expected with space
        // as a delimiter, name age power
        friend std::istream& operator >>(std::istream &is, Superhero& hero);
        // convert from a one char power into the true power
        std::string getpower(char power);
    private:
        std::string name;
        int age;
        char superpower;
};

#endif
