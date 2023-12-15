#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
ll cnt[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        cnt[aux]++;
    }
    ll ans = 0;
    for(ll i=1;i<N;i++){
        for(ll j=i;i*j<N;j+=2){
            ans += cnt[i*j]*cnt[(j-i)/2];
        }
    }
    cout << ans << "\n";
}
