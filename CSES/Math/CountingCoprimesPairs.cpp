#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
ll mi[N];
int p[N];
ll cnt[N];
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


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    mobius();
    int n;
    cin >> n;
    ll ans = ((ll)n*(n-1))/2;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        cnt[aux]++;
    }
    for(int i=2;i<N;i++){
        ll curcnt = 0;
        for(int j=i;j<N;j += i){
            curcnt += cnt[j];
        }
        curcnt  = mi[i] * (curcnt * (curcnt-1))/2;
        ans += curcnt;
    }
    cout << ans;
}
