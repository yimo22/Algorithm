#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/*
*	Algo HW#10
*	- BackTracking, Monte Carlo Algorithm
*	ID : 20172612
*	Major : Computer Science&Engineering
*	name : 김영도
*/
#define W1 2
#define W2 10
#define W3 13
#define W4 17
#define W5 22
#define W6 42
#define _CRT_SECURE_NO_WARNINGS
int LIMIT; // 구하는 SUBSET의 합
bool IsPrint = false; // SumOfSubset의 Print부분의 작동유무를 찾을 Flag
int arr[6] = { W1,W2,W3,W4,W5,W6 }; // 문자열 배열
int x[6] = { 0, }; // Subset의 sum에 맞는 값들을 저장하는 배열
int numnodes = 0; // Monte Carlo에서 사용될 방문한 노드의 개수를 저장하는 변수
bool IsValid(int i, int weight, int total) { // 유망한지 여부를 판단하는 함수(Backtracking)
	/* 수준 i+1 원소가 유효한 경우는 다음과 같다.
	 1. 그 원소의 값과 SUM 값을 합쳤을때, 한계값(LIMIT)을 넘지 않을 경우
	 2. 현재까지 더한 값(Weight)와 남아있는 원소의 합(total)을 합했을때, LIMIT 보다 크거나 같은경우.
	-> Weight+total < LIMIT 일 경우 남은 원소를 다 더해도 LIMIT 을 도달 할 수 없으므로 이 경우의 반되되는 경우가 Valid 하다.
	(Word가 크기순으로 정렬되있기 때문에 가능)
	*/
	if (weight + total >= LIMIT && (weight == LIMIT || weight + arr[i + 1] <= LIMIT))
		return true;
	else
		return false;
}
void Print_C() {
	for (int i = 0; i < 6; i++) {
		if (x[i] != 0) { // 포함하지않은 원소(0)를 제외한 모든 원소에 대하여 출력
			printf("%d ", x[i]);
		}
	}
	printf("\n");
}
void SumOfSubset(int i, int weight, int total) {// LIMIT 의 모든 경우를 IsValid를 통해서, 찾는 함수
	numnodes++; // Monte Carlo Algo의 Proming한 Node를 Count
	if (IsValid(i,weight,total)) { // 유효한 것에만 Search를 한다.
		if (IsPrint && weight == LIMIT) { // 해당 되는 경우를 찾은경우, 출력해준다.
			Print_C();
		}
		else
		{
			// 왼쪽 가지에 대한 DFS
			x[i + 1] = arr[i + 1];
			SumOfSubset(i + 1, weight + arr[i + 1], total - arr[i + 1]);

			// 오른쪽 가지에 대한 DFS
			x[i + 1] = 0;
			SumOfSubset(i + 1, weight, total - arr[i + 1]);
		}
	}
}
int main() {
	int sumofnum = 0;
	for (int i = 0; i < 6; i++)
		sumofnum += arr[i];
	printf("Set Limit : \n");
	IsPrint = true;
	scanf("%d", &LIMIT);

	printf("Finding Sum of Subset ,which sum is %d\n", LIMIT);
	SumOfSubset(-1, 0, sumofnum);

	/* Monte Carlo Algorithm */
	
	int m = 0; // 누적 numnodes
	int count = 0;
	IsPrint = false; //SumofSubset 함수의 중간중간 Print함수 사용여부 == false
	srand((unsigned int)time(NULL)); // Random 
	m = 0;
	for (int i = 0; i < 100000; i++) {
		LIMIT = rand() % sumofnum + 1;
		SumOfSubset(-1, 0, sumofnum);

		m += numnodes;
		count = i; // 반복횟수 갱신
		count++;
		if (count % 10000 == 0) { // count == 10000의 배수 일때마다 출력
			printf("\tRepeated :  %d\n", count);
			printf("\tSum of visited Node : %d\n", m);
			printf("Monte Calo : %.2f\n\n",(double) m / count);
		}

		numnodes = 0; // 방문노드수 초기화
	}

	return 0;
}