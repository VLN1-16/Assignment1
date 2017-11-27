#include "Superhero.h"

Superhero::Superhero(){
    this->name = "";
    this->age = 0;
    this->superpower = 'n';
}
Superhero::Superhero(std::string Name, int Age, char Superpower){
    this->name = Name;
    this->age  = Age;
    this->superpower = Superpower;
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
    out << this->name << " (" << this->age << "): " << this->getpower(this->superpower) << std::endl;
}
