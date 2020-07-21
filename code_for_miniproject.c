//WAP TO IMPLEMENT BEST FIT FIRST FIT AND WORST FIT ALGORITHMS OF
//MEMORY ALLOCATION .
#include<stdio.h>
#include<conio.h>
int memory_partitions[20];
int processes[20];
int number_of_processes;
int number_of_memory_partitions;
int ff[20];	//array for first fit
int bf[20];	//array for best fit
int wf[20];	//array for worst fit
int array[20];	//temporary array
int temp_process[20];	//temp array to hold  all the processes
int temp_memory_partitions[20];    //temp array to hold all the memory partitions
int min(int arr[20],int number_of_elements)
{
	int i;	//for iteration
	int M=arr[0];
	//clrscr();
	for(i=0;i<number_of_elements;i++)
	{
		if(M>arr[i])
			M=arr[i];
	}
	return M;
}
void first_fit()
{
	int i;	//for iteration of processes array
	int j;	//for iteration of memory partition array
	for(i=0;i<number_of_processes;i++)
	{
		for(j=0;j<number_of_memory_partitions;j++)
		{
			if(memory_partitions[j]>processes[i])
			{
				ff[i]=memory_partitions[j];
				memory_partitions[j]-=processes[i];
				break;
			}
		}
		if(j==number_of_memory_partitions)
			ff[i]=9999;
	}
	//printing the first fit array
	for(i=0;i<number_of_processes;i++)
	{
		if(ff[i]!=9999)
		{
			printf("\nprocess %d = %d gets the memory =%d\n",
			i+1,processes[i],ff[i]);
		}
		else
		{
			printf("\nprocess %d = %d has to wait\n",i+1,
			processes[i]);
		}
	}
}
void bestfit()
{
	int i;	//for iteration of processes array
	int j;	//for iteration of memory partion array
	int count;	//to count the number of elements which has
			//memory_partition greater than processes
	int k;
	for(i=0;i<number_of_processes;i++)
	{
		count=0;
		//initialise the array
		for(k=0;k<20;k++)
			array[k]=9999;
		for(j=0;j<number_of_memory_partitions;j++)
		{
			if(memory_partitions[j]>processes[i])
			{
				array[j]=memory_partitions[j];
				count++;
			}
		}
		/*printf("\nthe array = \n");
		for(k=0;k<count;k++)
			printf("%d\t",array[k]);*/
		if(count!=0){
			bf[i]=min(array,number_of_memory_partitions);
			for(j=0;j<number_of_memory_partitions;j++)
			{
				if(memory_partitions[j]==bf[i])
				{
					memory_partitions[j]-=processes[i];
				}
			}
		}
		else
		{
			bf[i]=9999;
		}
	}
	//printing the best fit
	for(i=0;i<number_of_processes;i++)
	{
		if(bf[i]!=9999)
		{
			printf("\nprocess %d = %d gets memory =%d\n",
			i+1,processes[i],bf[i]);
		}
		else
		{
			printf("\nprocess %d = %d has to wait\n",i+1,processes[i]);
		}
	}
}
void worstfit()
{
	int i;	//for iteration of the processes array
	int j;	//for iteraion of the memory partition array      \
	int max;
	int k;
	for(i=0;i<number_of_processes;i++)
	{
		max=memory_partitions[0];
		for(j=0;j<number_of_memory_partitions;j++)
		{
			if(max<memory_partitions[j])
			{
				max=memory_partitions[j];
				k=j;
			}
		}
		if(max>=processes[i])
		{
			wf[i]=memory_partitions[k];
			memory_partitions[k]-=processes[i];
		}
		else
		{
			wf[i]=9999;
		}
	}
	for(i=0;i<number_of_processes;i++)
	{
		if(wf[i]!=9999)
			printf("\nprocess %d = %d gets memory =%d\n",
			i+1,processes[i],wf[i]);
		else
			printf("\nprocess %d = %d has to wait\n",i+1,processes[i]);
	}
}
void main()
{
	int i;	//for iteration
	int choice;	//for switch case
	clrscr();
	printf("\n*********************************\n");
	printf("\nenter the number of processes\n");
	scanf("%d",&number_of_processes);
	printf("\nenter the number of memory partitions\n");
	scanf("%d",&number_of_memory_partitions);
	printf("\nenter the processes size one by one\n");
	for(i=0;i<number_of_processes;i++)
	{
		printf("\nenter the process %d size : ",i+1);
		scanf("%d",&processes[i]);
		temp_process[i]=processes[i];
	}
	printf("\nenter the memory partitions one by one\n");
	for(i=0;i<number_of_memory_partitions;i++)
	{
		printf("\nenter the memory partition %d size : ",i+1);
		scanf("%d",&memory_partitions[i]);
		temp_memory_partitions[i]=memory_partitions[i];
	}
	clrscr();
	printf("\nour process table now becomes\n");
	printf("\nprocess |   size\n");
	for(i=0;i<number_of_processes;i++)
	{
		printf("\nP%d      |        %d\n",i+1,processes[i]);
	}
	//printf("\nour memory partition table is :\n");
	do{
	//clrscr();
	for(i=0;i<number_of_processes;i++)
	{
		processes[i]=temp_process[i];
	}
	for(i=0;i<number_of_memory_partitions;i++)
	{
		memory_partitions[i]=temp_memory_partitions[i];
	}
	printf("\n1.first fit\n2.best fit\n3.worst fit\n4.exit\n");
	printf("\nenter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
	printf("\n*******************************\n");
	printf("\nfirst fit\n");
	first_fit();
	//printf("\n\n\n");
	break;
	case 2:
	printf("\n*******************************\n");
	printf("\nbest fit\n");
	bestfit();
	break;
	case 3:
	printf("\n*******************************\n");
	printf("\nworst fit\n");
	worstfit();
	break;
	case 4:
	printf("\n end of program \n");
	break;
	}
	}while(choice!=4);
	getch();
}
