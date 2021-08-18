#include <iostream>
#include <fstream>
#include "misteryWord.h"
using namespace std;

int main()
{
    cout << "Your current is " << myScore() << endl;
    char continueOrNot;
    do{
        misteryWord();
        cout << "Do you want to continue ? o/n" << endl;
        cin >> continueOrNot;
    }while(continueOrNot == 'o');


return 0;
}
