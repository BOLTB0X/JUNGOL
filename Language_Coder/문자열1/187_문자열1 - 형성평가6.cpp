#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	string str;
	int i;
	cin >> str;
	
	vector<char> v;
	for (int i = 0; i < str.length();++i)
		v.push_back(str[i]);
	
	while(v.size() != 1) {
		cin >> i;
		
		if (i > v.size())
			v.pop_back();
		else {		
			vector<char> tmp;
			for (int j = 0; j < v.size(); ++j) {
				if (i - 1 == j)
					continue;
				tmp.push_back(v[j]);
			}
			v = tmp;
		}
		for(int j = 0; j < v.size(); ++j)
			cout << v[j];
		cout << '\n';
	} 
	return 0;
}
