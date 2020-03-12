#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin >> s){
        int f = 0, t = 0, ff = 0, hu = 0, bu = 0;
        for(int i = 0; i < s.size(); i++){
            f = (f * 10 + (s[i] - '0')) % 4;
            t = (t * 10 + (s[i] - '0')) % 10;
            ff = (ff * 10 + (s[i] - '0')) % 400;
            hu = (hu * 10 + (s[i] - '0')) % 15;
            bu = (bu * 10 + (s[i] - '0')) % 55;
        }
        bool flag = 0;
        if((!f && t) || !ff){
            flag = 1;
            cout << "This is leap year." << endl;
        }
        if(!hu){
            flag = 1;
            cout << "This is huluculu festival year." << endl;
        }
        if(!bu){
            flag = 1;
            cout << "This is bulukulu festival year." << endl;
        }
        if(!flag){
            cout << "This is an ordinary year." << endl;
        }
        cout << endl;
    }
    return 0;
}