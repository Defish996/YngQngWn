#include "Add.h"  
#include "Sub.h"  
#include "Mul.h"  
#include "Div.h"  

int main()
{
    int x = 10;
    int y = 20;
    printf("%d + %d = %d\n", x, y, Add(x, y));
    printf("%d - %d = %d\n", x, y, Sub(x, y));
    printf("%d * %d = %d\n", x, y, Mul(x, y));

    return 0;
}
