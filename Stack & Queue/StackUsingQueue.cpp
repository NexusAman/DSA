#include<bits/stdc++.h>
using namespace std;

// Stack using one queue
class Stack{
    public:
    queue<int> q;

    void push(int x){
        int s = q.size();
        q.push(x);

        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop(){
        q.pop();
    }

    int top(){
        return q.front();
    }

    int size(){
        return q.size();
    }
};

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();

    return 0;
}