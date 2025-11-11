#include<iostream>
using namespace std;
int main(){
int size, i,j,pass;

cout<<"\n how many students for selection sort";
cin>>size;
float s[20];
cout<<"\n Enter the percentage of students";
for(i=0;i<size;i++)
{
                   cin>>s[i];
}
cout<<"\n Selection Sort: ";
for(i=0;i<size;i++)
{
                cout<<s[i]<<" ";
   }
   cout<<endl;
   for(pass=0;pass<size-1;pass++)
   {
         int mini=pass;
         int comparisons=0;
         for(j=pass+1;j<size;j++)
         {
                  comparisons++;
                  if(s[j]<s[mini])
                  {
                     mini=j;
                                }
                                 
         }       
         if(mini!=pass)
         {
                       float temp;
                       temp=s[pass];
                       s[pass]=s[mini];
                       s[mini]=temp;
                       }
   cout<<"pass : " <<pass+1<<"\n Comparisons: "<<comparisons<<"\n Array: ";
   for(i=0;i<size;i++)
   {
                      cout<<s[i]<<"  ";
                      }
   cout<<endl;
  
     }
     char ch;
     cout<<"Press any key to exit";
     cin>> ch;      
     return 0;
}
