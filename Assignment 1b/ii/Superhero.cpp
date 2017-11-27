#include "Superhero.h"
#include <iostream>
Superhero::Superhero(){
    //name[0] = '\0';
    age = 0;
    superpower = 'n';
}
Superhero::Superhero(char Name[100], int Age, char Superpower){
    for(int i = 0; i < 100; i++){
        name[i] = Name[i];
    }
    age  = Age;
    superpower = Superpower;
}
std::string Superhero::getpower(char power){
    switch(power){
        case 'f':
            return "Flying";
        case 'g':
            return "Giant";
        case 'h':
            return "Hacker";
    }
    return "None"; 
}
std::ostream& operator <<(std::ostream &out, Superhero& hero){
    out << hero.name << " " << hero.age << " " << hero.superpower << std::endl;
    return out;
}
std::istream& operator >>(std::istream &is, Superhero& hero){
    is >> hero.name >> hero.age >> hero.superpower; 
    return is;
}
void Superhero::print(std::ostream& out) {
    out << name << " (" << age << "): " << getpower(superpower) << std::endl;
}
