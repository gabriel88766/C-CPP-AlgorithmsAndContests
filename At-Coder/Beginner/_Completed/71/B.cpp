#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    vector<int> mp(26, 0);
    cin >> s;
    for(int i=0;i<s.size();i++){
        mp[s[i]-'a']++;
    }
    char ans = 0;
    for(int i=0;i<26;i++){
        if(!mp[i]){
            ans = i+'a';
            break;
        }
    }
    if(ans) cout << ans;
    else cout << "None";
}
