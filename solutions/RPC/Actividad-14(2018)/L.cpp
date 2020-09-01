#include <bits/stdc++.h>
using namespace std;

bool back(int n, int i, int s){
    int ans = 0;
    bool flag = 1;
    while(ans < s){
        if(flag)ans += n;
        else ans += i;
        flag ^= 1;
    }
    return s == ans;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int s;
    while(cin >> s){
        int mid = (s >> 1) + (s&1);
        cout << s << ':' << endl;
        for(int i = 2; i <= mid; i++){
            if(back(i,i-1,s))
                cout << i << "," << i-1 << endl;
            if(back(i,i,s))
                cout << i << "," << i << endl;
        }
    }
    return 0;
}