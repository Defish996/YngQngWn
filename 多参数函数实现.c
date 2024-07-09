#include <stdio.h>  
#include <stdarg.h>

// 使用哨兵值（如-1）作为输入结束的标志  
int sumWithSentinel(int first, ...) {  
    va_list args;  
    int sum = first;  
    va_start(args, first); // 初始化args以访问可变参数  

    // 注意：这里我们假设所有输入都是整数，并且以-1作为结束  
    int num;  
    while ((num = va_arg(args, int)) != -1) {  
        sum += num;  
    }  
    va_end(args); // 清理工作  
    return sum;  
}  

int main() {  
    printf("Sum: %d\n", sumWithSentinel(1, 2, 3, 4, -1));  
    return 0;  
}  