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
    ll n, k;
    cin >> n >> k;
    vector<vector<int>> cnt(51, vector<int>(51));
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        cnt[a][b]++;
    }

    ll ans = 1;
    for(int x=1;x<=50;x++){
        for(int y=1;y<=50;y++){
            if(!cnt[x][y]) continue;
            ll cans = x + y;
            auto aux = cnt;
            aux[x][y]--;
            int ac = 1;
            vector<pair<int,int>> av;
            for(int ux=50;ux>=1;ux--){
                for(int uy=50;uy>=1;uy--){
                    while(aux[ux][uy] && ac < k){
                        av.push_back({ux, uy});
                        ac++;
                        aux[ux][uy]--;
                    }
                }
            }
            
            sort(av.begin(), av.end(), [&](pair<int,int> &u, pair<int,int> &v){
                return u.first * v.second + u.second < v.first * u.second + v.second;
            });
            for(auto [a,b]:av){
                cans = cans * a + b;   
            }
            ans = max(ans, cans);
        }
    }
    
    cout << ans << "\n";
}
