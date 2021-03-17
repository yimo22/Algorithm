#include <stdio.h>
/*
*	ALGO HW#8
*	- Floyd Algorithm
*	Major : Computer Science & engineering
*	ID : 20172612
*	Name : 김영도
*/
#define SIZE 7
#define INF 9999
int Path_Weight[SIZE][SIZE] = {
	{0, 4, INF, INF, INF, 10, INF},
	{3, 0, INF, 18, INF, INF, INF},
	{INF, 6, 0, INF, INF, INF, INF},
	{INF, 5, 15, 0, 2, 19, 5},
	{INF, INF, 12, 1, 0, INF, INF},
	{INF, INF, INF, INF, INF, 0, 10},
	{INF, INF, INF, 8, INF, INF, 0}
};
int R_Path_Weight[SIZE][SIZE];// Problem3 에서 사용할 배열.
int d[SIZE][SIZE];
int R_d[SIZE][SIZE];
int P[SIZE][SIZE];
int R_P[SIZE][SIZE];
void Floyd()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			d[i][j] = Path_Weight[i][j];
		}
	}
	int k;
	for (k = 0; k < SIZE; k++)
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (d[i][j] >  d[i][k] + d[k][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					P[i][j] = k+1; // index는 0부터 시작하므로 -1을 준다. ( V1 -> V6 == (0,5)) 
				}
			}
		}
	}
}
void R_Floyd()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			R_d[i][j] = R_Path_Weight[i][j];
		}
	}
	int k;
	for (k = 0; k < SIZE; k++)
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (R_d[i][j] >  R_d[i][k] + R_d[k][j])
				{
					R_d[i][j] = R_d[i][k] + R_d[k][j];
					R_P[i][j] = k+1;
				}
			}
		}
	}
}
void PrintMatrixD() // D[][] 배열에 대한 모든 값을 출력
{
	printf("Print Matrix of D[][]\n");
	printf("  j  | V1\tV2\tV3\tV4\tV5\tV6\tV7\n");
	printf("-------------------------------------------------------------\n");
	for (int i = 0; i < SIZE; i++){
		printf(" V:%d | ", i+1 );
		for (int j = 0; j < SIZE; j++)
			printf("%d\t", d[i][j]);
		printf("\n");
	}
	return ;
}
void R_PrintMatrixD() // R_D[][]에 대한 모든 값을 출력
{
	printf("Print Matrix of R_D[][]\n");
	printf("  j  | V1\tV2\tV3\tV4\tV5\tV6\tV7\n");
	printf("-------------------------------------------------------------\n");
	for (int i = 0; i < SIZE; i++){
		printf(" V:%d | ", i+1 );
		for (int j = 0; j < SIZE; j++)
			printf("%d\t", R_d[i][j]);
		printf("\n");
	}
	return ;
}
void PrintMatrixP() // P[][] 에 대한 모든 값을 출력
{
	printf("Print Matrix of P[][]\n");
	printf("  j  | V1\tV2\tV3\tV4\tV5\tV6\tV7\n");
	printf("-------------------------------------------------------------\n");
	for (int i = 0; i < SIZE; i++){
		printf(" V:%d | ", i+1 );
		for (int j = 0; j < SIZE; j++)
			printf("%d\t", P[i][j]);
		printf("\n");
	}
	return ;
}
void R_PrintMatrixP() // R_P[][]에 대한 모든 값을 출력
{
	printf("Print Matrix of R_P[][]\n");
	printf("  j  | V1\tV2\tV3\tV4\tV5\tV6\tV7\n");
	printf("-------------------------------------------------------------\n");
	for (int i = 0; i < SIZE; i++){
		printf(" V:%d | ", i+1 );
		for (int j = 0; j < SIZE; j++)
			printf("%d\t", R_P[i][j]);
		printf("\n");
	}
	return ;
}
void Vertex_path_Print(int i, int j ){ // P[][]을 통한 경로를 출력한다.
	if(i>=0 && j>=0 && P[i][j] != 0){
		Vertex_path_Print(i,P[i][j]-1); // Path_Weight 는 index가 0부터 시작하므로 -1을 해준다.
		printf("->V%d",P[i][j]);
		Vertex_path_Print(P[i][j]-1,j);
	}
}
void R_Vertex_path_Print(int i, int j ){ // R_P[][]을 통한 경로를 재귀적 호출을 통해 출력한다. (BFS)
	if(i>=0 && j>=0 && R_P[i][j] != 0){
		R_Vertex_path_Print(i,R_P[i][j]-1);
		printf("->a%d",R_P[i][j]);
		R_Vertex_path_Print(R_P[i][j]-1,j);
	}
}
int main()
{
		/* Problem num#2
		Using Floyd Algorithm, Find d[][], P[][] , AllShortestPath and ShortestPath from V3 to V6.
		*/
	Floyd();
	PrintMatrixP();
	printf("\n\n");
	PrintMatrixD();
	printf("\n\n");
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE;j++){
			printf("V%d -> V%d 로 가는 최단 경로 :  ",i+1,j+1);
			if(i==j)
				{printf("Noway(selfNode)\n");
			continue;
		}
		printf("V%d(start)",i+1);
		Vertex_path_Print(i,j);
		printf("->V%d(End)\n",j+1);
	}
	printf("==================================================================================\n");
		/* Problem num#3
		V1 <-> a7, V2 <-> a6 ..... V6 <-> a1
		Find d[][], p[][] and shortest path from a5 to a2.
		compare the result from num#2 and num#3.
		*/

	for(int i=0; i<SIZE;i++){ // V1 = A7 , V2 = A6 .... 이므로 V와 A의 index 합은 8로 항상 일정하다.
		for(int j=0;j<SIZE;j++){
			R_Path_Weight[i][j] = Path_Weight[SIZE-1-i][SIZE-1-j];
		}
	}

	R_Floyd();
	R_PrintMatrixP();
	printf("\n\n");
	R_PrintMatrixD();
	printf("\n\n");
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE;j++){
			printf("a%d -> a%d 로 가는 최단 경로 : ",i+1,j+1);
			if(i==j)
				{printf("Noway(selfNode)\n");
			continue;
		}
		printf("a%d(start)",i+1);
		R_Vertex_path_Print(i,j);
		printf("->a%d(End)\n",j+1);
	}


	printf("\n\nCompare V3->V6 and A5->A2 : \n");
	printf("V3 -> V5 로 가는 최단 경로 : ");
	printf("V3(start)");
	Vertex_path_Print(2,5);
	printf("->V5(End)\n");
	printf("a5 -> a3 로 가는 최단 경로 : ");
	printf("a5(start)");
	R_Vertex_path_Print(4,1);
	printf("->a3(End)\n");
	return 0;
}
