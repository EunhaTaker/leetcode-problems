#include<vector>
#include<iostream>
using namespace std;

int maxArea(vector<int>& height) {
    int i=0, j=height.size()-1;
    int ans=0;  //储存最大容量
    int off;
    while(i<j){
        ans = max(ans, (j-i)*((height[i]<height[j])?
            height[i]:
            height[j])
        );
        off = 1;
        if(height[i]>height[j]){
            while(height[j]>=height[j-off])off++;
            j-=off;
        }
        else{
            while(height[i]>=height[i+off])off++;
            i+=off;
        }
    }
    return ans;
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height);
}