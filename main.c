#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999 

int main()
{
	int cost[10][10], visited[10], dist[10], min, source_ver, totver, start_again;
	
	printf("Enter number of vertices: ");
	scanf("%d", &totver);	// taking the total number of vertex from user

	// Every loop in this program start from 1 so that it is easy to understand and better for the user to do input and output
	printf("Enter cost matrix: \n");
	for (int i = 1; i <= totver; i++)
	{
		for (int j = 1; j <= totver; j++)
		{
			scanf("%d", &cost[i][j]); // taking the distance between each vertex
			if (cost[i][j] == 0) // checking if the user enter 0 as distance 
			{
				cost[i][j] = INFINITY; // making the 0 distance as INFINITY
			}
		}
	}
	
	printf("Enter the source: ");
	source_again: 
	scanf("%d", &source_ver); // asking the user that which vertex he what to take as source vertex

	if (source_ver > totver) // it pervent the user from entering invalid input 
	{
		printf("\t\t*****Invaild Input*****\n");
		printf("Please enter the source again: ");
		goto source_again; // sending back up for taking the source vertex
	}

	for (int i = 1; i <= totver; i++)
	{
		visited[i] = 0; // it initailize the visited array with 0
		dist[i] = cost[source_ver][i]; // it initailize the distance array with repespect to cost matrix and source vertex
	}
	
	visited[source_ver] = 1; // it initailize the index of visited array at source_ver as visisted
	dist[source_ver] = 0;  // it initailize the index of distance array at source_ver as 0 because distance from source_ver to source_ver is 0

//this for loop finds the shortest path from source vertex to every other vertex
	
	//this loop has to run for every vertex apart from the source vertex therefore it runs totver-1 times
	for (int i = 1; i <= totver-1; i++)
	{
		min = INFINITY; // considering minimum as infinity

		for (int j = 1; j <= totver; j++)
		{
			// checking weather it is neighbouring vextex, weather distance is smaller than minimum and it is visited or not
			if (dist[j] < min && visited[j] == 0) 
			{
				min = dist[j];
				visited[j] = 1; // making current j index of visited array as visited
			}

			// again checking every vertex from this(j) neighbouring vextex
			for (int k = 1; k <= totver; k++)
			{
				//checking weather the distance of dist[j](neighbouring vextex) + cost[j][k](neighbouring vextex to other vertex) is smaller than dist[k](other vertex)
				if (dist[j] + cost[j][k] < dist[k]) 
				{
					dist[k] = cost[j][k] + dist[j];
				}
			}
		}
	}
	
	// printing the shortest path discovered 
	printf("\nShortest Paths: \n");
	for (int i = 1; i <= totver; i++)
	{
		if (i != source_ver)
		{
			printf("\t%d->%d = %d\n", source_ver, i, dist[i]);
		}
	}
	
	// check's weather the user what to try with diffrent source vertex
	switch_invalid:
	printf("\nIf you want find shortest path from other source vertex than press :1\n");
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
