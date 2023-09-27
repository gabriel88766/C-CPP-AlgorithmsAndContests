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
        int n, k;
        cin >> n >> k;
        cin >> s;
        vector<pair<int,int>> vp(k);
        for(int i=0;i<k;i++){
            cin >> vp[i].first;
        }
        for(int i=0;i<k;i++){
            cin >> vp[i].second;
        }
        vector<int> loc(n+1);
        vector<vector<int>> cnt(k);
        int p = 0;
        for(int i=1;i<=n;i++){
            if(vp[p].second < i) p++;
            loc[i] = p;
        }
        for(int i=0;i<k;i++){
            //
            int x = vp[i].second - vp[i].first + 2;
            cnt[i].assign(x/2, 0);
        }
        int q;
        cin >> q;
        for(int i=0;i<q;i++){
            int x;
            cin >> x;
            cnt[loc[x]][min(x-vp[loc[x]].first, vp[loc[x]].second - x)] ^= 1;
        }
        for(int i=0;i<k;i++){
            int l = vp[i].first, r = vp[i].second;
            int cur = 0;
            for(int j = 0; j < cnt[i].size(); j++){
                if(cnt[i][j] ^ cur){
                    swap(s[l-1+j], s[r-1-j]);
                }
                if(cnt[i][j]) cur ^= 1;
            }   
        }
        cout << s << "\n";
    }
}
