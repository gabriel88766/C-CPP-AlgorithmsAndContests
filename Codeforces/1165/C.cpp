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
    string s, ans;
    cin >> n >> s;
    int bp = -1;
    for(int i=0;i<s.size();i++){
        if(bp == -1) bp = i, ans += s[i];
        else{
            if(s[bp] != s[i]) bp = -1, ans += s[i];
        }
    }
    if(ans.size() % 2) ans.pop_back();
    cout << s.size()-ans.size() << "\n";
    cout << ans;
}
