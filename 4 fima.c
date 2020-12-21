#include<stdio.h>
#include<stdlib.h>
#include<time.h>	// for clock_t, clock()

int a[5000][5000]; //define randomly generated first matrix size
int Adjacency_Matrix[5000][5000];//define undirected graph adjacency matrix size

main()
{
    float time = 0.0;

    int n, initial_Vertex, Terminal_Vertex; //here n is for  Vertex
    scanf("%d", & n); //scan the value of n
    printf("Vertex = %d\n", n);

    clock_t begin = clock(); //Clock tick per second start for count exact run time

    for (initial_Vertex = 0; initial_Vertex < n; initial_Vertex++)
    {
        for (Terminal_Vertex = 0; Terminal_Vertex < n; Terminal_Vertex++)
        {
            a[initial_Vertex][Terminal_Vertex] = (rand() % 2); //use rand function to fill the matrix randomly where %2 is use to put only 0 and 1
        }
    }
    int total_degree = 0, count_degree = 0;

    for (initial_Vertex = 0; initial_Vertex < n; initial_Vertex++)
    {
        count_degree = 0;
        for (Terminal_Vertex = 0; Terminal_Vertex < n; Terminal_Vertex++)
        {
            if (a[initial_Vertex][Terminal_Vertex] == a[Terminal_Vertex][initial_Vertex]) //here the condition follow the rules
            {
                Adjacency_Matrix[initial_Vertex][Terminal_Vertex] = a[initial_Vertex][Terminal_Vertex];

                if (initial_Vertex == Terminal_Vertex && Adjacency_Matrix[initial_Vertex][Terminal_Vertex] == 1) //this is for the loops
                {
                    count_degree = count_degree + 2;
                }
                else if (Adjacency_Matrix[initial_Vertex][Terminal_Vertex] == 1)
                {
                    count_degree++;
                }
            }
            else if (a[initial_Vertex][Terminal_Vertex] != a[Terminal_Vertex][initial_Vertex])   //here did not follow
            {
                Adjacency_Matrix[initial_Vertex][Terminal_Vertex] = 0; //replies the matrix with 0
            }
        }
        total_degree = total_degree + count_degree; //summation of all degrees

        printf("degree of vertex %d = %d \n", initial_Vertex, count_degree);//showing degree of every vertex
    }
    printf("Total Degree of Vertex : %d\n", total_degree);
    int edges = total_degree / 2; //Number of edges
    printf("Total Number of Edges: %d\n", edges);
    printf("Total Degree of Vertex = (2*edges) ::  2*%d(e) = %d\n", edges, total_degree); //Handshaking Theorem
    //Checking if Handshaking theorem holds
    if (total_degree == 2 * edges)
    {
        printf("Handshaking theorem holds\n");
    }
    clock_t end = clock(); //Clock tick per second end
    // calculate elapsed time by finding difference (end - begin) and
    // divide by CLOCKS_PER_SEC to convert to seconds
    time = time + (float)(end - begin) / CLOCKS_PER_SEC;

    time = time * 1000000000; //converting second to ns

    printf("Total Time elapsed: %.2f ns", time);
    return 0;
}
