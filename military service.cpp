#include<iostream>
using namespace std;
int main()
{
        int t,n,k;
  /*
        t : Number of test cases (1 ≤ T ≤ 100)
        n : Number of soldiers (0 ≤ N ≤ 10, 000, 000)
        k : Number of continuous months a soldier can be on duty before they have to take a mont
of vacation (0 ≤ K ≤ 10, 000, 000)
  */
        cin>>t;
        int a,i,j,p;
        int ans[t];
        p=0;
        for(a=0;a<t;a++)
        {
                cin>>n>>k;
                int size;
                size=n*k+k;
                int m[n][size];
                int tmp[k];
                //Initialization of all elements to 2
                for(i=0;i<n;i++)
                {
                        for(j=0;j<size;j++)
                        {
                                m[i][j]=2;
                        }
                }
                //Logic
                for(i=0;i<n;i++)
                {
                        int count=0;
                        if(i==0)
                        {
                                for(j=0;j<size;j++)
                                {
                                        m[i][j]=1;
                                        count++;
                                        if(count>k)
                                        {
                                                        m[i][j]=0;
                                                        count=0;
                                        }
                                }
                        }
                }
                for(i=1;i<n;i++)
                {
                        int count=0;
                        int cnt=0;
                        for(j=0;j<size;j++)
                        {
                                cnt++;
                                if(m[i-1][j]==0)
                                {
                                        break;
                                }
                        }
                        for(j=cnt-1;j<size;j++)
                                {
                                        m[i][j]=1;
                                        count++;
                                        if(count>k)
                                        {
                                                        m[i][j]=0;
                                                        count=0;
                                        }
                                }
                }                            
                //count no os 1s
                int l=0;
                for(l=0;l<k;l++)
                        tmp[l]=0;

                l=0;              
                for(j=(n*k);j<size;j++)
                {
                        for(i=0;i<n;i++)
                        {
                                if(m[i][j]==1)
                                        tmp[l]=tmp[l]+1;
                        }
                        l++;
                }
                //Minimum
                int min=tmp[0];
                for(l=0;l<k;l++)
                {
                        if(tmp[l]<min)
                                min=tmp[l];
                }
                //Output
                ans[p]=min;
                p++;
                //Print array
                /*for(i=0;i<n;i++)
                {
                        for(j=0;j<size;j++)
                        {
                                cout<<m[i][j]<<" ";
                        }
                        cout<<"\n";
                }*/
        }
        cout<<"\nOutput:-\n";
        for(p=0;p<t;p++)
                cout<<ans[p]<<"\n";
        return 0;
}
