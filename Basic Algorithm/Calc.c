#include<stdio.h>
int main()
{
    float a,b,c;
    int x,y,f,d;
    printf("Enter Numbers= ");
    while((scanf("%f %f",&a,&b)!=EOF))
    {
        start:
        f=0;
        printf("For Addition press 1 \nFor Subtraction press 2 \nFor Multiplication press 3 \nFor Division press 4\n");
        scanf("%d",&y);
        switch(y)
        {
        case 1:
            c=a+b;
            printf("%.2f\n",c);
            break;
        case 2:
            if(a>b)
                c=a-b;
            else
                c=b-a;
            printf("%.2f\n",c);
            break;
        case 3:
            c=a*b;
            printf("%.2f\n",c);
            break;
        case 4:
            if(b==0)
            {
                shihan:
                printf("Undefined!!! Divisor can't be 0 \nEnter new divisor except 0\n");
                scanf("%f",&b);
                if(b == 0)
                {
                    goto shihan;
                }
                c=a/b;
                printf("%.2f",c);
            }
            else
            {
                c=a/b;
                printf("%.2f\n",c);
            }
            break;
        default:
            printf("Invalid choice!!!\n");
            goto start;
            break;

        }
        if(f>0)
        {
        loop:
            printf("Enter the second number= ");
            scanf("%f",&b);
            printf("Again For Addition press 1 \nFor Subtraction press 2 \nFor Multiplication press 3 \nFor Division press 4\n");
            scanf("%d",&y);
        switch(y)
        {
        case 1:
            c=a+b;
            printf("%.2f",c);
            break;
        case 2:
            if(a>b)
                c=a-b;
            else
                c=b-a;
            printf("%.2f",c);
            break;
        case 3:
            c=a*b;
            printf("%.2f",c);
            break;
        case 4:
            if(b==0)
            {
                last:
                printf("Undefined!!! Divisor can't be 0 \nEnter new divisor except 0\n");
                scanf("%f",&b);
                if(b==0)
                {
                    goto last;
                }
                c=a/b;
                printf("%.2f",c);
            }
            else
            {
                c=a/b;
                printf("%.2f",c);
            }
            break;
        default:
            printf("Invalid choice!!!\n");
            goto loop;
            break;

        }
        }
        f++;
        finish:
        printf("\nTo use previous number press 1 \nFor new input press 2 \nTo terminate the calculation press 3\n");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            a=c;
            goto loop;
            break;
        case 2:
            printf("Enter Numbers= ");
            scanf("%f %f",&a,&b);
            goto start;
            break;
        case 3:
            s:
            printf("Are you sure?\nPress 1 for YES or press 2 for No\n");
            scanf("%d",&d);
            if(d==1)
                break;
            else if(d == 2)
                goto finish;
            else
            {
                printf("Invalid choice!!!\n");
                goto s;
            }
            break;
        default:
            printf("Invalid choice!!!\n");
            goto finish;
            break;
        }


    }
    return 0;
}
