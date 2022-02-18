#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
	string name;
	int score;

	bool operator < (const Student& r) const {
		if (score == r.score)
			return name < r.name;
		return score > r.score;
	}
};

Student arr[50001];

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) 
		cin >> arr[i].name >> arr[i].score;
	
	
	sort(arr + 0,arr + n);
	for (int i = 0; i < n; ++i) 
		cout << arr[i].name << ' ' << arr[i].score << '\n';
	
	return 0;
}
