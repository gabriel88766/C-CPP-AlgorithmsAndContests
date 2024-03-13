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
    int n, m, l;
    vector<int> v1, v2, v3;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v1.push_back(x);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        v2.push_back(x);
    }
    cin >> l;
    for(int i=0;i<l;i++){
        int x;
        cin >> x;
        v3.push_back(x);
    }
    vector<int> alln;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<l;k++){
                alln.push_back(v1[i] + v2[j] + v3[k]);
            }
        }
    }
    sort(alln.begin(), alln.end());
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        auto it = lower_bound(alln.begin(), alln.end(), x);
        if(it != alln.end() && *it == x) cout << "Yes\n";
        else cout << "No\n";
    }
}
