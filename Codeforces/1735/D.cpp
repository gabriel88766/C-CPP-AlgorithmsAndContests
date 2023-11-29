#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> calcdif(vector<int> &a, vector<int> &b){
    vector<int> ans(a.size());
    for(int i=0;i<a.size();i++){
        if(a[i] == b[i]) ans[i] = a[i];
        else{
            for(int j=0;j<3;j++){
                if(a[i] != j && b[i] != j){
                    ans[i] = j;
                }
            }
        }
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    map<vector<int>, bool> mp;
    vector<vector<int>> v(n, vector<int> (k));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin >> v[i][j];
        }
        mp[v[i]] = true;;
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll cur = 0;
        for(int j=0;j<n;j++){
            if(j == i) continue;
            auto x = calcdif(v[i], v[j]);
            if(mp[x]) cur++;
        }
        cur /= 2;
        ans += (cur * (cur-1))/2;
    }
    cout << ans << "\n";
}
