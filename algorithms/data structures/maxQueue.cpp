// typedef pair<ll,ll> pll
struct MaxQueue {
    stack<pll> s1, s2;
    MaxQueue() {}
    int size() {
        return s1.size() + s2.size();
    }
    bool empty() {
        return size() == 0;
    }
    void push(ll val) {
        ll mx = s1.empty() ? val : max(val, s1.top().second);
        s1.push({val, mx});    
    }
    void pop() {
        if(s2.empty()) {
            while(!s1.empty()) {
                ll elem = s1.top().first;
                s1.pop();
                ll mx = s2.empty() ? elem : max(elem, s2.top().second);
                s2.push({elem, mx});
            }
        }
        s2.pop();
    } 
    ll getMax() {
        if(!s1.empty() && !s2.empty()) 
            return max(s1.top().second, s2.top().second);
        if(!s1.empty()) return s1.top().second;
        if(!s2.empty()) return s2.top().second;
        else return -INF;
    }
};