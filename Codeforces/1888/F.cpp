#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

set<int> pos; 
void init(int n){
    pos.clear();
    for(int i=0;i<=n;i++){
        pos.insert(i);
    }
}

void remove(int l, int r){
    if(r < 0 || l > r) return;
    vector<int> rml;
    for(auto it = pos.lower_bound(l); it != pos.end() && *it <= r; ++it){
        rml.push_back(*it);
    }
    for(auto x : rml) pos.erase(x);
}

bool has(int l, int r){
    auto it = pos.lower_bound(l);
    if(it != pos.end() && *it <= r) return true;
    else return false;
}

struct Oper{
    int l, r, i;
    ll x;
};

struct Interval{
    int l, r;
    ll val;
    Interval(int x, int y, ll z){
        l = x;
        r = y;
        val = z;
    }
    bool operator< (const Interval in) const{
        if(val != in.val) return val < in.val;
        else return l < in.l;
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        cin >> q;
        vector<vector<Oper>> ops(n+1);
        vector<Oper> allops(q+1);
        for(int i=1;i<=q;i++){
            Oper op;
            cin >> op.l >> op.r >> op.x;
            op.i = i;
            ops[op.l].push_back(op);
            allops[i] = op;
        }
        init(q);
        for(int i=1;i<=n;i++){
            ll cur = 0;
            if(!ops[i].size()) continue;
            vector<Interval> in;
            in.emplace_back(0, ops[i][0].i-1, 0LL);
            for(int j=0;j<ops[i].size();j++){
                cur += ops[i][j].x;
                if(j != (ops[i].size() - 1)){
                    in.emplace_back(ops[i][j].i, ops[i][j+1].i-1, cur);
                }else{
                    in.emplace_back(ops[i][j].i, q, cur);
                }
            }
            sort(in.begin(), in.end());
            ll minv;
            for(int j=0;j<in.size();j++){
                if(has(in[j].l, in[j].r)){
                    minv = in[j].val;
                    break;
                }
            }
            vector<pair<int,int>> intervals;
            for(int j=0;j<in.size();j++){
                if(minv == in[j].val){
                    intervals.push_back({in[j].l, in[j].r});
                }
            }
            sort(intervals.begin(), intervals.end());
            remove(0, intervals[0].first-1);
            for(int i=1;i<intervals.size();i++){
                remove(intervals[i-1].second+1, intervals[i].first-1);
            }
            remove(intervals.back().second+1, q);
            
        }
        int posv = *pos.begin();
        vector<ll> ans(n+2, 0);
        for(int i=1;i<=posv;i++){
            ans[allops[i].l] += allops[i].x;
            ans[allops[i].r+1] -= allops[i].x;
        }
        ans[1] += v[1];
        for(int i=2;i<=n;i++) ans[i] += v[i] - v[i-1];
        ll cur = 0;
        for(int i=1;i<=n;i++){
            cur += ans[i];
            cout << cur << " ";
        }
        cout << "\n";
    }
}
