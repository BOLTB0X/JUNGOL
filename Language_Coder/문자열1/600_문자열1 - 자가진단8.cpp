#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str, tmp = "";
    int cnt = 0;
    getline(cin, str);

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ' ') {
            tmp = "";
            cnt++;
        }
        tmp += str[i];
    }
    if (!tmp.empty())
        cnt++;

    cout << cnt;
    return 0;
}