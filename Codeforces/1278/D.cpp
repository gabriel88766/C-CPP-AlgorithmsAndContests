#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+3;   
int p[N], sz[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //brute force unite after sort, if get(a) == get(b) then not tree
    init();
    int n;
    cin >> n;
    vector<pair<int,int>> vp(n+1);
    set<tuple<int,int,int>> st;
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        vp[i] = {a, b};
    }
    sort(vp.begin(), vp.end(), [&](pair<int,int> &u, pair<int,int> &v){
        return u.second < v.second;
    });
    for(int i=1;i<=n;i++){
        auto [a, b] = vp[i];
        st.insert({a, b, i});
    }
    bool ok = true;
    int cntCmp = n;
    for(int i=1;i<=n;i++){
        auto [l, r] = vp[i];
        st.erase(st.lower_bound({l, r, 0}));
        for(auto it = st.lower_bound({l, 0, 0}); it != st.end(); ++it){
            auto [ll, rr, ii] = *it;
            if(ll > r) break;
            
            if(get(i) != get(ii)){
                unite(i, ii);
                cntCmp--;
            }else{
                ok = false;
                break;
            }
        }
        if(!ok) break;
    }
    if(ok && cntCmp == 1) cout << "YES\n";
    else cout << "NO\n";

}
