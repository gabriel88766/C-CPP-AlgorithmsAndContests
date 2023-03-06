#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int qt[9];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, minv = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        if(aux < 400) qt[0]++;
        else if(aux < 800) qt[1]++;
        else if(aux < 1200) qt[2]++;
        else if(aux < 1600) qt[3]++;
        else if(aux < 2000) qt[4]++;
        else if(aux < 2400) qt[5]++;
        else if(aux < 2800) qt[6]++;
        else if(aux < 3200) qt[7]++;
        else qt[8]++;
    }
    for(int i=0;i<8;i++) if(qt[i]) minv++;
    
    cout << max(minv, 1) << " " << minv+qt[8]; 
}
