#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 4e5+5;
int p[N]; // 0 if prime, 1 if not prime
int lp[N];
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            for(ll j=i;j<N;j+=i){
                if(!lp[j]) lp[j] = i;
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> ap;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(!p[a[i]]){
                ap.push_back(a[i]);
            }
        }
        if(ap.size() == 1){
            //only 1 prime
            ll x = ap[0];
            sort(a.begin(), a.end());
            for(auto &y : a){
                if(y != x && y < 2*x){
                    x = -1;
                    break;
                }else if(y == x){ 
                    continue;
                }else if(y < 4*x){
                    ll l = lp[y]; // <= sqrt(4*x)
                    ll k = y / l;
                    if(l == 2) continue;
                    else if((k-1)*l >= 2*x) continue;
                    else{
                        x = -1;
                        break;
                    }
                }   
            }
            cout << x << "\n";
        }else if(ap.size() > 1){
            cout << "-1\n";
        }else cout << "2\n";
    }
}
