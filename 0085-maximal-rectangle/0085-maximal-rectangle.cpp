class Solution {
public:
    int largestRectangleArea(vector<int>&heights) {
        int n=heights.size();
        vector<int>left(n),right(n);
        stack<int>st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                st.pop();
            }

            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }
        int maxi=INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi=max(maxi,(right[i]-left[i]-1)*heights[i]);
        }
        return maxi;  
    }
    int maximalRectangle(vector<vector<char>>& matrix){
        int maxi=INT_MIN;
        vector<vector<int>>matrix2(matrix.size(), vector<int>(matrix[0].size()));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                matrix2[i][j]=matrix[i][j]-'0';
            }
        }
        for(int i=0;i<matrix2.size();i++){
            if(i==0){
                maxi=max(maxi,largestRectangleArea(matrix2[i]));
            }
            else{
                for(int j=0;j<matrix2[0].size();j++){
                    if(matrix[i][j] == '1')
                        matrix2[i][j] += matrix2[i-1][j];
                    else
                        matrix2[i][j] = 0;
                }
                maxi=max(maxi,largestRectangleArea(matrix2[i]));
            }
        }
        return maxi;
    }
};