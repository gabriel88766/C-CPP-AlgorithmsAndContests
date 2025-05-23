#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> get_best(int n){
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    do{
        bool ok = true;
        for(int j=1;j<v.size();j++){
            if(abs(v[j] - v[j-1]) == 1){
                ok = false;
                break;
            }
        }
        if(ok){
            break;
        }
    }while(next_permutation(v.begin(), v.end()));
    return v;
}
vector<int> v[12];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=4;i<=8;i++) v[i] = get_best(i);
    int n;
    cin >> n;
    if(n == 1) cout << "1\n";
    else if(n == 2 || n == 3) cout << "NO SOLUTION\n";
    else{
        int p = 1;
        while(n > 8){
            for(int j=0;j<5;j++) cout << p + v[5][j] <<  " ";
            n -= 5;
            p += 5;
        }
        for(int j=0;j<v[n].size();j++) cout << p + v[n][j] << " ";
        cout << "\n";
    }
}
