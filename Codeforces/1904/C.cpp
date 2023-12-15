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
        int n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        if(k >= 3) cout << "0\n";
        else{
            vector<ll> v2;
            v2.reserve(n*n);
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    v2.push_back(abs(v[i]-v[j]));
                }
            }
            sort(v2.begin(), v2.end());
            sort(v.begin(), v.end());
            if(k == 1) cout << min(v2[0], v[0]) << "\n";
            else{
                ll minv = min(v2[0], v[0]);
                int p = 0;
                for(int i=0;i<v2.size();i++){
                    while(p+1 < n && v[p+1] <= v2[i]) p++;
                    minv = min(minv, abs(v2[i] - v[p]));
                    if(p+1 < n) minv = min(minv, abs(v[p+1] - v2[i]));
                }
                cout << minv << "\n";
            }
        }
    }
}
