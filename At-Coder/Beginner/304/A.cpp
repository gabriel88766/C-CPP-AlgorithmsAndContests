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
    vector<string> name(n);
    vector<int> age(n);
    for(int i=0;i<n;i++){
        cin >> name[i] >> age[i];
    }
    int youngest = -1, minage = INF_INT;
    for(int i=0;i<n;i++){
        if(minage > age[i]){
            minage = age[i];
            youngest = i;
        }
    }
    for(int i=youngest;i<n;i++) cout << name[i] << "\n";
    for(int i=0;i<youngest;i++) cout << name[i] << "\n";
}
