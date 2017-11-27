#include <iostream>
#include <fstream>

using namespace std;

/*
* Read ten lines of text from file or until end of file has been reached.
* integer variable 'i' is a counter
* string variable 'line' is our output line read from file
*/
void readFile(ifstream &file){
    int i = 0;
    string line;

    while(!file.eof() && i < 10){
        i++;
        getline(file, line);
        cout << line << endl;
    }
}

/*
* Function to check if user wants to continue reading from file
* If user input is 'y' it means to continue, 'n' is to quit.
* character variable 'x' is user input
*/
bool continueReading(){
    char input = 'x';
    do{
        cout << "Do you want to continue: ";
        cout << "y/n" << endl;
        cin >> input;
    }while(input != 'y' && input != 'n');

    return input == 'y';
}

int main()
{
    ifstream file;

    file.open("test.txt");

    if(file.is_open()){
        while(!file.eof()){

            //Read ten lines of text or until end of file
            readFile(file);

            //If end of file has not been reached
            if (!file.eof()){
                //Check if user wants to continue reading from file
                if (!continueReading()){
                    break;
                }
            }

        }
        file.close();
    }
    else{
        cout << "could not open file" << endl;
    }
    return 0;
}
