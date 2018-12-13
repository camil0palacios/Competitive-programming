#include <bits/stdc++.h>
using namespace std;

int main(){
  int t, caso = 1;
  cin >> t;
  while(t--){
    int e, h = 0, n;
    cin >> e >> n;
    deque<int> q(n);
    for(auto &i : q) cin >> i;
    sort(q.begin(), q.end());

    if(!q.empty() && e > q.front()){
      while(!q.empty()){

        while(e - q.front() > 0){
          e -= q.front();
          h++;
          q.pop_front();
          if(q.empty())break;
        }

        if(!q.empty() && h - 1 >= 0){
            if(q.size() == 1) break;
            e += q.back();
            h--;
            q.pop_back();
        }
        else break;
      }
    }
    cout << "Case #" << caso++ << ": " << h << endl;
  }
  return 0;
}
