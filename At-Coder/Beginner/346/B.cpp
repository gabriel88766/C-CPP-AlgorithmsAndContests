#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool dp[8][8];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int w, b;
    cin >> w >> b;
    while(w >= 7 && b >= 5){
        w -= 7;
        b -= 5;
    }
    if(b > 5 || w > 7) cout << "No\n";
    else{
        string s = "wbwbwwbwbwbwwbwbwwbwbwbw";
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                auto x = s.substr(i, j-i+1);
                int cw = 0, cb = 0;
                for(auto &y : x){
                    if(y == 'w') cw++;
                    else cb++;
                }
                if(cw <= 7 && cb <= 5) dp[cw][cb] = true;
            }
        }
        dp[0][0] = true;
        if(dp[w][b]) cout << "Yes\n";
        else cout << "No\n";
    }
}
