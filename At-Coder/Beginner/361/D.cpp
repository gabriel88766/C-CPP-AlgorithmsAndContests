#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n;
map<string, int> dp;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s, t;
    cin >> n >> s >> t;
    s += "__";
    t += "__";
    dp[s] = 0;
    queue<string> q;
    q.push(s);
    while(!q.empty()){
        auto str = q.front();
        q.pop();
        int ind;
        for(int i=0;i<=n;i++){ 
            if(str[i] == '_'){
                ind = i;
                break;
            }
        }
        for(int i=0;i<=n;i++){
            if(str[i] != '_' && str[i+1] != '_'){
                string ns = str;
                swap(ns[ind], ns[i]);
                swap(ns[ind+1], ns[i+1]);
                if(!dp.count(ns)){
                    dp[ns] = dp[str] + 1;
                    q.push(ns);
                }
            }
        }
    }



    if(dp.count(t)) cout << dp[t] << "\n";
    else cout << "-1\n";
}
