#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;
const int N = 1e6+5;
int ans = 1;

int isdiv[N];
int isin[N];

vector<int> nums;

int p[1003];
vector<ll> primes;

void solve(){
    for(int i = 2; i <= 1000000;i++){
        for(int j = i; j <= 1000000; j += i){
            if(isin[j]){
                if(isdiv[i]) ans = max(ans, i);
                isdiv[i] = 1;
            }

        }
    }
}
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, aux;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> aux;
        nums.push_back(aux);
        isin[aux] = 1;
    }
    sort(nums.begin(), nums.end());
    for(int i = 1;i < nums.size();i++){
        if(nums[i] == nums[i-1]) ans = nums[i];
    }
    solve();
    cout << ans;
}   
