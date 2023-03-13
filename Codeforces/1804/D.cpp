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
    int n, m;
    cin >> n >> m;
    int dw = m/4, ow = m/2;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int minoc = 0, maxoc = 0;

    for(int i=0;i<n;i++){
        int cnt = 0;

        for(int j=0;j<m;j++){
            if(v[i][j] == '1'){
                if(cnt < dw && j < (m-1) && v[i][j+1] == '1'){
                    j++;
                    cnt++;
                }
                minoc++;
            }
        }
        cnt = 0;
        int lj = -1;
        maxoc += (dw+ow);
        for(int j=0;j<m;j++){
            if(v[i][j] == '0'){
                if(cnt < dw ){
                    if(j > 0 && v[i][j-1] == '1' && lj != (j-1)) { lj = j-1; cnt++;}
                    else if(j < (m-1) && v[i][j+1] == '1'){lj = j+1; cnt++;}
                    else{
                        maxoc--;
                        if(j < (m-1) && v[i][j+1] == '0'){cnt++; j++;}
                    }
                }else maxoc--;
            }
        }

    }
    cout << minoc << " " << maxoc;

}
