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
        int n;
        string s;
        cin >> n >> s;
        vector<int> c(3, 0); //I, L, T
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(s[i] == 'I') c[0]++;
            else if(s[i] == 'L') c[1]++;
            else c[2]++;
        }
        vector<char> oc = {'I', 'L', 'T'};
        auto insertlet = [&](string &s, vector<int> &ans, char let){
            vector<char> ol;
            for(auto &x : oc) if(x != let) ol.push_back(x);
            for(int i=1;i<s.size();i++){
                if(min(s[i], s[i-1]) == min(ol[0], ol[1]) && max(s[i], s[i-1]) == max(ol[0], ol[1])){
                    ans.push_back(i);
                    s = s.substr(0, i) + let + s.substr(i, s.size()-i);
                    if(let == 'I') c[0]++;
                    else if(let == 'L') c[1]++;
                    else c[2]++;
                    return true;
                }
            }
            return false;
        };
        bool flag = false;
        while(c[0] != c[1] || c[1] != c[2]){
            int mn = min({c[0], c[1], c[2]});
            int mx = max({c[0], c[1], c[2]});
            vector<char> pl;
            if(c[0] == mn) pl.push_back('I');
            if(c[1] == mn) pl.push_back('L');
            if(c[2] == mn) pl.push_back('T');
            if(pl.size() == 1){
                if(!insertlet(s, ans, pl[0])){
                    if(c[0] == mx && insertlet(s, ans, 'I')) continue;
                    else if(c[1] == mx && insertlet(s, ans, 'L')) continue;
                    else if(c[2] == mx && insertlet(s, ans, 'T')) continue;
                    break;
                }else continue;
            }
            assert(pl.size() == 2);
            bool ok = false;
            for(auto &c : pl){
                if(insertlet(s, ans, c)){
                    ok = true;
                    break;
                }
            }
            if(!ok){
                assert(flag == false);
                flag = true;
                for(auto &c : oc){
                    if(c != pl[0] && c != pl[1]){
                        if(insertlet(s, ans, c)){
                            ok = true;
                            break;
                        }
                    }
                }
            }
            if(!ok) break;
        }
        if(c[0] != c[1] || c[1] != c[2]){
            cout << "-1\n";
        }else{
            cout << ans.size() << "\n";
            for(auto &x : ans) cout << x << " ";
            cout << "\n";
        } 
    }
}
