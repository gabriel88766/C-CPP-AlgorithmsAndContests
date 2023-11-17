#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cnt = 0;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        vector<int> cnt(n+1, 0);
        int x = 0;
        for(int i=0;i<20;i++){
            int qt = 1 << i;
            if(x + qt <= n){
                x += qt;
                cnt[i] = qt;
            }else{
                qt = n - x;
                x = n;
                cnt[i] = qt;
                break;
            }
        }
        int ttd = 0;
        for(int i=0;i<=n;i++) ttd += cnt[i] * i;
        if(ttd > d) cout << "NO\n";
        else{
            while(ttd < d){
                bool ok = false;
                for(int i=1;i<=n;i++){
                    if(cnt[i] > 1 && 2*(cnt[i] - 1) >= (cnt[i+1] + 1)){
                        cnt[i]--;
                        cnt[i+1]++;
                        ok = true;
                        ttd++;
                        break;
                    }
                }
                if(!ok) break;
            }   
            if(ttd != d){
                int x = (n * (n-1))/2;
                assert(d > x);
                 cout << "NO\n";
            }
            else{
                cout << "YES\n";
                map<int,int> mp[n];
                mp[0][1] = 2;
                int v = 1;
                for(int i=1;i<=n;i++){
                    if(cnt[i]){
                        for(int j=0;j<cnt[i];j++){
                            auto it = mp[i-1].begin();
                            ++v;
                            cout << it->first << " ";
                            mp[i][v] = 2;
                            if(it->second == 1) mp[i-1].erase(it);
                            else mp[i-1][it->first]--;
                        }
                    }
                }
                cout << "\n";
            }
        }

    }
}
