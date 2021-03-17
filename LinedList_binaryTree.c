#include <stdio.h>
/*
* 연결리스트를 이용한 이진 트리 만들기.
* 소속 : 숭실대학교 컴퓨터학부 (나)반
* 작성자(학번) : 김영도(20172612)
* 작성일시 : 31. August. 2020.
*/
typedef struct _TreeNode {
	char value ;
	struct _TreeNode* Left_Child;
	struct _TreeNode* Right_Child;
} TreeNode;
void treeInOrder(TreeNode* root) {
	if (root->Left_Child != NULL)
		treeInOrder(root->Left_Child);
	printf("%c",root->value);
	if (root->Right_Child != NULL)
		treeInOrder(root->Right_Child);
	return;
} // 트리를 중위 순회 방식으로 출력하는 함수이다. 
/* 재귀함수를 통한 Node를 찾는 함수
입력값 : Root노드 포인터, value 값
출력값 : 해당 노드의 포인터
작동 원리 : 재귀함수를 통해 각 노드들을 돌면서 Search_ptr에 Input 값(value 값)과
일치하는 노드를 대입한다. 이후 Search_ptr을 return 하여 해당노드의 포인터를 반환한다.*/
TreeNode* serachNode(TreeNode* ptr, char input) {
	TreeNode* Search_ptr = (TreeNode*)malloc(sizeof(TreeNode));
	Search_ptr->value = NULL;
	if (ptr != NULL) {
		Search_ptr = serachNode(ptr->Left_Child, input);
		if (Search_ptr->value != NULL)
			return Search_ptr;
		if (ptr->value == input) {
			Search_ptr = ptr;
			return Search_ptr;
		}
		Search_ptr = serachNode(ptr->Right_Child, input);
		if (Search_ptr->value != NULL)
			return Search_ptr;
	}
} // root 노드와 value 값을 통해 해당되는 노드를 Searching 해주는 함수
TreeNode* MakingNode(TreeNode* Node_ptr, char input_value) {
	Node_ptr->value = input_value;
	Node_ptr->Left_Child = NULL;
	Node_ptr->Right_Child = NULL;
	return Node_ptr;
}
int main() {
	int n = 0;
	scanf("%d", &n);
	getchar();
	TreeNode* root = NULL;
	TreeNode* head = NULL;
	if (0 < n && n < 27) {
		for (int i = 0; i < n; i++) {
			char parent, leftChild_char, rightChild_char;
			scanf("%c %c %c", &parent, &leftChild_char, &rightChild_char);
			getchar();
			if (head == NULL) {
				head = (TreeNode*)malloc(sizeof(TreeNode));
				head = MakingNode(head, parent);
				root = head;
			}
			head = serachNode(root, parent);
			head->value = parent;
			if (leftChild_char != '.') {
				head->Left_Child = (TreeNode*)malloc(sizeof(TreeNode));
				head->Left_Child = MakingNode(head->Left_Child, leftChild_char);
			}
			if (rightChild_char != '.') {
				head->Right_Child = (TreeNode*)malloc(sizeof(TreeNode));
				head->Right_Child = MakingNode(head->Right_Child, rightChild_char);
			}
		}
		treeInOrder(root);
	}
	else
		printf("N의 값의 범위는 26이하의 자연수 입니다.");
	return 0;
}

