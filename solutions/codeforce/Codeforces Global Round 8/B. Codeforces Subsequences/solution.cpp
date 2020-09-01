#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

char c[10] = {'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};
int a[10];

long long eval() {
    long long ans = 1;
    for(int i = 0; i < 10; i++) {
        ans *= a[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long k;
    cin >> k;
    for(int i = 0; eval() < k; i++) {
        a[i % 10]++;
    }
    for(int i = 0; i < 10; i++) {
        cout << string(a[i], c[i]);
    }
    cout << endl;
    return 0;
}