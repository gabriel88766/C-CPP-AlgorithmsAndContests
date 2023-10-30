#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool test(string s){
    for(int i=0;i<s.size();i++){
        if(s[i] == s[s.size()-i-1]) return true;
    }
    return false;
}
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
        int c1 = 0;
        for(int i=0;i<n;i++) if(s[i] == '1') c1++;
        if(c1 != (n-c1)) cout << "-1\n";
        else{
            vector<int> ans;
            int cnt = 0;
            while(test(s)){
                int k = s.size();
                for(int i=0;i<k;i++){
                    if(s[i] == s[k-i-1]){
                        if(s[i] == '0'){
                            ans.push_back(k-i);
                            s = s.substr(0, k-i) + "01" + s.substr(k-i, i);
                        }else{
                            ans.push_back(i);
                            s = s.substr(0, i) + "01" + s.substr(i, k-i);
                        }
                        break;
                        cnt++;
                    }
                }
            }
            cout << ans.size() << "\n";
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }
    }
}
