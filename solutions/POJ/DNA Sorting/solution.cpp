#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#define endl '\n'
using namespace std;

vector<int> b;

const bool cmp(pair<string,int> & p1, pair<string,int> & p2) {
    if(b[p1.second] == b[p2.second]) return p1.first < p2.first;
    return b[p1.second] < b[p2.second];
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<string, int> > a(m);
    b.assign(m, 0);
    char l[4] = {'A', 'C', 'G', 'T'};
    for(int i = 0; i < m; i++) {
        cin >> a[i].first;
        a[i].second = i;
        map<char,int> mp;
        string & s = a[i].first;
        for(int j = n - 1; j >= 0; j--) {
            char c = s[j];
            int inv = 0;
            for(int k = 0; k < 4; k++) {
                if(l[k] < c) inv += mp[l[k]];
            }
            mp[c]++;
            b[i] += inv;
        }
    }
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < a.size(); i++) {
        cout << a[i].first << endl;
    }
    return 0;
}