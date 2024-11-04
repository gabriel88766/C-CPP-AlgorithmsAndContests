#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll lt[N], gt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> rv(n+1,vector<int>(k+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            cin >> rv[i][j];
            rv[i][j] |= rv[i-1][j];
        }
    }
    memset(lt, 63, sizeof(lt));
    memset(gt, 0, sizeof(gt));
    for(int i=1;i<=q;i++){
        int m;
        cin >> m;
        vector<int> ch;
        for(int j=0;j<m;j++){
            ll r, c;
            char s;
            cin >> r >> s >> c;
            ch.push_back(r);
            if(s == '>') gt[r] = max(gt[r], c);
            if(s == '<') lt[r] = min(lt[r], c);
        }
        sort(ch.begin(), ch.end());
        ch.resize(unique(ch.begin(), ch.end()) - ch.begin());
        int l = 1, r = n;
        for(auto x : ch){
            if(lt[x] <= gt[x]){
                l = n+1;
                r = 0;
            }else{
                int fn = n, ln = 1;
                if(rv[fn][x] <= gt[x] || rv[ln][x] >= lt[x]){
                    //impossible
                    fn = n+1;
                    ln = 0;
                }else{
                    assert(rv[fn][x] > gt[x] && rv[ln][x] < lt[x]);
                    for(int j=n/2;j>=1;j>>=1){
                        while(fn-j >= 1 && rv[fn-j][x] > gt[x]) fn -= j;
                        while(ln+j <= n && rv[ln+j][x] < lt[x]) ln += j;
                    }
                }
                l = max(l, fn);
                r = min(r, ln);
            }
            lt[x] = INF_LL;
            gt[x] = 0;
        }
        if(l <= r) cout << l << "\n";
        else cout << "-1\n";
    }
}
