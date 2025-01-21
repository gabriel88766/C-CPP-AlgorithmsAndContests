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
        vector<int> pl(2*n+1);
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i].first;
            pl[a[i].first] = i;
        }
        for(int i=0;i<n;i++){
            cin >> a[i].second;
            pl[a[i].second] = i;
        }
        vector<bool> vis(2*n+1, false);
        bool ok = true;
        int sw = 0;
        int right = INF_INT;
        vector<int> ord;
        vector<int> bi;
        for(int i=2*n;i>=1;i--){
            if(vis[i]) continue;
            int j = pl[i];
            bool ssw = false;
            if(a[j].first != i){
                sw++;
                ssw = true;
                swap(a[j].first, a[j].second);
            }
            vis[a[j].first] = vis[a[j].second] = true;
            if(right < a[j].second){
                ok = false;
                break;
            }
            right = a[j].second;
            if(a[j].first == 2*n - 2*ord.size()) bi.push_back(ord.size());
            ord.push_back(j);
            if(ssw) swap(a[j].first, a[j].second);
        }
        
        if(ok){
            vector<pair<int, int>> sums;
            bi.push_back(ord.size());
            int ts = 0;
            bool ok2 = false;
            for(int j=1;j<bi.size();j++){
                int cs = 0;
                int sz = bi[j] - bi[j-1];
                for(int k=bi[j-1];k<bi[j];k++){
                    int ci = ord[k];
                    if(a[ci].first < a[ci].second) cs++;
                }
                ts += cs;
                if((sz - cs) % 2 != cs % 2) ok2 = true;
            }
            if(ts % 2 == 0 || ok2) cout << "YES\n";
            else cout << "NO\n";
        }else cout << "NO\n";
    }
}
 