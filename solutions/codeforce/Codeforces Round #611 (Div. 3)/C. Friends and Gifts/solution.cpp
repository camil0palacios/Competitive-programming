#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN], in[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] != 0) in[a[i]] = 1;
    }
    deque<int> x, y;
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) {
            if(in[i]) x.emplace_back(i);
            else y.emplace_back(i);
        }
    }
    if(x.size()) y.push_front(x[0]);
    for(int i = 1; i < y.size(); i++) {
        a[y[i - 1]] = y[i];
        in[y[i]] = 1;
    }
    x.clear(), y.clear();
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) x.push_back(i);
        else if(a[i] && !in[i]) y.push_back(i);
    }
    for(int i = 0; i < x.size(); i++) {
        a[x[i]] = y[i];
    }
    for(int i = 1; i <= n; i++) 
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}