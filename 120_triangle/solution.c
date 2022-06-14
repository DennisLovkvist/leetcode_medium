int Eval(int** triangle, int triangleSize,int index, int depth,int *t)
{       
    if(depth == triangleSize-1)return triangle[depth][index];  
    
    int n = ((depth*(depth+1))/2) + index; 
    if(t[n] != -10000) return t[n];
    
    int left = Eval(triangle, triangleSize,index,depth+1,t);  
    int right = Eval(triangle, triangleSize,index+1,depth+1,t); 
    
    t[n] = triangle[depth][index] + ((left < right)?left:right);    
    return t[n];
}


int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
{    
    int positions = ((triangleSize*(triangleSize+1))/2);
    int *t = malloc(sizeof(int)*positions);      
    
    for(int i = 0; i < positions;i++)
    {
        t[i] = -10000;
    }       
    
    return Eval(triangle, triangleSize,0,0,t);
}