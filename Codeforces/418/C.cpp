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
    vector<vector<int>> av(101);
    av[1] = {1};
    av[2] = {3, 4};
    av[3] = {1, 2, 2};
    for(int i=4;i<=100;i++){
        int jx = -1;
        for(int j=0;j<av[i-3].size();j++){
            if(av[i-3][j] % 2 == 0) jx = j;
        }
        if(jx == -1){
            for(int j=0;j<av[i-3].size();j++){
                av[i].push_back(2*av[i-3][j]);
            }
            int bck = av[i].back();
            av[i].pop_back();
            for(int j=0;j<4;j++) av[i].push_back(bck/2);
        }else{
            for(int j=0;j<av[i-3].size();j++){
                if(j != jx) av[i].push_back(av[i-3][j]);
            }
            for(int j=0;j<4;j++) av[i].push_back(av[i-3][jx]/2);
        }
    }
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans(n, av[m]);
    for(int i=0;i<n;i++){
        int cv = av[n][i];
        for(int j=0;j<m;j++){
            ans[i][j] *= cv;
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
