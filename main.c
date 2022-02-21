#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define maks
#include <time.h>
#include <assert.h>
#include <string.h>

void gotoxy(int x, int y){
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

typedef struct mahasiswa{
    char nama[50];
    int nim;
    float ipk;
    char progdi[50];
    char asal[50];
};

struct riwayat{
	char aktivitas[100];
}rwy[1000];

int fu = 5;
int bnyk;
struct mahasiswa mhs[50];
int total_rwy=0;


void menu(){
    int pil;
    system("color 17");
    system("cls");
    gotoxy(40,5);
    printf("+=====================================================+");
    gotoxy(40,7);
    printf("          Selamat Datang di Database Mahasiswa");
    gotoxy(40,8);
    printf("               ===Data Mahasiswa FTI===");
    gotoxy(40,10);
    printf("+-----------------------------------------------------+");
    gotoxy(40,12);
    printf("|                                                     |");
    gotoxy(40,13);
    printf("|   Silahkan Memilih Menu dibawah ini :               |");
    gotoxy(40,14);
    printf("|   1. Membuat Data                                   |");
    gotoxy(40,15);
    printf("|   2. Lihat Data                                     |");
    gotoxy(40,16);
    printf("|   3. Menambah Data                                  |");
    gotoxy(40,17);
    printf("|   4. Hapus Data                                     |");
    gotoxy(40,18);
    printf("|   5. Mengedit Data                                  |");
    gotoxy(40,19);
    printf("|   6. Mencari Data                                   |");
    gotoxy(40,20);
    printf("|   7. Riwayat Aktivasi Mahasiswa                     |");
    gotoxy(40,21);
    printf("|   8. Mengurutkan Data                               |");
    gotoxy(40,22);
    printf("|   9. Keluar                                         |");
    gotoxy(40,23);
    printf("|                                                     |");
    gotoxy(40,26);
    printf("+=====================================================+");
    gotoxy(40,24);
    printf("|                                                     |");
    gotoxy(44,24);
    printf("Silahkan Masukan Pilihan Anda : ");
    scanf("%d",&pil);
    switch(pil){
    case 1:
        menu1();
        menu();
        break;
    case 2:
        menu2();
        menu();
        break;
    case 3:
        menu3();
        menu();
        break;
    case 4:
        menu4();
        menu();
        break;
    case 5:
        menu();
        break;
    case 6:
    	menu6();
        menu();
        break;
    case 7:
        menu7();
        menu();
        break;
    case 8:
        menu8();
        menu();
        break;
    case 9:
        exit(0);
        break;
    default: gotoxy(40,27);printf("Pilihan Tidak Tersedia"); gotoxy(40,28);printf("Press Any KEy to Continue>>..");
        getch();
        menu();
        break;
    }
}

void vict(){
    system("cls");
    system("color 20");
    gotoxy(40,9);
    printf("|-------------------------------|");
    gotoxy(40,10);
    printf("|                               |");
    gotoxy(40,11);
    printf("|       Anda Telah Login!       |");
    gotoxy(40,12);
    printf("|         Hello Admin !         |");
    gotoxy(40,13);
    printf("|_______________________________|");
    gotoxy(40,14);
    printf("Press Any Key to Continue >> ");
    getch();
    menu();
}

void lose(){
    system("color 57");
    system("cls");
    gotoxy(40,9);
    printf("|-------------------------------|");
    gotoxy(40,10);
    printf("|                               |");
    gotoxy(40,11);
    printf("|Username / Password Anda Salah!|");
    gotoxy(40,12);
    printf("|    Silahkan Masukan Ulang!    |");
    gotoxy(40,13);
    printf("|                               |");
    gotoxy(40,14);
    printf("|_______________________________|");
    gotoxy(40,15);
    printf("Press Any Key to Continue >> ");
    getch();
    Login();
}

void Login(){
    char s[64],name[10],pwd[10];
    system("color 47");
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    assert(strftime(s, sizeof(s), "%c", tm));
    system("cls");
    gotoxy(40,9);
    printf("Selamat Datang di Database Mahasiswa\n");
    gotoxy(40,10);
    printf("====================================\n");
    gotoxy(40,13);
    printf("====================================\n");
    gotoxy(40,14);
    printf("%s\n", s);
    gotoxy(40,11);
    printf("Masukan Username (admin) : ");
    scanf(" %s", &name);
    gotoxy(40,12);
    printf("Masukan Password (admin) : ");
    int p=0;
    do{
        pwd[p]=getch();
        if(pwd[p]!='\r'){
            printf("*");
        }
        p++;
    }while(pwd[p-1]!='\r');
    pwd[p-1]='\0';
    if (strcmp(name,"admin")==0 && strcmp (pwd,"admin")==0 ) {
        vict();
    }else{
        lose();
    }
}

menu1(){
    system("color 0C");
    system("cls");
    gotoxy(23,3);
    printf("+===================================================================+");
    gotoxy(23,11);
    printf("+===================================================================+");
    gotoxy(54,5);
    printf("DATABASE");
    gotoxy(40,6);
    printf("== Membuat Database Mahasiswa ==");
    gotoxy(23,8);
    printf("+-------------------------------------------------------------------+");
    gotoxy(40,9);
    printf("Banyak Data maks yang ingin diinput %d ", fu);
    gotoxy(40,10);
    printf("Banyak Data yang ingin diinput  : ");
    scanf("%d", &bnyk);
    gets(mhs[0].nama);
    if (bnyk<1||bnyk>fu){
        gotoxy(40,12);
        printf("Data yang Dapat diinputkan : 5!!!");
        gotoxy(40,13);
        printf("Press Any Key to Continue >> ");
        getch();
        menu1();
        }else{
    for(int i=0;i<bnyk;i++){
        printf("\n\t\t\t::Data Mahasiswa Ke %d\n",i+1);

        printf("\t\t\t::Nama Mahasiswa\t: ");
        gets(mhs[i].nama);

        printf("\t\t\t::NIM Mahasiswa \t: ");
        scanf(" %d",&mhs[i].nim);

        printf("\t\t\t::IPK Mahasiswa \t: ");
        scanf(" %f",&mhs[i].ipk);
        gets(mhs[i].progdi);
        printf("\t\t\t::Progdi Mahasiswa \t: ");
        gets(mhs[i].progdi);

        printf("\t\t\t::Asal Mahasiswa \t: ");
        gets(mhs[i].asal);
        }
        }
        printf("\n\n\t\t\tTekan Enter Untuk Kembali Ke Menu");
        strcpy(rwy[total_rwy].aktivitas, "Admin Membuat Database");
        total_rwy+=1;
        getch();
        system("cls");
}

menu2(){
    system("color 09");
    system("cls");
    gotoxy(23,3);
    printf("+===================================================================+");
    gotoxy(23,8);
    printf("+===================================================================+");
    gotoxy(54,5);
    printf("DATA MAHASISWA");
    gotoxy(40,6);
    printf("== Data Mahasiswa yang Sudah di input ==");
    gotoxy(24,9);
    printf("NAMA");
    gotoxy(40,9);
    printf("NIM");
    gotoxy(51,9);
    printf("IPK");
    gotoxy(62,9);
    printf("PROGDI");
    gotoxy(83,9);
    printf("ASAL");
    gotoxy(23,10);
    printf("+-------------------------------------------------------------------+");
    gotoxy(23,11);
    for(int i=0;i<bnyk;i++){
        printf(" %-12s %-12d %-9.2f %-19s %-21s\n", mhs[i].nama, mhs[i].nim, mhs[i].ipk, mhs[i].progdi, mhs[i].asal);
    gotoxy(23,11+i+1);
    }
    gotoxy(23,20);
    printf("+-------------------------------------------------------------------+");
    gotoxy(23,23);
    printf("Tekan Enter Untuk Lanjut....");
    strcpy(rwy[total_rwy].aktivitas, "Admin Melihat Data");
    total_rwy+=1;
    getch();
}

menu3(){
    system("cls");
    int bnyk1;
    system("color 0C");
    system("cls");
    gotoxy(23,3);
    printf("+===================================================================+");
    gotoxy(23,11);
    printf("+===================================================================+");
    gotoxy(54,5);
    printf("DATABASE");
    gotoxy(40,6);
    printf("== Membuat Database Mahasiswa ==");
    gotoxy(23,8);
    printf("+-------------------------------------------------------------------+");
    gotoxy(40,9);
    printf("Data maksimum yang dapat ditambahkan  : %d", fu-bnyk);
    gotoxy(40,10);
    printf("Banyaknya Data Yang Ditambah          : ");
    scanf("%d", &bnyk1);
    printf("\n\n");
    gets(mhs[bnyk].nama);
    if (bnyk1<1||bnyk1>fu-bnyk){
        gotoxy(40,12);
        printf("Data yang Dapat diinputkan : 5!!!");
        gotoxy(40,13);
        printf("Press Any Key to Continue >> ");
        getch();
        menu3();
    }else{
        for(int i=0; i<bnyk1; i++){
        printf("\n\t\t\t::Data Mahasiswa Ke - %d\n",bnyk+1);
        printf("\t\t\t::Nama Mahasiswa\t: ");
        gets(mhs[bnyk].nama);
        printf("\t\t\t::NIM Mahasiswa \t: ");
        scanf("%d", &mhs[bnyk].nim);
        printf("\t\t\t::IPK Mahasiswa \t: ");
        scanf("%f", &mhs[bnyk].ipk);
        gets(mhs[bnyk].progdi);
        printf("\t\t\t::Progdi Mahasiswa \t: ");
        gets(mhs[bnyk].progdi);
        printf("\t\t\t::Asal Mahasiswa \t: ");
        gets(mhs[bnyk].asal);
        bnyk++;
        }
    }
    printf("\n\n\t\t\t\t\tTekan Enter Untuk Kembali Ke Menu");
    strcpy(rwy[total_rwy].aktivitas, "Admin Menambah Data");
    total_rwy+=1;
    getch();
    system("cls");
    }

menu4(){
    char ans;
    int i,n;
    int nim;
    system("color 0C");
    system("cls");
    gotoxy(23,3);
    printf("+===================================================================+");
    gotoxy(23,10);
    printf("+===================================================================+");
    gotoxy(54,5);
    printf("DATABASE");
    gotoxy(40,6);
    printf("== Menghapus data Mahasiswa ==");
    gotoxy(23,8);
    printf("+-------------------------------------------------------------------+");
    gotoxy(40,9);
    printf("Masukan nim yang ingin dihapus : ");
    scanf("%d", &nim);

    for (i=0; i<bnyk; i++){
        if (nim == mhs[i].nim){
            printf("\n\t\t\t::Data Mahasiswa Ke - %d\n",i);
            printf("\n\t\t\t::Nama Mahasiswa\t: %s",mhs[i].nama);
            printf("\n\t\t\t::NIM Mahasiswa \t: %d",mhs[i].nim);
            printf("\n\t\t\t::IPK Mahasiswa \t: %f",mhs[i].ipk);
            printf("\n\t\t\t::Progdi Mahasiswa \t: %s", mhs[i].progdi);
            printf("\n\t\t\t::Asal Mahasiswa \t: %s", mhs[i].asal);
            printf("\n\n\t\t\tMau dihapus?[y/n]");
            scanf(" %c", &ans);
                if(ans == 'y' || ans == 'Y'){
                    for(int j=i; j<=bnyk; j++){
                        mhs[j] = mhs[j + 1];
                    }bnyk--;
                    printf("\n\t\t\tData dengan nim %d telah dihapus", nim);
                    printf("\n\t\t\tTekan Enter Untuk Lanjut....");
                    strcpy(rwy[total_rwy].aktivitas, "Admin Menghapus Data");
                    total_rwy+=1;
                    getch();
                }else if(ans == 'n' || ans == 'N'){
                    printf("Tekan Enter Untuk Lanjut....");
                    getch();
                }
        }
    }
}

menu8(){
    int pili,i,j;
    struct mahasiswa temp;
    system("color 0C");
    system("cls");
    gotoxy(23,3);
    printf("+===================================================================+");
    gotoxy(23,10);
    printf("+===================================================================+");
    gotoxy(54,5);
    printf("DATABASE");
    gotoxy(40,6);
    printf("== Mengurutkan data Mahasiswa ==");
    gotoxy(23,8);
    printf("+-------------------------------------------------------------------+");
    gotoxy(30,12);
    printf("Urutkan berdasar : ");
    gotoxy(30,13);
    printf("1. Nama");
    gotoxy(30,14);
    printf("2. Nim");
    gotoxy(30,15);
    printf("3. Ipk");
    gotoxy(30,16);
    printf("4.Progdi");
    gotoxy(30,17);
    printf("5.Asal");
    gotoxy(30,18);
    printf("Pilihan :");
    scanf("%d", &pili);
    switch(pili){
        case 1: for (i = 1; i < bnyk; i++){
                    for (j = 0; j < bnyk - i; j++) {
                        if (strcmp(mhs[j].nama, mhs[j + 1].nama) > 0) {
                            temp = mhs[j];
                            mhs[j] = mhs[j + 1];
                            mhs[j + 1] = temp;
                        }
                    }
                }
                strcpy(rwy[total_rwy].aktivitas, "Admin Mengurutkan Data dari Nama");
                total_rwy+=1;
            break;
        case 2: for (i = 0; i < bnyk - 1; i++){
                    for (j = 0; j < (bnyk -i-1); j++){
                        if (mhs[j].nim > mhs[j + 1].nim){
                            temp = mhs[j];
                            mhs[j] = mhs[j + 1];
                            mhs[j + 1] = temp;
                        }
                    }
                }
                strcpy(rwy[total_rwy].aktivitas, "Admin Mengurutkan Data dari NIM");
                total_rwy+=1;
            break;
        case 3: for (i = 0; i < bnyk - 1; i++){
                    for (j = 0; j < (bnyk -i); j++){
                        if (mhs[j].ipk > mhs[j + 1].ipk){
                            temp = mhs[j];
                            mhs[j] = mhs[j + 1];
                            mhs[j + 1] = temp;
                        }
                    }
                }
                strcpy(rwy[total_rwy].aktivitas, "Admin Mengurutkan Data dari IPK");
                total_rwy+=1;
            break;
        case 4: for (i = 1; i < bnyk; i++){
                    for (j = 0; j < bnyk - i; j++) {
                        if (strcmp(mhs[j].progdi, mhs[j + 1].progdi) > 0) {
                            temp = mhs[j];
                            mhs[j] = mhs[j + 1];
                            mhs[j + 1] = temp;
                        }
                    }
                }
                strcpy(rwy[total_rwy].aktivitas, "Admin Mengurutkan Data dari Prodi");
                total_rwy+=1;
            break;
        case 5 : for (i = 1; i < bnyk; i++){
                    for (j = 0; j < bnyk - i; j++) {
                        if (strcmp(mhs[j].asal, mhs[j + 1].asal) > 0) {
                            temp = mhs[j];
                            mhs[j] = mhs[j + 1];
                            mhs[j + 1] = temp;
                        }
                    }
                }
                strcpy(rwy[total_rwy].aktivitas, "Admin Mengurutkan Data dari Asal");
                total_rwy+=1;
            break;
        default : gotoxy(30,19);printf("Pilihan tidak Tersedia!");getch();menu8();
   }
menu2();
}

menu6(){
	system("color FC");
	int pilihan, i, nim, ipk;
	char nama[50], progdi[50], asal[50];
			system("cls");
			gotoxy(23,3);
			printf("+===================================================================+");
			gotoxy(53,5);
			printf("DATABASE");
			gotoxy(40,6);
			printf("== Mencari Database Mahasiswa ==");
			gotoxy(23,8);
			printf("+-------------------------------------------------------------------+");
			gotoxy(35,10);printf("Apa yang akan Anda cari 	? \n");
			gotoxy(35,11);printf("1. Nama Mahasiswa\n");
			gotoxy(35,12);printf("2. NIM Mahasiswa\n");
			gotoxy(35,13);printf("3. IPK Mahasiswa\n");
			gotoxy(57,11);printf("4. Progdi Mahasiswa\n");
			gotoxy(57,12);printf("5. Asal Mahasiswa\n");
			gotoxy(35,14);printf("Pilihan Anda 		:	");
			scanf("%d",&pilihan);
			gotoxy(23,16);
			printf("+-------------------------------------------------------------------+");
    		if (pilihan==1){
				gotoxy(35,15);printf("Nama Mahasiswa yang dicari 	: ");
				scanf("%s",&nama);
				gotoxy(23,16);
				printf("+-------------------------------------------------------------------+");
				system("cls");
				gotoxy(23,3);
				printf("+===================================================================+");
				gotoxy(23,8);
				printf("+===================================================================+");
				gotoxy(54,5);
				printf("DATA MAHASISWA");
				gotoxy(40,6);
				printf("== Data Mahasiswa yang telah diinput ==");
				gotoxy(24,9);
				printf("NAMA");
				gotoxy(40,9);
				printf("NIM");
				gotoxy(51,9);
				printf("IPK");
				gotoxy(62,9);
				printf("PROGDI");
				gotoxy(83,9);
				printf("ASAL");
				gotoxy(23,10);
				printf("+-------------------------------------------------------------------+");
				for(i=0;i<=bnyk;i++){
					if (strcmp(nama,mhs[i].nama)==0){
						gotoxy(24,11);printf(" %s",mhs[i].nama);
						gotoxy(40,11);printf("%d",mhs[i].nim);
						gotoxy(46,11);printf("%9.2f",mhs[i].ipk);
						gotoxy(62,11);printf("%s",mhs[i].progdi);
						gotoxy(83,11);printf("%s",mhs[i].asal);
						printf("\n");
						printf("\t\t       +-------------------------------------------------------------------+");
					}
				}strcpy(rwy[total_rwy].aktivitas, "Admin Mencari Data");
                total_rwy+=1;
				printf("\n\t\t\tTekan enter untuk kembali ke menu");
			getch();
			}
			else if (pilihan==2){
				gotoxy(35,15);printf("NIM Mahasiswa yang dicari 	: ");
				scanf("%d",&nim);
				gotoxy(23,16);
				printf("+-------------------------------------------------------------------+");
				system("cls");
				gotoxy(23,3);
				printf("+===================================================================+");
				gotoxy(23,8);
				printf("+===================================================================+");
				gotoxy(54,5);
				printf("DATA MAHASISWA");
				gotoxy(40,6);
				printf("== Data Mahasiswa yang telah diinput ==");
				gotoxy(24,9);
				printf("NAMA");
				gotoxy(40,9);
				printf("NIM");
				gotoxy(51,9);
				printf("IPK");
				gotoxy(62,9);
				printf("PROGDI");
				gotoxy(83,9);
				printf("ASAL");
				gotoxy(23,10);
				printf("+-------------------------------------------------------------------+");
				for(i=0;i<=bnyk;i++){
					if (mhs[i].nim==nim){
						gotoxy(24,11);printf(" %s",mhs[i].nama);
						gotoxy(40,11);printf("%d",mhs[i].nim);
						gotoxy(46,11);printf("%9.2f",mhs[i].ipk);
						gotoxy(62,11);printf("%s",mhs[i].progdi);
						gotoxy(83,11);printf("%s",mhs[i].asal);
						printf("\n");
						printf("\t\t       +-------------------------------------------------------------------+");
					}
				}strcpy(rwy[total_rwy].aktivitas, "Admin Mencari Data");
                total_rwy+=1;
				printf("\n\t\t\tTekan enter untuk kembali ke menu");
			getch();
			}
			else if (pilihan==3){
				gotoxy(35,15);printf("IPK Mahasiswa yang dicari 	: ");
				scanf("%d",&ipk);
				gotoxy(23,16);
				printf("+-------------------------------------------------------------------+");
				system("cls");
				gotoxy(23,3);
				printf("+===================================================================+");
				gotoxy(23,8);
				printf("+===================================================================+");
				gotoxy(54,5);
				printf("DATA MAHASISWA");
				gotoxy(40,6);
				printf("== Data Mahasiswa yang telah diinput ==");
				gotoxy(24,9);
				printf("NAMA");
				gotoxy(40,9);
				printf("NIM");
				gotoxy(51,9);
				printf("IPK");
				gotoxy(62,9);
				printf("PROGDI");
				gotoxy(83,9);
				printf("ASAL");
				gotoxy(23,10);
				printf("+-------------------------------------------------------------------+");
				for(i=0;i<=bnyk;i++){
					if (mhs[i].ipk==ipk){
						gotoxy(24,11);printf(" %s",mhs[i].nama);
						gotoxy(40,11);printf("%d",mhs[i].nim);
						gotoxy(46,11);printf("%9.2f",mhs[i].ipk);
						gotoxy(62,11);printf("%s",mhs[i].progdi);
						gotoxy(83,11);printf("%s",mhs[i].asal);
						printf("\n");
						printf("\t\t       +-------------------------------------------------------------------+");
					}
				}strcpy(rwy[total_rwy].aktivitas, "Admin Mencari Data");
                total_rwy+=1;
				printf("\n\t\t\tTekan enter untuk kembali ke menu");
			getch();
			}
			else if (pilihan==4){
				gotoxy(35,15);printf("NIM Mahasiswa yang dicari 	: ");
				scanf("%s",&progdi);
				gotoxy(23,16);
				printf("+-------------------------------------------------------------------+");
				system("cls");
				gotoxy(23,3);
				printf("+===================================================================+");
				gotoxy(23,8);
				printf("+===================================================================+");
				gotoxy(54,5);
				printf("DATA MAHASISWA");
				gotoxy(40,6);
				printf("== Data Mahasiswa yang telah diinput ==");
				gotoxy(24,9);
				printf("NAMA");
				gotoxy(40,9);
				printf("NIM");
				gotoxy(51,9);
				printf("IPK");
				gotoxy(62,9);
				printf("PROGDI");
				gotoxy(83,9);
				printf("ASAL");
				gotoxy(23,10);
				printf("+-------------------------------------------------------------------+");
				for(i=0;i<=bnyk;i++){
					if (strcmp(progdi,mhs[i].progdi)==0){
						gotoxy(24,11);printf(" %s",mhs[i].nama);
						gotoxy(40,11);printf("%d",mhs[i].nim);
						gotoxy(46,11);printf("%9.2f",mhs[i].ipk);
						gotoxy(62,11);printf("%s",mhs[i].progdi);
						gotoxy(83,11);printf("%s",mhs[i].asal);
						printf("\n");
						printf("\t\t       +-------------------------------------------------------------------+");
					}
				}strcpy(rwy[total_rwy].aktivitas, "Admin Mencari Data");
                total_rwy+=1;
				printf("\n\t\t\tTekan enter untuk kembali ke menu");
			getch();
			}
			else if (pilihan==5){
				gotoxy(35,15);printf("NIM Mahasiswa yang dicari 	: ");
				scanf("%s",&asal);
				gotoxy(23,16);
				printf("+-------------------------------------------------------------------+");
				system("cls");
				gotoxy(23,3);
				printf("+===================================================================+");
				gotoxy(23,8);
				printf("+===================================================================+");
				gotoxy(54,5);
				printf("DATA MAHASISWA");
				gotoxy(40,6);
				printf("== Data Mahasiswa yang telah diinput ==");
				gotoxy(24,9);
				printf("NAMA");
				gotoxy(40,9);
				printf("NIM");
				gotoxy(51,9);
				printf("IPK");
				gotoxy(62,9);
				printf("PROGDI");
				gotoxy(83,9);
				printf("ASAL");
				gotoxy(23,10);
				printf("+-------------------------------------------------------------------+");
				for(i=0;i<=bnyk;i++){
					if (strcmp(asal,mhs[i].asal)==0){
						gotoxy(24,11);printf(" %s",mhs[i].nama);
						gotoxy(40,11);printf("%d",mhs[i].nim);
						gotoxy(46,11);printf("%9.2f",mhs[i].ipk);
						gotoxy(62,11);printf("%s",mhs[i].progdi);
						gotoxy(83,11);printf("%s",mhs[i].asal);
						printf("\n");
						printf("\t\t       +-------------------------------------------------------------------+");
					}
				}
				strcpy(rwy[total_rwy].aktivitas, "Admin Mencari Data");
                total_rwy+=1;
				printf("\n\t\t\tTekan enter untuk kembali ke menu");
			getch();
			}else {
				gotoxy(35,15);printf("Pilihan tidak ada");
				gotoxy(35,15);printf("\nTekan enter untuk kembali ke menu");
				getch();
			}
}

menu7(){
    int ash;
    strcpy(rwy[total_rwy].aktivitas, "Admin Melihat Riwayat Data");
    total_rwy+=1;
    system("cls");
    system("color 71");
    gotoxy(23,4);
    printf("Riwayat Aktivitas Admin!");
    gotoxy(23,5);
    printf("+===================================================================+");
    gotoxy(23,7);
    printf("No\t Riwayat");
    gotoxy(23,8);
    printf("+===================================================================+");
    for(ash=0; ash<total_rwy; ash++){
        gotoxy(23, 9+ash); printf("%2.i", ash+1);
        gotoxy(26, 9+ash); printf("%s", rwy[ash].aktivitas);
    }
    gotoxy(23,total_rwy);
    printf("+===================================================================+");
    gotoxy(23,total_rwy+1);
    printf("Press Any Key to Continue >>..");
    getch();
}

void main()
{
    Login();
}
