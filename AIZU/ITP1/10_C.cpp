#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin);
    int n;
    cin >> n;
    while(n){
        double m = 0, s=0;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
            m += a[i];
        }
        m /= n;
        for(int i=0;i<n;i++){
            s += pow(a[i] - m, 2);
        }
        s /= n;
        cout << setprecision(15) << fixed <<  sqrt(s) << "\n";
        cin >> n;
    }


}

