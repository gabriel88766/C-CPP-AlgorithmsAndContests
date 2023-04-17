#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 11;
ll dist[N][N];
void floyd(){
    for(int k=0;k<=9;k++)
        for(int i=0;i<=9;i++)
            for(int j=0;j<=9;j++)
                if(dist[i][k] < INF_LL && dist[k][j] < INF_LL)//for negative edge
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);    
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h,w;
    cin >> h >> w;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            cin >> dist[i][j];
        }
    }
    floyd();
    int ans = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int aux;
            cin >> aux;
            if(aux >= 0 && aux<=9) ans += dist[aux][1];
        }
    }
    cout << ans;
}
