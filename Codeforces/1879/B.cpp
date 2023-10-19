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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        ll S1 = 0, S2 = 0;
        for(int i=0;i<n;i++){
             cin >> a[i];
             S1 += a[i];
        }
        for(int i=0;i<n;i++){
             cin >> b[i];
             S2 += b[i];
        }
        S2 += (*min_element(a.begin(), a.end()))*n;
        S1 += (*min_element(b.begin(), b.end()))*n;
        cout << min(S1, S2) << "\n";
        
    }
}
