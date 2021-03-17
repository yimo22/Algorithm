/*
* Sep. 13. 2020
* 컴퓨터학부
* 20172612 김영도
* Algorithm Hw#3
* 버블정렬,선택정렬,삽입정렬,병합정렬,퀵정렬,힙정렬 구현
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_RAND 32767
void Print_arr(double* ptr, int size);
void Sel_Sort(double* ptr, int size);
void Bubble_Sort(double* ptr, int size);
void Insert_Sort(double* ptr, int size);
void Merge_Sort(double* ptr, int Left, int Right);
void Heap_Sort(double* ptr, int N);
void Heaping(double* ptr, int RootIndex, int size);
void Quick_Sort(double* ptr, int Left, int Right);
void Make_Random_arr(double* p, int size);
double* temp_arr;
int count = 0;
double TestArr[20000];
int main() {
	temp_arr = malloc(sizeof(double) * 8);
	/*
	*아래 1과 2에서 병합 정렬을 제외하고는 정렬하는 과정 중에서 처음 2개의 최소값을 구하는 과정만을 보이면 됩니다.
	*/
	double arr01[6] = { 12,70,30,20,55,25 };
	double arr02[6] = { 12,70,30,20,55,25 };
	double arr03[6] = { 12,70,30,20,55,25 };
	double arr04[6] = { 12,70,30,20,55,25 };
	double arr05[6] = { 12,70,30,20,55,25 };
	double arr06[6] = { 12,70,30,20,55,25 };

	count = 3;
	printf("******************************************************선택정렬******************************************************\n");
	printf("정렬 전 ");
	Print_arr(arr01, 6);
	Sel_Sort(arr01, 6);
	count = 3;
	printf("정렬 후 ");
	Print_arr(arr01, 6);
	printf("******************************************************버블정렬******************************************************\n");
	printf("정렬 전 ");
	Print_arr(arr02, 6);
	Bubble_Sort(arr02, 6);
	count = 3;
	printf("정렬 후 ");
	Print_arr(arr02, 6);
	printf("******************************************************삽입정렬******************************************************\n");
	printf("정렬 전 ");
	Print_arr(arr03, 6);
	Insert_Sort(arr03, 6);
	count = 0; // 병합 정렬은 모든 과정을 다 보여야 하므로 0으로 초기화 한다.
	printf("정렬 후 ");
	Print_arr(arr03, 6);
	printf("******************************************************병합정렬******************************************************\n");
	printf("정렬 전 ");
	Print_arr(arr04, 6);
	Merge_Sort(arr04, 0, 6 - 1);
	count = 3;
	printf("정렬후 ");
	Print_arr(arr04, 6);
	printf("******************************************************퀵정렬******************************************************\n");
	printf("정렬 전 ");
	Print_arr(arr05, 6);
	Quick_Sort(arr05, 0, 6 - 1);
	count = 3;
	printf("정렬 후 ");
	Print_arr(arr05, 6);
	printf("******************************************************힙정렬******************************************************\n");
	printf("정렬 전 ");
	Print_arr(arr06, 6);
	Heap_Sort(arr06, 6);
	printf("정렬 후 ");
	Print_arr(arr06, 6);
	count = 0;
	/*
	*	12, 70, 30, 20, 55, 25, 40, 50의 입력이 제대로 출력되는지를 확인하시오.
	* (정렬 알고리즘별로 처음 5개 step과 결과를 출력하시오)
	*/

	double arr11[8] = { 12, 70, 30, 20, 55, 25, 40, 50 };
	double arr12[8] = { 12, 70, 30, 20, 55, 25, 40, 50 };
	double arr13[8] = { 12, 70, 30, 20, 55, 25, 40, 50 };
	double arr14[8] = { 12, 70, 30, 20, 55, 25, 40, 50 };
	double arr15[8] = { 12, 70, 30, 20, 55, 25, 40, 50 };
	double arr16[8] = { 12, 70, 30, 20, 55, 25, 40, 50 };

	printf("******************************************************선택정렬******************************************************\n");
	printf("정렬 전 ");
	Print_arr(arr11, 8);
	Sel_Sort(arr11, 8);
	count = 0;
	printf("정렬후 ");
	Print_arr(arr11, 8);
	printf("******************************************************버블정렬******************************************************\n");
	printf("정렬 전 ");
	Print_arr(arr12, 8);
	Bubble_Sort(arr12, 8);
	count = 0;
	printf("정렬 후 ");
	Print_arr(arr12, 8);
	printf("******************************************************삽입정렬******************************************************\n");
	printf("정렬 전 ");
	Print_arr(arr13, 8);
	Insert_Sort(arr13, 8);
	count = 0;
	printf("정렬후 ");
	Print_arr(arr13, 8);
	printf("******************************************************병합정렬******************************************************\n");
	printf("정렬 전 ");
	Print_arr(arr14, 8);
	Merge_Sort(arr14, 0, 8 - 1);
	count = 0;
	printf("정렬 후 ");
	Print_arr(arr14, 8);
	printf("******************************************************퀵정렬******************************************************\n");
	printf("정렬 전 ");
	Print_arr(arr15, 8);
	Quick_Sort(arr15, 0, 8 - 1);
	count = 0;
	printf("정렬 후 ");
	Print_arr(arr15, 8);
	printf("******************************************************힙정렬******************************************************\n");
	printf("정렬 전 ");
	Print_arr(arr16, 8);
	Heap_Sort(arr16, 8);
	printf("정렬 후 ");
	Print_arr(arr16, 8);
	count = 5;

	/*
	* rand(seed) 함수를 이용하여 n=8개의 –1 ~ 1 사이의 값을 출력하시오. (소수 셋째점까지만) 정렬 알고리즘별로 결과를 출력하시오
	* (같은 seed 값을 주면 같은 랜덤 값을 생성하므로, 출력 결과가 같아야 함)
	*/

	double* arr21 = malloc(sizeof(double) * 8);
	double arr22[8];
	double arr23[8];
	double arr24[8];
	double arr25[8];
	double arr26[8];

	for (int i = 0; i < 8; i++)
		arr21[i] = pow(-1, rand() % 2) * rand() / MAX_RAND;
	// MAX_RAND는 RAND() 함수의 최대출력값인 32767로써, rand() / MAX_RAND 는 0과 1사이의 실수를 출력한다.
	// pow(-1, rand() % 2) 는 부호를 결정해 준다.
	for (int i = 0; i < 8; i++) {
		arr22[i] = arr21[i];
		arr23[i] = arr21[i];
		arr24[i] = arr21[i];
		arr25[i] = arr21[i];
		arr26[i] = arr21[i];
	}

	printf("******************************************************선택정렬******************************************************\n");
	printf("정렬 전 ");
	Print_arr(arr21, 8);
	Sel_Sort(arr21, 8);
	printf("정렬후 ");
	Print_arr(arr21, 8);
	printf("******************************************************버블정렬******************************************************\n");
	printf("정렬 전 ");
	Print_arr(arr22, 8);
	Bubble_Sort(arr22, 8);
	printf("정렬 후 ");
	Print_arr(arr22, 8);
	printf("******************************************************삽입정렬******************************************************\n");
	printf("정렬 전 ");
	Print_arr(arr23, 8);
	Insert_Sort(arr23, 8);
	printf("정렬후 ");
	Print_arr(arr23, 8);
	printf("******************************************************병합정렬******************************************************\n");
	printf("정렬 전 ");
	Print_arr(arr24, 8);
	Merge_Sort(arr24, 0, 8 - 1);
	printf("정렬후 ");
	Print_arr(arr24, 8);
	printf("******************************************************퀵정렬******************************************************\n");
	printf("정렬 전 ");
	Print_arr(arr25, 8);
	Quick_Sort(arr25, 0, 8 - 1);
	printf("정렬후 ");
	Print_arr(arr25, 8);
	printf("******************************************************힙정렬******************************************************\n");
	printf("정렬 전 ");
	Print_arr(arr26, 8);
	Heap_Sort(arr26, 8);
	printf("정렬후 ");
	Print_arr(arr26, 8);

	/*
	*	 n=1000, 2000, ...... , 20,000까지 1000씩 증가시키면서 정렬하는 입력 값의 개수를 변경하면서
	*	 각 정렬 알고리즘의 수행 시간을 측정하시오. (msec 까지 측정하시오)
	*/
	printf("++++++++++++++++++++++++++++++++++++++++++++선택정렬++++++++++++++++++++++++++++++++++++++++++++\n");
	for (int i = 1000; i < 20001; i += 1000) {
		Make_Random_arr(TestArr, i);
		double start = clock();
		Sel_Sort(TestArr, i);
		double end = clock();
		printf("크기가 %d일때 걸리는 시간은 %.3f ms 입니다.\n", i, end-start);
	}printf("++++++++++++++++++++++++++++++++++++++++++++버블정렬++++++++++++++++++++++++++++++++++++++++++++\n");
	for (int i = 1000; i < 20001; i += 1000) {
		Make_Random_arr(TestArr, i);
		double start = clock();
		Bubble_Sort(TestArr, i);
		double end = clock();
		printf("크기가 %d일때 걸리는 시간은 %.3f ms 입니다.\n", i, end - start);
	}printf("++++++++++++++++++++++++++++++++++++++++++++삽입정렬++++++++++++++++++++++++++++++++++++++++++++\n"); 
	for (int i = 1000; i < 20001; i += 1000) {
		Make_Random_arr(TestArr, i);
		double start = clock();
		Insert_Sort(TestArr, i);
		double end = clock();
		printf("크기가 %d일때 걸리는 시간은 %.3f ms 입니다.\n", i, end - start);
	}printf("++++++++++++++++++++++++++++++++++++++++++++병합정렬++++++++++++++++++++++++++++++++++++++++++++\n"); 
	for (int i = 1000; i < 20001; i += 1000) {
		printf("1");
		Make_Random_arr(TestArr, i);
		double start = clock();
		Merge_Sort(TestArr, 0,i-1);
		double end = clock();
		printf("크기가 %d일때 걸리는 시간은 %.3f ms 입니다.\n", i, end - start);
	}printf("++++++++++++++++++++++++++++++++++++++++++++퀵정렬++++++++++++++++++++++++++++++++++++++++++++\n"); 
	for (int i = 1000; i < 20001; i += 1000) {
		Make_Random_arr(TestArr, i);
		double start = clock();
		Quick_Sort(TestArr, 0,i-1);
		double end = clock();
		printf("크기가 %d일때 걸리는 시간은 %.3f ms 입니다.\n", i, end - start);
	}printf("++++++++++++++++++++++++++++++++++++++++++++힙정렬++++++++++++++++++++++++++++++++++++++++++++\n");
	for (int i = 1000; i < 20001; i += 1000) {
		Make_Random_arr(TestArr, i);
		double start = clock();
		Heap_Sort(TestArr, i);
		double end = clock();
		printf("크기가 %d일때 걸리는 시간은 %.3f ms 입니다.\n", i, end - start);
	}

	return 0;
}
void Make_Random_arr(double* p, int size) {
	for (int i = 0; i < size; i++)
		p[i] = rand() % size;
}
void Print_arr(double* ptr, int size) {
	printf("Array : ");
	for (int i = 0; i < size; i++)
		printf("%.3g ", ptr[i]);
	printf("\n");
	return;
}
void Print_part_arr(double* ptr, int start_index, int last_index) {
	printf("Array : ");
	for (int i = start_index; i <= last_index; i++)
		printf("%.3g ", ptr[i]);
	printf("\n");
}
void Swap(double* n, double* m) {
	double temp = *m;
	*m = *n;
	*n = temp;
}
void Sel_Sort(double* ptr, int size) {
	int temp;
	for (int i = 0; i < size; i++) {
		temp = i;
		
		for (int j = i + 1; j < size; j++)
			if (ptr[temp] > ptr[j])
				temp = j;
		Swap(&ptr[i], &ptr[temp]);
		if (count < 5)
		{
			Print_arr(ptr, size);
			count++;
		}
	}
	return;
}
void Bubble_Sort(double* ptr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - (i + 1); j++) {
			if (ptr[j] > ptr[j + 1])
				Swap(&ptr[j], &ptr[j + 1]);

		}
		if (count < 5) {
			Print_arr(ptr, size);
			count++;
		}
	}
	return;
}
void Insert_Sort(double* ptr, int size) {
	for (int i = 1.; i < size; i++) {
		double temp = ptr[i];
		int j = i - 1;
		while (j >= 0 && temp < ptr[j]) { // 적정한 위치를 찾을 때 까지 모든 원소를 한 칸씩 옮긴다.
			ptr[j + 1] = ptr[j];
			j--;
		}
		ptr[j + 1] = temp;
		if (count < 5) {
			Print_arr(ptr, size);
			count++;
		}
	}
	return;
}
void Merge(double* ptr, int p, int q, int r) {
	/* 정렬되어 있는 두 배열 ptr[p~q] , ptr[q+1~r]을 합쳐
	하나의 정렬된 배열 ptr[p~r] 을 만든다.*/
	int loc_1 = p, loc_2 = q + 1;
	int index = 0;
	temp_arr = malloc(sizeof(double) * (r - p + 1));
	// 더 작은 데이터들을 배열에 넣는다.
	while (loc_1 <= q && loc_2 <= r) {
		if (ptr[loc_1] <= ptr[loc_2]) {
			temp_arr[index] = ptr[loc_1];
			loc_1++;
		}
		else {
			temp_arr[index] = ptr[loc_2];
			loc_2++;
		}
		index++;
	}
	// 그중 어느 한쪽이 먼저 끝까지 도달하여, while문이 작동 하지 않을 경우
	if (loc_1 > q) {
		for (; loc_2 <= r; loc_2++, index++)
			temp_arr[index] = ptr[loc_2];
		
	}
	else if (loc_2 > r) {
		for (; loc_1 <= q; loc_1++, index++)
			temp_arr[index] = ptr[loc_1];
		
	}
	index = 0;
	for (int i = p; i <= r; i++)
		ptr[i] = temp_arr[index++];
	if (count != 5)
		Print_part_arr(ptr, p, r);
}
void Merge_Sort(double* ptr, int Left, int Right) {
	if (Left < Right) {
		int mid = (Left + Right) / 2;
		// 좌측과 우측으로 나눈 후, 병합하면서 오름차순으로 정렬한다.
		Merge_Sort(ptr, Left, mid);
		Merge_Sort(ptr, mid + 1, Right);
		Merge(ptr, Left, mid, Right);
	}
}
void Quick_Sort(double* ptr, int Left, int Right) {

	if (Left < Right) {
		/*
		* pivot 은 ptr[Left ~ Right] 사이의 임의의 인덱스 이며, 이때 우린 pivot을 제일 맨 마지막 인덱스로 잡는다.
		* ptr[pivot] 보다 작은 수는 왼쪽으로, 큰수는 오른쪽으로 정렬한다.
		* 정렬할 때, A,B,C 구역으로 3구역으로 나뉜다.
		* A 구역은 ptr[pivot]보다 작은 수가 들어가는 곳이며, B구역은 ptr[pivot]보다 큰수가 들어간다.
		* C 구역은 아직 탐색하지 않은 수들이다.
		*
		* A구역의 마지막 인덱스를 Pointing 하는 변수가 i 이며, C구역(아직 탐색하지 않은 수)의 첫번째 인덱스를 Pointing하는 변수는 j 이다.
		* j 가 반복문을 통해 돌면서 pivot과 비교하여 ABC 구역에 맞게 수들이 SWAP 된다.
		* 이후 재귀함수를 통해 QuickSort가 진행된다.
		*/
		int pivot = Right;
		int i = Left - 1; // ptr[pivot] 보다 작은 수들의 마지막 인덱스를 point 하는 변수이다.

		for (int j = Left; j < Right; j++) { // 변수 j 는 아직 탐색하지 않은 수들의 첫번째 인덱스를 Point하는 변수이다.
			if (ptr[j] <= ptr[pivot]) // ptr[i]가 ptr[pivot] 값보다 더 작으면, 피봇 앞쪽(ptr[++i])에 위치한다.
				Swap(&ptr[++i], &ptr[j]);
			
		}
		/*
		*	각 원소들을 순회한 후, 기준으로 한 pivot 을 맞게 끼워 넣는다.
		* 이후 pivot의 인덱스 값을 재설정 해준다.
		*/
		Swap(&ptr[i + 1], &ptr[pivot]);
		if(count != 5)
			Print_part_arr(ptr, Left, Right);
		pivot = i + 1;
		/*
		*	pivot 기준으로 왼쪽과 오른쪽으로 나눠 재귀함수를 호출한다.
		*/
		Quick_Sort(ptr, Left, pivot - 1);
		Quick_Sort(ptr, pivot + 1, Right);
	}
}
void Heap_Sort(double* ptr, int N) { // N 는 전체 배열의 크기
	/*
	* 최소힙을 통한 힙정렬을 구현한다.
	* 입력받은 ptr 배열을 HeapSort 하기 위해
	* ptr 배열을 Heaping 한다.
	* i를 (N-1)/2 부터 진행하는 이유는 ptr의 마지막 원소의 부모가 ptr[(n-1)/2]이기 때문이다.
	*/
	for (int i = (N - 1) / 2; i >= 0; i--)
	{
		Heaping(ptr, i, N);
	}/*
	*	현재 rootNode에 있는것이 제일 작은 수 이다.
	*	Leaf 노드와 root 노드를 교환하고 다시 ptr 배열을 size-1에 대하여 Heaping을 한다.
	*/
	for (int i = N; i >= 1; i--) {
		Swap(&ptr[0], &ptr[i - 1]);
		Heaping(ptr, 0, i - 1);
		if (count < 5) {
			Print_arr(ptr, N);
			count++;
		}
	}
	// 이렇게 될경우, ptr은 내림차순 배열되기 때문에 다시 오름차순으로 정렬한다.
	for (int i = 0; i < N / 2; i++)
		Swap(&ptr[i], &ptr[(N - 1) - i]);
}
void Heaping(double* ptr, int RootIndex, int size) { // 이때 Root Index 는 0이며, size는 전체 배열의 크기 이다.
	/*
	*	A[K] 의 자식은 A[2K+1], A[2K] 이며,
	*	A[K] 의 부모는 A[k/2] 이다.
	*/
	// arr의 root index는 0으로 입력된다.
	int LeftChild = 2 * (RootIndex + 1), RightChild = 2 * (RootIndex + 1) + 1; // LeftChild 인덱스는 RightChild 인덱스 보다 항상 작다.
	int Min_Child;
	// 더 작은 쪽의 자식을 선택한다.
	if (RightChild <= size) { // 왼쪽, 오른쪽 자식이 둘다 존재하는경우.
		if (ptr[LeftChild - 1] < ptr[RightChild - 1])
			Min_Child = LeftChild;
		else
			Min_Child = RightChild;
	}
	else if (LeftChild <= size) { // 왼쪽 자식만 존재하는 경우.
		Min_Child = LeftChild;
	}
	else // 이 노드가 자식이 없을 경우 종료한다.
		return;
	/*
	* 만약 자식노드가 루트노드값 보다 작을 경우, 그 노드와 루트노드를 교환한다.
	* 이후 바꾼 노드트리에 대하여 SubTree가 Heap 성질을 만족하도록 재정렬 한다. (재귀함수)
	*/
	if (ptr[Min_Child - 1] < ptr[RootIndex]) {
		Swap(&ptr[Min_Child - 1], &ptr[RootIndex]);
		Heaping(ptr, Min_Child, size);
	}
}