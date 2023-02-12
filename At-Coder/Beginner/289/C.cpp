#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int N, M;
    cin >> N >> M;
    vector<int> v[M];
    for(int i=0;i<M;i++){
        int n;
        cin >> n;
        for(int j=0;j<n;j++){
            int aux;
            cin >> aux;
            v[i].push_back(aux);
        }
    }
    int cnt = 0;
    for(int i=1;i < (1 << M); i++){
        vector<bool> in(N+1, false);
        for(int j=0;j<M;j++){
            if(i & (1 << j)){
                for(int k=0;k<v[j].size();k++){
                    in[v[j][k]] = true;
                }
            }
        }
        bool ok = true;
        for(int j=1;j<=N;j++) if(!in[j]) ok = false;
        if(ok) cnt++;
    }
    cout << cnt;

}
