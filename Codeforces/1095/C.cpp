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
    int n, k;
    cin >> n >> k;
    if(k > n){
        cout << "NO\n";
        return 0;
    }
    int cnt = 0;
    vector<int> p2(30, 0);
    for(int i=0;i<30;i++){
        if(n & 1 << i){
            cnt++;
            p2[i]++;
        }
    }
    if(cnt > k){
        cout << "NO\n";
        return 0;
    }
    int bp = 29;
    while(cnt < k){
        if(p2[bp]){
            p2[bp-1]+=2;
            p2[bp]--;
            cnt++;
        }else bp--;
    }
    cout << "YES\n";
    for(int i=0;i<30;i++){
        for(int j=0;j<p2[i];j++){
            cout << (1 << i) << " ";
        }
    }
}
