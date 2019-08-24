// 该算法性能差，而且算法难写，不要尝试了

#include<vector>
#include<iostream>
using namespace std;

void print(vector<int>& h){
    for(int i=0;i<h.size();i++)cout<<h[i]<<" ";
    cout<<endl;
}

bool rid(vector<int>& h, vector<int>& p, int i=0){ //剔除废柴元素
    if(i==h.size()-1) return true;  // 最右端一定不是废柴
    if(i==0 || h[i]>h[i-1]){    // 我比左边的大
        // 不是废柴
    }else{  // 我比左边的小
        while(true){
            if(h[i]<=h[i+1]){    // 我比右边的小
                // 妥妥的废柴
                h.erase(h.begin()+i);
                p.erase(p.begin()+i);
                return false;
            }else{  // 左大右小
                if(rid(h, p, i+1)) return true; //待定，若小弟不是废柴，我一定不是废柴，只是趋势在走下坡路了
                // 否则，while，重新判断
            }
        }
    }
    while(!rid(h, p, i+1)); //若右边是废柴，皮球踢回来，再探
    return true;    //能来这里的一定不是废柴
}

int getSmaller(vector<int> const& h, int &i, int &j){
    int idx;
    if(i==0 || j==h.size()-1){
        if(i==0) idx = ++j;
        else idx = --i;
    }else if(h[i-1]>=h[j+1]){
        idx = --i;
    }else{
        idx = ++j;
    }
    return h[idx];
}

int maxArea(vector<int>& height) {
    vector<int> place;  //储存柱子i对应位置
    for(int i=0;i<height.size();i++)
        place.push_back(i);
    rid(height, place);
    print(height);
    print(place);
    int l = height.size();
    int maxi = l-1; // 防止下面循环不存在符合if的情况
    for(int i=1;i<l;i++){
        if(height[i]<height[i-1]){
            // 涨停
            maxi = i-1;
            break;
        }
    }
    cout<<maxi<<endl;
    int ans = 0;    // 最大容量，初始为0
    int i=maxi,j=maxi; // 左右指针，分别初始化为maxi
    int smaller;    //天下第三高
    while(i>0 || j<l-1){
        smaller = getSmaller(height, i, j);
        cout<<smaller<<"  smaller"<<endl;
        ans = max(ans, smaller*(place[j]-place[i]));
    }
    return ans;
}

int main(){
    vector<int> height = {6,4,3,1,4,6,99,62,1,2,6};
    print(height);
    cout<<maxArea(height);
}

/*反思：
 * 确保所有变量能被初始化
 * 递归基要无懈可击
 */
    
