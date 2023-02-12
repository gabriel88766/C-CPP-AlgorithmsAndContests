#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, mincur = 2e9+1, maxp = -1e9+1;
    cin >> n;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        maxp = max(maxp, aux - mincur);
        mincur = min(mincur, aux);
    }
    cout << maxp << "\n";
}