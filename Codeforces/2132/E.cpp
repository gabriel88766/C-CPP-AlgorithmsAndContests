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
        int n, m, q;
        cin >> n >> m >> q;
        vector<ll> a(n+m+1), b(n+m+1);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<m;i++) cin >> b[i];
        sort(a.begin(), a.end(), greater<ll>());
        sort(b.begin(), b.end(), greater<ll>());
        vector<ll> psa(n+m+1), psb(n+m+1);
        vector<pair<int, int>> aux;
        aux.push_back({0, 0});
        for(int i=1;i<=n+m;i++){
            int la = aux.back().first, lb = aux.back().second;
            // cout << a[0] << " " << a[1]
            if(a[la] > b[lb]) aux.push_back({la+1, lb});
            else aux.push_back({la, lb + 1});
        }
        for(int i=1;i<=n+m;i++){
            psa[i] = psa[i-1] + a[i-1];
            psb[i] = psb[i-1] + b[i-1];
        }
        for(int i=1;i<=q;i++){
            int x, y, z;
            cin >> x >> y >> z;
            auto xx = aux[z];
            // cout << xx.first << " " << xx.second << " " << psa[xx.first] << " " << psb[xx.second] << "\n";
            if(xx.first <= x && xx.second <= y){
                cout << psa[xx.first] + psb[xx.second] << "\n";
            }else if(xx.first > x){
                cout << psa[x] + psb[z-x] << "\n";
            }else{
                cout << psa[z-y] + psb[y] << "\n";
            }
        }
    
    }
}
