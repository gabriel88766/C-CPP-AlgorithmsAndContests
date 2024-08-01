#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 230;
int p[N]; // 0 if prime, 1 if not prime
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    bool ok = false;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for(int i=a;i<=b;i++){
        bool okcur = false;
        for(int j=c;j<=d;j++){ //2, 3  // 3, 4
            if(!p[i+j]) okcur = true; //aoki can win if takahashi choose i
        }
        if(!okcur) ok = true; //takahashi can win
    }
    if(!ok) cout << "Aoki\n";
    else cout << "Takahashi\n";
}   
