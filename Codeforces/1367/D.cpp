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
        int m;
        cin >> m;
        vector<int> v(m), ans(m, -1);
        for(int i=0;i<m;i++) cin >> v[i];
        //up to O(m^3)
        vector<int> st;
        for(int i=0;i<m;i++){
            if(v[i] == 0){
                ans[i] = 0;
                st.push_back(i);
            }
        }
        int cur = 1;
        while(st.size() != m){
            vector<int> add;
            for(int j=0;j<m;j++){
                if(ans[j] == -1){
                    int curs = 0;
                    for(auto k : st) curs += abs(k - j);
                    if(curs == v[j]){
                        add.push_back(j);
                        ans[j] = cur;
                    }
                }
            }
            for(auto x : add) st.push_back(x);
            cur++;
        }
        assert(cur <= 26);
        vector<int> cnt(26, 0);
        vector<int> cnt2(26, 0);
        for(auto c : s) cnt[c - 'a']++;
        for(auto x : ans) cnt2[x]++;
        int cx = 0;
        string anss(m, '.');
        for(int j=25;j>=0;j--){
            if(cnt2[cx] == 0) break;
            if(cnt2[cx] <= cnt[j]){
                for(int k=0;k<m;k++){
                    if(ans[k] == cx){
                        anss[k] = (char)('a' + j);
                    }
                }
                cx++;
            }
        }
        cout << anss << "\n";
    }
}
