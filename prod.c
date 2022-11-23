#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 10
#define READ_FILE "in.txt"
#define WRITE_FILE "out.txt"

int main()
{
    char c = 'g';
    char* txt;
    int i;
    FILE* read;
    FILE* write;

    /* 入力ファイル保存用の、配列の容量確保 */
    txt = (char*)malloc( sizeof(char) * MEM_SIZE );

    /* 配列の容量確保失敗 */
    if(txt == NULL)
    {
        printf("failed to get memory size of txt...\n");
        return 1;
    }

    /* 入力ファイルを開く */
    read = fopen(READ_FILE, "r");

    /* 配列へテキストを格納 */
    for(i = 0; i < MEM_SIZE; i++)
    {
        if( (c = fgetc(read)) != EOF )
        {
            txt[i] = c;
        }
        else
        {
            txt[i] = '0';
        }
    }



    while( (txt = fgetc(read)) != EOF )
    {
        fprintf(read, "%c", txt);
        printf("%c", c);
    }
                

    /* 配列へ、テキストを格納 */
    for(i = 0; i < MEM_SIZE; i++)
    {
    
        txt[i] = c;
        printf("txt[%d] = %c\n", i, txt[i]);
    }

    /* 配列を出力ファイルに出力 */
    write = fopen(WRITE_FILE, "w");
    fprintf(write, "%s\n", txt);
    fclose(write);
}