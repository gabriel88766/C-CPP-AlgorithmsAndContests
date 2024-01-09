#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> solve(int n){
    vector<int> ans;
    if(n % 2){
        for(int i=1;i<=3;i++) ans.push_back(i);
        for(int i=n;i>=4;i--) ans.push_back(i);
    }else{
        for(int i=n;i>=1;i--) ans.push_back(i);
    }
    return ans;
}
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
        auto ans = solve(n-2);
        ans.push_back(n-1);
        ans.push_back(n);
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
