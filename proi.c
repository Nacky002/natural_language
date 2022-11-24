#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MEM_SIZE 1000           // 読み込み可能最大文字数
#define READ_FILE "in.txt"      // 入力ファイル
#define WRITE_FILE "out.csv"    // 出力ファイル

int main()
{
    char c = 0;
    char* txt;
    unsigned short i;
    unsigned short c_num = 0;
    unsigned short half[28] = {0};
    FILE* read;
    FILE* write;



    /* 入力ファイル保存用の、配列のメモリ確保 */
    txt = (char*)malloc( sizeof(char) * MEM_SIZE );

    /* 配列のメモリ確保失敗 */
    if(txt == NULL)
    {
        perror("\n配列のメモリ確保に失敗しました。\n");
        return 1;
    }



    /* 入力ファイルを開く ------------------------------*/
    read = fopen(READ_FILE, "r");

    /* 入力ファイルを開く失敗 */
    if(read == NULL)
    {
        perror("\n入力ファイルへのアクセスに失敗しました。\n");
        return 1;
    }

    /* 配列へ入力ファイルを格納 */
    while(1)
    {
        c = fgetc(read);
        if(c == EOF) break;
        txt[c_num] = c;
        c_num ++;
    }

    /* 入力ファイルを閉じる ----------------------------*/
    fclose(read);



    /* テキスト置換 */
    for(i = 0; i <= c_num; i++)
    {
        if( isalpha(txt[i]) );
        else if( txt[i] == ' ' );
        else if( txt[i] == '\n' );
        else txt[i] = ',';
    }



    /* 頻度を求める */
    for(i = 0; i <= c_num; i++)
    {
        if( txt[i] == 'a' || txt[i] == 'A' ) half[0] ++;
        else if( txt[i] == 'b' || txt[i] == 'B' ) half[1] ++;
        else if( txt[i] == 'c' || txt[i] == 'C' ) half[2] ++;
        else if( txt[i] == 'd' || txt[i] == 'D' ) half[3] ++;
        else if( txt[i] == 'e' || txt[i] == 'E' ) half[4] ++;
        else if( txt[i] == 'f' || txt[i] == 'F' ) half[5] ++;
        else if( txt[i] == 'g' || txt[i] == 'G' ) half[6] ++;
        else if( txt[i] == 'h' || txt[i] == 'H' ) half[7] ++;
        else if( txt[i] == 'i' || txt[i] == 'I' ) half[8] ++;
        else if( txt[i] == 'j' || txt[i] == 'J' ) half[9] ++;
        else if( txt[i] == 'k' || txt[i] == 'K' ) half[10] ++;
        else if( txt[i] == 'l' || txt[i] == 'L' ) half[11] ++;
        else if( txt[i] == 'm' || txt[i] == 'M' ) half[12] ++;
        else if( txt[i] == 'n' || txt[i] == 'N' ) half[13] ++;
        else if( txt[i] == 'o' || txt[i] == 'O' ) half[14] ++;
        else if( txt[i] == 'p' || txt[i] == 'P' ) half[15] ++;
        else if( txt[i] == 'q' || txt[i] == 'Q' ) half[16] ++;
        else if( txt[i] == 'r' || txt[i] == 'R' ) half[17] ++;
        else if( txt[i] == 's' || txt[i] == 'S' ) half[18] ++;
        else if( txt[i] == 't' || txt[i] == 'T' ) half[19] ++;
        else if( txt[i] == 'u' || txt[i] == 'U' ) half[20] ++;
        else if( txt[i] == 'v' || txt[i] == 'V' ) half[21] ++;
        else if( txt[i] == 'w' || txt[i] == 'W' ) half[22] ++;
        else if( txt[i] == 'x' || txt[i] == 'X' ) half[23] ++;
        else if( txt[i] == 'y' || txt[i] == 'Y' ) half[24] ++;
        else if( txt[i] == 'z' || txt[i] == 'Z' ) half[25] ++;
        else if( txt[i] == ' ' ) half[26] ++;
        else if( txt[i] == '\n' ) half[27] ++;
        else ;
    }



    /* 出力ファイルを開く ------------------------------*/
    write = fopen(WRITE_FILE, "w");

    /* 出力ファイルを開く失敗 */
    if(write == NULL)
    {
        perror("\n出力ファイルへのアクセスに失敗しました。\n");
        return 1;
    }

    fprintf(write, "%u a found\n", half[0]);
    fprintf(write, "%u b found\n", half[1]);
    fprintf(write, "%u c found\n", half[2]);
    fprintf(write, "%u d found\n", half[3]);
    fprintf(write, "%u e found\n", half[4]);
    fprintf(write, "%u f found\n", half[5]);
    fprintf(write, "%u g found\n", half[6]);
    fprintf(write, "%u h found\n", half[7]);
    fprintf(write, "%u i found\n", half[8]);
    fprintf(write, "%u j found\n", half[9]);
    fprintf(write, "%u k found\n", half[10]);
    fprintf(write, "%u l found\n", half[11]);
    fprintf(write, "%u m found\n", half[12]);
    fprintf(write, "%u n found\n", half[13]);
    fprintf(write, "%u o found\n", half[14]);
    fprintf(write, "%u p found\n", half[15]);
    fprintf(write, "%u q found\n", half[16]);
    fprintf(write, "%u r found\n", half[17]);
    fprintf(write, "%u s found\n", half[18]);
    fprintf(write, "%u t found\n", half[19]);
    fprintf(write, "%u u found\n", half[20]);
    fprintf(write, "%u v found\n", half[21]);
    fprintf(write, "%u w found\n", half[22]);
    fprintf(write, "%u x found\n", half[23]);
    fprintf(write, "%u y found\n", half[24]);
    fprintf(write, "%u z found\n", half[25]);
    fprintf(write, "%u ' ' found\n", half[26]);

    /* 出力を閉じる ------------------------------------*/
    fclose(write);

    return 0;
}