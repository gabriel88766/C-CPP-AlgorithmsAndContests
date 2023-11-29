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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int ml = 0, mr = 0, il, ir;
    for(int i=0;i<n;i++){
        if(ml < v[i] + i){
            ml = v[i] + i;
            il = i;
        }
        if(mr < v[i] + n - 1 - i){
            mr = v[i] + n - 1 - i;
            ir = i;
        }
    }
    int mil = v[il], mir = v[ir];
    //cout << il << " " << ir << "\n";
    for(int i=0;i<n;i++){
        if(i < il){
            mil = max(mil, v[i] + n-1-i);
        }
        if(i > il){
            mil = max(mil, v[i] + i);
        }
        if(i < ir){
            mir = max(mir, v[i] + n-1-i);
        }
        if(i > ir){
            mir = max(mir, v[i] + i);
        }
    } 
    //cout << ml << " " << mr << " " << mil << " " << mir << "\n";
    cout << min(min(ml, mr), min(mil, mir)) << "\n";
}
