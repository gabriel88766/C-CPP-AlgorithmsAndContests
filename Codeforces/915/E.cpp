#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


struct Intervals{
    set<pair<int,int>> s;
    int sz;
    Intervals(int n){
        s.insert({1, n});
        sz = n;
    }
    void remove(int l, int r){
        if(r < l) return;
        if(s.size() == 0) return;
        auto it = s.lower_bound({l, 0});
        vector<pair<int,int>> erl;
        if(it != s.begin()){
            auto it2 = prev(it);
            if(it2->second > r){
                pair<int,int> p1 = {it2->first, l-1};
                pair<int,int> p2 = {r+1, it2->second};
                erl.push_back(*it2);
                sz += p1.second - p1.first + 1;
                sz += p2.second - p2.first + 1;
                s.insert(p1);
                s.insert(p2);
            }else if(it2->second >= l){
                pair<int,int> p1 = {it2->first, l-1};
                erl.push_back(*it2);
                sz += p1.second - p1.first + 1;
                s.insert(p1);
            }
        }
        while(it != s.end()){
            if(it->second <= r){
                erl.push_back(*it);
                ++it;
                continue;
            }else if(it->first <= r && it->second > r){
                pair<int,int> p = {r+1, it->second};
                erl.push_back(*it);
                sz += p.second - p.first + 1;
                s.insert(p);
            }
            break;
        }
        for(auto x : erl){
            sz -= x.second - x.first + 1;
            s.erase(x);
        }
    }

    void insert(int l, int r){
        if(r < l) return;
        auto it = s.lower_bound({l, 0});
        vector<pair<int,int>> erl;
        pair<int,int> p = {l, r};
        if(it != s.begin()){
            auto it2 = prev(it);
            if(it2->second >= r) return; //do nothing
            else if(it2->second >= (l-1)){
                p = {it2->first, r};
                erl.push_back(*it2);
            }
        }
        while(it != s.end()){
            if(it->second <= r){
                erl.push_back(*it);
                ++it;
                continue;
            }else if(it->first <= r){
                p.second = it->second;
                erl.push_back(*it);
            }
            break;
        }
        for(auto x : erl){
            sz -= x.second - x.first + 1;
            s.erase(x);
        }
        sz += p.second - p.first + 1;
        s.insert(p);
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    Intervals st(n);
    for(int i=0;i<q;i++){
        int l, r, t;
        cin >> l >> r >> t;
        if(t == 1){
            st.remove(l, r);
        }else{
            st.insert(l, r);
        }
        cout << st.sz << "\n";
    }
}
