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
    string s;
    cin >> s;
    int ans = 0;
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            auto cur = s.substr(i, j-i+1);
            sort(cur.begin(), cur.end());
            cur.resize(unique(cur.begin(), cur.end()) - cur.begin());
            bool ok = true;
            for(auto x : cur){
                if(x != 'A' && x != 'C' && x != 'T' && x != 'G') ok = false;
            }
            if(ok) ans = max(ans, j-i+1);
        }
    }
    cout << ans << "\n";
}
