/*
Diyelim ki tuttuğunuz sayı 4564. Belirlediğimiz en büyük ve en küçük sayı ise sırasıyla 6544 ve 4456. 
Şimdi büyük sayıdan küçük sayıyı çıkaralım: 6544 – 4456 = 2088. Sonrasında da elde ettiğimiz sayıyı kullanarak aynı işlemleri tekrar­layalım: 
8820 – 0288 = 8532 ve 8532 – 2358 =6174. Er ya da geç ulaşacağınız sayı 6174 olacaktır. 
Bu sayıya ulaştığımızda işlem kendini tekrar eder ve her seferinde 6174’e döner.
en fazla 2 basamak aynı olabilir.
*/

#include <stdio.h>

int* swap(int basamaklar[4]);
int kaprekarHesaplama(int sayi);

int main()
{
    int sayi, sayac = 0, fark;
    do
    {
        printf("4 basamakli, en fazla iki basamaği ayni olan bir sayi giriniz: ");
        scanf("%d", &sayi);
    }while(!((sayi / 1000) > 0 && (sayi / 1000) < 10));
    
    do
    {
        ++sayac;
        fark = kaprekarHesaplama(sayi);
        if(fark == -1)
        {
            return 0;
        }
        printf("%d.adimdaki fark: %d\n", sayac, fark);
        sayi = fark;
    }while(fark != 6174); 

    printf("\n%d adim sonunda kaprekar sabitini elde ettik. (iki sayinin farki %d oldu.)\n", sayac, fark);

return 0; 
}

int kaprekarHesaplama(int sayi)
{
    int basamaklar[4], max_sayi, min_sayi, fark, kontrol = 0;
    int* swapped;

    basamaklar[0] = sayi % 10;          //birler bas
    basamaklar[1] = (sayi / 10) % 10;   //onlar bas
    basamaklar[2] = (sayi / 100) % 10;  //yüzler bas
    basamaklar[3] = (sayi / 1000) % 10; //binler bas    

    for(int i = 0; i < 4; i++)
    {
        for(int j = i + 1; j < 4; j++)
        {
            if(basamaklar[i] == basamaklar[j])
            {
                kontrol++;
                if(kontrol > 2)
                {
                    printf("girilen sayinin iki rakamindan fazlasi esit olamaz");
                    return -1;
                }
            }
        }
    }

    swapped = swap(basamaklar);

    max_sayi = (swapped[0] * 1000) + (swapped[1] * 100) + (swapped [2] * 10) + swapped[3];
    min_sayi = swapped[0] + (swapped[1] * 10) + (swapped [2] * 100) + (swapped[3] * 1000);

    printf("\nmax sayi: %d    min sayi: %d\n", max_sayi, min_sayi);

    fark = max_sayi - min_sayi;

    return fark;
}


int* swap(int basamaklar[4])
{
    int temp;

    for(int i = 0; i < 4; i++)
    {
            for(int j = 0; j < 4; j++)
            {
                if(basamaklar[i] > basamaklar[j])
                {
                    temp = basamaklar[j];
                    basamaklar[j] = basamaklar[i];
                    basamaklar[i] = temp;   //döngüler tamamlandığında dizinin 0.elemanında en büyük basamak, dizinin 3. elemanında en küçük sayı olacak.
                }

                
            }
    }

        return basamaklar;
}
