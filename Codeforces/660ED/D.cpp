#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
vector<pair<int,int>> vans;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++){
        cin >> vp[i].first >> vp[i].second;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j) continue;
            vans.push_back({vp[i].first-vp[j].first, vp[i].second-vp[j].second});
        }
    }
    sort(vans.begin(), vans.end());
    ll ans = 0;
    int p = 0;
    while(p < vans.size()){
        int p1 = p;
        while(p1+1 < vans.size() && vans[p1+1] == vans[p]) p1++;
        ll aux = p1 - p + 1;
        ans += aux * (aux - 1);
        p = p1+1;
    }
    ans /= 8;
    cout << ans << "\n";

}
