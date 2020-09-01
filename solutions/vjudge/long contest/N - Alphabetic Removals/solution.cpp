#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    string s;
    cin >> n >> k >> s;
    deque<int> pos[26];
    for(int i = 0; i < n; i++) {
        pos[s[i] - 'a'].emplace_back(i);
    }
    bool check[n];
    memset(check, 0, sizeof check);
    int it = 0;
    while(k) {
        if(!pos[it].empty()) {
            check[pos[it].front()] = 1;
            pos[it].pop_front();
            k--;
        } else it++;
    }
    for(int i = 0; i < n; i++) {
        if(!check[i]) {
            cout << s[i];
        }
    }
    cout << endl << endl;
    return 0;
}