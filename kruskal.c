#include <stdio.h>
#include <stdbool.h>
/*
*	Algo HW#9
*	- Prim Algorithm, Kruskal Algorithm
*	ID : 20172612
*	Major : Computer science & Engineering
*	Name : 김영도
*/
typedef struct Edge {
	int start_v;
	int dest_v;
	int Weight;
}Edge;
#define _CRT_SECURE_NO_WARNINGS
#define Edge_SIZE 13 // 총 Edge의 개수는 13
#define SIZE 8 // Vertex의 갯수가 8
#define INFI 9999	// INFINITE 
int Cycletable[SIZE+1]; // 각 Vertex에 대하여 포함된 Graph의 집합을 표시
Edge* course[SIZE - 1]; // 각 진행되는 순서를 보여주기 위한 배열
int Path_Weight[SIZE + 1][SIZE + 1] = {
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
int getParent(int* Cycletable, int x) { // x가 속한 Set을 구한다.
	if (Cycletable[x] == x)
		return x;
	return Cycletable[x] = getParent(Cycletable, Cycletable[x]);
}
void UnionP(int* Cycletable, int a, int b) { // a 와 b를 숫자가 더 작은 부모로 병합
	// 각각 속한 집합을 확인
	a = getParent(Cycletable, a);
	b = getParent(Cycletable, b);
	// 숫자가 더 작은 부모로 병합
	if (a < b)
		Cycletable[b] = a;
	else
		Cycletable[a] = b;
}
bool IsCycle(int* Cycletable , int a, int b) { //Cycle생성여부 확인
	// a와b가 같은 집합에 속할경우, Cycle을 생성한다.
	a = getParent(Cycletable, a);
	b = getParent(Cycletable, b);
	return a == b ? true : false; // a와b가 같으면 true 리턴, 그렇지 않으면 false 리턴
}
int main() {
	Edge ptr[14] = {
	{1,2,11},
	{1,3,9},
	{1,4,8},
	{2,3,3},
	{2,5,8},
	{2,6,8},
	{3,4,15},
	{3,6,12},
	{3,7,1},
	{4,7,10},
	{5,6,7},
	{5,8,4},
	{6,8,5},
	{7,8,2},
	}; // 각 Vertex에 대한 간선
	for (int i = 0; i <= Edge_SIZE; i++) { // 각 간선을 올림차순으로 정렬한다.
		for (int j = i + 1; j <= Edge_SIZE; j++) {
			if (ptr[i].Weight > ptr[j].Weight) {
				Edge temp = ptr[j];
				ptr[j] = ptr[i];
				ptr[i] = temp;
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
		Cycletable[i] = i; // 각 Vertex가 어떤 그래프에 속하는지 여부를 초기화 해준다. (Cycle 생성 여부 조사)

	int sum = 0;
	int index = 0;
	for (int i = 0; i < Edge_SIZE; i++) {
		if (!IsCycle(Cycletable, ptr[i].start_v, ptr[i].dest_v)) // Cycle을 만들지 않을때
		{
			// 간선의 값을 SUM에 더해주고, 해당 집합을 UNION 한다.
			// 진행되는 과정도 보여주기 위해 course[] 에 해당 Edge를 추가한다.
			UnionP(Cycletable, ptr[i].start_v, ptr[i].dest_v);
			sum += ptr[i].Weight;
			course[index++] = &ptr[i];
		}
	}
	// 과정 및 그 결과값을 보여주는 부분
	for (int i = 0; i < SIZE-1; i++) {
		if (i == 0)
			printf("(i,j) : Edge from Vi to Vj\n");
		printf("(%d, %d)'s Edge connected, Weight is %d\n", course[i]->start_v, course[i]->dest_v, course[i]->Weight);
	}
	printf("Sum of Edge is %d\n", sum);

	return 0;
}
