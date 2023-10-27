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
        set<int> st;
        for(int i=0;i<n;i++){
            if(s[i] != '?') st.insert(i);
        }
        for(int i=0;i<n;i++){
            if(s[i] == '?'){
                auto it = st.lower_bound(i);
                if(it == st.end()) s[i] = '1';
                else if(s[*it] == '1') s[i] = '1';
                else s[i] = '0';
            }
        }
        cout << s << "\n";
    }
}
