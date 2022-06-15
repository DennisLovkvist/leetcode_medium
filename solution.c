int minOperations(int* nums, int numsSize, int x)
{
    int left = 0;
    int right = 0;    
    int sum = 0;    
    
    for(int i = 0;i < numsSize;i++)
    {
        sum+= nums[i];
    }
    int remainder = sum-x;    
    int n = 0;
    
    int longest = -1;
    
    if(sum-x <0)
    {
        return -1;
    }
    else if(sum-x == 0)
    {
        return numsSize;
    }
    
    while(true)
    {    
        if(right < numsSize)
        {
            if(n < remainder)
            {
                n += nums[right];
                right++; 
            }
        }
        else
        {
            if(n < remainder)
            {
                break;
            }
        }
        if(n > remainder)
        {
            n -= nums[left];
            left++;                
        }        
        if(n+x == sum)
        {
            longest = (right-left) > longest ? (right-left):longest;
            n -= nums[left];
            left++;    
        }                
    }
    
    return longest == -1  ? -1:numsSize-longest;        
}
 
