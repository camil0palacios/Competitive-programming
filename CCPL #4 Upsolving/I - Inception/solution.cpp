#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    string ins, per;
    cin >> q;
    deque<string> dream;
    for(int i = 0; i < q; i++){
        cin >> ins;
        if(ins == "Sleep"){
            cin >> per;
            dream.push_back(per);
        }
        else if(ins == "Kick" && dream.size())dream.pop_back();
        else if(ins == "Test"){
            if(dream.size())cout << dream.back() << endl;
            else cout << "Not in a dream" << endl;
        }
    }
    return 0;
}