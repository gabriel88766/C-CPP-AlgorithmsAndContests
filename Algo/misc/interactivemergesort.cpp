//sometimes we can determine if P[j] > P[i], but cant store it directly
//the goal of this algorithm is to store the order. edit query. 1-indexed
//https://atcoder.jp/contests/arc154/tasks/arc154_d
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int cur1;

const int N = 2e3+3;
bool compare(ll i, ll j){//modify
    string s;
    cout << "? " << i << " " << cur1 << " " << j << "\n";
    cout.flush();
    cin >> s;
    if(s == "No") return true; //P[i] < P[j]
    else return false; //P[i] > P[j]
}

ll auxms[N];
void mergesort(vector<ll> &v, int a, int b){
    if(a == b) return;
    else{
        int mid = (a + b)/2;
        mergesort(v, a, mid);
        mergesort(v, mid+1, b);
        int pv1 = a, pv2 = mid+1;
        for(int i=a;i<=b;i++){
            if(pv1 <= mid && pv2 <= b){
                if(compare(v[pv1], v[pv2])) auxms[i-a] = v[pv1++];
                else auxms[i-a] = v[pv2++];
            }else if(pv1 > mid){
                auxms[i-a] = v[pv2++];
            }else{
                auxms[i-a] = v[pv1++];
            }
        }
        for(int i=a;i<=b;i++){
            v[i] = auxms[i-a];
        }
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    string anss;
    cin >> n;
    cur1 = 1;
    for(int i=2;i<=n;i++){
        cout << "? " << i << " " << i << " " << cur1 << "\n";
        cout.flush();
        cin >> anss;
        if(anss == "No") cur1 = i;
    }
    vector<ll> ans(n+1, 0), ord(n+1, 0);
    for(int i=1;i<=n;i++) ord[i] = i; //order not sorted
    mergesort(ord, 1, n); //sort order
    cout << "! ";
    for(int i=1;i<=n;i++) ans[ord[i]] = i; //in this case, ans[ord[1]] = 1 
    for(int i=1;i<=n;i++) cout << ans[i] << " ";

    cout.flush();
}