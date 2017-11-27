#include <iostream>
#include <fstream>

using namespace std;

/*
* Write input to text file if the first character is not '\'
* ofstream variable 'file' is the file being written to
* string variable 'input' is the input for the text file
*/
bool write(ofstream &file){
    string input;

    getline(cin, input);
    if (input[0] == '\\'){
        return false;
    }
    else{
        input = input + "\n";
        file << input;
    }
    return true;
}

int main()
{
    ofstream file;

    //Open text file to write to
    file.open("test.txt", ios_base::app);

    //While output from boolean function 'write' is true keep writing to the text file
    while(write(file));

    //Close the text file
    file.close();
    return 0;
}
