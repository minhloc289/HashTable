#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    // Khai báo bảng băm sử dụng unordered_map
    unordered_map<string, string> user_data;

    // Nhập dữ liệu vào bảng băm
    for (int i = 0; i < n; i++) {
        string username, password;
        cin >> username >> password;
        user_data[username] = password;
    }

    // Truy xuất dữ liệu từ bảng băm và in kết quả
    for (int i = 0; i < q; i++) {
        string username;
        cin >> username;
        if (user_data.find(username) != user_data.end()) {
            cout << user_data[username] << endl;
        }
        else {
            cout << "Chua Dang Ky!" << endl;
        }
    }

    return 0;
}