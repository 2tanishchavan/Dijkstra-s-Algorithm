#include <stdio.h>
#include <stdlib.h> // for exit function
#define INFINITY 99999 

int main()
{
	int cost[10][10], visited[10], dist[10], min, source_node, tot_node, start_again;
	
	printf("Enter number of nodes: ");
	scanf("%d", &tot_node);	// taking the total number of node from user

	// Every loop in this program start from 1 so that it is easy to understand and better for the user to do input and output
	printf("Enter cost matrix: \n");
	for (int i = 1; i <= tot_node; i++)
	{
		for (int j = 1; j <= tot_node; j++)
		{
			scanf("%d", &cost[i][j]); // taking the distance between each node
			if (cost[i][j] == 0) // checking if the user enter 0 as distance 
			{
				cost[i][j] = INFINITY; // making the 0 distance as INFINITY
			}
		}
	}
	
	printf("Enter the source: ");
	source_again: 
	scanf("%d", &source_node); // asking the user that which node he what to take as source node

	if (source_node > tot_node) // it pervent the user from entering invalid input 
	{
		printf("\t\t*****Invaild Input*****\n");
		printf("Please enter the source again: ");
		goto source_again; // sending back up for taking the source node
	}

	for (int i = 1; i <= tot_node; i++)
	{
		visited[i] = 0; // it initailize the visited array with 0
		dist[i] = cost[source_node][i]; // it initailize the distance array with repespect to cost matrix and source node
	}
	
	visited[source_node] = 1; // it initailize the index of visited array at source_node as visisted
	dist[source_node] = 0;  // it initailize the index of distance array at source_node as 0 because distance from source_node to source_node is 0

//this for loop finds the shortest path from source node to every other node
	
	//this loop has to run for every node apart from the source node therefore it runs tot_node-1 times
	for (int i = 1; i <= tot_node-1; i++)
	{
		min = INFINITY; // considering minimum as infinity

		for (int j = 1; j <= tot_node; j++)
		{
			// checking weather it is neighbouring vextex, weather distance is smaller than minimum and it is visited or not
			if (dist[j] < min && visited[j] == 0) 
			{
				min = dist[j];
				visited[j] = 1; // making current j index of visited array as visited
			}

			// again checking every node from this(j) neighbouring vextex
			for (int k = 1; k <= tot_node; k++)
			{
				//checking weather the distance of dist[j](neighbouring vextex) + cost[j][k](neighbouring vextex to other node) is smaller than dist[k](other node)
				if (dist[j] + cost[j][k] < dist[k]) 
				{
					dist[k] = cost[j][k] + dist[j];
				}
			}
		}
	}
	// printing the shortest path discovered 
	printf("\nShortest Paths: \n");
	for (int i = 1; i <= tot_node; i++)
	{
		if (i != source_node)
		{
			printf("\t%d->%d = %d\n", source_node, i, dist[i]);
		}
	}
	// check's weather the user what to try with diffrent source node
	switch_invalid:
	printf("\nIf you want find shortest path from other source node than press :1\n");
	printf("To exit press :0\n");
	scanf("%d", &start_again); 
	switch (start_again)
	{
	case 0:
		exit(0);
		break;
	case 1:
		printf("Please enter new source : ");
		goto source_again;
		break;
	
	default:
		printf("\t\t*****Invaild Input*****\n");
		goto switch_invalid;
		break;
	}
	return 0;
}
