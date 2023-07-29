#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n,m;
        n = matrix.size();
        if(n==0)
            return 0;
        m = matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                matrix[i][j] -= '0';
                if(j>0&&matrix[i][j]>0)
                    matrix[i][j] += matrix[i][j-1];
                cout << (int)matrix[i][j] << " ";
            }
            cout << endl;
        }
        int re = 0;
        for(int j=0;j<m;j++)
        {
            stack<int> st;
            for(int i=n-1;i>=0;i--)
            {
                while((!st.empty())&&(matrix[st.top()][j]>=matrix[i][j]))
                {
                    int now = st.top();
                    st.pop();
                    int len;
                    if(st.empty())
                        len = n;
                    else
                        len = st.top();
                    re = max(re,matrix[now][j]*(len-i-1));
                }
                st.push(i);
            }
            while(!st.empty())
            {
                int now = st.top();
                    st.pop();
                    int len;
                    if(st.empty())
                        len = n;
                    else
                        len = st.top();
                    re = max(re,matrix[now][j]*len);
            }
            cout << re << endl;
        }
        return re;
    }
};