#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<char>> gr(n, vector<char>(m, '.'));
    int i = 0, j = 0, d = 0;
    for(int k=0;k<q;k++){
        if(gr[i][j] == '#'){
            d--;
            if(d < 0) d = 3;
            gr[i][j] = '.';
        }else{
            d++;
            if(d == 4) d = 0;
            gr[i][j] = '#';
        }
        j += dx[d];
        i += dy[d];
        if(i < 0) i += n;
        if(i == n) i = 0;
        if(j < 0) j += m;
        if(j == m) j = 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << gr[i][j];
        }
        cout << "\n";
    }
}
