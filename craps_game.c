/*
-------------------------------------------------------------------------------------------------------------------------
Craps hemen hemen dünyanın her yerinde bilinen, iki zarla oynanan bir kumardır.

Oyunun kuralları şöyledir :
Zarları atacak oyuncu oyunu kasaya karşı oynar. 
Atılan iki zarın toplam değeri 7 ya da 11 ise oyuncu kazanır. 
Atılan iki zarın toplam değeri 2, 3, 12 ise oyuncu kaybeder. (Buna craps denir!)

İki zarın toplam değeri yukarıdakilerin dışında bir değer ise (yani 4, 5, 6, 8, 9, 10) oyun şu şekilde sürer :
Oyuncu aynı sonucu buluncaya kadar zarları tekrar atar. 
Eğer aynı sonucu bulamadan
önce oyuncu 7 atarsa (yani atılan iki zarın toplam değeri 7 olursa) oyuncu kaybeder.
Eğer 7 gelmeden önce oyuncu aynı sonucu tekrar atmayı başarırsa , kazanır.

Birkaç örnek :
##Oyuncunun attığı zarlar##         ##Oyun sonucu##
11                                  Oyuncu kazanır
3                                   Oyuncu kaybeder
9 8 6 3 12 5 8 4 2 4 9              Oyuncu kazanır
6 5 8 9 2 3 7                       Oyuncu kaybeder
7                                   Oyuncu kazanır
10 4 8 11 8 3 6 5 4 9 10            Oyuncu kazanır
-------------------------------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define     NKEZ        1000000

int oyun_devami(int);

int zar_at()
{
    int zar1 = rand() % 6 + 1;
    int zar2 = rand() % 6 + 1;
    return zar1 + zar2;
}

int oyun()
{
    int zar_toplam = zar_at();
    switch (zar_toplam)
    {
    case 7 : return 1;
    case 11: return 1;
    case 2 : return 0; 
    case 3 : return 0; 
    case 12: return 0; 
    }
    return oyun_devami(zar_toplam);
}

// Oyuncu 4, 5, 6, 8, 9, 10 atmissa oyunun devami
int oyun_devami(int zar_toplam)
{
    int yeni_zar;

    for(;;)
    {
        yeni_zar = zar_at();
        if(yeni_zar == zar_toplam)
            return 1;
        if(yeni_zar == 7)
            return 0;
    }
}

int main()
{
    int i;
    int kazanma_sayisi;

    srand(time(0));

    for(i = 0; i < NKEZ; i++)
        kazanma_sayisi += oyun();
    printf("kazanma olasılığı = %lf\n", (double)kazanma_sayisi / NKEZ);
}
