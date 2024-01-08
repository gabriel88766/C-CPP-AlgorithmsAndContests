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
        set<char> st;
        for(int i=0;i<n;i++) st.insert(s[i]);
        int ll = -1;
        string ans;
        while(!st.empty()){
            for(auto it = st.rbegin(); it != st.rend(); it++){
                vector<bool> used(26, false);
                int ini = -1;
                for(int i=ll+1;i<n;i++){
                    if(s[i] == *it){
                        if(ini == -1) ini = i;
                        used[s[i] - 'a'] = true;
                    }else if(ini != -1){
                        used[s[i] - 'a'] = true;
                    }
                }
                bool ok = true;
                for(auto x : st){
                    if(!used[x - 'a']){
                        ok = false;
                    }
                }
                if(ok){
                    ll = ini;
                    ans += s[ll];
                    break;
                }
            }
            assert(st.count(s[ll]));
            st.erase(s[ll]);
        }
        cout << ans << "\n";
    }
}   
