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
        int n = s.size();
        int ans = 0;
        for(char c = '0';c<='9';c++){
            int cur = 0;
            for(auto x : s) if(x == c) cur++;
            ans = max(ans, cur);
        }
        for(char x1 = '0';x1<='9';x1++){
            for(char x2 = '0';x2<='9';x2++){
                if(x1 == x2) continue;
                int cx = 0;
                for(auto c : s){
                    if(cx % 2){
                        if(c == x1) cx++;
                    }else{
                        if(c == x2) cx++;
                    }
                }
                ans = max(ans, cx - (cx % 2));
            }
        }
        cout << n-ans << "\n";
    }
}
