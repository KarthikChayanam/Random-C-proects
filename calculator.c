#include <stdio.h>
#include <math.h>

void add()
{
    int i,num;
    float sum=0;
    float arr[20];
    printf("Enter the number of numbers you want added : ");
    scanf("%d", &num);

    for (i=0;i<num;i++){
        printf("The %d number is : ",(i+1));
        scanf("%f",&arr[i]);
        sum += arr[i];
    }

    printf("The sum of the numbers is %.2f",sum);
}

void minus()
{
    int i;
    float num, diff, add, ori;
    float arr[20];
    printf("Enter the number of numbers you want subtracted : ");
    scanf("%f", &num);
    printf("Enter 1 number : ");
    scanf("%f",&ori);

    for (i=0;i<num-1;i++){
        printf("The %d number is : ",(i+2));
        scanf("%f",&arr[i]);
        add += arr[i];
    }

    diff = ori-add;
    printf("The difference of the numbers is %.2f",diff);
}

void multi()
{
    int i,num;
    float pro=0;
    float arr[20];
    printf("Enter the number of numbers you want multiplied : ");
    scanf("%d", &num);

    for (i=0;i<num;i++){
        printf("The %d number is : ",(i+1));
        scanf("%f",&arr[i]);
        pro *= arr[i];
    }

    printf("The sum of the numbers is %.2f",pro);
}


void divi()
{
    float num, den, quo, rem;
    printf("Enter your numerator : ");
    scanf("%f",&num);
    printf("Enter your denominator : ");
    scanf("%f",&den);

    quo = num/den;

    printf("The quotient is %.2f", quo);

}

void expo()
{
    int i;
    float num, exp, tot=1.0;
    printf("Enter your number : ");
    scanf("%f",&num);
    printf("Enter the power : ");
    scanf("%f",&exp);

    for (i=0; i<exp; i++)
        tot *= num;

    printf("The total is %.2f", tot);

}

void rootss()
{
    float num, exp, tot=1.0;
    printf("Enter your number : ");
    scanf("%f",&num);
    printf("Enter the root power : ");
    scanf("%f",&exp);

    tot = pow(num, 1.0/exp);

    printf("The total is %.2f", tot);

}


void sinn()
{
    float num, ans, rads;
    rads = 3.14159265/180;
    printf("Enter the angle in degrees : ");
    scanf("%f",&num);
    ans = sin(num*rads);
    printf("The sine value is %.2f",ans);

}


void coss()
{
    float num, ans, rads;
    rads = 3.14159265/180;
    printf("Enter the angle in degrees : ");
    scanf("%f",&num);
    ans = cos(num*rads);
    printf("The cosine value is %.2f",ans);

}


void tann()
{
    float num, ans, rads;
    rads = 3.14159265/180;
    printf("Enter the angle in degrees : ");
    scanf("%f",&num);
    ans = tan(num*rads);
    printf("The tan value is %.2f",ans);

}


void ln()
{
    float num, ans;
    printf("Enter the number you want to find log : ");
    scanf("%f",&num);
    ans = log(num);
    printf("The ln value is %.2f",ans);

}


void main()
{
    int ch,ch1;
    printf("\nWelcome to COMPLEX CALCULATOR");
    printf("\n==============================================");
    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Division");
    printf("\n5. Exponent");
    printf("\n6. Roots");
    printf("\n7. sin");
    printf("\n8. cos");
    printf("\n9. tan");
    printf("\n10. natural log");
    printf("\nEnter your operator : ");
    scanf("%d",&ch);
    printf("\n");

    if (ch == 1)
        add();
    else if (ch == 2)
        minus();
    else if (ch == 3)
        multi();
    else if (ch == 4)
        divi();
    else if (ch == 5)
        expo();
    else if (ch == 6)
        rootss();
    else if (ch == 7)
        sinn();
    else if (ch == 8)
        coss();
    else if (ch == 9)
        tann();
    else if (ch == 10)
        ln();
    else{
        printf("Invalid Entry\n");
        printf("Try again\n");
        main();
    }


    printf("\n");
    printf("Do you want to calculate something else ?(1.yes/2.no) : ");
    scanf("%d",&ch1);
    if (ch1 == 1)
        main();
    else
        printf("Thank you!!");

}