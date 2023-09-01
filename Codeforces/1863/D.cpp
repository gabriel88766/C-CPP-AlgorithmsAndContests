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
        int n, m;
        cin >> n >> m;
        vector<vector<char>> v(n, vector<char> (m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> v[i][j];
            }
        }
        bool ok = true;
        for(int i=0;i<n;i++){
            //check U in rows
            int cnt = 0, aux;
            for(int j=0;j<m;j++){
                if(v[i][j] == 'U'){
                    cnt++;
                    if(cnt % 2) aux = j;
                    else{
                        v[i][aux] = 'B';
                        v[i+1][aux] = 'W';
                        v[i][j] = 'W';
                        v[i+1][j] = 'B';
                    }
                }
            }
            if(cnt % 2) ok = false;
        }
        for(int i=0;i<m;i++){
            int cnt = 0, aux;
            for(int j=0;j<n;j++){
                if(v[j][i] == 'L'){
                    cnt++;
                    if(cnt % 2) aux = j;
                    else{   
                        v[aux][i] = 'B';
                        v[aux][i+1] = 'W';
                        v[j][i] = 'W';
                        v[j][i+1] = 'B';
                    }
                }
            }
            if(cnt % 2) ok = false;
        }
        if(!ok) cout << "-1\n";
        else{
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout << v[i][j];
                }
                cout << "\n";
            }
        }
    }
}
