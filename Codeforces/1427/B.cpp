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
        vector<int> v;
        int lw = -1;
        int ans = 0, cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'W'){
                ans++;
                if(lw != -1){
                    if(i - lw - 1) v.push_back(i - lw - 1);
                    else ans++;
                }
                lw = i;
            }else cnt++;
        }
        if(lw == -1){
            if(k) cout << 2*k-1 << "\n";
            else cout << "0\n";
            continue;
        }
        sort(v.begin(), v.end());
        for(auto x : v){
            if(k >= x){
                ans += 2*x+1;
                k -= x;
                cnt -= x;
            }else{
                ans += 2*k;
                k = 0;
                cnt -= k;
                break;
            }
        }
        ans += 2*min(k, cnt);
        cout << ans << "\n";

        

    }
}
