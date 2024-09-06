#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cnt[105];
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
        cnt[v[i]]++;
    }
    int pn = 0, cn = 0;
    for(int i=1;i<=100;i++){
        if(cnt[i] == 1) cn++;
        if(cnt[i] >= 3) pn++;
    }
    if(!(cn % 2)){
        cout << "YES\n";
        int cur = 0;
        for(int i=0;i<n;i++){
            if(cnt[v[i]] == 1){
                if(cur) cout << "B";
                else cout << "A";
                cur ^= 1;
            }else cout << "A";
        }
        cout << "\n";
    }else if(pn){
        cout << "YES\n";
        bool fpn = false;
        int cur = 0;
        for(int i=0;i<n;i++){
            if(cnt[v[i]] == 1){
                if(cur) cout << "B";
                else cout << "A";
                cur ^= 1;
            }else if(cnt[v[i]] >= 3 && !fpn){
                cout << "B";
                fpn = true;
            }else cout << "A";
        }
        cout << "\n";
    }else cout << "NO\n";
}
