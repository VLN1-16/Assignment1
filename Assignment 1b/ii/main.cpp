#include <iostream>
#include "Superhero.h"
#include "Heros.h"
using namespace std;
char getinput(){
    cout << "l: List heros" << endl;
    cout << "n: New hero" << endl;
    cout << "q: Quit" << endl;
    char userinput;
    cin >> userinput;
    if(userinput == 'l' || userinput == 'n' || userinput == 'q')
        return userinput;
    cout << "Invalid input!"<< endl;
    cout << "Please Enter one of the following : " << endl;
    return getinput();
}
int main(){
    // Load old heros from file, Instance with just the default file
    Heros heros;
    // Interact with the user
    char userinput;
    do{
        userinput = getinput(); 
        if(userinput == 'l'){
            cout << heros << endl;
            cout << "Listing heros: " << endl;
        }
        else if(userinput == 'n'){
            // string name;
            char name[100];
            int age;
            char power;
            cout << "Adding a new hero" << endl;
            cout << "Please enter a name for the hero: ";
            cin >> name;
            cout << "How old is the hero : ";
            cin >> age;
            cout << "What is the heros power : ";
            cin >> power;
            heros.Addahero(new Superhero(name,age,power));
        }
    }while(userinput != 'q');
}
