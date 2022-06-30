int lengthOfLongestSubstring(char * s)
{
    int len = strlen(s);
    
    if(len == 0)
    {
        return 0;
    }
    else if(len == 1)
    {
        return 1;
    }    
    
    int start = 0;
    int end = 1;
    int longest = 1;
    while(end< len)
    {    
        bool flag = false;
        for(int i = start; i < end;i++)
        {                
            if(s[end] == s[i])
            {    
                longest = (longest<(end-start)) ? end-start:longest; 
                start = i+1;
                end = start+1;
                flag = true;                
                break;
            }
        }  
        end += (!flag) ? 1:0;      
    }
    if(end == len)
    {
        longest = (longest<(end-start)) ? end-start:longest; 
    }
        
    return longest;
}