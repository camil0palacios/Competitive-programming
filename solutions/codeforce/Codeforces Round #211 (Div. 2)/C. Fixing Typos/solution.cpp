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
    string s;
    cin >> s;
    int n = (int) s.size();
    int cnt = 0, lst = 0;
    string ans;
    for(int i = 0; i < n; i++) {
        int j = i;
        while(j < n && s[i] == s[j]) j++;
        int sz = j - i >= 3 ? 2 : j - i;
        if(sz == 2 && lst == 2) ans += string(--sz, s[i]);
        else ans += string(sz, s[i]);
        lst = sz;
        i = j - 1;
    }
    cout << ans << endl;
    return 0; 
}