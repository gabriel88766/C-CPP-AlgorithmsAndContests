#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    ll v;
    //static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(ll u){ v = (u >= 0 ? u % MOD : u % MOD + MOD);}
    Mint pow(ll u){
        Mint ans = 1;
        Mint aux = *this;
        while(u){
            if(u & 1) ans *= aux;
            aux *= aux;
            u >>= 1;
        }
        return ans;
    }
    friend Mint operator* (Mint a, Mint const &b){ return a *= b;}
    friend Mint operator/ (Mint a, Mint const &b){ return a /= b;}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint operator*= (Mint u){ v = (u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (Mint u){ return v == u.v;}
    bool operator!= (Mint u){ return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

const int N = 2e5+3;   
int p[N], sz[N];
int il[N], ir[N];
void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1; il[i] = ir[i] = -1;}
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
    //il[a] = min(il[b], il[a]);
    //ir[a] = max(ir[b], ir[a]);
    sz[a] += sz[b];
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        init(n);
        vector<int> v(2*n+1);
        for(int i=1;i<=2*n;i++){
             cin >> v[i];
             if(il[v[i]] == -1) il[v[i]] = i;
             else ir[v[i]] = i;
        }
        //wow
        vector<int> visp(2*n+1, false);
        vector<pair<int,int>> seg;
        for(int i=1;i<=2*n;i++){
            if(!visp[i]){
                visp[i] = true;
                int rmax = ir[v[i]];
                int p = i;
                while(p != rmax){
                    p++;
                    visp[p] = true;
                    rmax = max(rmax, ir[v[p]]);
                }
                seg.push_back({i, p});
            }
        }
        Mint ans = 1;
        vector<bool> vis(n+1, false);
        for(auto [l, r] : seg){
            set<int> s;
            s.insert(l);
            s.insert(ir[v[l]]);
            queue<pair<int,int>> q;
            q.push({il[v[l]], ir[v[l]]});
            while(!q.empty()){
                auto [l, r] = q.front();
                q.pop();
                for(int i=l+1;i<r;i++){
                    if(il[v[i]] < l || ir[v[i]] > r && get(v[i]) != get(v[l])){
                        unite(v[i], v[l]);
                        int u1 = il[v[i]];
                        int u2 = ir[v[i]];
                        auto insrt = [&](int u){
                            auto it1 = s.lower_bound(u);
                            if(it1 != s.begin() && it1 != s.end()){
                                int d1 = u - *prev(it1);
                                int d2 = *it1 - u;
                                if(d1 < d2) q.push({*prev(it1), u});
                                else q.push({u, *it1});
                            }else if(it1 == s.begin()){
                                q.push({u, *it1});
                            }else{
                                q.push({*prev(it1), u});
                            }
                        };
                        insrt(u1);
                        insrt(u2);
                        s.insert(u1);
                        s.insert(u2);
                    }
                }
            }
            int cur = 0;
            for(int i=l;i<=r;i++) if(get(v[i]) == get(v[l])) cur++;
            ans *= cur;
        }
        cout << seg.size() << " " << ans << "\n";
    }
}