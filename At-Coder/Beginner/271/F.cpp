#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int gr[20][20];
vector<int> bc1[20], bc2[20];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> gr[i][j];
        }
    }
    int x = n-1;
    for(int i=0;i<(1 << x);i++){
        int xx = 0, yy = 0;
        int xs = gr[xx][yy];
        for(int j=0;j<x;j++){
            if(i & (1 << j)){
                yy++;
            }else xx++;
            xs ^= gr[xx][yy];
        }
        // val1[i] = xs;
        bc1[__builtin_popcount(i)].push_back(xs);
        xx = n-1, yy = n-1;
        xs = 0;
        for(int j=0;j<x;j++){
            xs ^= gr[xx][yy];
            if(i & (1 << j)){
                yy--;
            }else xx--;
        }
        bc2[__builtin_popcount(i)].push_back(xs);
    }
    ll ans = 0;
    for(int i=0;i<=x;i++){
        sort(bc1[i].begin(), bc1[i].end());
        sort(bc2[x-i].begin(), bc2[x-i].end());
        int p0 = 0, p1 = 0;
        while(p0 < bc1[i].size() && p1 < bc2[x-i].size()){
            if(bc1[i][p0] < bc2[x-i][p1]) p0++;
            else if(bc1[i][p0] > bc2[x-i][p1]) p1++;
            else{
                ll p2 = p0, p3 = p1;
                while(p2 + 1 < bc1[i].size() && bc1[i][p2+1] == bc1[i][p0]) p2++;
                while(p3 + 1 < bc2[x-i].size() && bc2[x-i][p3+1] == bc2[x-i][p1]) p3++;
                ans += (p2 - p0 +1) * (p3 - p1 + 1);
                p0 = p2 + 1;
                p1 = p3 + 1;
            }
        }
    }
    cout << ans << "\n";
}
