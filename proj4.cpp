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
using std::min;

//variables to hold all the palindromes and input
string input;
string caseOnePal;
string caseTwoPal;
string caseThreePal;
//string caseFourPal;
string finalPal;

//checks to see if it's a palindrome
void caseOne(string input) {

    int index = 0;
    int length = input.length()-1;
    while(length > index) {
        if(input.at(index) != input.at(length)) {
            //input not a palindrome
            index++;
            length--;
            return;
        }
    }
    //input is palindrome
    caseOnePal = input;

    /* previous palindrome code just incase new stuff didn't work
    bool isPal = false;
    if(input.length() == 1) {
        isPal = true;
    }
    if (input.length() == 2) {
        if(input.at(0) == input.at(1)) {
            isPal = true;
        } else {
            isPal = false;
        }
    }
    int index = input.length()-1;
    if(input.length() > 2 && input.at(0) == input.at(index)) {
        isPal = caseOne(input.substr(1,(index-1)));
    }
    if(isPal == true) {
        caseOnePal = input;
    }
    */
    /*
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
    */
}

void caseTwo(string input) {
    int length = input.size();
    string string1 = input;
    string string2 = input;
    reverse(string2.begin(), string2.end());
    //splits the string so then there's a pivot and the middle letter is not repeated
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
    //splits the string so then there's a pivot and the middle letter is not repeated
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

/* instructions say to ignore this case
void caseFour(string input) {

}
*/


//the actual dynamic programming part
//formula in box
// p(i + 1, j − 1) + 2  if S[i] = S[j]
// min {p(i + 1, j) + 2, p(i, j − 1) + 2}  if S[i] =\= S[j]
int boxFormTwo(int i, int j) {
    int num = 0;
    //i = 0;
    //j = input.length()-1;
    //string palSection = caseTwoPal.find(input);
    //reverse(palSection.begin(), palSection.end());
    if(caseTwoPal.at(i) == caseTwoPal.at(j)) {
        num = boxFormTwo(i+1,j-1)+2;
        //return caseTwoPal.length();
    } else if (caseTwoPal.at(i) != caseTwoPal.at(j)) {
        num = min(boxFormTwo(i+1,j)+2, boxFormTwo(i,j-1)+2);
        //return caseTwoPal.length();
    }
    return num;
}

//formula in box
// p(i + 1, j − 1) + 2  if S[i] = S[j]
// min {p(i + 1, j) + 2, p(i, j − 1) + 2}  if S[i] =\= S[j]
int boxFormThree(int i, int j) {
    int num = 0;
    //i = 0;
    //j = input.length()-1;
    //string palSection = caseThreePal.find(input);
    //reverse(palSection.begin(), palSection.end());
    //if(caseThreePal.at(i).compare(caseThreePal.at(j)) == 0) {
    if(caseThreePal.at(i) == caseThreePal.at(j)) {
        num = boxFormThree(i+1,j-1)+2;
        //return caseThreePal.length();
    } else if (caseThreePal.at(i) != caseThreePal.at(j)) {
        num = min(boxFormThree(i+1,j)+2, boxFormThree(i,j-1)+2);
        //return caseThreePal.length();
    }
    return num;
}

void palindrome() {
    //if case one produces the best palindrome it is the smallest (from assignment notes)
    if (caseOnePal.length() < caseTwoPal.length() && caseOnePal.length() < caseThreePal.length()) {
        finalPal = caseOnePal;
    }
    int i = 0;
    int j = input.length()-1;
    if (boxFormTwo(i,j) < boxFormThree(i,j)) {
        //case2 pal is smallest
        finalPal = caseTwoPal;
    } else if (boxFormTwo(i,j) >= boxFormThree(i,j)) {
        //case3 pal is smallest, I just put the case2 and case3 are equal case here
        finalPal = caseThreePal;
    }
}



int main(int argc, char* argv[]) {
    //string input;
    cin >> input;
    caseOne(input);
//    cout << "1" << caseOnePal;
//    cout << endl;
    caseTwo(input);
//    cout << "2" << caseTwoPal;
//    cout << endl;
    caseThree(input);
//    cout << "3" << caseThreePal;
    palindrome();
    cout << finalPal.length() << " " << finalPal << endl;

    if (!cin.good()) {
        return 0;
    }
}
