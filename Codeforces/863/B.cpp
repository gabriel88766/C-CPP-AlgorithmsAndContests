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
    int n;
    cin >> n;
    vector<int> a(2*n);
    for(int i=0;i<2*n;i++) cin >> a[i];
    int ans = INF_INT;
    for(int i=0;i<2*n;i++){
        for(int j=i+1;j<2*n;j++){
            //i and j are the chosen 
            vector<int> xx;
            for(int k=0;k<2*n;k++){
                if(k != i && k != j) xx.push_back(a[k]);
            }
            sort(xx.begin(), xx.end());
            int cur = 0;
            for(int i=0;i<xx.size();i+=2){
                cur += xx[i+1] - xx[i];
            }
            ans = min(ans, cur);
        }
    }
    cout << ans << "\n";
}
