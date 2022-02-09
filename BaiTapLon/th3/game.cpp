#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_SIZE 3
#define MAX 100
enum NguoiChoi
{
    NO_PLAYER = 0,
    fIRST_PLAYER = 1,
    SECOND_PLAYER = 2
};
enum Menu
{
    PLAY_GAME = 1,
    HISTORY_GAME = 2,
    HELP = 3,
    SETTING = 4,
    EXIT = 5
};
typedef struct PLAYER
{
    char first_player[MAX];
    char second_player[MAX];
};
void nhapMangCoGiaTri(int a[MAX_SIZE][MAX_SIZE], int n, int x);
void nhapGiaTriTaiViTri(int a[MAX_SIZE][MAX_SIZE], int n, int i, int j, int x);
void chonViTriDanh(int a[MAX_SIZE][MAX_SIZE], int n, int nguoidanh, PLAYER *Player);
void choiGame(int a[MAX_SIZE][MAX_SIZE], int n);
void xuatMang(int a[MAX_SIZE][MAX_SIZE], int n);
bool winGame(int a[MAX_SIZE][MAX_SIZE], int n, int nguoidanh, int &nguoithang);
bool conViTriDanh(int a[MAX_SIZE][MAX_SIZE], int n);
void datTenNguoiChoi(PLAYER *Player);
void mainmenu(int a[MAX_SIZE][MAX_SIZE], int n, int &option, FILE *file, char str[MAX], FILE *f, PLAYER *Player);
void historyGame(FILE *f, PLAYER *Player);
void tutorialGame(FILE *file, char str[MAX]);
void readfile(FILE *file, char str[MAX], char *filename);
void savehistory(FILE *f, PLAYER *Player);
void Color(int ForgC, int BackC);
void SettingGame();

