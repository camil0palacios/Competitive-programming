#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    map<char, set<char>> m;
    m['a'].insert({ 'b', 'j', 'k' });
    m['b'].insert({ 'a', 'j', 'k', 'l', 'c' });
    m['c'].insert({ 'b', 'k', 'l', 'm', 'd' });
    m['d'].insert({ 'c','l','m','n','e'  });
    m['e'].insert({ 'd','m','n','o','f'  });
    m['f'].insert({ 'e','n','o','p','g'  });
    m['g'].insert({ 'f','o','p','q','h'  });
    m['h'].insert({ 'g','p','q','r','i'  });
    m['i'].insert({ 'h','q','r' });
    m['j'].insert({ 'a','b','k','t','s'  });
    m['k'].insert({ 'b','c','l','u','t','s','j','a'  });
    m['l'].insert({ 'c','d','m','v','u','t','k','b'  });
    m['m'].insert({ 'd','e','n','w','v','u','l','c'  });
    m['n'].insert({ 'e','f','o','x','w','v','m','d'  });
    m['o'].insert({ 'f','g','p','y','x','w','n','e'  });
    m['p'].insert({ 'g','h','q','z','y','x','o','f'  });
    m['q'].insert({ 'h','i','r','z','y','p','g',' ' });
    m['r'].insert({ 'i','z','q','h'  });
    m['s'].insert({ 'j','k','t'  });
    m['t'].insert({ 's','j','k','l','u'  });
    m['u'].insert({ 't','k','l','m','v'  });
    m['v'].insert({ 'u','l','m','n','w'  });
    m['w'].insert({ 'v','m','n','o','x'  });
    m['x'].insert({ 'w','n','o','p','y'  });
    m['y'].insert({ 'x','o','p','q','z'  });
    m['z'].insert({ 'y','p','q','r'  });
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        int ok = 0;
        if(a.size() == b.size()) {
            if(a == b) ok = 1;
            else {
                for(int i = 0; i < a.size(); i++) {
                    if(a[i] != b[i]) {
                        bool tmp = m[a[i]].count(b[i]);
                        if(!tmp) {
                            ok = 3;
                            break;
                        } 
                    } 
                }
                if(ok == 0) ok = 2; 
            }
        }
        else ok = 3;
        cout << ok << endl;
    }
    return 0;
}