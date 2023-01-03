#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// a and b index to sort
void mergesort(vector<ll> &v, int a, int b){
    if(a == b) return;
    else{
        int mid = (a + b)/2;
        mergesort(v, a, mid);
        mergesort(v, mid+1, b);
        int pv1 = a, pv2 = mid+1;
        ll aux[b-a+1];
        for(int i=a;i<=b;i++){
            if(pv1 <= mid && pv2 <= b){
                aux[i-a] = v[pv1] < v[pv2] ? v[pv1++] : v[pv2++]; 
            }else if(pv1 > mid){
                aux[i-a] = v[pv2++];
            }else{
                aux[i-a] = v[pv1++];
            }
        }
        for(int i=a;i<=b;i++){
            v[i] = aux[i-a];
        }
    }
}

//Testing problem https://cses.fi/problemset/task/1621
int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    mergesort(v, 0, n-1);
    int ans = 1;
    for(int i=1;i<n;i++){
        if(v[i] != v[i-1]) ans++;
    }
    cout << ans;
}