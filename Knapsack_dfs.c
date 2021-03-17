#include <stdio.h>
#include <stdbool.h>
#define _CRT_SECURE_NO_WARNINGS
/*
*   Algo HW#11
*   - 0/1 Knapsack ( Depth First + backtracking )
*   ID : 20172612
*   Major : Computer Science & Engineering
*   Name : 김영도
*/
int sum = 0;
int W = 9; // 총 무게의 한계
int w[6] = { 0,2,5,7,3,1 }; // 각 원소에 대한 무게치
int p[6] = { 0,20,30,35,12,3 }; // 각 원소에 대한 값어치
int isInclude[6] = { 0,0,0,0,0,0 }; // 각 수준에 대한 포함여부 저장 배열
int bestset[6]; // 우리가 요구하는 답을 저장하는 배열
int maxprofit = 0;
bool promising(int i, int profit, int weight) {
    int j, k, total_weight;
    float bound;
    if (weight >= W)
        return false;
    else {
        /*
        무게의 총합이 W를 넘지 않은 상태에서
        i 수준의 bound를 비교한다.
        */
        j = i + 1; // 다음원소
        // bound를 찾는 과정중, 넣을 수 있는 원소를 최대한 넣고난 뒤의 다음원소 indicate
        bound = profit;
        total_weight = weight;
        // 무게치를 최대한 넣을 수 있을때까지 넣고, 남은 무게치에 대한 값어치는 가루로 생각해서 넣는다.
        while ((total_weight + w[j] <= W) && (j <= 5)) {
            total_weight = total_weight + w[j];
            bound += p[j];
            j++;
        }
        k = j;
        if (k <= 5) // 최대 수준 5까지에 대해서
        {
            bound = bound + (W - total_weight) * (p[k] / w[k]);

        }
        if (bound > (float)maxprofit) // bound를 갱신하고 나서, 이미 앞서 구한 값과 비교하여 새로운 최대값이 나온경우 갱신한다.
            return true;
        else
            return false;
    }
}
void makebestset() {
    for (int i = 1; i <= 6; i++) {
        bestset[i] = isInclude[i];
    }
}
void knapsack(int i, int profit, int weight) {
    if (weight <= W && profit > maxprofit) { // Maxprofit 에대한 갱신
        maxprofit = profit;
        makebestset();
    }

    if (promising(i, profit, weight)) { // i수준에서 유망하다면
       // 수준 i를 포함하는 경우
        isInclude[i + 1] = true;
        knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);


        // 수준 i를 포함하지 않는 경우
        isInclude[i + 1] = false;
        knapsack(i + 1, profit, weight);

    }
}
void Print_bestset() {
    for (int i = 1; i <= 5; i++) {
        if (bestset[i]) {
            printf("i: %d, w[%d]: %d, p[%d]: %d\n", i, i, w[i], i, p[i]);
            sum += p[i];
        }
    }
    printf("\n");
}
int main() {



    knapsack(0, 0, 0);
    Print_bestset();
    printf("sum: %d\n", sum);

    return 0;
}