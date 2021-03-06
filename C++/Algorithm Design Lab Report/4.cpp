#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value, weight;
};

bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n){
    sort(arr, arr + n, cmp);
    int curWeight = 0;
    double finalvalue = 0.0;
    for (int i = 0; i < n; i++) {
        if(curWeight + arr[i].weight <= W){
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }else{
            int remain = W - curWeight;
            finalvalue += arr[i].value * ((double) remain / arr[i].weight);
            break;
        }
    }
    return finalvalue;
}
int main(){
    int w, n;
    cin >> w >> n;
    Item arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].value >> arr[i].weight;
    }
    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(w, arr, n);
    return 0;
}
// 50 3
// 60 10
// 100 20
// 120 30
// Maximum value in Knapsack = 240
