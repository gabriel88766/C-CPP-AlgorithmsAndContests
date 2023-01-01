#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

vector<ll> v;
vector<ll> psum;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    vector<int> v;
    long long int dif=0;
    for(int i=1;i<=n;i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        dif += abs(v[i]-v[(n-1)/2]);
    }
    cout << dif;
    return 0;
}
