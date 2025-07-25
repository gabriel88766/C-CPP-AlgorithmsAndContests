#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+2;
int cnt[N];
bool rc[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    for(int i=1;i<N;i++){
        if(cnt[i] == 1 && rc[i] == false) ans++;
        if(cnt[i]){
            for(int j=i;j<N;j+=i) rc[j] = true;
        }
    }
    cout << ans << "\n";
}
