#include <bits/stdc++.h>
using namespace std;

const int NM = 2e5 + 5;
int a[NM], n;

int main(){
    cin >> n;
    map<int,int> s;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        s[tmp]++;
    }
    int k = 1, ans = 0;
    map<int,int>::iterator it; 
    for(int i = 0; i < n; i++){
        it = s.lower_bound(k);
        pair<int,int> x = *it;
        if(it != s.end() && x.first >= k){
            ans++;
            s[x.first]--;
            if(s[x.first] == 0)s.erase(it);
        }
        k++;
    }
    cout << ans << endl;
    return 0;
}