#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
int nim[N];
bool vis[N][200];
void init(){
    for(int i=1;i<N;i++){
        for(int k=0;;k++){
            if(!vis[i][k]){
                nim[i] = k;
                break;
            }
        }
        for(int j=2*i;j<N;j+=i){
            vis[j][nim[i]] = 1;
        }
        
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int x = 0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int y;
        cin >> y;
        x ^= nim[y];
    }
    if(x == 0) cout << "Bruno\n";
    else cout << "Anna\n";
}
