#include <stdio.h>
/*
*	ALGO HW#8
*	- All Shortest Path Algorithm
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
int d[SIZE][SIZE] = { INF };
int P[SIZE][SIZE];

void SimpleShortestPath2()
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			d[i][j] = Path_Weight[i][j];
		}
	}
	for (int m = 2; m < SIZE - 1; m++) {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				for (int k = 0; k < SIZE; k++) {
					if (d[i][j] > d[i][k] + Path_Weight[k][j]) {
						d[i][j] = d[i][k] + Path_Weight[k][j];
						P[i][j] = k + 1;
					}
				}
			}
		}
	}
}
void Vertex_path_Print(int i, int j) {
	if (i >= 0 && j >= 0 && P[i][j] != 0) {
		Vertex_path_Print(i, P[i][j] - 1);
		printf("->V%d", P[i][j]);
		Vertex_path_Print(P[i][j] - 1, j);
	}
}
int main()
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++) {
			printf("V%d -> V%d 로 가는 최적경로 : ", i + 1, j + 1);
			if (i == j)
			{
				printf("Noway(selfNode)\n");
				continue;
			}
			printf("V%d(start)", i + 1);
			Vertex_path_Print(i, j);
			printf("->V%d(End)\n", j + 1);
		}
	return 0;
}
