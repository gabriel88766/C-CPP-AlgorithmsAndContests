#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


int cnt[600005];
int mid = 300001;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int h, w;
        cin >> h >> w;
        vector<string> gr(h+1);
        for(int i=1;i<=h;i++){
            cin >> gr[i];
            gr[i] = " " + gr[i];
        }
        if(h > w){
            vector<string> agr(w+1, string(h+1, ' '));
            for(int i=1;i<=h;i++){
                for(int j=1;j<=w;j++){
                    agr[j][i] = gr[i][j];
                }
            }
            gr = agr;
            swap(h, w);
        }
        assert(h <= 600);
        //O(n sqrt n) whatever.
        vector<vector<int>> ps(h+1, vector<int>(w+1));
        ll ans = 0;
        for(int i=1;i<=h;i++){
            for(int u=i;u<=h;u++){
                cnt[mid] = 1;
                for(int v=1;v<=w;v++){
                    if(gr[u][v] == '#') ps[u][v] = 1;
                    else ps[u][v] = -1;
                    ps[u][v] += (ps[u-1][v] + ps[u][v-1] - ps[u-1][v-1]);
                    ans += cnt[ps[u][v] + mid]++;
                }
                for(int v=1;v<=w;v++) cnt[ps[u][v] + mid]--;
            }
        }
        cout << ans << "\n";
    }
}
