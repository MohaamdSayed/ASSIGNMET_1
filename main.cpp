/**
 *
 * this code is writen By Mohamed Sayed Mohamed ibrahim
 * Section 2 third Year Mechatronics Mainstream
 * For assignment 1
 * No set and get methods are written
 * you can use ( cout ,cin  , =) instead
 * additional methods (size) which return the number of the non empty character in the object;
 * */


#include <iostream>

using namespace std;

class entry {
private:
    char arr[1000];

    void clear() {
        for (int i = 0; i < 1000; i++) {
            arr[i] = '\0';
        }
    }

public:
    entry() {
        clear();
    }

    int findC(char c, int start = 0) {
        for (int i = start; i < 1000; i++)
            if (arr[i] == c)
                return i;
        return -1;
    }

    void replace(char oldChar, char newChar) {
        for (int i = 0; i < 1000; i++) {
            if (arr[i] == oldChar) {
                arr[i] = newChar;
            }
        }
    }

    int numOf(char c) {
        /* return the number of existing char c in the object
         * return -1 if the character isn't in the object
        */

        int num = 0;
        bool flag = false;
        for (int i = 0; i < 1000; i++) {
            if (arr[i] == c) {
                num++;
                flag = true;
            }
        }
        if (flag)
            return num;
        return -1;
    }


    int size() {
        /*
         * return the size of the non empty characters of the array
         * */
        int size = 0;
        bool end = false;
        while (!end) {
            size++;
            if (arr[size] == '\0') {
                end = true;
            }
        }
        return size;
    }

    void operator=(char *str) {
        /*
         * this function is used to overload the operator =
         * so we can set the object by simply make it equal to string
         *
         */

        // find size of the entered string
        int size = 0;
        bool end = false;
        while (!end) {
            if (str[size] == '\0') {
                end = true;
            }
            size++;
        }
        clear(); // clear the object
        for (int i = 0; i < size; i++) {
            arr[i] = str[i];
        }
    }

    friend ostream &operator<<(ostream &output, entry const &str) {
        output << str.arr << endl;
        return output;
    }

    friend istream &operator>>(istream &input, entry &str) {
        input.getline(str.arr, 1000);
        return input;
    }
};

int main() {
    entry myString; //creating object

    cout << "ENTER YOUR NAME" << endl;

    cin >> myString; // initializing the object;

    cout << "Enter Character and starting position to find  " << endl;

    char find;
    int pos;

    cin >> find;
    cin >> pos;
    cout << myString.findC(find, pos) << endl; // printing the index of the char find in the object

    char oldChar, newChar;

    cout << "Enter character to replace followed by the new character\n";

    cin >> oldChar >> newChar;

    myString.replace(oldChar, newChar); //calling the method replace

    cout << myString;  // printing the object after replacing the required character

    cout << "Enter a character u want to know the number of\n";

    cin >> find;    // cin charcter

    cout << myString.numOf(find) << endl; //printing the number of the find character found in the object

/*
    // U can set the value of the object directly using the = operator
    // (char*) is typed before the string to cast it as char array
    myString = (char *) "0123456789"; // additional feature

    cout << myString;
    cout << "the size of the object = " << myString.size();
  */
    return 0;
}