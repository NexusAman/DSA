#include <bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> &mat)
{
    if(mat.size() == 1){
        return 0;
    }

    stack<int> st;
    int n = mat.size();

    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    
    while (st.size() > 1)
    {
        int i = st.top();
        st.pop();
        int j = st.top();
        st.pop();

        if(mat[i][j] == 0){
            st.push(i);
        }else{
            st.push(j);
        }
    }
    
    int celeb = st.top();
    st.pop();

    for (int i = 0; i < n; i++)
    {
        if( (i != celeb) && (mat[i][celeb] == 0 || mat[celeb][i] == 1)){
            return -1;
        }
    }
    return celeb;
}

int main()
{
    vector<vector<int>> mat = {{1, 1, 0}, {0, 1, 0}, {0, 1, 1}};
    cout << celebrity(mat);
    return 0;
}