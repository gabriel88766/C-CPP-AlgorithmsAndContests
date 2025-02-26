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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int j=0;j<k;j++){
        vector<pair<int,int>> vc;
        for(int i=j; i<n;i+=k){
            vc.push_back({v[i], i});
        }
        sort(vc.begin(), vc.end());
        int p = 0;
        for(int i=j; i<n;i+=k){
            v[i] = vc[p++].first;
        }
    }
    auto u = v;
    sort(u.begin(), u.end());
    if(u == v) cout << "Yes\n";
    else cout << "No\n";
}
