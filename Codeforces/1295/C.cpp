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
        string s, x;
        cin >> s >> x;
        int ans = 1;
        vector<vector<int>> ix(26);
        for(int i=0;i<s.size();i++){
            ix[s[i]-'a'].push_back(i);
        }
        int cur = -1;
        for(int i=0;i<x.size();i++){
            if(ix[x[i]-'a'].size()){
                auto it = upper_bound(ix[x[i]-'a'].begin(), ix[x[i]-'a'].end(), cur);
                if(it == ix[x[i]-'a'].end()){
                    ans++;
                    cur = *ix[x[i]-'a'].begin();
                }else{
                    cur = *it;
                }
            }else{
                ans = -1;
                break;
            }
        }
        cout << ans << "\n";
    }
}
