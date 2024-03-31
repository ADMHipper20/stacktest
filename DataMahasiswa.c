#include <stdio.h>
#include <string.h>

struct MHS
{
    int nim[3];
    float IPK[3];
    char namaLengkap[3][40], alamat[3][100];
};

void showData(struct MHS *mhs, int banyakData){
    // Menampilkan seluruh data Mahasiswa
    printf("NIM        Nama                 IPK        Alamat\n");
    for (int i = 0; i < banyakData; i++){
        printf("%-10d %-20s %-10.2f %s\n", mhs->nim[i], mhs->namaLengkap[i], mhs->IPK[i], mhs->alamat[i]);
    }
    printf("\n");
}

void inputData(struct MHS *mhs, int banyakData){
    // Memasukkan tiap data struct, sesuai dengan Opsi yang dipilih
    for (int i = 0; i < banyakData; i++){
        printf("Masukkan NIM: ");
        scanf("%d", &mhs->nim[i]);
        printf("Masukkan Nama lengkap: ");
        scanf(" %[^\n]", mhs->namaLengkap[i]);
        printf("Masukkan Alamat Rumah: ");
        scanf(" %[^\n]", mhs->alamat[i]);
        printf("Masukkan IPK: ");
        scanf("%f", &mhs->IPK[i]);
    }
}

void showDataByGrade(struct MHS *mhs){
    // Menampilkan data berdasarkan Nilai IPK dibawah 3.00
    printf("NIM        Nama                 IPK        Alamat\n");
    for (int i = 0; i < 3; i++){
        if (mhs->IPK[i] != 0 && mhs->IPK[i] < 3.00){
            printf("%-10d %-20s %-10.2f %s\n", mhs->nim[i], mhs->namaLengkap[i], mhs->IPK[i], mhs->alamat[i]);
        }
    }
    printf("\n");
}

void sortNIM(struct MHS *mhs) {
    int sizeData = sizeof(mhs->nim)/sizeof(int);

    for (int i = 0; i < sizeData - 1; i++) {
        for (int j = 0; j < sizeData - i - 1; j++) {
            if (mhs->nim[j] > mhs->nim[j+1]) {
                // Menukar elemen nim
                int tempNIM = mhs->nim[j];
                mhs->nim[j] = mhs->nim[j+1];
                mhs->nim[j+1] = tempNIM;

                // Menukar elemen IPK
                float tempIPK = mhs->IPK[j];
                mhs->IPK[j] = mhs->IPK[j+1];
                mhs->IPK[j+1] = tempIPK;

                // Menukar elemen namaLengkap
                char tempNamaLengkap[40];
                strcpy(tempNamaLengkap, mhs->namaLengkap[j]);
                strcpy(mhs->namaLengkap[j], mhs->namaLengkap[j+1]);
                strcpy(mhs->namaLengkap[j+1], tempNamaLengkap);

                // Menukar elemen alamat
                char tempAlamat[100];
                strcpy(tempAlamat, mhs->alamat[j]);
                strcpy(mhs->alamat[j], mhs->alamat[j+1]);
                strcpy(mhs->alamat[j+1], tempAlamat);
            }
        }
    }
}

void showDataByAscendNIM(struct MHS *mhs){
    // Menampilkan data berdasarkan urutan NIM terkecil
    for (int i = 0; i < 3; i++){
        printf("%-10d %-20s %-10.2f %s\n", mhs->nim[i], mhs->namaLengkap[i], mhs->IPK[i], mhs->alamat[i]);
    }
    printf("\n");
}

void editData(struct MHS *mhs){
    int inputEdit;

    // Memasukkan nilai Input untuk data Mahasiswa yang akan diubah
    printf("Pilih Data Mahasiswa: ");
    scanf("%d", &inputEdit);

    printf("NIM        Nama                 IPK        Alamat\n");
    for (int i = inputEdit - 1; i < inputEdit; i++){
        printf("%-10d %-20s %-10.2f %s\n", mhs->nim[i], mhs->namaLengkap[i], mhs->IPK[i], mhs->alamat[i]);
        printf("Masukkan NIM: ");
        scanf("%d", &mhs->nim[i]);
        printf("Masukkan Nama lengkap: ");
        scanf(" %[^\n]", mhs->namaLengkap[i]);
        printf("Masukkan Alamat Rumah: ");
        scanf(" %[^\n]", mhs->alamat[i]);
        printf("Masukkan IPK: ");
        scanf("%f", &mhs->IPK[i]);
    }
}

int main(){
    struct MHS mhs;
    int input, banyakData;
    
    // Melakukan Perulangan do-while dan Switch Case untuk Opsi yang ditampilkan
    do{
        printf("1. Lihat seluruh data Mahasiswa\n");
        printf("2. Masukkan 1 data Mahasiswa\n");
        printf("3. Masukkan 3 data Mahasiswa\n");
        printf("4. Lihat data Mahasiswa(IPK < 3.00)\n");
        printf("5. Lihat data Mahasiswa(NIM Ascending)\n");
        printf("6. Edit data Mahasiswa\n");
        printf("0. Exit\n");
        printf("Masukkan Pilihan: ");
        scanf("%d", &input);

        switch (input){
        case 1:
            showData(&mhs, banyakData);
            break;
        case 2:
            banyakData = 1;
            inputData(&mhs, banyakData);
            break;
        case 3:
            banyakData = 3;
            inputData(&mhs, banyakData);
            break;
        case 4:
            showDataByGrade(&mhs);
            break;
        case 5:
            sortNIM(&mhs);
            showDataByAscendNIM(&mhs);
            break;
        case 6:
            editData(&mhs);
            break;
        case 0:
            printf("exit. . .");
            break;
        default:
            break;
        }
    } while (input != 0);
}