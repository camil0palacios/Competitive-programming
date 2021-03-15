#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

string s;

int count_max(char c, char d) {
    int n = (int) s.size();
    queue<int> a;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == c) a.push(i);
        else if(s[i] == d && !a.empty()) {
            ans++;
            a.pop();
        }
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> s;
        int ans = count_max('(',')') + count_max('[',']');
        cout << ans << endl;
    }
    return 0; 
}