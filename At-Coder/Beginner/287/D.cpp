#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s, t;
    cin >> s >> t;
    set<int> unm;
    vector<string> ans;
    for(int i=0;i<t.size();i++){
        if(s[i] != '?' && t[i] != '?' && s[i] != t[i]) unm.insert(i);
    }
    if(unm.size() == 0) ans.push_back("Yes");
    else ans.push_back("No");
    
    for(int i=(t.size()-1);i>=0;i--){
        unm.erase(i);
        int poss = s.size()-(t.size()-i);
        if(s[poss] != '?' && t[i] != '?' && s[poss] != t[i]) unm.insert(i);

        if(unm.size() == 0) ans.push_back("Yes");
        else  ans.push_back("No");
    }
    reverse(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++) cout << ans[i] << "\n";
}
