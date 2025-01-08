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
    vector<pair<pair<int,int>, char>> vp(m);
    for(int i=0;i<m;i++){
        cin >> vp[i].first.first >> vp[i].first.second >> vp[i].second;
    }
    sort(vp.begin(), vp.end());
    int x = n;
    int p = 0;
    while(p < m){
        int p2 = p;
        while(p2 + 1 < m && vp[p2+1].first.first == vp[p].first.first) p2++;
        int ll = 0, rr = n;
        for(int i=p;i<=p2;i++){
            if(vp[i].second == 'W') rr = min(rr, vp[i].first.second - 1);
            else ll = max(ll, vp[i].first.second);
        }
        if(x >= ll && rr >= ll) x = min(rr, x);
        else{
            x = -1;
            break;
        }
        p = p2 + 1;
    }
    if(x != -1) cout << "Yes\n";
    else cout << "No\n";
}
