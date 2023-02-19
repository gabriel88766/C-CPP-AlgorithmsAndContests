//I saw editorial..
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e7+4;
int p[N];
char isp[N];
void sieve(){
    p[1] = 1;
    for(ll i=2; i<N; i++){
        if(!p[i]){
            isp[i] = true;
            for(ll j = i; j < N; j += i){
                if(!p[j]) p[j] = 2;
                else p[j] <<= 1;
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    sieve();
    while(t--){
        ll c, d, k;
        cin >> c >> d >> k;
        ll ans = 0;
        //for all g such that (k/g + d) % c == 0, 
        vector<ll> divs;
        for(ll i=1;i * i <=k; i++){
            if(!(k % i)){
                divs.push_back(i);
               if(k != i*i) divs.push_back(k/i); 
            }
        }
        for(auto u : divs){
            if(!((k/u+d) % c) ){
                
                ans += p[(k/u + d)/c];  
            }
            
        }
            
        cout << ans << "\n";
        
    }
}
