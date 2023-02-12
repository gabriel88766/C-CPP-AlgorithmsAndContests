    #include <bits/stdc++.h>

    using namespace std;

    int main(){
        int n, cnt = 0;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        //bubble sort (another o(n2))
        for(int i=0;i<n;i++){
            int mini = i;
            for(int j=(i+1); j<n;j++){
                if(v[j] < v[mini]){
                    mini = j;
                }
            }
            if(mini != i){
                cnt++;
                swap(v[i], v[mini]);
            }
        }
        for(int i=0;i<n;i++){
            cout << v[i];
            if(i == (n-1)) cout << "\n";
            else cout << " ";
        }
        cout << cnt << "\n";
    }