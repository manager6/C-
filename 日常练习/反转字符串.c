

void reverse(char *str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
}