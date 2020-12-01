//Elizabeth Stevenson
//CSCE350 Project4

#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

string caseOnePal;
string caseTwoPal;
string caseThreePal;
string caseFourPal;

//checks to see if it's a palindrome
void caseOne(string input) {
    int length = input.length();
    unsigned int size = length - 1;
    bool isPal = false;
    for (unsigned int i = 0; i <= size; ++i, --size) {
        if (input[i] != input[size]) {
            isPal = false;
        }
        isPal = true;
    }
    if(isPal == true) {
        caseOnePal = input;
    }
}

void caseTwo(string input) {
    int length = input.size();
    string string1 = input;
    string string2 = input;
    reverse(string2.begin(), string2.end());
    string2 = input + "^" + string2;
    vector<int> temp(string2.size());
    unsigned int i = 1;
    unsigned int j = 0;
    while (i < string2.size()) {
        if(string2[i] == string2[j]) {
            temp[i] = j+1;
            j++;
            i++;
        } else {
            if (j>0) {
                j = temp[j-1];
            } else {
                i++;
            }
        }
    }
    string special = input.substr(temp[temp.at(0)], length-temp[temp.size()-1]);
    reverse(special.begin(), special.end());
    caseTwoPal = input+special;


    /*
    cout << string(input.rbegin(), input.rend()) + input;
    return string(input.rbegin(), input.rend()) + input;
    */
}

void caseThree(string input) {
    int length = input.size();
    string string1 = input;
    string string2 = input;
    reverse(string2.begin(), string2.end());
    string2 = input + "^" + string2;
    vector<int> temp(string2.size());
    unsigned int i = 1;
    unsigned int j = 0;
    while (i < string2.size()) {
        if(string2[i] == string2[j]) {
            temp[i] = j+1;
            j++;
            i++;
        } else {
            if (j>0) {
                j = temp[j-1];
            } else {
                i++;
            }
        }
    }
    string special = input.substr(temp[temp.size()-1], length-temp[temp.size()-1]);
    reverse(special.begin(), special.end());
    caseThreePal = special+input;

/*
    cout << input + string(input.rbegin(), input.rend());
    return input + string(input.rbegin(), input.rend());
    */
}


/*
string palindrome(string input) {

    //case 1

    //case 2
    caseTwo(input);
    //case 3

    //case 4
    return palindromeFinal;
}
*/
int main(int argc, char* argv[]) {

    string input;
    cin >> input;
//    caseOne(input);
//    cout << "1" << caseOnePal;
    cout << endl;
    caseTwo(input);
    cout << "2" << caseTwoPal;
    cout << endl;
    caseThree(input);
    cout << "3" << caseThreePal;
    /*
    cout << palindromeFinal.size() << " ";
    palindrome(input);
    cout << endl;
    palindromeFinal.clear();
    */

    if (!cin.good()) {
        return 0;
    }
}
