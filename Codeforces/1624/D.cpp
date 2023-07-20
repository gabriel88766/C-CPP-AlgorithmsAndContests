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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> cnt(26, 0);
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']++;
        }
        int nodd = 0;
        for(int i=0;i<26;i++){
            if(cnt[i] % 2) nodd++;
        }
        int div = n - nodd;
        int m = 2*k;
        int tt = div / m;
        int rem = n - m*tt;
        if(rem >= k) cout << 2*tt+1 << "\n";
        else cout << 2*tt << "\n";
    }
}
