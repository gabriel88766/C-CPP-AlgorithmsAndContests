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
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    bool pii = false, pii2 = false;
    for(int i=0;i<n-2;i++){
        int c = 0;
        if(a[i] % 2) c++;
        if(a[i+1] % 2) c++;
        if(a[i+2] % 2) c++;
        if(c == 2) pii = true;
        c = 0;
        if(b[i] % 2) c++;
        if(b[i+1] % 2) c++;
        if(b[i+2] % 2) c++;
        if(c == 2) pii2 = true;
    }
    if(pii){
        bool ok = true;
        vector<int> nums1, nums2, nn1, nn2;
        for(int i=0;i<n;i++){
            if(a[i] % 2 == 0) nums1.push_back(a[i]);
            else nn1.push_back(a[i]);
            if(b[i] % 2 == 0) nums2.push_back(b[i]);
            else nn2.push_back(b[i]);
        }
        if(nums1.size() >= 3){
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
        }
        sort(nn1.begin(), nn1.end());
        sort(nn2.begin(), nn2.end());
        if(nums1 != nums2) ok = false;
        if(nn1 != nn2) ok = false;
        if(!pii2) ok = false;
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }else{
        //at most ppp, odd cant change positions
        bool ok = true;
        vector<int> v = {-1};
        for(int i=0;i<n;i++){
            if(a[i] % 2) v.push_back(i);
        }
        v.push_back(n);
        for(int i=1;i<v.size();i++){
            vector<int> nums1, nums2;
            for(int j=v[i-1]+1;j<v[i];j++){
                nums1.push_back(a[j]);
                nums2.push_back(b[j]);
            }
            if(nums1.size() >= 3){
                sort(nums1.begin(), nums1.end());
                sort(nums2.begin(), nums2.end());
            }
            if(nums1 != nums2) ok = false;
            if(v[i] != n && a[v[i]] != b[v[i]]) ok = false;
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
