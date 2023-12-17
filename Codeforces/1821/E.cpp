#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> calc(string &s){
    int n = s.size();
    vector<int> ans(n+1);
    ans[0] = 0;
    for(int i=1;i<=n;i++){
        ans[i] = ans[i-1] + (s[i-1] == '(' ? 1 : -1);
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
        int k;
        cin >> k;
        string s;
        cin >> s;
        int n = s.size();
        for(int i=0;i<k;i++){
            auto v = calc(s);
            vector<int> ps;
            for(int j=0;j<=n;j++) if(v[j] == 0) ps.push_back(j);
            int bst = 0, pos = -1;
            for(int j=1;j<ps.size();j++){
                int cur = 0;
                for(int x=ps[j-1]+1;x<ps[j];x++){
                    if(s[x-1] == ')') if(v[x] >= 1) cur += v[x]; 
                }
                if(cur > bst){
                    bst = cur;
                    pos = j;
                }
            }
            if(bst == 0) break;
            for(int j=ps[pos-1]+1;j<ps[pos]-1;j++){
                swap(s[j-1], s[j]);
            }
        }
        auto v = calc(s);
        ll ans = 0;
        for(int i=1;i<=n;i++){
            if(s[i-1] == ')') ans += v[i];
        }
        cout << ans << "\n";
    }
}
