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
    int ans = n;
    sort(v.begin(), v.end());
    vector<pair<int,int>> v2;
    for(int i=0;i<n;i++){
        if(v2.size() && v2.back().first == v[i]){
            v2.back().second++;
        }else{
            v2.push_back({v[i], 1});
        }
    }
    for(int i=1;i<v2.size();i++){
        if(v2[i-1].first + k >= v2[i].first) ans -= v2[i-1].second;
    }
    cout << ans << "\n";
}
