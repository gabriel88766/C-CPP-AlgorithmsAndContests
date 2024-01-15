#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

pair<int,int> dp[5005][5005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k, v;
    cin >> n >> k >> v;
    int need = v % k;
    int sum = 0;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum < v) cout << "NO\n";
    else{
        //subset sum
        vector<int> cg(n+1);
        for(int i=1;i<=n;i++) cg[i] = a[i] % k;
        for(int i=0;i<=n;i++) for(int j=0;j<k;j++) dp[i][j] = {-2, -2};
        dp[0][0] = {-1, -1};
        for(int i=1;i<=n;i++){
            for(int j=0;j<k;j++){
                dp[i][j] = dp[i-1][j];
            }
            for(int j=0;j<k;j++){
                if(dp[i][j] != make_pair(-1, -1) && dp[i][j] != make_pair(-2, -2)) continue;
                else{
                    int ol = (k + j - cg[i]) % k;
                    auto p = dp[i-1][ol];
                    if(p != make_pair(-2, -2)){
                        dp[i][j] = {i-1, ol};
                    }
                }
            }
        }
        vector<int> st;
        if(need == 0){
            cout << "YES\n";
            for(int i=2;i<=n;i++){
                if(a[i] != 0){
                    int xt = cg[i] ? 1 : 0;
                    cout << xt + a[i]/k << " " << i << " " << 1 << "\n";
                    a[1] += a[i];
                }
            }
            if(v != 0){
                cout << v/k << " " << 1 << " " << 2 << "\n";
            }
            return 0;
        }
        if(dp[n][need] != make_pair(-2, -2)){
            cout << "YES\n";
            int aux1 = n, aux2 = need;
            while(dp[aux1][aux2] != make_pair(-1, -1)){
                if(dp[aux1-1][aux2] == dp[aux1][aux2]) aux1--;
                else{
                    st.push_back(aux1);
                    auto [n1, n2] = dp[aux1][aux2];
                    aux1 = n1, aux2 = n2;
                }
            }
            vector<bool> used(n+1, false);
            sort(st.begin(), st.end());
            used[st[0]] = true;
            for(int i=1;i<st.size();i++){
                used[st[i]] = true;
                if(a[st[i]] > 0){
                    int xt = cg[st[i]] ? 1 : 0;
                    cout << xt + a[st[i]]/k << " " << st[i] << " " << st[0] << "\n";
                    a[st[0]] += a[st[i]];
                }
            }
            int oi = -1;
            for(int i=1;i<=n;i++){
                if(!used[i]){
                    oi = i;
                    used[i] = true;
                    break;
                }
            }
            if(oi != -1){
                for(int i=1;i<=n;i++){
                    if(used[i]) continue;
                    if(a[i] != 0){
                        int xt = cg[i] ? 1 : 0;
                        cout << xt + a[i]/k << " " << i << " " << oi << "\n";
                        a[oi] += a[i];
                    }
                }
                if(a[st[0]] > v){
                    cout << (a[st[0]]-v)/k << " " << st[0] << " " << oi << "\n";
                }else if(a[st[0]] == v){
                    //ok;
                }else{
                    cout << (v-a[st[0]])/k << " " << oi << " " << st[0] << "\n";
                }
            }else{
                oi = st[0] == 1 ? 2 : 1;
                if(a[st[0]] > v){
                    cout << (a[st[0]]-v)/k << " " << st[0] << " " << oi << "\n";
                }else if(a[st[0]] == v){
                    //ok;
                }else{
                    cout << (v-a[st[0]])/k << " " << oi << " " << st[0] << "\n";
                }   
            }
        }else cout << "NO\n";
    }
}
