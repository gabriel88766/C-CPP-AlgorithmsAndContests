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
        string s;
        cin >> n;
        vector<int> adj(n+1, 0);
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a]++;
            adj[b]++;
        }
        cin >> s;
        s = " " + s;
        int ans = 0;

        //case s[1] == '?' and at least 1 leaf not equal '?'
        if(s[1] != '?'){
            int cnt1 = 0, cnt2 = 0;
            for(int i=2;i<=n;i++){
                if(adj[i] == 1){
                    if(s[i] != s[1]){
                        if(s[i] == '?') cnt2++;
                        else cnt1++;
                    }
                }
            }
            ans = cnt1 + (cnt2+1)/2;
        }else{
            int cntx = 0, cnt1 = 0, cnt0 = 0, cntl = 0;
            for(int i=2;i<=n;i++){
                if(adj[i] == 1){
                    if(s[i] == '1') cnt1++;
                    else if(s[i] == '0') cnt0++;
                    else cntl++;
                }else{
                    if(s[i] == '?') cntx++;
                }
            }
            if(cnt1 == cnt0){
                if(!(cntx % 2)) ans = cnt1 + cntl/2;
                else ans = cnt1 + (cntl+1)/2;
            }else{
                ans = max(cnt1, cnt0) + cntl/2;
            }
        }
        cout <<  ans << "\n";
    }
}
