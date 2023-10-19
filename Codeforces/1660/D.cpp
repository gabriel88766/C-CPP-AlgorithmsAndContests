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
        cin >> n;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        pair<int,int> ans = {n, 0};
        int maxcnt = 0;
        vector<int> z = {0};
        for(int i=1;i<=n;i++){
            if(v[i] == 0) z.push_back(i);
        }
        z.push_back(n+1);
        for(int i=0;i<z.size()-1;i++){
            int l = z[i], r = z[i+1];
            if(l == r-1) continue;
            else{
                //analyze [l+1, r-1];
                int f2 = -1, l2 = -1, cnt = 0, cnt2 = 0, fn = -1, ln = -1;
                for(int j=l+1; j<=r-1;j++){
                    if(abs(v[j]) == 2){
                        if(f2 == -1) f2 = j;
                        l2 = j;
                        cnt++;
                    }
                    if(v[j] < 0){
                        if(fn == -1) fn = j;
                        ln = j;
                        cnt2++;
                    }
                }
                if(cnt2 % 2 == 0){
                    //all array
                    if(cnt > maxcnt){
                        maxcnt = cnt;
                        ans = {l, n-r+1};
                    }
                }else{
                    int c1 = 0, c2 = 0;
                    for(int j=fn+1;j<=r-1;j++){
                        if(abs(v[j]) == 2) c1++;
                    }
                    for(int j=l+1;j<=ln-1;j++){
                        if(abs(v[j]) == 2) c2++;
                    }
                    if(c1 > c2 && c1 > maxcnt){
                        l = fn;
                        maxcnt = c1;
                        ans = {l, n-r+1};
                    }else if(c2 > maxcnt){
                        r = ln;
                        maxcnt = c2;
                        ans = {l, n-r+1};
                    }
                }
                
            }
        }
        cout << ans.first << " " << ans.second << "\n";
    }
}
