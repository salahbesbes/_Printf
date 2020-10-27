#ifndef GARD
#define GARD

int _putchar(char);
int _atoi(char *str);
int _printf(const char *format, ...);
char *convertBase(unsigned int nb, unsigned int base);
void _puts(char *str);
char *concatAt(int pos, char *des, char *src);
char *cleanTypeArg(char *format);
int _strlen(const char *str);
int checkTypeForClean(char c);
char *deleteChar(int pos, char *p);
char *concatCharAt(int pos, char *str, char c);
char *strCopyAlloc(const char *format);
char *numToString(int n);
int p_int(int nb);
int p_dec(int nb);
char *handlePercent(int i, char *p);
char *rev_string(char *s);
char *rot13(char *str);

#endif
