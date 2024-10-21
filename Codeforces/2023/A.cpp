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
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++){
            cin >> vp[i].first >> vp[i].second;
        }
        sort(vp.begin(), vp.end(), [&](pair<int,int> u, pair<int,int> v){
            if(max(u.first, u.second) == max(v.first, v.second)) return min(u.first, u.second) < min(v.first, v.second);
            else return max(u.first, u.second) < max(v.first, v.second);
        });
        for(auto [a, b] : vp) cout << a << " " << b << " ";
        cout << "\n";
    }
}
