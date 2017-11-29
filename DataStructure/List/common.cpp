给一个数组，找出里面最大的2个，并且回答出算法的时间复杂度。可以用任何语言。
例子：输入数组[1,2,5,6,3,4,5,4],输出6，5

方法1  选择排序，时间复杂度 O（2N）
vector<int>  Max2nums(vector<int> nums){
   vector<int>  res;
   if(nums.size()<=0)
       return res;
   int max=nums[0]
   int index=0;
   for(int i=0;i<nums.size();i++)
      if(max<nums[i]){
          max=nums[i]
          index=i;
       }  
   swap(index,0);
   res.push_back(max);
   int secondaryMax=nums[1];
   index=nums[1];
   for(int i=1;i<nums.size();i++)
      if(secondaryMax<nums[i]){
          secondaryMax=nums[i]
          index=i;
          }
   swap(index,1);
   res.push_back(secondaryMax);
   return res;
   
}

方法2 利用堆排序，时间复杂度，nlogK,这里K=2，因此，时间复杂度为nlog2

vector<int> GetLeastNumbers_Solution(vector<int> nums, int k) {
    vector<int> res;
        int l=nums.size();
        if(k<1||l<1||k>l)
            return res;
        priority_queue<int> q;
        while(!q.empty())
            q.pop();
        for(int i=0;i<l;i++){
            if(q.size()<k)
                q.push(nums[i]);
            else{
                if(nums[i]<q.top()){
                    q.pop();
                    q.push(nums[i]);
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }