#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2750132;
int p[N], lsdiv[N]; // 0 if prime, 1 if not prime
vector<ll> primes;
map<int,int> pi;
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = 2*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            primes.push_back(i);
        }
        for(int j=2*i; j<N;j+=i){
            lsdiv[j] = i;
        }
    }
    for(int i=0;i<primes.size();i++){
        pi[primes[i]] = i+1;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    multiset<int> ms;
    cin >> n;
    for(int i=1;i<=2*n;i++){
        int aux;
        cin >> aux;
        ms.insert(aux);
    }
    sieve();
    vector<int> ans;
    for(int i=1;i<=n;i++){
        int x = *prev(ms.end());
        int y;
        if(p[x]){
            ans.push_back(x);
            y = lsdiv[x];
        }else{
            y = pi[x];
            ans.push_back(y);
        }
        ms.erase(ms.find(x));
        ms.erase(ms.find(y));
    }
    for(auto x : ans) cout << x << " ";
}
