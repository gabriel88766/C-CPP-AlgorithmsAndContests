#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//first n such that 3^n > 1000000 number with n or more factors??
//just check brute force n until the 1000000th number is lower than 3^n.
//answer is just 2^(1000000-n) * Y, where Y is the 1000000th with n or more factors
//from 3^n > 1000001 * 2 ^ (n-1) for n >= 33, we can use n = 33 to solve.(turns out n = 28 is enough)
//but our algorithm grows almost linearly with n;


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    const int X = 33;
    // set<ll> sl[X+1];
    // sl[0].insert(1);
    // ll p = 1;
    // for(int i=0;i<X;i++){
    //     p *= 2;
    //     ll lim = sl[i].size() >= 1000000 ? (2 * (*prev(sl[i].end()))) : INF_LL;
    //     for(auto x : sl[i]){
    //         for(ll u = 2; ; u++){
    //             if(u * x > lim) break;
    //             if(sl[i+1].size() == 0) sl[i+1].insert(x * u);
    //             else if(sl[i+1].size() < 1000000) sl[i+1].insert(x * u);
    //             else if(x * u < *prev(sl[i+1].end())){
    //                 if(!sl[i+1].count(x * u)){
    //                     sl[i+1].erase(prev(sl[i+1].end()));
    //                     sl[i+1].insert(x * u);
    //                 }
    //             }else break;
    //         }
    //     }
    //     //this must be a constant (86597.5) from values greater than or equal to n = 28
    //     // double f = *prev(sl[i+1].end());
    //     // f /= *sl[i+1].begin();
    //     // cout <<  fixed << setprecision(6) << f << endl;
    // }
    // ll ans = *prev(sl[X].end());
    //just find the constant... 
    
    //33 factors again. but now I'll set limit to ceil((3/2)^33) = 647160
    //the upper bound is actually 86597.5, but we "dont know" yet
    struct CustomCompare {
        bool operator()(const pair<ll, ll> &a, const pair<ll, ll> &b) const {
            // Higher score gets higher priority (Max-Heap)
            // If scores are equal, sort alphabetically by name (A to Z at top)
            __int128 v1 = a.first;
            __int128 v2 = b.first;
            v1 *= b.second;
            v2 *= a.second;
            return v1 < v2;
        }
    };
    set<pair<ll, ll>, CustomCompare> st;
    st.insert({1, 1});
    ll ans = 0;
    for(int i=1;i<=1000000;i++){
        auto cp = *st.begin();
        st.erase(st.begin());
        ans = 1LL << 33;
        ans /= cp.second;
        ans *= cp.first;
        for(int u=3;;u++){
            ll nxt = ((__int128)cp.first * u + cp.second - 1) / cp.second;
            if(nxt > 2 * 647160) break;
            st.insert({cp.first * u, cp.second * 2});
        }
        while(st.size() > 1000000-i) st.erase(*prev(st.end()));
    }
    const ll mod = 123'454'321;
    ans %= mod;
    for(int i=1;i<=1000000-X;i++) ans = (ans * 2) % mod;
    cout << ans << "\n";
    //runtime 23s
}
