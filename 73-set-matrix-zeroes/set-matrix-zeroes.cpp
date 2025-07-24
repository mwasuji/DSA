class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();    //row
        int n = matrix[0].size(); //col
        bool firstRowZero = false;
        bool firstColZero = false;
        
        // check if first row has a zero
        for(int i=0; i<n; i++){
            if(matrix[0][i]==0){
                firstRowZero=true;
            }
        }

        //check if first column has a zero
        for(int i=0; i<m; i++){
            if(matrix[i][0]==0){
                firstColZero=true;
            }
        }

        //use first row and column as markers
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
 
        // zero out the cells based on markers
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        
        //zero ot the first row if needed
        if(firstRowZero){
            for(int i=0; i<n; i++){
                matrix[0][i]=0;
            }
        }
      
        //zero ot the first column if needed
        if(firstColZero){
            for(int i=0; i<m; i++){
                matrix[i][0]=0;
            }
        }

        
    }
};