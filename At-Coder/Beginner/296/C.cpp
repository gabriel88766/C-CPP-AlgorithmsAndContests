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
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    if(x < 0){
        sort(v.begin(), v.end(), greater<int>());
        int bp = 0;
        bool ok = false;
        for(int i=1;i<n;i++){
            if(v[i]-v[bp] > x) continue;
            else if(v[i]-v[bp] == x) ok = true;
            else{
                while(v[i]-v[bp] < x) bp++;
                if(v[i]-v[bp] == x) ok = true;
            }
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }else if(x > 0){
        sort(v.begin(), v.end());
        int bp = 0;
        bool ok = false;
        for(int i=1;i<n;i++){
            if(v[i]-v[bp] < x) continue;
            else if(v[i]-v[bp] == x) ok = true;
            else{
                while(v[i]-v[bp] > x) bp++;
                if(v[i]-v[bp] == x) ok = true;
            }
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }else{ 
        cout << "Yes\n";
    }
}
