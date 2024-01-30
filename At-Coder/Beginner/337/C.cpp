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
    int fr = -1;
    vector<int> pos(n+1);
    vector<int> num(n+1);
    for(int i=1;i<=n;i++){
        cin >> num[i];
        if(num[i] == -1) fr = i;
        else pos[num[i]] = i;
    }
    cout << fr << " ";
    while(pos[fr]){
        fr = pos[fr];
        cout << fr << " ";
    }
    cout << "\n";
}
