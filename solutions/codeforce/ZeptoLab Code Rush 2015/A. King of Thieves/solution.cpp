#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    bool ok = 0;
    for(int l = 1; l <= n / 4; l++) {
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = i; j < n && s[j] == '*'; j += l) {
                cnt++;
            }
            if(cnt == 5) ok = 1;
        }
    }
    cout << (ok ? "yes" : "no") << endl;
    return 0; 
}