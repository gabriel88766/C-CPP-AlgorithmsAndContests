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
        string ord = "";
        set<char> st;
        for(int i=s.size()-1;i>=0;i--){
            if(!st.count(s[i])){
                st.insert(s[i]);
                ord += s[i];
            }
        }
        reverse(ord.begin(), ord.end());
        bool ok = false;
        vector<int> cnt(26, 0);
        string ans;
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']++;
            int sz = 0;
            for(int j=0;j<ord.size();j++){
                sz += (j+1) * cnt[ord[j]-'a'];
            }
            if(sz == s.size()){
                ans = s.substr(0, i+1);
                ok = true;
            }else if(sz > s.size()) break;
        }
        

        if(ok){
            string xx = ans;
            string aux = ans;
            for(auto x : ord){
                string news = "";
                for(auto u : aux){
                    if(u != x) news += u;
                }
                xx += news;
                aux = news;
            }
            if(xx == s) cout << ans << " " << ord << "\n";
            else cout << "-1\n";
        }else cout << "-1\n";
        
    }
}
