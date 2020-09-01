#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[101][101];

void sol() {
    int n;
    cin >> n;
    int dsum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            dsum += (i == j ? a[i][j] : 0); 
        }
    }
    int r = 0, c = 0;
    for(int i = 0; i < n; i++) {
        unordered_set<int> s;
        for(int j = 0; j < n; j++) {
            s.insert(a[i][j]);
        }
        if(s.size() != n) r++;
    }
    for(int i = 0; i < n; i++){
        unordered_set<int> s;
        for(int j = 0; j < n; j++) {
            s.insert(a[j][i]);
        }
        if(s.size() != n) c++;
    }
    cout << dsum << ' ' << r << ' ' << c << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        sol();
    }
    return 0;
}