#include <stdio.h>

int main() {
    int gelirSayisi;
    int giderSayisi;
    int stokSayisi;
    float gelirMiktari;
    float giderMiktari;
    int stokMiktari;
    float toplamGelir = 0;
    float toplamGider = 0;
    int toplamStok = 0;
    float karZarar;

    printf("Kaç adet gelir kaydı girmek istersiniz? ");
    scanf("%d", &gelirSayisi);
    for (int i = 0; i < gelirSayisi; i++) {
        printf("Gelir miktarını giriniz: ");
        scanf("%f", &gelirMiktari);
        toplamGelir += gelirMiktari;
    }

    printf("Kaç adet gider kaydı girmek istersiniz? ");
    scanf("%d", &giderSayisi);
    for (int i = 0; i < giderSayisi; i++) {
        printf("Gider miktarını giriniz: ");
        scanf("%f", &giderMiktari);
        toplamGider += giderMiktari;
    }

    printf("Kaç adet stok kaydı girmek istersiniz? ");
    scanf("%d", &stokSayisi);
    for (int i = 0; i < stokSayisi; i++) {
        printf("Stok miktarını giriniz: ");
        scanf("%d", &stokMiktari);
        toplamStok += stokMiktari;
    }

    printf("Toplam Gelir: %.2f\n", toplamGelir);
    printf("Toplam Gider: %.2f\n", toplamGider);
    printf("Toplam Stok: %d\n", toplamStok);

    karZarar = toplamGelir - toplamGider;
    if (karZarar > 0) {
        printf("Kar: %.2f\n", karZarar);
    } else if (karZarar < 0) {
        printf("Zarar: %.2f\n", karZarar);
    } else {
        printf("Kar/Zarar Yok\n");
    }

return 0;
}