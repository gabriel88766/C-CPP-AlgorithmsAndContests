#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    vector<bool> pr(1001, true);
    vector<int> primes;
    for(int i=2;i<=1000;i++){
        if(pr[i]){
            for(int j=2*i;j<=1000;j+=i){
                pr[j] = false;
            }
            primes.push_back(i);
        }
    }
    vector<bool> pos(1001,false);
    for(int i=0;i<primes.size();i++){
        if(primes[i]+primes[i+1]+1 <= 1000){
            if(pr[primes[i]+primes[i+1]+1]){
                pos[primes[i]+primes[i+1]+1] = true;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(pos[i]) cnt++;
    }
    if(cnt >= k) cout << "YES\n";
    else cout << "NO\n";
}
