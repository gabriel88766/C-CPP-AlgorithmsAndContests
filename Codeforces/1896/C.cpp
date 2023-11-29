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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        sort(b.begin(), b.end());
        vector<int> pos(n);
        for(int i=0;i<n;i++) pos[i] = i;
        sort(pos.begin(), pos.end(), [&](int u, int v){
            return a[u] > a[v];
        });
        bool ok = true;
        vector<int> ans(n);
        for(int i=0;i<x;i++){
            //greater a with b[x-i-1]
            if(a[pos[i]] > b[x-i-1]){
                ans[pos[i]] = b[x-i-1];
            }else ok = false;
        }
        for(int i=x;i<n;i++){
            if(a[pos[i]] <= b[n-1-(i-x)]){
                ans[pos[i]] = b[n-1-(i-x)];
            }else ok = false;
        }
        if(ok){
            cout << "YES\n";
            for(auto x: ans) cout << x << " ";
            cout << "\n";
        }else cout << "NO\n";
    }
}
