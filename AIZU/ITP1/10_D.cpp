#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin);
    double s1, s2, s3, sinf;
    s1 = s2 = s3 = sinf = 0;
    int n;
    cin >> n;
    vector<double> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    for(int i=0;i<n;i++){
        s1 += abs(a[i] - b[i]);
        s2 += abs(pow(a[i]-b[i], 2));
        s3 += abs(pow(a[i]-b[i], 3));
        sinf = max(sinf, abs(a[i] - b[i]));
    }
    s2 = pow(s2, 0.5);
    s3 = pow(s3, 0.33333333333333333);
    cout << setprecision(10) << fixed;
    cout << s1 << "\n" << s2 << "\n" << s3 << "\n" << sinf << "\n";


}

