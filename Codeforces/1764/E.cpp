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
        vector<pair<int,int>> vp;
        int x, y;
        cin >> x >> y;
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            vp.push_back({a,b});
        }
        sort(vp.begin(), vp.end(), [&](pair<int,int> u, pair<int,int> v){
            return u.first+u.second < v.first + v.second;
        });
        int b = 0;
        if(n > 30){
            b = vp[0].first;
            for(int i=1;i<vp.size();i++){
                b = max(b, min(b, vp[i].first) + vp[i].second);
            }
        }else{
            for(int i=0;i<vp.size();i++){
                int c = vp[i].first;
                for(int j=0;j<vp.size();j++){
                    if(i == j) continue;
                    c = max(c, min(c, vp[i].first) + vp[i].second);
                }
                b = max(c, b);
            }
        }
        if(min(b, x) + y >= k) cout << "YES\n";
        else cout << "NO\n";
    }
}
