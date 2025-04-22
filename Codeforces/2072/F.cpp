#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> solve(int n, int k){
    int x = 1;
    while(2*x <= n) x *= 2;
    if(n == x){
        vector<int> ans;
        for(int i=0;i<n;i++) ans.push_back(k);
        return ans;
    }else{
        vector<int> ans;
        vector<int> aux = solve(n - x, k);
        for(auto &x : aux) ans.push_back(x);
        n -= 2*aux.size();
        for(int i=0;i<n;i++) ans.push_back(0);
        for(auto &x : aux) ans.push_back(x);
        return ans;
    }
}

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
        auto v = solve(n, k);
        for(auto &x : v) cout << x << " ";
        cout << "\n";
    }
}  
