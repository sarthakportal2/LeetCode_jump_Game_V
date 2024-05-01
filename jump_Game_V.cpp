class Solution {
public:
        int dp[1001];//Dp array's Size declare
        int Game(vector<int>& arr,int d,int i){//Game Funct declare
            if(dp[i]!=-1)return dp[i];//initizlaing Dp array from arr's Left side
            int out=1;int n=arr.size();//Variables and Array's size declare
            for(int j=i+1;j<=min(i+d,n-1)&&arr[i]>arr[j];j++)out=max(out,1+Game(arr,d,j));//Iterating through  array's Rightmost idnx
            for(int j=i-1;j>=max(i-d,0)&&arr[i]>arr[j];j--)out=max(out,1+Game(arr,d,j));//Iterating through array's leftmost idnx
            return dp[i]=out;}//printing Dp's Output

        int maxJumps(vector<int>& arr, int d) {//MaxJumps's funct declare
            memset(dp,-1,sizeof dp);//Memset Protoype Func declare
            int out=1;//Output declare
            for(int i=0;i<arr.size();i++)out=max(out,Game(arr,d,i));//Iterating through Game Array's Max's Size
            return out;}};//Printing Output
