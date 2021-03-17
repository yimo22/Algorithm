#include <stdio.h>
#include <math.h>
#include <stdbool.h>
/*
*	ALGO HW#7
*	-Traveling Sales Person
*	성명 : 김영도
*	소속 : 컴퓨터학부
*	학번 : 20172612
*/

int city = 5;
#define CITY 5
// 도시의 수를 정의
#define MAX 999
int Path[MAX][MAX]; // 경로를 저장하는 함수
int Des[MAX][MAX]; // 각각의 경로들을 저장하는 이차원 배열
// Des[i][j] 는 현재 위치가 i 인 도시에서 j 도시들을 방문하지 않은 상태 이다.
int Way[MAX][MAX]; // Path_weight를 담아두는 2차원 배열
int Path_Weight[5][5] = { // 가중치
	{0,8,13,18,20},
	{3,0,7,8,10},
	{4,11,0,10,7},
	{6,6,7,0,11},
	{10,6,2,1,0}
}; // 인접행렬 입력값
void print_matrix(int n, int M[][MAX]) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			printf("%3d", M[i][j]);
		printf("\n");
	}
}
void printPowmatrix(int n, int M[][MAX]) { // PowerMatrix 출력함수
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= pow(2, n - 1); j++)
			printf("%3d", M[i][j]);
		printf("\n");
	}
}
int IsContain(int i, int A) { // 포함여부를 판단하는 함수
	if ((A & (1 << (i - 2))) != 0)
		return true;
	else
		return false;
}
int Isit(int A, int k) {
	int i, j = 0;

	for (i = 0; i < city; i++)
		if ((A & (1 << i)) != 0) j++;

	if (j == k)
		return true;
	else
		return false;
}
int delvertex(int A, int j) {
	int t = 1 << (j - 2);
	return (A & (~t));
}
int minimumpath(int A, int i, int* jj) {
	int j, n, minnum;

	minnum = MAX;
	for (j = 1; j < (int)pow(2, city - 1); j++) {
		if (!IsContain(j, A)) continue; // J 가 A의 부분집합이 아니면 실행하지 않는다.
		n = Way[i][j] + Des[j][delvertex(A, j)];
		if (minnum > n) {
			minnum = n;
			*jj = j;
		}
	}
	return minnum;
}
void travel() {
	int i, j, k, A;
	// 이미 다 순회하고 더이상 돌 경우의 수가 없을 경우.
	// 즉 , 남은도시가 공집합 인 경우.
	for (i = 2; i <= city; i++) {
		Des[i][0] = Way[i][1];
	}
	// 도시가 아직 남은 경우
	for (k = 1; k <= city - 2; k++) {
		for (A = 1; A < (int)pow(2, city - 1); A++) { // 부분집합의 모든 경우의 수에 대해 탐색한다.
			if (!Isit(A, k)) continue; // 만약 A가 K를 Contain 하고 있지 않을 경우 PASS
			for (i = 2; i <= city; i++) { // V1은 이미 출발이라고 가정했기 때문에
				if (IsContain(i, A)) continue; // A가 i의 부분집합일경우,
				Des[i][A] = minimumpath(A, i, &j); // 최소값을 저장한다.
				Path[i][A] = j; // 최소값을 줄때의 J 값을 저장한다.
				printf("Des[%d][%d]: %d\n", i, A, Des[i][A]);
			}
		}
		printf("경로행렬 : \n");
		printPowmatrix(city, Des);
	}
	A = (int)pow(2, city - 1) - 1; // 부분집합의 갯수 이기 때문에
	Des[1][A] = minimumpath(1, A, &j);
	Path[1][A] = j;
}
void minPath(int cityy, int A) { // 경로 출력
	int nextcity = Path[cityy][A];
	printf("V%d - ", cityy);
	if (A == 0)
		return;
	minPath(nextcity, delvertex(A, nextcity));
}
int main() {
	int i, j, cities = 1;
	for (i = 1; i <= city; i++)
		for (j = 1; j <= city; j++)
			Way[i][j] = Path_Weight[i - 1][j - 1];
	printf("Way 행렬: \n");
	print_matrix(city, Way);
	travel();

	printf("최단경로 배열:\n");
	printPowmatrix(city, Path);

	printf("trevel Path: ");
	minPath(1, (int)pow(2, city - 1) - 1);
	printf("V%d", cities);

	return 0;
}