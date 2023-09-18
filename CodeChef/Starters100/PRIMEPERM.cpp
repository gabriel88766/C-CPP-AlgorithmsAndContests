#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+5;
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
        if(n <= 3) cout << "-1\n";
        else{
            int num = -1;
            vector<int> ans;
            if(n % 2 && n >= 11){
                ans = {3, 4, 5, 1, 2};
                for(int i=2;i<=n-5;i++){
                    if(!p[i] && !p[n-5-i]){
                        num = i;
                        break;
                    }
                }
                for(int i=1;i<=n-5-num;i++){
                    ans.push_back(i+num+5);
                }
                for(int i=1;i<=num;i++){
                    ans.push_back(i+5);
                }
            }else{
                for(int i=2;i<=n;i++){
                    if(!p[i] && !p[n-i]){
                        num = i;
                        break;
                    }
                }
                for(int i=1;i<=n-num;i++){
                    ans.push_back(i+num);
                }
                for(int i=1;i<=num;i++){
                    ans.push_back(i);
                }
            }
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }
    }
}
