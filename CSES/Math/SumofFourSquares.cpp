#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e7+3;
bool pos[N];
pair<int, int> ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    for(int i=0;i*i<N;i++){
        for(int j=0;i*i+j*j<N;j++){
            pos[i*i+j*j] = true;
            ans[i*i+j*j] = {i, j};
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=0;i<=n;i++){
            if(pos[i] && pos[n-i]){
                cout << ans[i].first << " " << ans[i].second << " " << ans[n-i].first << " " << ans[n-i].second << "\n";
                break;
            }
        }
    }
}
