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
        vector<string> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        int ans = 0;
        for(char a='a';a<='e';a++){
            vector<int> dif;
            for(int j=0;j<n;j++){
                int le = 0, ld = 0;
                for(auto x : v[j]){
                    if(x == a) le++;
                    else ld++;
                }
                dif.push_back(le - ld);
            }
            sort(dif.begin(), dif.end(), greater<int>());
            if(dif[0] <= 0) continue;
            else{
                int cur = dif[0];
                int cnt = 1;
                for(int j=1;j<dif.size();j++){
                    if(cur + dif[j] > 0){
                        cnt++;
                        cur += dif[j];
                    }else break;
                }
                ans = max(ans, cnt);
            }
        }
        cout << ans << "\n";
    }
}
