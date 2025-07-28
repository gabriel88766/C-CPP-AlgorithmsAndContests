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
        //sum everything subtract (n-k+1) smallest minimums and sum 1
        ll ans = 0;
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> vp(n);
        for(int i=0;i<n;i++){
            cin >> vp[i].first;
            ans += vp[i].first;
        }
        for(int i=0;i<n;i++){
            cin >> vp[i].second;
            ans += vp[i].second;
        }
        vector<int> aux;
        for(int i=0;i<n;i++){
            aux.push_back(min(vp[i].first, vp[i].second));
        }
        sort(aux.begin(), aux.end());
        for(int i=0;i<n-k+1;i++) ans -= aux[i];
        ans++;
        cout << ans << "\n";
    }
}
