#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
ll ans[N], aux[N], aux2[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        ll cur = 0;
        for(int j=0;j<=cnt;j++){
            cur += ans[j];
        }
        if(x == 0){
            ll cur = 0;
            for(int i=0;i<=cnt;i++){
                cur += ans[i];
                aux[i] = cur;
            }
            aux2[0] = aux[0];
            for(int i=1;i<=cnt+1;i++){
                aux2[i] = max(aux[i], aux[i-1]);
            }
            ans[0] = aux2[0];
            for(int i=1;i<=cnt+1;i++){
                ans[i] = aux2[i] - aux2[i-1];
            }
            cnt++;
        }else if(x < 0){
            x = abs(x);
            if(cnt-x >= 0){
                ans[0]++;
                ans[cnt-x+1]--;
            }
        }else{
            //for j = x to cnt, make st.update(x, cnt, 1);
            if(cnt >= x){
                ans[cnt+1]--;
                ans[x]++;
            }
        }
    }
    ll mv = 0;
    ll cur = 0;
    for(int i=0;i<=m;i++){
        cur += ans[i];
        mv = max(cur, mv);
    }
    cout << mv << "\n";
}
