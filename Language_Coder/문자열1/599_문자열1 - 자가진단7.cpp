#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str, res = "";

    getline(cin, str);
    
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] >= 'a' && str[i] <= 'z')
            cout << (char)(str[i] - 32);
        else if (str[i] >= 'A' && str[i] <= 'Z')
            cout << (char)str[i];
    }
    return 0;
}