#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

int change(int x) {
    if(x == 2) return 5; 
    else if(x == 5) return 2;
    return x;
}

string get_s(int h, int m) {
    string s = "00:00";
    s[4] = char(change((h/10)%10) + '0');
    s[3] = char(change(h%10) + '0');
    s[0] = char(change(m%10) + '0');
    s[1] = char(change(m/10)%10 + '0');
    return s;
}

bool check(int h, int m, int ch, int cm) {
    set<char> v({0,1,2,5,8});
    string s = get_s(ch, cm);
    fori(i,0,5) {
        if(s[i] == ':') continue;
        if(!v.count(s[i]-'0')) return 0;
    }
    ch = (s[0]-'0')*10 + (s[1]-'0');
    cm = (s[3]-'0')*10 + (s[4]-'0');
    return ch < h && cm < m;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int h, m;
        string s;
        cin >> h >> m >> s;
        int ch = (s[0]-'0')*10 + (s[1]-'0');
        int cm = (s[3]-'0')*10 + (s[4]-'0');
        while(1) {
            if(check(h, m, ch, cm)) break;
            cm++;
            if(cm == m) {
                ch++;
                cm = 0;
                if(ch == h) ch = 0;
            } 
        }
        s[0] = char(((ch/10)%10) + '0');
        s[1] = char((ch%10) + '0');
        s[3] = char(((cm/10)%10) + '0');
        s[4] = char((cm%10) + '0');
        cout << s << endl;
    }
    return 0; 
}