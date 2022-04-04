


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int addqueue(int t, int q[],int v);

int main()
{
    int q;
    scanf("%d",&q);
    
    while(q--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int a[n+1][n+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                a[i][j]=-1;
            }
        }
        
        while(m--)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            a[u][v]=6;
            a[v][u]=6;
        }
        int s;
        scanf("%d",&s);
        
        int ans[n+1];
        ans[0]=0;
        ans[s]=0;
        for(int i=1;i<=n;i++)
        {
            if(i!=s)
                ans[i]=-1;
        }
        
        int queue[n];
        queue[0]=s;
        int c=0,top=1;
        while(c!=top)
        {   
            
             for(int i=1;i<=n;i++)
             {
                if(a[queue[c]][i]==6)
                {
                    if(addqueue(top,queue,i))
                    {   
                        queue[top]=i;
                        top++;
                      //  ans[i]=6*(c+1);
                        ans[i]=6+ans[queue[c]];
                    }
                    
                }
             }
            c++;
        }
        for(int i=1;i<=n;i++)
        {
            if(i==s)
                continue;
            else
                printf("%d ",ans[i]);
        } printf("\n");
              
    }    
    return 0;
}

int addqueue(int t, int q[],int v)
{
    for(int i=0;i<t;i++)
    {
        if(q[i]==v)
            return 0;
    }
    return 1;
}
