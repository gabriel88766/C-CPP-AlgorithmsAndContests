#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+5;
int lp[N]; 
void sieve(){
    for(ll i=2; i<N; i++){
        if(!lp[i]){
            for(ll j = i; j < N; j += i){
                if(!lp[j]) lp[j] = i; //marking all multiples of i as not prime
            }
        }
    }
}

int cnt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int cur;
        cin >> cur;
        int lst = -1;
        while(cur != 1){
            if(lst != lp[cur]){
                cnt[lp[cur]]++;
                lst = lp[cur];
            }
            cur /= lp[cur];
        }
    }
    bool ok1 = true, ok2 = false;
    for(int i=1;i<N;i++){
        if(cnt[i] > 1) ok1 = false;
        if(cnt[i] == n) ok2 = true;
    }
    if(ok1) cout << "pairwise coprime\n";
    else if(ok2) cout << "not coprime\n";
    else cout << "setwise coprime\n";

}
