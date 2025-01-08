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
        int n;
        cin >> n;
        vector<int> vx(n-1);
        int ch;
        cin >> ch;
        for(int i=0;i<n-1;i++){
            cin >> vx[i];
        }
        sort(vx.begin(), vx.end());
        auto it = lower_bound(vx.begin(), vx.end(), ch);
        if(it == vx.begin()){
            int nx = *it;
            int r = (ch + nx + 2)/2;
            while((nx - r) < r - ch) r--;
            cout << r << "\n"; 
        }else if(it == vx.end()){
            int lw = *prev(it);
            int l = (ch + lw)/2;
            while((l-lw) < ch - l) l++;
            cout << 1000000 - l + 1 << "\n";
        }else{
            int nx = *it;
            int r = (ch + nx + 2)/2;
            while((nx - r) < r - ch) r--;
            int lw = *prev(it);
            int l = (ch + lw)/2;
            while((l-lw) < ch - l) l++;
            cout << r - l + 1 << "\n";
        }
    }
}
