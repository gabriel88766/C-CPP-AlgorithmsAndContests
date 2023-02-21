#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

using namespace __gnu_pbds; //required 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

struct Queries{
    int l, r, i;
    Queries(int l, int r, int i){
        this->l = l, this->r = r, this->i = i;
    }
    bool operator< (const Queries &q){
        if(l != q.l) return l < q.l;
        else if(r != q.r) return r < q.r;
        else return i < q.i;
    }
};

const int N = 2e5+3;
int v[N], ans[N];
int n;
map<int,int> mp;
vector<pair<int,int>> eqs1;
ordered_set<pair<int,int>>  eqs2;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++){
        if(mp.count(v[i])){
            eqs1.emplace_back(mp[v[i]], i);
            eqs2.insert({i, mp[v[i]]});
        }
        mp[v[i]] = i;
    }
    sort(eqs1.begin(), eqs1.end());
    int bp = 0;
    vector<Queries> vq;

    for(int i=1;i<=q;i++){
        int a,b;
        cin >> a >> b;
        vq.emplace_back(a,b,i);
    }
    sort(vq.begin(), vq.end());
    for(auto x : vq){
        while(bp < eqs1.size() && eqs1[bp].first < x.l){
            eqs2.erase({eqs1[bp].second, eqs1[bp].first});
            bp++;
        }
        int as = x.r - x.l + 1 - eqs2.order_of_key({x.r, INF_INT});
        ans[x.i] = as;
    }
    for(int i=1;i<=q;i++) cout << ans[i] << "\n";
}   
