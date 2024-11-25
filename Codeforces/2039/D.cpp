#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 3e5+5;
int p[N], qf[N]; // 0 if prime, 1 if not prime
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            for(ll j=i;j<N;j+=i){
                int aux = j;
                while(!(aux % i)){
                    aux /= i;
                    qf[j]++;
                }
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
        int n, m;
        cin >> n >> m;
        int mv = 0;
        for(int i=1;i<=n;i++) mv = max(mv, qf[i]);
        vector<int> v;
        for(int i=1;i<=m;i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end(), greater<int>());
        if(mv < m){
            for(int i=1;i<=n;i++) cout << v[qf[i]] << " ";
            cout << "\n";
        }else cout << "-1\n";
    }
}
