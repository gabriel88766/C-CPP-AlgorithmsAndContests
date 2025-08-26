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
    vector<string> v(n);
    vector<int> cnt(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int j=0;j<m;j++){
        int x = 0, y = 0;
        for(int i=0;i<n;i++){
            if(v[i][j] == '1') y++;
            else x++;
        }
        char val;
        if(x < y){
            val = '0';
        }else{
            val = '1';
        }
        for(int i=0;i<n;i++){
            if(v[i][j] == val) cnt[i]++;
        }
    }
    int mx = *max_element(cnt.begin(), cnt.end());
    for(int i=0;i<n;i++){
        if(cnt[i] == mx){
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
}
