/*
*	소속 : 컴퓨터학부
*	학번 : 20172612
*	성명 : 김영도
*	Date : Sep. 30. 2020.
*	Algorithm HW#5
*	HashTable에서의 충돌 해결법 구현.
*		- 선형조사 방법
*		- 이차원조사 방법
*		- 체이닝 방법
*/
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
typedef struct Node_int { // Chaining 에서의 연결리스트를 위한 구조체 선언
	int value ;
	struct Node_int* NextNode ;
}Node_int;
void Hash_Insert_Linear(int* ptr, int input); // 선형 조사 방법을 이용한 Hash Table
void Hash_Insert_Dimention(int* ptr, int input);// 이차원 조사 방법을 이용한 Hash Table
void Hash_Insert_Chain(Node_int** ptr, int input);// 체이닝 방법을 이용한 Hash Table
void Print_Node(Node_int** ptr, int size);
void Print_arr(int* ptr, int size);
void Print_LinkedList(Node_int* ptr);
int Linear_HashX(int input, int i);
int Dimention_HashX(int input, int i);
int main() {
	int input_arr[8] = { 10,20,30,40,33,46,50,60 };

	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++선형조사방법++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	int arr1[13] = { NULL };
	for(int i =0 ;i<8; i++)
		Hash_Insert_Linear(arr1, input_arr[i]);
	Print_arr(arr1, 13);

	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++이차원조사방법++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	int arr2[13] = { NULL };
	for (int i = 0; i < 8; i++)
		Hash_Insert_Dimention(arr2, input_arr[i]);
	Print_arr(arr2, 13);

	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++체이닝방법++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	Node_int** arr3[13];
	for (int i = 0; i < 13; i++) 
		arr3[i] = NULL;
	for (int i = 0; i < 8; i++)
		Hash_Insert_Chain(arr3, input_arr[i]);
	Print_Node(arr3, 13);

}
int Linear_HashX(int input , int i) {
	int Ex = (input+i) % 13; // 크기가 13인 배열에서의 Hash()값을 리턴한다.
	return Ex;
}
int Dimention_HashX(int input, int i) {
	int Ex = (input + (i * i)) % 13; // 크기가 13인 배열에서의 input i값에 따라 i^2 함으로 Hash()값을 리턴한다.
	return Ex;
}
void Print_arr(int* ptr, int size) { // arr 배열과 size를 인자로 받아 해당 배열의 원소를 전부 출력해주는 함수
	for (int i = 0; i < size; i++)
		printf("%d번째 원소 : %d\n", i,ptr[i]);
}
void Print_Node(Node_int** ptr , int size) { // ptr 포인터를 받아 해당 Node들을 전부 출력하는 함수
	for (int i = 0; i < size; i++) {
		if (ptr[i] != NULL) {
			printf("%d 번쨰 원소 : %d", i,ptr[i]->value);
			Print_LinkedList(ptr[i]->NextNode);
			printf("\n");
		}
		else {
			printf("%d 번째 원소 : %s\n", i, "NULL");
		}
	}
}
void Print_LinkedList(Node_int* ptr) { // 연결리스트에 달린 Node들을 전부 출력해주는 함수 (재귀호출)
	if (ptr != NULL){
		printf("\t%d",ptr->value);
		Print_LinkedList(ptr->NextNode);
	}
}
void Hash_Insert_Linear(int *ptr, int input) { // 개방주소 방법의 선형조사 방법을 통한 Hash	
	int i = 0;
	while (i < 13) {
		int j = Linear_HashX(input,i); // Hash()값을 재설정한다.
		if (ptr[j] == NULL) // 탐색하다 해당부분에 자료가 없을경우 자료를 삽입한다.
		{
			ptr[j] = input;
			break;
		}
		else // 그렇지 않은경우는 바로 다음 Index로 옮긴다.
			i++;
	}
}
void Hash_Insert_Dimention(int* ptr, int input) { // 개방주소 방법의 이차원조사 방법을 통한 Hash	
	int i = 0;
	while (i < 13) {
		int j = Dimention_HashX(input, i); // 이차원 조사 방법의 Hash()값으로 재설정 해준다.
		if (ptr[j] == NULL) // 탐색하다 해당부분에 자료가 없을경우 자료를 삽입한다.
		{
			ptr[j] = input;
			break;
		}
		else // 그렇지 않은 경우는 Index를 옮긴다.
			i++;
	}
}
void Hash_Insert_Chain(Node_int** ptr, int input) { // 체이닝 방법을 통한 Hash
	int index = Linear_HashX(input, 0);
	if (ptr[index] == NULL	) {	// 원소가 없는경우, 원소를 삽입한다.
		Node_int* temp = malloc(sizeof(Node_int));
		temp->value = input;
		temp->NextNode = NULL;
		ptr[index] = temp;
	}
	else {	// 원소가 있을경우, 원소를 링크드 리스트로 연결한다. 
		//이때 마지막에 삽입된 원소가 제일 앞으로 온다.
		Node_int* temp = malloc(sizeof(Node_int));
		temp->value = input;
		temp->NextNode = ptr[index];
		ptr[index] = temp;
	}
}