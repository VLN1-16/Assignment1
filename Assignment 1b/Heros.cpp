#include "Heros.h"
Heros::Heros(std::string Datafile){
    this->datafile = Datafile;
    this->loadFromDatafile();
}
Heros::Heros() : Heros::Heros(DEFDATAFILE)
{}
void Heros::loadFromDatafile(){
    std::ifstream fin(this->datafile);
    if(fin.is_open()){
        while(!fin.eof()){
            Superhero newhero;
            fin >> newhero;
            fin >> newhero;
            fin >> newhero;
            std::cout << "Hero: " << std::endl;
            std::cout << newhero << std::endl;
            this->heros.push_back(newhero);
       }
       fin.close();
    } else {
        std::ofstream fout(this->datafile);
       fout << "";
       fout.close();
    }
}
bool Heros::writeIntoDatafile(){
    std::ofstream fout(this->datafile, std::ios::app);
    for(unsigned int i = 0; i < this->heros.size(); i++){
        fout << this->heros[i];
    }
    fout.close();
    return true;
}
bool Heros::Addahero(Superhero hero){
    this->heros.push_back(hero);
    this->writeIntoDatafile();
    return true;
}
std::ostream& operator <<(std::ostream &out, Heros& heros){
    for(unsigned int i = 0; i < heros.heros.size(); i++){
        heros.heros[i].print(out);
    }
    return out;
}
