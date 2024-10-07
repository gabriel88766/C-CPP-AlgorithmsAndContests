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
    int q;
    cin >> q;
    while(q--){
        int n, k;
        string s;
        cin >> n >> k >> s;
        s = " " + s;
        vector<int> v0;
        for(int i=1;i<=n;i++) if(s[i] == '0') v0.push_back(i);
        string ans(k, '0');
        int chk = min(k, 20);
        vector<int> cmsk;
        for(int i=1;i<=n-k+1;i++){
            
            int r = i+k-1;
            int l = r - chk + 1;
            int cur = 0;
            auto it = lower_bound(v0.begin(), v0.end(), i);
            if(it != v0.end() && *it < l) continue;
            for(int j=l;j<=r;j++){
                if(s[j] == '0') cur |= (1 << (r - j)); 
            }
            // cout << cur << " ";
            cmsk.push_back(cur); //this should happen only if there is no "0" in prefix
        }
        sort(cmsk.begin(), cmsk.end());
        cmsk.resize(unique(cmsk.begin(), cmsk.end()) - cmsk.begin());
        int bst = -1;
        for(int i=0;;i++){
            if(i < cmsk.size() && cmsk[i] == i) continue;
            else{
                bst = i;
                break;
            }
        }
        if(bst < (1 << chk)){
            for(int j=k-chk;j<k;j++){
                int b = 1 << (k - j - 1);
                if(bst & b) ans[j] = '1';
            }
            cout << "YES\n";
            cout << ans << "\n";
        }else cout << "NO\n";
    }
}
