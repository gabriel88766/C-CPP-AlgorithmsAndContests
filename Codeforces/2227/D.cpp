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
        vector<int> v(2*n);
        vector<int> p0;
        for(int i=0;i<2*n;i++){
            cin >> v[i];
            if(v[i] == 0) p0.push_back(i);
        }
        int ans = 1;
        for(auto x : p0){
            for(int i=1;;i++){
                if(x - i < 0 || x + i >= 2*n || v[x - i] != v[x + i]){
                    vector<int> has(n+1);
                    for(int j=0;j<i;j++) has[v[x - j]] = true;
                    for(int j=0;;j++){
                        if(!has[j]){
                            ans = max(ans, j);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        int p1 = min(p0[0], p0[1]);
        int p2 = max(p0[0], p0[1]);
        while(p2 - 1 >= p1 + 1){
            p2--;
            p1++;
        }
        assert(p2 >= p1);
        assert(p2 <= p1 + 1);
        vector<bool> has(n+1);
        while(p1 >= 0 && p2 < 2*n){
            if(v[p1] == v[p2]){
                has[v[p1]] = true;
            }else break;
            p1--;
            p2++;
        }
        for(int j=0;;j++){
            if(!has[j]){
                ans = max(ans, j);
                break;
            }
        }
        cout << ans << "\n";
    }
}
