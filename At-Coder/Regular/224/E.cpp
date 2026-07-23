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
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        string ans;
        for(auto c : s){
            ans += c;
            int x = ans.size();
            if(x >= 3 && ans[x-1] == 'A' && ans[x-2] == 'B' && ans[x-3] == 'C'){
                ans.pop_back();
                ans.pop_back();
                ans.pop_back();
            }else if(x >= 2 && ans[x-1] == 'A' && ans[x-2] == 'B'){
                ans.pop_back();
                ans.pop_back();
            }else if(ans[x-1] == 'A'){
                ans.pop_back();
            }
        }
        cout << ans.size() << "\n";
    }
}
