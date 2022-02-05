#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, n;
    vector<vector<int>> v;
    vector<int> cmm;
    cin >> T;

    v.resize(T);
    cmm.resize(T);

    for (int i = 0; i < T; ++i) {
        cin >> n;
        v[i].resize(n);
        for (int& x : v[i]) {
            cin >> x;
        }
    }

    for (int& x : cmm)
        cin >> x; 
    
    for (int x1 : cmm) {
        for (int x2 : v[x1])
            cout << x2 << ' ';
        cout << '\n';
    }
   
    return 0;
}