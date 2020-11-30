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

vector<string> palindromeFinal;

string caseTwo(string input) {
    int length = input.size();
    string string1 = input;
    string string2 = input;
    reverse(string2.begin(), string2.end());
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
    return special+input;
}

string palindrome(string input) {

    //case 1

    //case 2
    caseTwo(input);
    //case 3

    //case 4
    return palindromeFinal;
}

int main(int argc, char* argv[]) {

    string input;
    cin >> input;
    cout << palindromeFinal.size() << " ";
    palindrome(input);
    cout << endl;
    palindromeFinal.clear();

    if (!cin.good()) {
        return 0;
    }
}