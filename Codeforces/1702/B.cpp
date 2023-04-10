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
        int cnt = 1, cnt2 = 0;
        vector<bool> mp(26, false);
        for(int i=0;i<s.size();i++){
            if(!mp[s[i]-'a']){
                if(cnt2 == 3){
                    cnt++;
                    for(int j=0;j<26;j++) mp[j] = false;
                    cnt2 = 1;
                }else cnt2++;
                mp[s[i]-'a'] = true;
            }
        }
        cout << cnt << "\n";
    }
}
