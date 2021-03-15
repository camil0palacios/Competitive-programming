#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    map<char,int> m({{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}});
    char mi[4] = {'A', 'C', 'G', 'T'}; 
    int lst[4] = {n + 1, n + 1, n + 1, n + 1};
    int a[n][4];
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < 4; j++) {
            a[i][j] = lst[j];
        }
        lst[m[s[i - 1]]] = i;
    }
    for(int i = 0; i < 4; i++) a[0][i] = lst[i];
    int i = 0;
    while(i < n + 1) {
        int nxt = -1, pt = 0;
        for(int j = 0; j < 4; j++) {
            if(nxt < a[i][j]) {
                nxt = a[i][j];
                pt = j;
            }
        }
        i = nxt;
        cout << mi[pt]; 
    }
    cout << endl;
    return 0;
}