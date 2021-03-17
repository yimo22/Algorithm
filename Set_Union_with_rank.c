/*
*	ALGO HW#6
*	소속 : 컴퓨터학부 
*	학번 : 20172612
*	성명 : 김영도
*	Rank를 이용한 Set의 Union 구현
*/
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
typedef struct Node { // LinkedList를 위한 구조체
	char data;
	struct Node* root;
	int rank;
}Node;
void Print_Set(Node* ptr);//노드를 입력받아 해당 노드의 data와 rank를 출력해주는 함수
Node* Make_Set(char c); // 노드를 입력받아 유일한 원소로 하는 집합 생성. 
Node* Make_Element(Node* Pre_Node, char c); // 노드를 집합에 넣는다.
Node* ReMake_rank(Node* ptr); // 원소를 붙일경우, rank 조정을 재귀로 해준다.
void Union(Node* pre, Node* Next); // 서로다른 집합간에 Union
Node* Find_Set(Node* ptr); // 노드 ptr이 속한 집합을 알아낸다.(해당 루트노드 리턴)
int main() {
	Node* Element_a = Make_Set('a'); // a를 루트로 하는 집합 형성
	Node* Element_b = Make_Element(Element_a, 'b'); // a를 루트로 하는 원소 b 생성
	Node* Element_c = Make_Set('c'); // c를 루트로 하는 집합 형성
	printf("++++++++++++++++++++Before Union++++++++++++++++++++\n");
	Print_Set(Element_a);
	Print_Set(Element_b);
	Print_Set(Element_c);
	Union(Element_a, Element_c); // 각각 a와c를 루트로 하는 집합을 UNION
	printf("++++++++++++++++++++After Union++++++++++++++++++++\n");
	Print_Set(Element_a);
	Print_Set(Element_b);
	Print_Set(Element_c);

	Node* Element_d = Make_Set('d'); // d를 루트로 하는 집합 형성
	Node* Element_e = Make_Element( Element_d, 'e'); // e를 루트로 하는 원소 e 생성

	Node* Element_f = Make_Set('f'); // f를 루트로 하는 집합 형성
	Node* Element_g = Make_Element( Element_f, 'g'); // g를 루트로 하는 원소 e 생성
	Node* Element_h = Make_Element( Element_f, 'h'); // h를 루트로 하는 원소 e 생성
	Node* Element_i = Make_Element( Element_f, 'i'); // i를 루트로 하는 원소 e 생성

	printf("++++++++++++++++++++Before Union++++++++++++++++++++\n");
	Print_Set(Element_d);
	Print_Set(Element_e);
	Print_Set(Element_f);
	Print_Set(Element_g);
	Print_Set(Element_h);
	Print_Set(Element_i);
	Union(Element_d, Element_f); // 각각 d와 f를 루트로 하는 집합 UNION 
	printf("++++++++++++++++++++After Union++++++++++++++++++++\n");
	Print_Set(Element_d);
	Print_Set(Element_e);
	Print_Set(Element_f);
	Print_Set(Element_g);
	Print_Set(Element_h);
	Print_Set(Element_i);

	printf("++++++++++++++++++++Before Union++++++++++++++++++++\n");
	Print_Set(Element_a);
	Print_Set(Element_b);
	Print_Set(Element_c);
	Print_Set(Element_d);
	Print_Set(Element_e);
	Print_Set(Element_f);
	Print_Set(Element_g);
	Print_Set(Element_h);
	Print_Set(Element_i);
	Union(Element_a, Element_d); // 앞의 집합들 UNION 
	printf("++++++++++++++++++++After Union++++++++++++++++++++\n");
	Print_Set(Element_a);
	Print_Set(Element_b);
	Print_Set(Element_c);
	Print_Set(Element_d);
	Print_Set(Element_e);
	Print_Set(Element_f);
	Print_Set(Element_g);
	Print_Set(Element_h);
	Print_Set(Element_i);

	return 0;
}
void Print_Set(Node* ptr) {
	printf("%c의 부모 노드는 %c 입니다. \n", ptr->data, ptr->root->data);
	printf("%c의 rank는 %d 입니다.\n", ptr->data, ptr->rank);
	printf("\n");
}
Node* Make_Set(char c) { // 노드를 입력받아 유일한 원소로 하는 집합 생성. 
	Node* ptr = malloc(sizeof(Node));
	ptr->data = c;
	ptr->root = ptr;
	ptr->rank = 0;
	return ptr;
}
Node* Make_Element(Node* Pre_Node, char c) { // 노드를 집합에 넣는다.
	Node* temp = malloc(sizeof(Node));
	temp->data = c;
	temp->root = Pre_Node;
	temp->rank = 0;
	ReMake_rank(temp);
	return temp;
}
Node* ReMake_rank(Node* ptr) { // 원소를 붙일경우, rank 조정을 재귀로 해준다.
	if (ptr->root != ptr && (ptr->root->rank) <= (ptr->rank) ) // 만약 root 노드까지 올라오지 않은 경우
	{
		ptr->root->rank = ptr->root->rank + 1;
		ReMake_rank(ptr->root);
	}
	else // 루트 노드까지 올라온 경우 or Rank를 조정할 필요가 없을경우
		return;
}
void Union(Node* pre, Node* Next) { // 서로다른 집합간에 Union
	// 노드 pre와 Next를 서로 Union 한다.
	// 루트 노드로 올라간 후, rank를 비교하여 rank가 적은 쪽이 많은 쪽으로 붙는다.
	// 단, rank가 서로 같은경우, rank++ 한다.
	pre = Find_Set(pre);
	Next = Find_Set(Next);

	// rank 비교
	if (pre->rank < Next->rank) { // Next의 rank가 더 큰경우, pre를 Next에 붙인다.
		pre->root = Next;
	}
	else { // Next의 Rank가 더 작은경우, Next를 Pre 뒤로 붙인다.
		Next->root = pre;
		if (pre->rank == Next->rank) // 만약 서로 Rank가 같은경우, Next를 Pre 뒤로 붙인후, rank++ 해준다.
			(pre->rank)++;
	}	


}	
Node* Find_Set(Node* ptr) { // 노드 ptr이 속한 집합을 알아낸다.(해당 루트노드 리턴)
	// ptr의 root 포인터가 자신과 같다면, 루트 노드이므로 해당노드를 return 한다.
	if (ptr->root == ptr)	return ptr;
	else // 그렇지 않으면 재귀를 통해 루트노드로 올라간다.
		Find_Set(ptr->root);
}