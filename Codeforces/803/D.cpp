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
    string s1, s;
    int k;
    getline(cin, s1);
    k = stoi(s1);
    getline(cin, s);
    vector<int> v;
    int p = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == ' ' || s[i] == '-'){
            v.push_back(i-p+1);
            p = i+1;
        }
    }
    v.push_back(s.size() - p);
    int lo = *max_element(v.begin(), v.end()), hi = s.size();
    //cout << lo << " " << hi << "\n";
    while(lo != hi){
        int mid = lo + (hi - lo)/2;
        int cnt = 1;
        int sum = 0;
        for(int i=0;i<v.size();i++){
            if(sum + v[i] > mid){
                cnt++;
                sum = v[i];
            }else sum += v[i];
        }
        if(cnt <= k) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
}
 