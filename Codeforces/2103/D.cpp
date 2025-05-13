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
        int n;
        cin >> n;
        vector<int> a(n+2);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<int> ans(n+1);
        int l = 1, r = n, x = 0;
        while(l != r){
            x++;
            bool flag = false;
            vector<int> vi;
            for(int i=1;i<=n;i++) if(a[i] == -1 || a[i] >= x) vi.push_back(i);
            vector<int> v1;
            vector<int> v2;
            for(auto &u : vi){
                if(a[u] != x) flag = true;
                else{
                    if(flag) v2.push_back(u);
                    else v1.push_back(u);
                }
            }
            for(auto &u : v1){
                if(x % 2){
                    ans[u] = r--;
                }else{
                    ans[u] = l++;
                }
            }
            reverse(v2.begin(), v2.end());
            for(auto &u : v2){
                if(x % 2){
                    ans[u] = r--;
                }else{
                    ans[u] = l++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i] == -1) ans[i] = l;
        }
        for(int i=1;i<=n;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
