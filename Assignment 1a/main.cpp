#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // Assignment1
    // A ii)
    string str1;
    ofstream fout;

    cout << "Input a string to a file: " << endl;
    fout.open("NewTextDoc.txt", ios::app);
    while(getline(cin, str1))  //Exiting user input string with 'Enter' key
    {
        if(str1[0] == '\\')
            break;
        fout << str1 << endl;
    }
    fout.close();

    //Assignment1
    //A i)
    string str2;
    ifstream fin;

    fin.open("NewTextDoc.txt");
    if(fin.is_open())
    {
        int counter = 0;
        int tenCount = 1;
        while(!fin.eof() && counter < 10)
        {
            getline(fin, str2);
            cout << str2 << endl;
            counter++;
            tenCount = counter % 10;
            if (tenCount == 0) // To mark every 10 lines.
            {
                char ans = 0;
                cout << "Do you wish to continue? (y/n)" << endl;
                cin >> ans;
                if(ans == 'y' || ans == 'Y')
                    counter = 0;
                else
                {
                   fin.close();
                   return 0;
                }
            }
        }
        fin.close();
    }
    else
        cout << "Unable to read from file..." << endl;

return 0;
}
