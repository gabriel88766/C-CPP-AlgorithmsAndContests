#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e7+5;
int p[N]; // 0 if prime, 1 if not prime
int l[N];
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            l[i] = i;
            for(ll j = 2*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
                if(!l[j]) l[j] = i;
            }
        }
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    sieve();
    while(n--){
        int x, y;
        cin >> x >> y;
        if(abs(x-y) == 1) cout << "-1\n";
        else{
            int dif = abs(x - y);
            int ans = INF_INT;
            while(dif != 1){
                if(x % l[dif]) ans = min(ans, l[dif] - (x % l[dif]));
                else ans = 0;
                dif /= l[dif];
            }
            cout << ans << "\n";
        }
    }
}
