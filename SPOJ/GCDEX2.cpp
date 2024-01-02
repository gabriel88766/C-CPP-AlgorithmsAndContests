#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 38e6; //2*10^7, for 10^11
//sf(n)  =  (s(f conv g)(n) - sum[i=2:n](sf(n/i) * g(i))) /g(1)
//example f(i) = phi(i), phi conv I = Id, sum Id is easy to calculate, sum of I is too
map<ull, ull> dp;
ull dp2[N];
ull calcconv(ull n){
    //something easy to calculate
    return n % 2 ? ((n + 1)/2) * n : (n/2) * (n+1);
}

ull gdp(ull n){
    if(n < N) return dp2[n];
    else return dp[n];
}

bool hdp(ull n){
    if(n < N) return true;
    else return dp.count(n);
}

ull calcsum(ull n){
    if(hdp(n)) return gdp(n);
    ull ans = calcconv(n);
    //ll g1 = 1; //ignore in this case
    ull fv = 2;
    for(ll i=2;i*i<=n;i++){
        if(!hdp(n/i)) calcsum(n/i);
        ans -= gdp(n/i); 
        fv = i+1;
    }
    while(fv <= n){
        ull lv = n/(n / fv);
        //sum of g from fv to lv . In this case = lv - fv + 1
        if(!hdp(n/lv)) calcsum(n/lv);
        ans -= (lv - fv + 1) * gdp(n/lv); 
        fv = lv+1;
    }
    //g(i) = 1, no need to divide
    return dp[n] = ans;
}


//precompute up to n^(2/3)

int phi[N];
void euler(){
    for(ll i=1;i<N;i++) phi[i] = i;
    for(ll i=2; i < N; i++){
        if(phi[i] == i){
            for(ll j = i; j < N; j += i){
                phi[j] -= phi[j]/i; 
            }
        }
    }
    dp2[1] = 1;
    for(int i=2;i<N;i++){
        dp2[i] = dp2[i-1] + phi[i];
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    euler();
    int t;
    cin >> t;
    while(t--){
        ull n;
        cin >> n;
        ull ans = 0;
        ull fi = 1;
        for(ull i=1;i*i<=n;i++){
            ans += calcsum(n/i) * i;
            fi = i+1;
        }
        while(fi <= n){
            ull li = n / (n / fi);
            ull cur =  (li + fi) % 2 ? ((li - fi + 1)/2)*(li + fi) : (li - fi + 1)*((li+fi)/2);
            ans += cur * calcsum(n/fi);
            fi = li + 1;
        }
        ans -= calcconv(n);
        cout << ans << "\n";
    }
}