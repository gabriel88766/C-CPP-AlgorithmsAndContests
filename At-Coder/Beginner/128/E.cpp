#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Block{
    int pos, s, t;
    bool operator< (Block v){
        if(pos != v.pos) return pos < v.pos;
        else return s < v.s; 
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<Block> v;
    set<pair<int,int>> qrs;
    vector<int> ans(q, -1);
    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back({c,a,b});
    }
    sort(v.begin(), v.end());
    for(int i=0;i<q;i++){
        int aux;
        cin >> aux;
        qrs.insert({aux, i});
    }
    //solve
    for(int i=0;i<n;i++){
        int l = v[i].s - v[i].pos;
        int r = v[i].t - v[i].pos - 1;
        vector<pair<int,int>> rml;
        for(auto it = qrs.lower_bound({l,0}); it != qrs.end(); ++it){
            if(it->first > r) break;
            ans[it->second] = v[i].pos;
            rml.push_back(*it);
        }
        for(auto x : rml) qrs.erase(x);
    }
    //end
    for(int i=0;i<q;i++) cout << ans[i] << "\n";
}
