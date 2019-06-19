#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

deque<int> pos, neg;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x, z = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x > 0)pos.emplace_back(x);
        if(x < 0)neg.emplace_back(x);
        if(x == 0)z++;
    }
    cout << 1 << " " << neg[0] << endl;
    neg.pop_front();
    if(neg.size() >= 2){
        cout << 2 + pos.size() << " ";
        for(int i = 0; i < 2; i++){
            cout << neg.front() << " ";
            neg.pop_front();
        }
    }else{ 
        cout << pos.size() << " ";
    }
    while(!pos.empty()){
        cout << pos.front() << " ";
        pos.pop_front();
    }
    cout << endl << z + neg.size() << " ";
    for(int i = 0; i < z; i++)cout << 0 << " ";
    while(!neg.empty()){
        cout << neg.front() << " ";
        neg.pop_front();
    }
    cout << endl;
    return 0;
}