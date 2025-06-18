#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

vector<int> acn[3'000'000];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin()); //optimize for repeated numbers
    vector<int> nums;

    int mn = *min_element(v.begin(), v.end());
    for(auto &x : v){
        for(int i=1;i*i<=x;i++){
            if(x % i == 0){
                if(i * i != x){
                    if(x/i <= mn) nums.push_back(x/i);
                }
                if(i <= mn) nums.push_back(i);
            }
        }
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    auto getp = [&](int x){ //better than map
        return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
    };
    for(int j=0;j<v.size();j++){
        auto x = v[j];
        for(int i=1;i*i<=x;i++){
            if(x % i == 0){
                if(i * i != x){
                    if(x/i <= mn) acn[getp(x/i)].push_back(j);
                }
                if(i <= mn) acn[getp(i)].push_back(j);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<nums.size();i++){
        int g = 0;
        for(auto &j : acn[i]) g = gcd(g, v[j]);
        if(g == nums[i]) ans++;
    }


    
    
    cout << ans << "\n";
}
