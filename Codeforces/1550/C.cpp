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
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        int ans = 0;
        for(int i=1;i<=n;i++){
            vector<int> cv;
            for(int j=i;j<=n;j++){
                cv.push_back(v[j]);
                bool ok = true;
                for(int w=0;w<cv.size();w++){
                    for(int x=w+1;x<cv.size();x++){
                        for(int y=x+1;y<cv.size();y++){
                            if(cv[w] <= cv[x] && cv[x] <= cv[y]) ok = false;
                            if(cv[w] >= cv[x] && cv[x] >= cv[y]) ok = false;
                        }
                    }
                }
                if(ok) ans++;
                else break;
            }
        }
        cout << ans << "\n";
    }
}
