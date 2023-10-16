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
        deque<int> v[26];
        for(int i=0;i<n;i++){
            v[s[i]-'a'].push_back(i+1);
        }
        int mcur = 0;
        vector<int> dp(n+1, 0);
        for(int i=1;i<=n;i++){
            v[s[i-1]-'a'].pop_front();
            if(v[s[i-1]-'a'].size()){
                dp[v[s[i-1]-'a'][0]] = mcur + 1;
            }
            mcur = max(dp[i], mcur);
        }
        cout << n - 2*mcur << "\n";
        
    }
}
