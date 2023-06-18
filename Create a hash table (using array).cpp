
#include <iostream>
#include <cstring>
#include <string>
#define M 10		// M là số nút có trên bảng băm, đủ để chứa các nút nhập vào bảng băm
#define NULLKEY -1
using namespace std;

struct node {
    int key;
    int value;
};

struct Hash {
    int m;
    node* hashtable;
    int n;
};

void initHash(Hash& H) {
    H.m = M;
    H.n = 0;
    H.hashtable = new node[H.m];
    for (int i = 0; i < H.m; i++) {
        H.hashtable[i].key = NULLKEY;
        H.hashtable[i].value = NULLKEY;
    }
}

int hashfunc(int key) {
    return key % M;
}


void insertHash(Hash& H, int k) {
    if (H.n == H.m) {  
        cout << "\nBang bam bi day, khong them duoc";
        return;
    }
    int i = hashfunc(k);
    while (H.hashtable[i].key != NULLKEY) {
        i = (i + 1) % H.m;  
    }
    H.hashtable[i].key = k; 
    H.n++;  
}


void traverseAllHash(Hash H) {
    for (int i = 0; i < H.m; i++) {
        if (H.hashtable[i].key != NULLKEY) {
            cout << H.hashtable[i].key << " ";
        }
    }
}

int main()
{
    Hash H;
    initHash(H);

    int n, x; cin >> n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        cout << "\nInsert " << x;
        insertHash(H, x); // them 1 gia tri du lieu vao bang bam
    }
    cout << "\nCreated Hash:" << endl;
    traverseAllHash(H);

    return 0;
}

