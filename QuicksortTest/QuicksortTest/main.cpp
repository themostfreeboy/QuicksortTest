#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int comp(const void*a,const void*b)
{
	return *((int*)a)-*((int*)b);
}

void quicksort(int data[],int first,int last)
{
	if(first>=last)    return;
	int key=data[first];
	int i=first;
	int j=last;
	while(i<j)
	{
		while(i<j && data[j]>=key)
		{
			j--;
		}
		data[i]=data[j];
		while(i<j && data[i]<=key)
		{
			i++;
		}
		data[j]=data[i];
	}
	data[i]=key;
	quicksort(data,first,i-1);
	quicksort(data,i+1,last);
}

int main()
{
	int data[N],ans[N],i,temp,wrongIndex;
	bool hasWrong;
	srand((unsigned)time(NULL));
	while(1)
	{
		for(i=0;i<N;i++)
		{
			temp=rand()%10000;
			data[i]=temp;
			ans[i]=temp;
		}
		printf("原始数据:\n");
		for(i=0;i<N;i++)
		{
			printf("%d ",data[i]);
		}
		printf("\n");
		quicksort(data,0,N-1);
		printf("我的排序后数据:\n");
		for(i=0;i<N;i++)
		{
			printf("%d ",data[i]);
		}
		printf("\n");
		hasWrong=false;
		for(i=0;i<N-1;i++)
		{
			if(data[i]>data[i+1])
			{
				hasWrong=true;
				wrongIndex=i+1;
				break;
			}
		}
		if(hasWrong)
		{
			printf("我的排序数据有误，第一个错误处出现在下标为%d处，标准排序后数据:\n",wrongIndex);
			qsort(ans,N,sizeof(int),comp);
			for(i=0;i<N;i++)
			{
				printf("%d ",ans[i]);
			}
			printf("\n");
		}
		else
		{
			printf("我的排序数据全部正确\n");
		}
		system("pause");
	}
	return 0;
}