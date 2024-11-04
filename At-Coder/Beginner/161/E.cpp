#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int pr[N], su[N];
int aux[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k, c;
    string s;
    cin >> n >> k >> c;
    cin >> s;
    s = " " + s;
    vector<int> aux;
    for(int i=1;i<=n;i++){
        if(s[i] == 'o') aux.push_back(i);
    }

    for(int i=1;i<=n;i++){
        int cur = pr[max(0, i-c-1)];
        if(s[i] == 'o') pr[i] = cur + 1;
        pr[i] = max(pr[i], pr[i-1]);
    }
    for(int i=n;i>=1;i--){
        int cur = su[min(n+1, i+c+1)];
        if(s[i] == 'o') su[i] = cur + 1;
        su[i] = max(su[i], su[i+1]);
    }
    for(int i=0;i<aux.size();i++){
        //greeeeeeeedy!
        if(i == 0){
            if(su[aux[i]+1] < k) cout << aux[i] << "\n";
        }else if(i == aux.size() - 1){
            if(pr[aux[i]-1] < k) cout << aux[i] << "\n";
        }else{
            if(pr[aux[i]] != pr[aux[i]-1] && su[aux[i]] != su[aux[i] + 1] && pr[n] == k) cout << aux[i] << "\n";
        }
    }
}
