#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int g[11][11];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int H, W;
    cin >> H >> W;
    string path;
    int ans = 0;
    for(int i=1;i<H;i++) path += 'D';
    for(int i=1;i<W;i++) path += 'L';
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> g[i][j];
        }
    }
    do{
        int x =1, y=1;
        set<int> nums;
        nums.insert(g[1][1]);
        for(int i=0;i<path.size();i++){
            if(path[i] == 'L') y++;
            else x++;
            nums.insert(g[x][y]);
        }
        if(nums.size() == (H+W-1)) ans++;
    }while(next_permutation(path.begin(), path.end()));
    cout << ans;
}
