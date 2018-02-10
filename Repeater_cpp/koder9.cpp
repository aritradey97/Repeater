#include<bits/stdc++.h>
#include<string.h>

using namespace std;
int main()
{
  ifstream fin;
  ofstream fout;
  string arr[100]; 
    char op[6];                                             //It stores the input from the user
  string line2,line1;                                       //Line1 is the token name , Line2 stores a line of data from the file
  cout<<"\nEnter the operation name : ";
  cin>>op;       
  cin.ignore(100,'\n');                                       
  cout<<"\nEnter the token name : ";
  getline(cin,line1);                                                   //Token name is saved in line1                               
  int j,y,l1,l2,i=0,m=-1,c=0,c1[100]={0},count=0,k=0,w=0;
  int ip[1000];                                             //contains all input int values to be operated upon
  int ipc=0,cal;                                            //ipc is the input counter, cal is to store the calculated value
  
  
  
  fout.open("test1.kdr", ios::trunc);
  //fout<<"koderunners koderunners koderunners\nkoderunners koderunners";
  fout<<"koderunners";
  fout.close();
  
  
  
  
  
  
  
  
  
  
  
  
  
  fin.open("test1.kdr");
  l1=line1.length();
  if(!fin)
  {
          cout<<"Error in opening file..!!";
                exit(0);
  }
  while(fin.eof()==0)
  
  {
    m++;
    getline(fin,line2);
    arr[m]=line2;
  }
  y=m;
  m=-1;
  
  for(j=0;j<=y;j++)
 {
    m++;
    l2=arr[m].length();
  for(i=0;i<l2;i++)                                             //Will run till the end of the line 
  {
    
    count=0;
    c=0;
    while(arr[m][i]==line1[c] && arr[m][i]!='\0')                 //To check the occourance of the token
    {
      count++;
      c++;
      i++;
    }
    if(count==l1)
    {
      c1[w]++;
    }
    else
    {
      k=1;
      break;
    }
  
  }
/*  if(k==0)
  {
     cout<<"\n"<<c1[w]<<"\n";
     w++;
  }   
  else
  {
     cout<<"\nWrong Input!!\n";
     break;
  }  */
   
 // if(op=="op_a")
   if(strcmp(op,"op_a")==0)
  {
      if(c1[w]==1)
      {
          if(ipc<2)
          {
             cout<<"\nNot enough values!!";
          }
          else 
          {
             cal=ip[ipc-2]+ip[ipc-1];
          }
      }
      else if(c1[w]==2) 
      {
           if(ipc<2)
          {
             cout<<"\nNot enough values!!";
          }
          else 
          {
             cal=ip[ipc-2]-ip[ipc-1];
          }   
      }
      else if(c1[w]==3)
      {
          if(ipc<2)
          {
             cout<<"\nNot enough values!!";
          }
          else 
          {
             cal=ip[ipc-2]*ip[ipc-1];
          }     
      }
      else if(c1[w]==4)
      {
           if(ipc<2)
          {
             cout<<"\nNot enough values!!";
          }
          else 
          {
             cal=ip[ipc-2]/ip[ipc-1];
          }    
      }
      else if(c1[w]==5)
      {
           if(ipc<2)
          {
             cout<<"\nNot enough values!!";
          }
          else 
          {
             cal=ip[ipc-2]%ip[ipc-1];
          }    
      }
      else
     {
         cout<<"\nToo much input!!";
     }   
  }
  if(strcmp(op,"op_b")==0)
  {
      if(c1[w]==1)
      {
          if(ipc<2)
          {
             cout<<"\nNot enough values!!";
          }
          else 
          {
             if(ip[ipc-2]==ip[ipc-1])
                cal=1;
             else
                cal=0;   
          }    
      }
      else if(c1[w]==2)
      {
          if(ipc<2)
          {
             cout<<"\nNot enough values!!";
          }
          else 
          {
             if(ip[ipc-2]<ip[ipc]-1)
                cal=1;
             else
                cal=0;   
          }
      }
      else if(c1[w]==3)
      {
          if(ipc<2)
          {
             cout<<"\nNot enough values!!";
          }
          else 
          {
             if(ip[ipc-2]>ip[ipc-1])
                cal=1;
             else
                cal=0;   
          }
      }
      else if(c1[w]==4)
      {
          if(ipc<2)
          {
             cout<<"\nNot enough values!!";
          }
          else 
          {
             cal=(ip[ipc-2]&ip[ipc-1]);   
          }
      }    
      else if(c1[w]==5)
      {
          if(ipc<2)
          {
             cout<<"\nNot enough values!!";
          }
          else 
          {
             cal=(ip[ipc-2]|ip[ipc]-1) ;  
          }
      }
      else if(c1[w]==6)
      {
          if(ipc<1)
          {
             cout<<"\nNot enough values!!";
          }
          else 
          {
             cal=!(ip[ipc-1])   ;
          }
      }
      else
     {
         cout<<"\nToo much input!!";
     }
 }
 else if(strcmp(op,"op_io")==0)
 {
     if(c1[w]==1)
     {
        cout<<"\nEnter a value : ";
        cin>>ip[ipc];
        cout<<ip[ipc];                                            //test
        ipc++;
     }
     else if(c1[w]==2)
     {
        cout<<"\n"<<ip[ipc-1];
     }
/*     else if(c1[w]==3)
     {
        char pr[1000] ;                                    //doubt
     }
*/     
     else
     {
         cout<<"\nToo much input!!";
     }
  }
  
/*  else if(op=="op_log")
  {
     if(c1[w]==1)
     {
*/
  else
  {
     cout<<"\nWrong operation !!";
  }    
 }                        
  fin.close();
  return 0;
}

