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
        string s;
        cin >> n >> k >> s;
        string s1= "", s2 = "", ans = "";
        for(int i=0;i<n;i++){
            if(i % 2) s1 += s[i];
            else s2 += s[i];
        }
        int p1 = 0, p2 = 0;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for(int i=0;i<n;i++){
            if(i % 2) ans += s1[p1++];
            else ans += s2[p2++];
        }
        if(k % 2){
            //no toggle.
            cout << ans << "\n";
        }else{
            sort(ans.begin(), ans.end());
            cout << ans << "\n";
        }
    }
}
