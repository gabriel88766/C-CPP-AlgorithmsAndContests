#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
int k[N];
vector<int> us[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> k[i];
        for(int j=0;j<k[i];j++){
            int x;
            cin >> x;
            us[x].push_back(i);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        int cur = 0;
        int x;
        cin >> x;
        for(auto &y : us[x]){
            k[y]--;
            if(k[y] == 0) cur++;
        }
        ans += cur;
        cout << ans << "\n";
    }
}
