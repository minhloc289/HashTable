#include <iostream>
#include <set>

using namespace std;
int main() {
	int n;
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
	int mex = 0;
	while (s.count(mex)) {
		mex++;
	}
	cout << mex << endl;
	return 0;
}