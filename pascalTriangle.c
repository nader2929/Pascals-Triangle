#include <stdio.h>
#include <stdlib.h>

int getFactorial(int num){
    int sum = 1;
    for(int x = num; x > 0; x--){
        sum = sum*x;
    }
    return sum;
}

//To get value formula is r!/p!(r-p)!
int getValueAtCoordinate(int r, int p){
    int value = 1;
    if(r == 0 && p == 0){
        return value;
    }
    int r_factorial;
    r_factorial = getFactorial(r);
    
    int p_factorial;
    p_factorial = getFactorial(p);

    int r_minus_p = r - p;
    if(r_minus_p == 0) r_minus_p = 1;
    int r_minus_p_factorial;
    r_minus_p_factorial = getFactorial(r_minus_p);

    value = r_factorial/(p_factorial*r_minus_p_factorial);

    return value;
}

int main(){
    int row;
    int position;
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter position: ");
    scanf("%d", &position);
    if(position > row){
        printf("The position you entered was larger than the row.\nThis is not possible\n");
    }
    printf("Row %d Position %d\n", row, position);
    
    int answer = getValueAtCoordinate(row, position);
    printf("The value is: %d\n", answer);
    
}

