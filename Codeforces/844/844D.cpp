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
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n, start, x, ans1,ans2;
    cin >> n >> start >> x;
    cout << "? " << start << "\n";
    cout.flush();
    cin >> ans1 >> ans2;
    if(ans1 >= x){
        cout << "! " << ans1;
        cout.flush();
        return 0;
    }else if(n == 1){
        if(ans1 < x) cout << "! -1";
        cout.flush();
        return 0;
    }
    vector<int> permutation(n);
    for(int i=0;i<n;i++) permutation[i] = i+1;
    shuffle(permutation.begin(), permutation.end(), rng);
    int indlo = start, curmax = -1;
    for(int i=0;i<min(1000,(int)permutation.size());i++){
        cout << "? " << permutation[i] << "\n";
        cout.flush();
        cin >> ans1 >> ans2;
        if(ans1 < x) {
            if(ans1 > curmax){
                indlo = permutation[i];
                curmax = ans1;
            }
        }
    }
    int ans;
    while(true){
        cout << "? " << indlo << "\n";
        cout.flush();
        cin >> ans1 >> ans2;
        if(ans2 == -1 && ans1 < x){
            cout << "! -1";
            cout.flush();
            break;
        }
        if(ans1 < x) indlo = ans2;
        else{
            cout << "! " << ans1 << "\n";
            cout.flush();
            break;
        }
    }
}
