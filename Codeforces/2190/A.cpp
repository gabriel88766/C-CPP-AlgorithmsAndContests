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
        int c0 = 0, c1 = 0;
        for(auto c : s){
            if(c == '0') c0++;
        }
        int idx = -1;
        for(int i=0;i<s.size();i++){
            if(s[i] == '1') c1++;
            else c0--;
            if(c1 == c0 && c1 != 0) idx = i;
        }
        if(idx == -1) cout << "Bob\n";
        else{
            cout << "Alice\n";
            vector<int> ans;
            for(int j=0;j<=idx;j++){
                if(s[j] == '1') ans.push_back(j+1);
            }
            for(int j=idx+1;j<s.size();j++){
                if(s[j] == '0') ans.push_back(j+1);
            }
            cout << ans.size() << "\n";
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }
    }

}
