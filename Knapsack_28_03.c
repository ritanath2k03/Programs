 
 #include<stdio.h>
typedef struct Knapsack{
	float profit,weight,ratio;
}Knapsack;
float capacity;
int main(){
	printf("Enter the capacity of the Bag :");
	scanf("%f",&capacity);
	printf("\nEnter the item number ");
	int item;
	scanf("%d",&item);
	Knapsack knapsackitem[item];
	printf("Enter the profit and weight accordingly :");
	int i,j;
	for(i=0;i<item;i++){
		scanf("%f %f",&knapsackitem[i].profit,&knapsackitem[i].weight);
		
	}
	for(i=0;i<item;i++)
	knapsackitem[i].ratio=((knapsackitem[i].profit)/(knapsackitem[i].weight));

	for( i=0;i<item;i++){
		for(j=i;j<item;j++){
			if(knapsackitem[i].ratio<=knapsackitem[j].ratio){
				//ratio sorted
				float temp=knapsackitem[i].ratio;
				knapsackitem[i].ratio=knapsackitem[j].ratio;
				knapsackitem[j].ratio=temp;
				//profit sorted
			     temp=knapsackitem[i].profit;
				knapsackitem[i].profit=knapsackitem[j].profit;
				knapsackitem[j].profit=temp;
				//weight sorted
				 temp=knapsackitem[i].weight;
				knapsackitem[i].weight=knapsackitem[j].weight;
				knapsackitem[j].weight=temp;
			}
		}
	}

	float totalprofit=0.0;
	for( i=0;i<item;i++){
		
		if(capacity>0){
			if(capacity<knapsackitem[i].weight){
				totalprofit+=(capacity/knapsackitem[i].weight)*knapsackitem[i].profit;
				capacity=0;
				
			}
		else{
            totalprofit+=knapsackitem[i].profit;
		capacity-=knapsackitem[i].weight;
        }
        printf("\nThe profit is %.2f ",totalprofit);
		}
        //I have integrated this else part for getting the profits which are being non considered.Otherwise break it.
		else
		{
            printf("\nNon-Considerable profit is : %.2f  ",knapsackitem[i].profit);
        }
	}
	printf("\nTotal profit is %.3f ",totalprofit);
	return 0;
}