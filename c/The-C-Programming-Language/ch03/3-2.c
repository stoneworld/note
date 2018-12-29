/* Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a Switch. Write a function for 
the other direction as well,converting the escape sequences into the real characters */

#include<stdio.h>
#define MAXLINE 1000
int mgetline(char line[],int maxline);
void escape(char s[],char t[]);
int main(void)
{
    char s[MAXLINE],t[MAXLINE];

    //mgetline(t,MAXLINE);
    s[0] = '2';
    s[1] = '\n';
    s[2] = 'c';
    s[3] = '\t';
    s[4] = 'r';
    s[5] = '\0';

    escape(s,t);

    printf("%s",t);

    return 0;
}
void escape(char s[], char t[])
{
    int n = 0;
    int j = 0;
    char c;
    while ((c = s[n]) != '\0') {
        switch (c) {
            case '\n':
                t[j] = '\\';
                t[++j] = 'n';
                break;
            case '\t':
                t[j] = '\\';
                t[++j] = 't';
                break;
            default:
                t[j] = c;
                break;
        }
        n++;
        j++;
    }
    s[j] = '\0';
}

int mgetline(char s[],int lim)
{
    int i,c;

    for(i=0;i<lim-1 && (c=getchar())!=EOF;++i)
        s[i]=c;

    s[i]='\0';
    return 0;
}