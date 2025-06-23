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
    vector<int> ans;
    ans.push_back(1);
    int n;
    cin >> n;
    for(int i=2;i<=n;i++){
        vector<int> nans;
        for(auto x : ans) nans.push_back(x);
        nans.push_back(i);
        for(auto x : ans) nans.push_back(x);
        ans = nans;
    }
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}
