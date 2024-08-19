#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+1;
int cnt[N];
vector<int> dv[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            dv[j].push_back(i);
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n+1);
        for(int i=1;i<=n;i++) cin >> p[i];
        vector<vector<int>> vs(n+1), iv(n+1);
        for(int i=1;i<=n;i++){
            int g = gcd(i, p[i]);
            vs[i/g].push_back(p[i]/g);
            iv[p[i]/g].push_back(i/g);
        }
        ll ans = 0;
        for(int i=1;i<=n;i++){
            if(!vs[i].size()) continue;
            vector<int> cmp;
            for(int j=i;j<=n;j+=i){
                for(int k=0;k<iv[j].size();k++){
                    cnt[iv[j][k]]++;
                }
            }   
            for(int j=0;j<vs[i].size();j++){
                for(auto d : dv[vs[i][j]]){
                    ans += cnt[d];
                }
            }
            for(int j=i;j<=n;j+=i){
                for(int k=0;k<iv[j].size();k++){
                    cnt[iv[j][k]]--;
                }
            }
        }
        ans -= vs[1].size();
        ans /= 2;
        cout << ans << "\n";
    }
}
