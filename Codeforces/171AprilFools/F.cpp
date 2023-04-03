#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
int p[N]; // 0 if prime, 1 if not prime
vector<ll> primes;
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            primes.push_back(i);
        }
    }
}

int reverseP(int u){
    int ans = 0;
    while(u){
        ans *= 10;
        ans += u % 10;
        u /= 10;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int cnt = 0;
    vector<int> ans(11185);
    for(int i=1;i<N-1;i++){
        if(p[i] == 0){
            int k = reverseP(i);
            if(p[k] == 0 && k != i){
                ans[++cnt] = i;
                if(cnt == 11185) break;
            }
        }
    }
    int x;
    cin >> x;
    cout << ans[x] << "\n";
}
