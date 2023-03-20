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
    vector<pair<int,int>> vp;
    int n, s;
    cin >> n >> s;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        vp.push_back({a,b});
    }
    sort(vp.begin(), vp.end());
    int ans = 2;
    for(int i=0;i<vp.size()-1;i++){
        int l = vp[i].first;
        int r = vp[i+1].first;
        int dif = 2*(r-l) - vp[i].second - vp[i+1].second;
        if(dif == 2*s) ans++;
        else if(dif > 2*s) ans += 2;
    }
    cout << ans;
}
