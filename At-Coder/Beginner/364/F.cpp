#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 2e5+3;   
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

struct eds{
    ll l, r, w;
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, q;
    cin >> n >> q;
    bool ok = true;
    vector<eds> ve(q);
    for(int i=0;i<q;i++){
        cin >> ve[i].l >> ve[i].r >> ve[i].w;
    }
    //check if ok
    sort(ve.begin(), ve.end(), [&](eds &a, eds &b){
        return a.l < b.l;
    });
    ll rm = 1;
    for(int i=0;i<q;i++){
        if(ve[i].l > rm) ok = false;
        rm = max(rm, ve[i].r);
    }
    if(rm != n) ok = false;
    if(ok){
        ll ans = 0;
        sort(ve.begin(), ve.end(), [&](eds &a, eds &b){
            return a.w < b.w;
        });
        for(int i=0;i<q;i++){
            auto [l, r, w] = ve[i];
            ans += w;
            while(true){
                int lo = l, hi = r;
                while(lo != hi){
                    int mid = lo + (hi - lo)/2;
                    if(get(mid) == get(l)) lo = mid + 1;
                    else hi = mid;
                }
                if(get(lo) == get(l)) break;
                ans += w;
                unite(l, lo);
            }
        }
        cout << ans << "\n";
    }else cout << "-1\n";
}
 