#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
 
    cin >> str;
    int size = str.length();

    for (int i = 0; i < size; ++i) {
        string tmp = "";
        char t = str[size - 1];
        for (int j = 0; j < size -1; ++j) 
            tmp += str[j];
        
        tmp = t + tmp;
        str = tmp;
        cout << str << '\n';
        
    }
 
    return 0;
}