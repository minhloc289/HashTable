#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int n;
	cin >> n;
	char* a = new char[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		a[i] = tolower(a[i]);
	}
	int count[26] = {};
	for (int i = 0; i < n; i++) {
		count[(int)a[i] - (int)'a'] = 1;
	}
	int missing = 0;
	for (int i = 0; i < 26; i++) {
		if (count[i] == 0){
			missing++;
		}
	}
	cout << missing;

}