int main()
{
    FILE *file;
    PLAYER *Player = (struct PLAYER *)malloc(100 * sizeof(struct PLAYER));
    char str[MAX];
    FILE *f;
    int option;
    int a[MAX_SIZE][MAX_SIZE];
    int n = MAX_SIZE;
    mainmenu(a, n, option, file, str, f, Player);
    return 0;
}
void nhapMangCoGiaTri(int a[MAX_SIZE][MAX_SIZE], int n, int x) // nhap mang 3 3
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = x;
        }
    }
}
void nhapGiaTriTaiViTri(int a[MAX_SIZE][MAX_SIZE], int n, int i, int j, int x)
{
    if (a[i][j] == 0)
    { //dieu kien khi nguoi choi chua danh vao cot va hang do moi dc danh
        a[i][j] = x;
    }
}
void xuatMang(int a[MAX_SIZE][MAX_SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == fIRST_PLAYER)
            {
                printf(" X  ");
            }
            else if (a[i][j] == SECOND_PLAYER)
            {
                printf(" O  ");
            }
            else
            {
                printf("__  ");
            }
        }
        printf("\n");
    }
}
bool winGame(int a[MAX_SIZE][MAX_SIZE], int n, int nguoidanh, int &nguoithang)
{
    bool win = false;
    for (int i = 0; i < n; i++)
    {
        if ((a[i][0] == a[i][1]) && (a[i][0] == a[i][2]) && (a[i][0] != NO_PLAYER)) // win hang ngang
        {
            win = true;
            break;
        }
        else if ((a[0][i] == a[1][i]) && (a[0][i] == a[2][i]) && (a[0][i] != NO_PLAYER)) // win hang doc
        {
            win = true;
            break;
        }
    }
    if ((a[0][0] == a[1][1]) && (a[0][0] == a[2][2]) && (a[0][0] != NO_PLAYER)) // win duong cheo chinh
    {
        win = true;
    }
    else if ((a[2][0] == a[1][1]) && (a[2][0] == a[0][2]) && (a[2][0] != NO_PLAYER))
    {
        win = true;
    }
    if (win)
    {
        nguoithang = nguoidanh;
    }
    return win;
}
void chonViTriDanh(int a[MAX_SIZE][MAX_SIZE], int n, int nguoidanh, PLAYER *Player)
{
    int hang, cot;
    do
    {
        if (nguoidanh == fIRST_PLAYER)
        {
            printf("=>%s danh:\n", Player->first_player);
        }
        else
        {
            printf("=>%s danh:\n", Player->second_player);
        }
        printf(" \n=>Hang: ");
        scanf("%d", &hang);
        printf("\n=>Cot: ");
        scanf("%d", &cot);
        if (!((cot >= 0 && cot < n) && (hang >= 0 && hang < n)) || a[hang][cot] != NO_PLAYER)
        {
            printf("\n nhap lai\n");
        }
    } while (!((cot >= 0 && cot < n) && (hang >= 0 && hang < n)) || a[hang][cot] != NO_PLAYER);

    nhapGiaTriTaiViTri(a, n, hang, cot, nguoidanh);
    xuatMang(a, n);
}
void choiGame(int a[MAX_SIZE][MAX_SIZE], int n, PLAYER *Player)
{
    // xuat bang chua danh
    int x = 0;
    int nguoithang = NO_PLAYER;
    int nguoidanh;
    int nguoichoitruoc;
    datTenNguoiChoi(Player);
    nhapMangCoGiaTri(a, n, x);
    xuatMang(a, n);
    // choi game
    nguoidanh = fIRST_PLAYER;
    nguoichoitruoc = SECOND_PLAYER;
    while (!winGame(a, n, nguoichoitruoc, nguoithang))
    {
        if (!conViTriDanh(a, n)) // da hoa
        {
            printf("=>Hoa!\n");
        }
        else // khong hoa
        {
            if (nguoidanh == fIRST_PLAYER)
            {
                chonViTriDanh(a, n, nguoidanh, Player);
                nguoichoitruoc = nguoidanh;
                nguoidanh = SECOND_PLAYER;
            }
            else
            {
                chonViTriDanh(a, n, nguoidanh, Player);
                nguoichoitruoc = nguoidanh;
                nguoidanh = fIRST_PLAYER;
            }
        }
    }
    if (nguoithang == fIRST_PLAYER)
    {
        printf("\n=> Nguoi Thang: %s\n", Player->first_player);
    }
    else
    {
        printf("\n=>Nguoi Thang: %s\n", Player->second_player);
    }
}
bool conViTriDanh(int a[MAX_SIZE][MAX_SIZE], int n)
{
    int dem = 9;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if ((a[i][j] == fIRST_PLAYER) || (a[i][j] == SECOND_PLAYER))
            {
                dem--;
            }
        }
    }
    return dem != 0; // neu dem ==0 thi het vi tri de danh
}
void datTenNguoiChoi(PLAYER *Player)
{
    fflush(stdin);
    printf("Ten nguoi choi 1: ");
    gets(Player->first_player);
    printf("\nTen nguoi choi 2: ");
    gets(Player->second_player);
}
void mainmenu(int a[MAX_SIZE][MAX_SIZE], int n, int &option, FILE *file, char str[MAX], FILE *f, PLAYER *Player)
{
    do
    {

        printf("\n--------------------------------------------------------------------\n");
        printf("---------------------------GAME XO ---------------------------------\n");
        printf("---------------------------1. Play game  ---------------------------\n");
        printf("---------------------------2. history    ---------------------------\n");
        printf("---------------------------3. Help       ---------------------------\n");
        printf("---------------------------4. Setting    ---------------------------\n");
        printf("---------------------------5. Exit       ---------------------------\n");
        printf("--------------------------------------------------------------------\n");
        printf("\n=> Nhap lua chon cua ban: ");
        scanf("%d", &option);
        switch (option)
        {
        case PLAY_GAME:
            choiGame(a, n, Player);
            break;
        case HISTORY_GAME:
            historyGame(f, Player);
            break;
        case HELP:
            tutorialGame(file, str);
            break;
        case SETTING:
            SettingGame();
        case EXIT:
            break;
        }
    } while (option != 5);
}
void historyGame(FILE *f, PLAYER *Player)
{
    savehistory(f, Player);
}
void tutorialGame(FILE *file, char str[MAX])
{
    char *filename = "C:\\C\\GameCaro\\public\\tutorial.txt";
    readfile(file, str, filename);
}
void readfile(FILE *file, char str[MAX], char *filename)
{
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf(" Khong mo duoc file ");
        system("color 7C");
    }
    while (fgets(str, MAX, file) != NULL)
        printf("%s", str);
    fclose(file);
}
void savehistory(FILE *f, PLAYER *Player)
{
    f = fopen("lichsu.txt", "a+"); // cho phep doc va ghi .tu tao file
    printf("|------------- Lich su choi ----------|\n");
    fprintf(f, " %s and %s  ", Player->first_player, Player->second_player); // ghi file
    fclose(f);
    fscanf(f, "\t %s and %s", Player->first_player, Player->second_player); //xuat
    printf("|              %s and %s            |\n", Player->first_player, Player->second_player);
    printf("|-------------------------------------|\n");
    fclose(f);
}
void Color(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SetConsoleTextAttribute(hStdOut, wColor);
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        FillConsoleOutputCharacter(hStdOut, (TCHAR)32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        SetConsoleCursorPosition(hStdOut, coord);
    }
    return;
}
void SettingGame()
{
    int mau;
    printf("\n---------- CHON MAU MAN HINH CHOI ----------");
    printf("\n 1.Mau den ");
    printf("\n 2.Mau trang ");
    printf("\n 3.Mau xam ");
    printf("\n 4.Mau xanh duong");
    printf("\n =>Chon mau man hinh:");
    scanf("%d", &mau);
    if (mau == 2)
    {
        Color(0, 15);
    }
    else if (mau == 3)
    {
        Color(0, 7);
    }
    else
    {
        Color(0,27);
    }   
    
    
}
