#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 110;

string s[MXN]; 
int a[MXN], b[MXN], c[MXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x >> s[i];
        for(int j = 0; j < x; j++) {
            string t; cin >> t;
            string tmp;
            for(int k = 0; k < t.size(); k++) {
                if(t[k] != '-')tmp += t[k]; 
            }
            t = tmp;
            bool eq = 1, des = 1;
            for(int k = 0; k < t.size(); k++) {
                eq &= t[0] == t[k];
            }
            for(int k = 0; k < t.size() - 1; k++) {
                des &= (t[k] - '0') > (t[k + 1] - '0');
            }
            if(eq) a[i]++;
            else if(des) b[i]++;
            else c[i]++;
        }
    }
    string taxy, pizza, girl; 
    int ma = 0, mb = 0, mc = 0;
    for(int i = 0; i < n; i++) {
        ma = max(ma, a[i]);
        mb = max(mb, b[i]);
        mc = max(mc, c[i]);
    }
    vector<string> mxa, mxb, mxc;
    for(int i = 0; i < n; i++) {
        if(ma == a[i]) mxa.emplace_back(s[i]);
        if(mb == b[i]) mxb.emplace_back(s[i]);
        if(mc == c[i]) mxc.emplace_back(s[i]);  
    } 
    cout << "If you want to call a taxi, you should call: ";
    for(int i = 0; i < mxa.size(); i++) {
        if(i) cout << ", ";
        cout << mxa[i];
    } cout << '.' << endl;
    cout << "If you want to order a pizza, you should call: ";
    for(int i = 0; i < mxb.size(); i++) {
        if(i) cout << ", ";
        cout << mxb[i];
    } cout << '.' << endl;
    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    for(int i = 0; i < mxc.size(); i++) {
        if(i) cout << ", ";
        cout << mxc[i];
    } cout << '.' << endl;
    
    return 0;
}