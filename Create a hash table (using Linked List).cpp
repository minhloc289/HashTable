
#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
using namespace std;

struct node {
    int key;
    node* next;
};

struct Hash {
    node* bucket[MAX];
    int m;
};

void initHash(Hash& H) {
    for (int i = 0; i < H.m; i++) {
        H.bucket[i] = nullptr;
    }
}

int myhash(int key, int m) {
    return key % m;
}

void insertHash(Hash& H, int key) {
    int i = myhash(key, H.m);
    node* p = new node;
    p->key = key;
    p->next = nullptr;

    if (H.bucket[i] == nullptr) { 
        H.bucket[i] = p;
    }
    else {
        node* prev = nullptr;
        node* curr = H.bucket[i];
        while (curr != nullptr && curr->key < key) { 
            prev = curr;
            curr = curr->next;
        }
        if (prev == nullptr) { 
            p->next = H.bucket[i];
            H.bucket[i] = p;
        }
        else { 
            prev->next = p;
            p->next = curr;
        }
    }
}

void traverseAllHash(Hash& H) {
    for (int i = 0; i < H.m; i++) {
        node* p = H.bucket[i];
        cout << "Bucket " << i << ": ";
        while (p != nullptr) {
            cout << p->key << " ";
            p = p->next;
        }
        cout << endl;
    }
}


int main()
{
    Hash H;
    cin >> H.m; // m la so dia chi co trong bang bam
    initHash(H); //khoi tao cac bucket

    int n, x; cin >> n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        insertHash(H, x); // them 1 gia tri du lieu vao bang bam
    }
    cout << "Created Hash:" << endl;
    traverseAllHash(H); // Xuat toan bo cac bucket cua Bang bam

    return 0;
}

