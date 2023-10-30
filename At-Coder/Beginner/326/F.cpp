#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

pair<int,int> 


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<int> xx, yy;
    for(int i=0;i<n;i++){
        if(i % 2) xx.push_back(v[i]);
        else yy.push_back(v[i]);
    }
    //meet-in-the-middle
    int mid = xx.size()/2;
    int s1 = 0, s2 = 0;
    for(int i=0;i<mid;i++) s1 += v[i];
    for(int i=mid;i<xx.size();i++) s2 += v[i];
    vector<pair<int,int>> sum1, sum2;
    for(int i=0;i< (1 << mid); i++){
        int cur = 0;
        for(int j=0;j<mid;j++){
            if(i & (1 << j)){
                cur += v[j];
            }
        }
        cur = cur - (s1 - cur);
        sum1.push_back({cur, i});
    }
    int sz1 = xx.size();
    for(int i=0; i < (1 << (sz1-mid)); i++){
        int cur = 0;
        for(int j=0;j<mid;j++){
            if(i & (1 << j)){
                cur += v[mid+j];
            }
        }
        cur = cur - (s2 - cur);
        sum2.push_back({cur, i});
    }
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());
    for(int i=0;i<sum1.size();i++){
        
        if
    }
}
