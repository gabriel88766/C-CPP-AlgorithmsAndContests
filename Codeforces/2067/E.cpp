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
        cin >> n;
        vector<int> v(n);
        vector<int> chk;
        int ans = 0;
        bool flag = false;
        for(int i=0;i<n;i++){
            cin >> v[i];
            if(v[i] != 0){
                chk.push_back(v[i]);
                ans++;
            }else if(!flag){
                flag = true;
                chk.push_back(v[i]);
            }
        }
        //check if chk is ok
        auto check = [&](){
            vector<int> mex(chk.size());
            vector<int> cnt(n+2, 0);
            for(int j=chk.size()-1;j>=0;j--){
                if(chk[j] <= n) cnt[chk[j]]++;
                if(j != chk.size() - 1) mex[j] = mex[j+1];
                else mex[j] = 0;
                while(cnt[mex[j]]) mex[j]++;
            }
            int mn = INF_INT;
            for(int j=0;j<chk.size() - 1;j++){
                mn = min(mn, chk[j]);
                if(mn < mex[j+1]) return false;
            }
            
            return true;
        };
        if(flag && check()) cout << ans + 1 << "\n";
        else cout << ans << "\n";

    }
}
