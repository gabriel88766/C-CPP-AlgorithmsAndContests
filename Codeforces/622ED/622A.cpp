#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
long long int n,lo,hi,mid,triang;
cin >> n;
    lo = 0;
    hi = 1e9;
    while(lo<(hi-1)){
        mid = (lo+hi)/2;
        triang = mid*(mid+1)/2;
        if(triang >= n) hi = mid;
        else lo = mid;
    }

    if((hi*(hi+1))/2==n) cout << hi << endl;
    else{
        cout << n -((lo*(lo+1))/2)  << endl;

    }

}
