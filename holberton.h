#ifndef GARD
#define GARD

int _putchar(char);
int _atoi(char*);
int _printf(const char *format, ...);
char *convertBase(unsigned int nb, int base);
void _puts(char *str);
char *concatAt(int pos, const char *des, char *src);
char *cleanTypeArg(const char *format);
int _strlen(char *str);
int checkTypeForClean(char c);
int deleteChar(int pos, char *p);
char *concatCharAt(int pos,const char *str, char c);

#endif
