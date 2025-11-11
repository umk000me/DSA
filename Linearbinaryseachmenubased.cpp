#include<iostream>
using namespace std;
int roll[50];
int n;
void getdata()
{
     cout<<"Enter no of student who attended the training\n";
     cin>>n;
     cout<<"Enter roll no of students";
     for(int i=0;i<n;i++)
     {
             cin>>roll[i];
             }
             }
     void linearsearch()
     {
          int key,flag=0;
          cout<<"Enter no to search :";
          cin>>key;
          for(int i=0; i<n;i++)
          {
                  if(roll[i]==key){
                  cout<<"Roll no : "<<key<<"Attended the training\n";
                  flag=1;
                  break;
                  }
                  }
          if(flag==0)
          {
                     cout<<"Roll no: "<<key<<" not attended the training\n";
                     }
                     }
          
     void binarysearch(){
          int key, low=0,high=n-1, mid,flag=0;
          cout<<"Enter roll no to search: \n";
          cin>>key;
          while(low<=high){
          mid=(low+high)/2;
          if(roll[mid]==key){
          cout<<"Roll no: "<<key<<"Is attended the training\n";
          flag=1;
          break;
          }
          else if(key<roll[mid])
          {
               high=mid-1;
          }
               else{
               low=mid+1;
          }
          }
          if (flag==0)
          {
                      cout<<"Roll no: "<<key<<"  not attended the training";
                      }
                      }
          int main()
          {
              
              int ch;
              do{
                  cout<<"********MENU*******";
                  cout<<"\n 1.Linear Search";
                  cout<<"\n 2.Binary Search";
                  cout<<"\n 3.Exit";
                  cout<<"\n Enter Your choice: \n";
                  cin>>ch;
                  switch(ch)
                  {
                  case 1:
                       getdata();
                       linearsearch();
                       break;
                  case 2:
                       getdata();
                       binarysearch();
                       break;
                  case 3:
                       cout<<"Exiting......";
                       break;
                  default:
                          cout<<"Invalid choice please select 1-3";
                          }
                          }
                  while(ch!=3);
                  return 0;
                  }
             
