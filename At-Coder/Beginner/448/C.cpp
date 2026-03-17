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
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> vp;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        vp.push_back({x, i});
    }
    sort(vp.begin(), vp.end());
    for(int i=1;i<=q;i++){
        int k;
        cin >> k;
        vector<int> cq(k);
        for(int j=0;j<k;j++) cin >> cq[j];
        bool ok = true;
        int p = 0;
        while(ok){
            ok = false;
            for(int j=0;j<k;j++) if(vp[p].second == cq[j]) ok = true;
            if(ok) p++;
        }
        cout << vp[p].first << "\n";    
    }
}
