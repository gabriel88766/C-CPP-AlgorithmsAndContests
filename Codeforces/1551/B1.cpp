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
        vector<int> cnt(26, 0);
        int c1 = 0, c2 = 0;
        string s;
        cin >> s;
        for(auto x : s) cnt[x-'a']++;
        for(int i=0;i<26;i++){
            if(cnt[i] >= 2) c2++;
            else if(cnt[i] == 1) c1++;
        }
        int ans = c2 + c1/2;
        cout << ans << "\n";
    }
}
