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
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<char>> gr(min(n, m), vector<char>(max(n, m)));
        if(n < m){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cin >> gr[i][j];
                }
            }
        }else{
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cin >> gr[j][i];
                }
            }
            swap(n, m);
        }
        ll ans = 0;
        function<void(void)> tryit = [&](){
            for(int i=0;i<n;i++){
                vector<int> pos(n);
                ll cur = 0;
                for(int p=i;p<=min(n-1, i+k);p++){
                    for(int j=0;j<=min(m-1, k-p+i);j++){
                        if(gr[p][j] == '#') cur++;
                    }
                    pos[p] = min(m-1, k-p+i);
                }
                ans = max(ans, cur);
                for(int j=1;j<m;j++){
                    for(int p=i;p<=min(n-1, i+k);p++){
                        if(gr[p][j-1] == '#') cur--;
                    }
                    for(int p=i;p<=min(n-1, i+k);p++){
                        if(pos[p] + 1 <= m-1){
                            pos[p]++;
                            if(gr[p][pos[p]] == '#') cur++;
                        }
                    }
                    ans = max(ans, cur);
                }
            }
        };
        tryit();
        //reverse
        vector<vector<char>> rev(n, vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rev[i][j] = gr[n-i-1][j];
            }
        }
        gr = rev;
        tryit();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rev[i][j] = gr[i][m-j-1];
            }
        }
        gr = rev;
        tryit();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rev[i][j] = gr[n-i-1][j];
            }
        }
        gr = rev;
        tryit();
        cout << ans << "\n";
    }
}
 