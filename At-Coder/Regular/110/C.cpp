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
    vector<bool> used(n, false);
    vector<int> v(n+1), ans;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++){
        int pl;
        for(int j=i;j<=n;j++){
            if(v[j] == i){
                pl = j;
                break;
            }
        }
        if(pl == i) continue;
        else{
            bool ok = true;
            for(int j=pl-1;j>=i;j--){
                if(!used[j]){
                    used[j] = true;
                    swap(v[j], v[j+1]);
                    ans.push_back(j);
                }else{
                    ok = false;
                    break;
                }
            }
            if(!ok){
                ans.clear();
                break;
            }
        }
    }
    if(ans.size() == n-1){
        for(auto x : ans) cout << x << "\n";
    }else cout << "-1\n";
}
