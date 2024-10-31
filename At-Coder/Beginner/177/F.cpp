#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w;
    cin >> h >> w;
    set<tuple<int,int,int>> st;
    multiset<int> sz;
    for(int i=1;i<=w;i++){
        st.insert({i, i, i});
        sz.insert(0);
    }
    for(int i=1;i<=h;i++){
        int l, r;
        cin >> l >> r;
        auto it = st.lower_bound({l, 0, 0});
        int rl = -1, rr;
        vector<tuple<int,int,int>> rml;
        while(it != st.end()){
            auto [a, b, c] = *it;
            if(a > r+1) break;
            rml.push_back(*it);
            sz.erase(sz.lower_bound(a - c));
            if(rl == -1) rl = b;
            rr = c;
            ++it;
        }
        for(auto x : rml) st.erase(x);
        if(r+1 <= w && rl != -1){
            st.insert({r+1, rl, rr});
            sz.insert(r+1 - rr);
        }
        if(sz.size()) cout << *sz.begin() + i << "\n";
        else cout << "-1\n";
    }

}
