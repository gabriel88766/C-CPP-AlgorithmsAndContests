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
    //freopen("out", "w", stdout); //test input
    vector<vector<int>> ans;
    int n, k;
    cin >> n >> k;
    int r;
    cin >> r;
    for(int i=1;i<=r;i++){
        vector<int> cur;
        cur.push_back(i);
        ans.push_back(cur);
    }
    for(int i=2;i<=n;i++){
        int r;
        cin >> r;
        vector<vector<int>> nans;
        for(auto v : ans){
            for(int i=1;i<=r;i++){
                auto cur = v;
                cur.push_back(i);
                nans.push_back(cur);
            }
        }
        ans = nans;
    }
    for(auto v : ans){
        int s = 0;
        for(auto x : v) s += x;
        if(!(s % k)){
            for(auto x : v) cout << x << " ";
            cout << "\n";
        }
    }
}
