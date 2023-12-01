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
        vector<char> c(26, 0);
        vector<bool> in(26, false);
        string ans;
        int cnt = 0;
        for(int i=0;i<n;i++){
            int cl = s[i] - 'a';
            if(!c[cl]){
                cnt++;
                for(int j=0;j<26;j++){
                    if(cl == j) continue;
                    if(in[j]) continue;
                    in[j] = true;
                    c[cl] = j + 'a';
                    break;
                }
            } 
            ans += c[s[i] - 'a'];
        }
        cout << ans << "\n";
    }
}
