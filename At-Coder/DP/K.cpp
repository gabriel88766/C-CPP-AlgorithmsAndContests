#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
bool lose[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        nums.push_back(aux);
    }
    for(int i=0;i<=k;i++) lose[i] = true;
    for(int i=1;i<=k;i++){
        for(int j=0;j<nums.size();j++){
            if(i < nums[j]) break;
            if(lose[i-nums[j]]) lose[i] = false;
        }
    }
    if(lose[k]) cout << "Second\n";
    else cout << "First\n";
}
