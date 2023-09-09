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
    for(int i=0;i<n;i++) cin >> v[i];
    int x = *max_element(v.begin(), v.end());
    int y = *min_element(v.begin(), v.end());
    int ans = 0, pos1, pos2;
    for(int i=0;i<n;i++){
        if(v[i] == x){
            pos1 = i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(v[i] == y){
            pos2 = i;
            break;
        }
    }
    if(pos2 > pos1){
        cout << n-1-pos2+pos1 << "\n";
    }else{
        cout << n-2-pos2+pos1 << "\n";
    }
}
