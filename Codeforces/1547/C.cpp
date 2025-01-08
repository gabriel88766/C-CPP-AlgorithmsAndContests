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
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> a(n), b(m);
        bool ok = true;
        vector<int> ans;
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<m;i++) cin >> b[i];
        int p0 = 0, p1 = 0;
        while(p0 < a.size() || p1 < b.size()){
            if(p0 < a.size() && a[p0] <= k){
                ans.push_back(a[p0]);
                if(a[p0] == 0) k++;
                p0++;
            }else if(p1 < b.size() && b[p1] <= k){
                ans.push_back(b[p1]);
                if(b[p1] == 0) k++;
                p1++;
            }else{
                ok = false;
                break;
            }
        }
        if(ok){
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }else cout << "-1\n";
    }
}
