int maximumUniqueSubarray(int* nums, int numsSize)
{
    
    int right = 1;
    int left = 0;    
    int max = 0;
    int temp = 0;
    
    if(numsSize == 1)
    {
        return nums[0];
    }
    while(right < numsSize || left < numsSize-1)
    {  
        temp = nums[right];
        int flag = false;
        for(int i = left;i < right;i++)
        {   
            if(nums[i] == nums[right])
            {                
                left = i+1;
                flag = true;
                break;                
            }
            else 
            {
                temp += nums[i];
            }
        }  
        if(temp > max)
        {
            max = temp;
        }
        
        if(!flag && (right >= numsSize-1))break;
        
        right += (right < numsSize-1)*1; 
    }
    
    return max;

} 
