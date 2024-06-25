#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HEADER_SIZE 4
#define SENDER_SIZE 6
#define TEXT_DATA 11
#define TOTAL_SIZE 30

char *Message_Data()
{
    char *message = (char *)malloc(sizeof(char *) * TOTAL_SIZE);

    memset(message, 0, sizeof(char) * TOTAL_SIZE);

    char *sender_name = "张三";
    char *text_data = "hello world";
    int text_len = strlen(text_data);

    memcpy(message, &text_len, HEADER_SIZE);
    memcpy(message + HEADER_SIZE, sender_name, SENDER_SIZE);
    memcpy(message + TEXT_DATA, text_data, text_len);

    return message;
}

int main()
{
    char *message_data_p = Message_Data();

    printf("数据大小  :%d \n", *(int *)message_data_p);
    printf("数据发送人:%s\n", message_data_p + HEADER_SIZE);
    printf("数据内容  :%s\n", message_data_p + TEXT_DATA);
    free(message_data_p);
    return 0;
}