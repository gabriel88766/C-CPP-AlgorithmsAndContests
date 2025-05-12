#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

using namespace __gnu_pbds; //required 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e7+1;
ll mi[N], p[N];
void mobius(){ //another sieve.
    for(ll i =1; i<N;i++) mi[i] = 1;
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i; j < N; j += i){
                p[j] = 1, mi[j] *= -1;
            }
            for(ll j = i*i; j < N; j += i*i){
                mi[j] = 0;
            }
        }
    }
}

int ps1[N], ps2[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    mobius();
    const int N = 20000000; //main N, not global
    for(int i=1;i<=N;i++){
        if(mi[i] == 1) ps1[i] += 99, ps2[i] -= 100;
        else if(mi[i] == -1) ps1[i] -= 100, ps2[i] += 99;
        ps1[i] += ps1[i-1];
        ps2[i] += ps2[i-1];
    }
    ll ans = 0;
    for(int a=1;a<=N;a++) ans += (N-a+1); //sum all
    ordered_set<pair<int, int>> ms1, ms2;
    for(int a=0;a<=N;a++){
        ans -= ms1.order_of_key({ps1[a], -1});
        ans -= ms2.order_of_key({ps2[a], -1});
        ms1.insert({ps1[a], a});
        ms2.insert({ps2[a], a});
    }
    cout << ans << "\n";

}
