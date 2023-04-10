#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

set<string> rem[105];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    string s;
    cin >> n >> k >> s;
    rem[0].insert(s);
    int cnt = 1;
    int ans = 0;
    bool ok = false;
    for(int i=1;i<=n;i++){
        for(auto x : rem[i-1]){
            for(int j=0; j<x.size();j++){
                if(j == 0) rem[i].insert(x.substr(1, x.size()-1));
                else if(j == (x.size()-1)) rem[i].insert(x.substr(0, j));
                else rem[i].insert(x.substr(0, j) + x.substr(j+1, x.size()-j-1));
            }
            if(cnt + rem[i].size() >= k){
                ans += (k-cnt)*i;
                ok = true;
                break;
            }
        }
        if(ok) break;
        cnt += rem[i].size();
        ans += rem[i].size()*i;
    }
    if(ok) cout << ans;
    else cout << -1;
}
