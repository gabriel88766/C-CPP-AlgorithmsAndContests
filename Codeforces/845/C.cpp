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
    int n;
    cin >> n;
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++) cin >> vp[i].first >> vp[i].second;
    sort(vp.begin(), vp.end(), [&](pair<int,int> u, pair<int,int> v){
        return make_pair(u.second, u.first) < make_pair(v.second, v.first);
    });
    bool ok = true;
    int e1 = -1, e2 = -1;
    for(int i=0;i<n;i++){
        if(e1 > e2) swap(e1, e2);
        if(e2 < vp[i].first) e2 = vp[i].second;
        else if(e1 < vp[i].first) e1 = vp[i].second;
        else{
            ok = false;
            break;
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
