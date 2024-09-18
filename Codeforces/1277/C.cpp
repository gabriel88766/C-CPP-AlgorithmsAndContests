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
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'o'){
                bool t1 = false, t2 = false;
                if(i+2 < s.size() && s[i+1] == 'n' && s[i+2] == 'e') t1 = true;
                if(i >= 2 && s[i-1] == 'w' && s[i-2] == 't') t2 = true;
                if(t1 || t2){
                    if(t1 && t2) ans.push_back(i+1);
                    else if(t1) ans.push_back(i+2);
                    else ans.push_back(i);
                }
            }
        }
        cout << ans.size() << "\n";
        for(auto x : ans) cout << x << " ";
        cout << "\n"; 
    }
}
