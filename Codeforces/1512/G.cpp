#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e7+1;
int sd[N];
int ans[N];
int cnt = 0;
void init(){
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            cnt++;
            sd[j] += i;
        }
    }
    for(int i=1;i<N;i++){
        if(sd[i] < N && !ans[sd[i]]){
            ans[sd[i]] = i;
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(ans[n]) cout << ans[n] << "\n";
        else cout << "-1\n";
    }
}