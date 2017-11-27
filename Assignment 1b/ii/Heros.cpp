#include "Heros.h"

Heros::Heros(std::string Datafile){
    this->datafile = Datafile;
    this->heros = new Superhero[size];
    this->loadFromDatafile();
}
Heros::Heros() : Heros::Heros(DEFDATAFILE)
{}
void Heros::loadFromDatafile(){
    std::ifstream fin(datafile, std::ios::binary);
    if(fin.is_open()){
        fin.seekg(0,fin.end);
        int records = fin.tellg() / sizeof(Superhero);
        fin.seekg(0,fin.beg);
        if(records != 0){
            Superhero *data = new Superhero[records*2];
            fin.read((char*) data, sizeof(Superhero) * records);
            fin.close();
            at = records;
            size = records*2;
            delete [] heros;
            heros = data;
        }
    }
}
bool Heros::writeIntoDatafile(){
    int cap = sizeof(Superhero) * at;
    std::ofstream fout(datafile, std::ios::binary);
    fout.write((char*)(heros), cap);
    fout.close();
    return true;
}
bool Heros::Addahero(Superhero* hero){
    if(at == size){
        resize();
    }
    heros[at] = *hero;
    at++;
    writeIntoDatafile();
    return true;
}
void Heros::resize(){
    std::cout << "resizeing" << std::endl;
    size *= 2;
    Superhero* narray = new Superhero[size];
    for(unsigned int i = 0; i < at; i++){
        narray[i] = heros[i];
    }
    delete [] heros;
    heros = narray;
}
std::ostream& operator <<(std::ostream &out, Heros& heros){
    for(unsigned int i = 0; i < heros.at; i++){
        heros.heros[i].print(out);
    }
    return out;
}
