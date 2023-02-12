#include <bits/stdc++.h>

using namespace std;


int main(){
    int cnt = 0, n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        bool ok = false;
        for(int j=2;j<min(10001,x);j++){
            if(!(x%j)) ok = true;
        }
        if(!ok) cnt++;
    }
    cout << cnt << "\n";
}