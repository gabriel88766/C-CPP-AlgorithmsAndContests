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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n+1), b(n);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<n;i++) cin >> b[i];
    for(int i=1;i<n;i++){
        b[i] -= a[i] + a[i+1];
        b[i] %= m;
        if(b[i] < 0) b[i] += m;
    }
    int ans1 = 0, ans2 = 1;
    auto aux = b;
    for(int i=1;i<n;i++){
        if(aux[i] == 1){
            ans1++;
            if(i != n-1) aux[i+1] ^= 1;
        }
    }
    aux = b;
    aux[1] ^= 1;
    for(int i=1;i<n;i++){
        if(aux[i] == 1){
            ans2++;
            if(i != n-1) aux[i+1] ^= 1;
        }
    }
    cout << min(ans1, ans2) << "\n";
}   
