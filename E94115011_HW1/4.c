#include<stdio.h>

int main()

{ 

    int f, i, j;

    int h[9] = {0}, x[6] = {0}, y[6] = {0}, z[1] = {0}; 

    FILE *input = fopen("../input/3.txt", "r");

    for(i = 0; i < 9; i++) fscanf(input, "%d", &h[i]);

    for(i = 0; i < 6; i++) fscanf(input, "%d", &x[i]);

    for(i = 0; i < 6; i++) fscanf(input, "%d", &y[i]);

    fclose(input);

    int *p_x = &x[0] ;

    int *p_h = &h[0] ;

    int *p_y = &y[0] ;

    int *p_z = &z[0] ;

    int temp1 = 0;

    int temp2 = 0;

    for (i = 0; i < 3; i++) { 

        p_x = &x[0];



        for (j = 0; j < 2; j++) {

            p_h = &h[i*3];



            for (f = 0; f < 3; f++) {

                temp1 = 0;

                asm volatile(

                "mul %[p_z_out], %[p_h], %[p_x]\n\t"

                "add %[temp1], %[p_y_in], %[p_z_in]\n\t"

                "add %[p_y_out], %[temp1], %[temp2]\n\t"

                : [p_z_out] "=r" (*p_z), [p_y_out] "=r" (*p_y), [temp1] "=r" (temp1)

                : [p_h] "r" (*p_h), [p_x] "r" (*p_x), [p_y_in] "r" (*p_y), [p_z_in] "r" (*p_z), [temp2] "r" (temp2)

                );

                p_h++;

                p_x += 2;

            }

            p_x = &x[1];

            p_y++;

	    }

    }

    p_y = &y[0];

    for(i = 0; i < 6; i++)

    printf("%d ", *p_y++);

    printf("\n");

    return 0; 

}

