typedef struct int1024{
  int *val;
  int filled;
  int sign;
}int1024;

void read(int1024*);
int compare(int1024*,int1024*);
int1024* add(int1024* , int1024* );
int1024* subtract(int1024* , int1024* );
int1024* multiply(int1024* , int1024* );
void print(int1024*);
int1024* maxcalc();
