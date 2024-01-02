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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> ans(n, 0);
        vector<vector<int>> pos(n+1);
        for(int i=0;i<n;i++){
             cin >> a[i];
             pos[a[i]].push_back(i);
        }
        int ckl = 0;
        for(int i=1;i<=n;i++){
            if(pos[i].size() >= k){
                for(int j=0;j<k;j++){
                    ans[pos[i][j]] = j+1;
                }
            }else ckl += pos[i].size();
        }
        int ansl = (ckl/k) * k;
        int p = 0, ct = 0;
        for(int i=1;i<=n;i++){
            if(pos[i].size() < k){
                for(int j=0;j<pos[i].size();j++){
                    if(ct < ansl){
                        ct++;
                        ans[pos[i][j]] = p + 1;
                        p++;
                        if(p == k) p -= k;
                    }else break;
                }
            }
        }
        for(int i=0;i<n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
