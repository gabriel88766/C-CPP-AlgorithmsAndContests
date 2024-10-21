#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 806;
int gr[N][N];
ll c1[N*N], c2[N*N];
ll cd[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("bunny_hopscotch_input.txt", "r", stdin); //test input
    freopen("out.txt", "w", stdout); //test input
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int r, c;
        ll k;
        cin >> r >> c >> k;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cin >> gr[i][j];
            }
        }
        // for rows - here cols equal distance is allowed
        for(int d=1;d<=r-1;d++){
            for(int i=1;i<=r;i++){
                if(i + d > r) break;
                int j = i + d;
                for(int z=1;z<=c;z++){
                    c1[gr[i][z]]++;
                    c2[gr[j][z]]++;
                    if(z > d + 1){
                        c1[gr[i][z-d-1]]--;
                        c2[gr[j][z-d-1]]--;
                    }
                    cd[d] += c1[gr[j][z]];
                    cd[d] += c2[gr[i][z]];
                    if(gr[i][z] == gr[j][z]) cd[d]--;
                }
                for(int z=1;z<=c;z++){
                    c1[gr[i][z]] = 0;
                    c2[gr[j][z]] = 0;
                }
            }
        }
        //for collums, equal not allowed
        for(int d=1;d<=c-1;d++){
            for(int i=1;i<=c;i++){
                if(i + d > c) break;
                int j = i + d;
                for(int z=1;z<=r;z++){
                    c1[gr[z][i]]++;
                    c2[gr[z][j]]++;
                    if(z > d){
                        c1[gr[z-d][i]]--;
                        c2[gr[z-d][j]]--;
                    }
                    cd[d] += c1[gr[z][j]];
                    cd[d] += c2[gr[z][i]];
                    if(gr[z][i] == gr[z][j]) cd[d]--;
                }
                for(int z=1;z<=r;z++){
                    c1[gr[z][i]] = 0;
                    c2[gr[z][j]] = 0;
                }
            }
        }
        //preprocessed.
        int lo = 1, hi = max(r, c) - 1;
        while(lo != hi){
            int mid = lo + (hi - lo)/2;
            ll cs = 0;
            for(int i=1;i<=r;i++){
                for(int j=1;j<=c;j++){
                    int lx = max(1, j-mid), rx = min(c, j+mid);
                    int ly = max(1, i-mid), ry = min(r, i+mid);
                    int cur = (rx-lx+1)*(ry-ly+1) - 1;
                    cs += cur;
                }
            }
            // cs /= 2;
            for(int i=1;i<=mid;i++) cs -= 2*cd[i];
            if(cs >= k) hi = mid;
            else lo = mid + 1;
        }
        cout << "Case #" << i << ": " << lo << endl;


        for(int u=1;u<=800;u++) cd[u] = 0;
    }
}
