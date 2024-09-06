#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
int cnt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input

    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    ll sum = 0, ans = 0;
    for(int i=N-1;i>=1;i--){
        if(cnt[i]){
            int aux = i;
            int sd = 0;
            while(aux){
                sd += aux % 10;
                aux /= 10;
            }
            sum += cnt[i];
            if(sum >= k){
                ans = sd;
                break;
            }
            cnt[i-sd] += cnt[i];
        }
    }
    cout << ans << "\n";
}
