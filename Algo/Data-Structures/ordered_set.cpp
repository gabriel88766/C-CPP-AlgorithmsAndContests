#include <bits/stdc++.h>
using namespace std;
//ordered_set. tested here https://cses.fi/problemset/task/2163/
//src https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/ and https://codeforces.com/blog/entry/11080
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required

using namespace __gnu_pbds; //required 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
//less_equal if multiset


//how to use


int main(){
    ordered_set<int> st;
    st.insert(4);
    st.insert(8);
    st.insert(1);
    st.insert(2);

    cout << *st.find_by_order(0) << " and " << *st.find_by_order(3) << "\n"; // 1 and 8.
    st.erase(4);
    cout << *st.find_by_order(0) << " and " << *st.find_by_order(2) << "\n"; // 1 and 8.

    cout << st.order_of_key(4) << " and " << st.order_of_key(8); // 2 and 2, acts like lower_bound


}