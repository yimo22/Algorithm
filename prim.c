#include <stdio.h>
#include <stdbool.h>
/*
*	Algo HW#9
*	- Prim Algorithm, Kruskal Algorithm
*	ID : 20172612
*	Major : Computer science & Engineering
*	Name : 김영도
*/
#define SIZE 8 // Vertex의 갯수가 8
#define INFI 9999	// INFINITE 
int Path_Weight[SIZE+1][SIZE+1] = {
	{0},
	{0,0,11,9,8,INFI,INFI,INFI,INFI},
	{0,11,0,3,INFI,8,8,INFI,INFI},
	{0,9,3,0,15,INFI,12,1,INFI},
	{0,8,INFI,15,0,INFI,INFI,10,INFI},
	{0,INFI,8,INFI,INFI,0,7,INFI,4},
	{0,INFI,8,12,INFI,7,0,INFI,5},
	{0,INFI,INFI,1,10,INFI,INFI,0,2},
	{0,INFI,INFI,INFI,INFI,4,5,2,0}
};
int Path[SIZE+1]; // Vi와 nearest[i]를 잇는 이음선의 가중치
int nearest[SIZE+1]; // Y에 속한 정점 중에서 vi에서 가장 가까운 정점의 인덱스
int path_Queue[SIZE][2];
bool IsitSubSet(int F, int a) {
	return (F & (1<< a-1)) != 0 ? true : false;
}
void Prim() {
	int min, vnear, visited = 0;
	int index = 0;
	//  무방향 그래프이기 때문에 어느 정점에서 시작하든 결국 결과는 같다.
	for (int i = 2; i <= SIZE; i++) { // 시작 노드를 V1으로 한다.
		nearest[i] = 1;
		Path[i] = Path_Weight[1][i];
	} 
	visited |= 1; // V1을 방문한 집합에 추가한다.
	

	while (visited != (1 << SIZE) - 1) { // 모든 Vertex를 방문 할 때까지 반복.
		min = INFI;
		for (int i = 2; i <= SIZE; i++) { // 가장 가까운 vertex와 그 경로를 찾는다.
			if (IsitSubSet(visited, i))
				continue;
			if ( Path[i] > 0 && min >= Path[i]) {
				min = Path[i];
				vnear = i;
			}
		}
		Path[vnear] = -1;
		path_Queue[index][0] = vnear;
		path_Queue[index++][1] = nearest[vnear];

		visited |= (1 << vnear - 1); // Vnear 에 해당되는 Vertex를 방문한 집합에 추가한다.		
		for (int i = 2; i <= SIZE; i++) { 
				if (Path_Weight[i][vnear] < Path[i]) { // 아직 Visited 하지않은 Vertex에 대하여 edge의 최소값 갱신
					Path[i] = Path_Weight[i][vnear];
					nearest[i] = vnear;
				}
		}
	}
}
void Print_Visited() {
	printf("순서 : \n");
	for (int i = 0; i < SIZE-1; i++) {
		printf(" ->V(  %d  , %d  ) : %d\n", path_Queue[i][0],path_Queue[i][1], Path_Weight[path_Queue[i][0]][path_Queue[i][1]]);
	}
}
int main() {
	
	Prim();
	Print_Visited();
	return 0;
}