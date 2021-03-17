#include <stdio.h>
#include <stdbool.h>
/*
*   Algo HW#11
*   - 0/1 Knapsack ( Best First Search )
*   ID : 20172612
*   Major : Computer Science & Engineering
*   Name : 김영도
*/
typedef struct SpaceTreeNode {
    int profit;
    int weight;
    int bound;
    int level;
}SpaceTreeNode;
/*큐 구현에 사용된 목록*/
#define MAX 100 
int front = -1;
int rear = -1;
SpaceTreeNode Priority_Queue[MAX];

int W = 9; // 총 무게의 한계
int w[6] = { 0,2,5,7,3,1 }; // 각 원소에 대한 무게치
int p[6] = { 0,20,30,35,12,3 }; // 각 원소에 대한 값어치
int maxprofit = 0; // 무게내에서 가질 수 있는 최대 이익
bool IsEmpty(void) {
    if (front == rear)//front와 rear가 같으면 큐는 비어있는 상태 
        return true;
    else return false;
}
bool IsFull(void) {
    int tmp = (rear + 1) % MAX; //원형 큐에서 rear+1을 MAX로 나눈 나머지값이
    if (tmp == front)//front와 같으면 큐는 가득차 있는 상태 
        return true;
    else
        return false;
}
void addq(SpaceTreeNode value) {
    rear = (rear + 1) % MAX;
    Priority_Queue[rear] = value;
}
SpaceTreeNode deleteq() {
    if (IsEmpty())
        printf("Priority_Queue is Empty.\n");
    else {
        front = (front + 1) % MAX;
        return Priority_Queue[front];
    }
}
int SetBound(SpaceTreeNode ptr, bool flag) {
    int total_weight = ptr.weight;
    int bound = ptr.profit;
    if (flag) { // 물건을 포함하는 경우에 대하여(왼쪽자식)
        total_weight = ptr.weight + w[ptr.level + 1];
        bound = ptr.profit + p[ptr.level + 1];
    }
    int j = ptr.level + 2; // 수준 i+1에 대해서(물건i에 대해서)
    int k = 0; // 가루로 생각하고 쪼개서 넣을 수준i의 값
    while ((total_weight + w[j] <= W) && (j <= 5)) {
        total_weight = total_weight + w[j];
        bound += p[j];
        j++;
    }
    k = j;
    if (k <= 5) // 최대 수준 5까지에 대해서
        bound = bound + (W - total_weight) * (p[k] / w[k]);
    return bound;
}
void priority_queue() { // queue 안에 값들을 bound 순으로 nonincreasing 정렬
    SpaceTreeNode ptr;
    for (int i = front + 1; i < rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (Priority_Queue[i].bound <= Priority_Queue[j].bound) {
                ptr = Priority_Queue[i];
                Priority_Queue[i] = Priority_Queue[j];
                Priority_Queue[j] = ptr;
            }
        }
    }
}
void breadth_first_search() {
    // SpaceTree 의 루트노드 생성.
    SpaceTreeNode rootNode = { 0,0,60,0 };
    SpaceTreeNode u, temp;
    addq(rootNode);

    while (!IsEmpty()) { // 큐가 비어있을때까지 반복
        priority_queue(); // 큐를 nonincreasing 정렬
        temp = deleteq(); // Priority_Queue로부터 원소pop
        // 유망성 검사
        if (temp.bound >= maxprofit) {
            // 아이템을 포함하는 자식마디 생성
            u.level = temp.level + 1;
            u.weight = temp.weight + w[temp.level + 1];
            u.profit = temp.profit + p[temp.level + 1];
            u.bound = SetBound(temp, true);

            // MaxProfit 갱신 Check
            if (u.weight <= W && u.profit > maxprofit) {
                // maxProfit 갱신
                printf("MaxProfit changed : %d --> %d\n", maxprofit, u.profit);
                maxprofit = u.profit;
                // 최적해를 얻어가는 노드 과정 출력
                printf("[ levele : %3d\tprice : %d\tweight : %d\tBound : %d]\n", u.level, u.profit, u.weight,u.bound);
            }
            if (u.bound > maxprofit && u.weight <= W)  {
                addq(u);
            }
            // 아이템을 포함하지 않는 자식마디 생성
            u.weight = temp.weight;
            u.profit = temp.profit;
            u.bound = SetBound(temp, false);
            if (u.bound > maxprofit)
                addq(u);
        }

    }
}
int main() {
    printf("Finding 0-1 knapsack with best first Search\n");
    breadth_first_search();
    return 0;
}