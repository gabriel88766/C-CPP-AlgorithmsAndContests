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
    vector<ll> ans(n);
    for(int i=0;i<n;i++){
        cin >> vp[i].first;
        vp[i].second = i;
    }
    sort(vp.begin(), vp.end(), greater<pair<int,int>>());
    int p = 0;
    ll sum = 0;
    for(int i=0;i<n;i++){
        while(vp[p].first > vp[i].first) sum += vp[p++].first;
        ans[vp[i].second] = sum;
    }
    for(int i=0;i<n;i++) cout << ans[i] << " ";
    cout << "\n";

}
