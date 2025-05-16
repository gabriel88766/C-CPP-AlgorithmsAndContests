#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
const int M = 18;
int jmp[N][M], v[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    v[n+1] = INF_INT;
    stack<pair<int, int>> st;
    st.push({INF_INT, n+1});
    for(int i=n;i>=1;i--){
        while(v[i] >= st.top().first) st.pop();
        jmp[i][0] = st.top().second;
        st.push({v[i], i});
    }
    jmp[n+1][0] = n+1;
    for(int i=1;i<M;i++){
        for(int j=1;j<=n+1;j++){
            jmp[j][i] = jmp[jmp[j][i-1]][i-1];
        }
    }
    for(int i=1;i<=q;i++){
        int l, r;
        cin >> l >> r;
        int ans = 1;
        for(int j=M-1;j>=0;j--){
            while(jmp[l][j] <= r){
                l = jmp[l][j];
                ans += 1 << j;
            }
        }
        cout << ans << "\n";
    }
}
