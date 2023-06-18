
#include <iostream>
#include <map>
#include <vector>

using namespace std;


int N;

int count_distinct(const vector<string>& ids) {

	map<string, int> Hash;
	int count = 0;
	for (const string& x : ids) {
		if (Hash.find(x) == Hash.end()) {
			Hash[x] = 1;
			count++;
		}
		else {
			Hash[x]++;
		}
	}
	return count;

}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	vector<string> ids(N);

	for (int i = 0; i < N; i++) cin >> ids[i];

	cout << count_distinct(ids);

	return 0;
}

