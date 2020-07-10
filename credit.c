#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long inp = get_long("Number: ");

    if ((inp < (4*pow(10, 12))) || (inp > 55*pow(10, 15)))                          // evalúa longitud de dígitos ern la tarjeta
    {
        printf("INVALID\n");
    }
    else
    {
        int sumStL, sumTtL, checksum;           
        int n = 1, m = 0;
        int checkStL = 0, checkTtL  = 0;
        int checkLabel = 0;
        long pota, potb, potc, potd;
                                                                                    // inicio de algoritmo de Luhn
        do                                                                          // evalúa primera suma a partir del anteúltimo número
        {
            long a = (inp/(pow(10,(n+1))));                                         
            pota = inp - (a * (pow(10,(n+1))));
            
            long b = (inp/(pow(10, n)));
            potb = inp - (b * (pow(10,n)));
            
            
            sumStL = ((pota - potb) / pow(10,n)) * 2;
            
            if (sumStL >= 10)
            {
                sumStL = (sumStL/10) + (sumStL - ((sumStL/10) * 10));
            }
            
            checkStL += sumStL;

            n+=2;
        }
        while (sumStL >= 0 && n < 16);
        
        do                                                                          // evalúa segunda suma a partir del último número
        {
            long c = (inp/(pow(10,(m+1))));
            potc = inp - (c * (pow(10,(m+1))));

            long d = (inp/(pow(10, m)));
            potd = inp - (d * (pow(10,m)));
            
            sumTtL = ((potc - potd) / pow(10,m));
            
            checkTtL += sumTtL;

            m+=2;
            
        }
        while (sumTtL >= 0 && m < 16);
        
        checksum = checkStL + checkTtL;                                             // sumatoria de ambas sumas anteriores
        
        long s = inp;
        int digits = 0;
        
        do
        {
            s = s / 10;
            digits++;
        }
        while (s > 0);
        
        checkLabel = floor(inp/pow(10, digits-2));
        
        if (checksum % 10 == 0)                                                     // evalúa si el último dígito de la sumatoria es 0. Fin de algoritmo de Luhn
        {
            if (checkLabel == 35 || checkLabel == 37)                               // imprime marca de la tarjeta según primeros dígitos
            {
                printf("AMEX\n");
            }
            else if (checkLabel == 51 || checkLabel == 52 || checkLabel == 53 || checkLabel ==54 || checkLabel == 55)
            {
                printf("MASTERCARD\n");
            }
            else if (checkLabel == 4 || (checkLabel >= 40 && checkLabel <50))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
        
    }

}
