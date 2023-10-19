#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+5;
int p[N]; // 0 if prime, 1 if not prime
vector<ll> pr;
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            pr.push_back(i);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    sieve();
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            for(int j=0; pr[j]*pr[j] <= aux; j++){
                while(aux % pr[j] == 0){
                    mp[pr[j]]++;
                    aux /= pr[j];
                }
            }
            if(aux != 1) mp[aux]++;
        }
        bool ok = true;
        for(auto x : mp){
            if(x.second % n) ok = false;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
