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
    string t;
    cin >> n >> t;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        if(s.size() == t.size()){
            int c = 0;
            for(int j=0;j<s.size();j++){
                if(s[j] != t[j]) c++;
            }
            if(c <= 1) ans.push_back(i);
        }
        if(s.size() == (t.size()+1)){
            int p = 0, c = 0;
            for(int j=0;j<t.size();j++){
                while(c <= 1 && t[j] != s[p]){
                    p++; c++;
                }
                p++;
            }
            if(c <= 1) ans.push_back(i);
        }
        if(s.size() == (t.size()-1)){
            int p = 0, c = 0;
            for(int j=0;j<s.size();j++){
                while(c <= 1 && s[j] != t[p]){
                    p++; c++;
                }
                p++;
            }
            if(c <= 1) ans.push_back(i);
        }
    }
    cout << ans.size() << "\n";
    for(auto x: ans) cout << x << " ";
}
