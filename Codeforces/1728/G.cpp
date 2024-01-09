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

Mint dp[1 << 16];
Mint dp2[1 << 16];
map<int, Mint> dp3[1 << 16];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int d, n, m;
    cin >> d >> n >> m;
    vector<int> l(n);
    for(int i=0;i<n;i++){
        cin >> l[i];
    }
    vector<int> p(m);
    for(int i=0;i<m;i++){
        cin >> p[i];
    }
    sort(l.begin(), l.end());
    sort(p.begin(), p.end());
    int msk = 0;
    for(int i=0;i<m;i++) msk |= (1 << i);
    for(int i=0;i<(1 << m);i++) dp[i] = 1;
    //####### begincalc dp[i] ##########
    for(int i=0;i<n;i++){
        int cur = 0;
        vector<int> vaux;
        for(int j=0;j<m;j++){
            vaux.push_back(abs(l[n] - p[j]));
        }
        vaux.push_back(d+1);
        sort(vaux.begin(), vaux.end());
        vector<int> ms;
        vector<int> val;
        while(cur <= d){
            int cmsk = 0;
            for(int j=0;j<m;j++){
                if(l[n]-cur <= p[j] && l[n] + cur >= p[j]){
                    cmsk |= (1 << j);
                }
            }
            int nxt = *upper_bound(vaux.begin(), vaux.end(), cur);
            ms.push_back(cmsk);
            val.push_back(nxt);
            //dp3[cmsk^msk] *= nxt;
            cur = nxt;
        }
        for(int j=0;j<ms.size();j++){
            int nx = j == (ms.size()-1) ? ms[j+1] ^ ms[j] : 0;
            if(dp3[ms[j] ^ msk].count(nx)) dp3[ms[j] ^ msk][nx] *= val[j];
            else dp3[ms[j] ^ msk][nx] = val[j];
        }
    }
    //fix
    for(int i=0;i<(1 << m);i++){
        int s = i;
        for(auto [k, v] : dp3[i]){
            cout << i << " " << k << " - " << v << "\n";
            int valp = msk ^ i;
            int ms = i ^ k;
            for (int s=ms; s; s=(s-1)&ms){ 
                dp[s^valp] *= v;
            }
            dp[valp] *= v;
        }
    }
    cout << dp[0] << " " << dp[1] << "\n";
    for(int i=1;i<(1 << m);i++){
        //dp[i] = dp3[i^msk];
        int s = i;
        do{ 
            s = (s-1) & i;
            if((__builtin_popcount(i) - __builtin_popcount(s)) % 2) dp[i] -= dp[s];
            else dp[i] += dp[s];
        }while(s);
    }
    //######## end calc dp[i] #############
    /*for(int i=0;i<=d;i++){
        for(int j=0;j<=d;j++){
            for(int k=0;k<=d;k++){
                int mm = 0;
                for(int x=0;x<m;x++){
                    if(l[0]-i <= p[x] && l[0] + i >= p[x]) mm |= (1 << x);
                    if(l[1]-j <= p[x] && l[1] + j >= p[x]) mm |= (1 << x);
                    if(l[2]-k <= p[x] && l[2] + k >= p[x]) mm |= (1 << x);
                }
                dp[mm] += 1;
            }
        }
    }*/
    for(int i=0;i<(1 << m);i++){
        for (int s=i; s; s=(s-1)&i){ 
            int cur = s ^ msk;
            dp2[i] += dp[cur];
        }
        dp2[i] += dp[msk];
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        Mint ans = 0;
        int cur = 0;
        vector<int> vaux;
        for(int j=0;j<m;j++){
            vaux.push_back(abs(x - p[j]));
        }
        vaux.push_back(d+1);
        sort(vaux.begin(), vaux.end());
        while(cur <= d){
            int cmsk = 0;
            for(int j=0;j<m;j++){
                if(x-cur <= p[j] && x + cur >= p[j]){
                    cmsk |= (1 << j);
                }
            }
            int nxt = *upper_bound(vaux.begin(), vaux.end(), cur);
            ans += dp2[cmsk] * (nxt - cur);
            cur = nxt;
        }

        cout << ans << "\n";
    }
}
