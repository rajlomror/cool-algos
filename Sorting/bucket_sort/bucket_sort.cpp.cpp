#include<iostream>
using namespace std;

/********************************************************************* NODE OPERATIONS *******************************************************************/

struct node 
{
	int data;
	node *next ;
		
};
		
		
//insert and delete work is remaining 
void insert(node* &bin,int x)
{
	node *t=new node;
	t->data=x;
	t->next =0;
	
	node *p=bin;
	if(bin==0)
		bin=t;
	
	else
	{
		while(p->next)
			p=p->next;
	}
}

//node deletion from link list
int delet(node * &bin)
{
	int x=bin->data;
	
	node *t=bin;
	bin=bin->next;
	delete t;
	return x;
}

/***************************************************************************************************************************************/

//find max from array 
int find_max(int arr[],int n){
	int maxElement = INT_MIN;
	for(int i=0;i<n;i++){
		maxElement = max(maxElement, arr[i]);
	}
	return maxElement;
}



//bucket or bin sort
void bucket_sort(int a[],int n)
{
	int max=find_max(a,n),i,j;
	
	node** bins=new node*[max+1];
	
	for(i=0;i<max+1;i++)
		bins[i]=NULL;                    
	
	for(i=0;i<n;i++)
		insert( bins[a[i]],a[i]);
	
	i=j=0;
	
	while(i < max+1)
	{
		while(bins[i]!= NULL)
		{
			a[j++]=delet(bins[i]);
		}	
		i++;
    }
}


//main function
int main(){
	
	int arr[]= {2,4,3,6,9,1};	
	int n = sizeof(arr)/sizeof(arr[0]);
		
	cout<<"Before Bucket Sort array is : ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	//bucket sort
	bucket_sort(arr,n);
	
	cout<<"After Bucket Sort array is : ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
