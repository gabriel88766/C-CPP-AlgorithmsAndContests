#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


int calc(pair<int,int> &p, vector<int> &v){
    int maxl = 0, l = 0;
    int n = v.size();
    for(int i=0;i<2*n;i++){
        if(v[i%n] > v[(i+1)%n]){
            if(i - l + 1 > maxl){
                maxl = i - l + 1;
                p = {l % n, i % n};
            }
            l = i+1;
        }
    }
    return maxl;
}
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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        int x1 = *max_element(v.begin(), v.end());
        int x2 = *min_element(v.begin(), v.end());
        if(x1 == x2){
            cout << "0\n";
            continue;
        }
        int maxl1, maxl2;
        pair<int,int> p1, p2;
        maxl1 = calc(p1, v);
        reverse(v.begin(), v.end());
        maxl2 = calc(p2, v);
        //cout << maxl1 << " " << p1.first << " " << p1.second << " and ";
        //cout << maxl2 << " " << p2.first << " " << p2.second << "\n";
        int ans = INF_INT;
        if(maxl1 == n || maxl2 == n){
            if(maxl1 == n){
                ans = min(ans, n-p1.second-1);
                ans = min(ans, 2 + p1.first);
            }
            if(maxl2 == n){
                ans = min(ans, n-p2.second);
                ans = min(ans, 1+p2.first);
            }
            cout << ans << "\n";
        }else cout << "-1\n";
    }
}
