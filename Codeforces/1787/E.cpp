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
        int n, k, x;
        cin >> n >> k >> x;
        int cur = 0;
        for(int i=1;i<=n;i++) cur ^= i; 
        int maxqt = 0;
        for(int i=1;i<=n;i++){
            if((i^x) == 0) maxqt+=2;
            else if((i^x) <= n) maxqt++;
        }
        maxqt /= 2;
        vector<bool> used(n+1, false);
        if((cur == x && k%2 && maxqt>=(k-1)) || (cur == 0 && !(k%2) && maxqt>=k)){
            int cnt = 1;
            vector<vector<int>> ans;
            if(k != 1){
                for(int i=1;i<=n;i++){
                    if(!used[i] && (i^x) <= n){
                        if((i^x) == 0) ans.push_back({i});
                        else ans.push_back({i, i^x});
                        used[i] = used[i^x] = true;
                        cnt++;
                        if(cnt == k) break;
                    }
                }
            }
            cout << "YES\n";
            int lsz = n;
            for(auto x : ans){
                cout << x.size() << " ";
                lsz -= x.size();
                for(auto y: x) cout << y << " ";
                cout << "\n";
            }
            cout << lsz << " ";
            for(int i=1;i<=n;i++) if(!used[i]) cout << i << " ";
            cout << "\n";
        }else cout << "NO\n";
    }
}
