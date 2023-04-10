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
        int c, tc = 0;
        cin >> s >> c;
        set<pair<int,int>> costs;
        set<int> rem;
        for(int i=0;i<s.size();i++){
            int cost = s[i] - 'a' + 1;
            costs.insert({-cost, i});
            tc += cost;
        }
        while(tc > c){
            auto val = *costs.begin();
            tc += val.first;
            costs.erase(val);
            rem.insert(val.second);
        }
        string ans;
        for(int i=0;i<s.size();i++){
            if(!rem.count(i)) ans += s[i];
        }
        cout << ans << "\n";
    }
}
