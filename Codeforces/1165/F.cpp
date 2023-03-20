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
    int n, m;
    cin >> n >> m;
    vector<int> k(n+1);
    int maxd = 0;
    for(int i=1;i<=n;i++){ cin >> k[i]; maxd += 2*k[i];}
    vector<pair<int,int>> pos;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        pos.push_back({a,b});
    }
    sort(pos.begin(), pos.end(), greater<pair<int,int>>());
    int ans;
    int lo = 1, hi = maxd+1, mid;
    while(lo != hi){
        mid = (lo+hi)/2;
        int j = mid;
        vector<int> auxk = k;
        int maxr = j;
        int cur = j;
        for(int i = 0; i<m;i++){
            if(pos[i].first > j) continue;
            int minus = min(auxk[pos[i].second], min(pos[i].first, maxr));
            cur -= minus;
            auxk[pos[i].second] -= minus;
            maxr = min(pos[i].first - minus, maxr-minus);
        }
        for(int i=1;i<=n;i++){
            cur -= 2*auxk[i];
        }
        if(cur >= 0) hi = mid;
        else lo = mid+1;
    }
    cout << lo;
}