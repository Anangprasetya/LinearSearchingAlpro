#include <termios.h>
using namespace std;
static struct termios old, baru;
 
/* Initialize baru terminal i/o settings */
inline void initTermios(int echo) 
{
  tcgetattr(0, &old); //grab old terminal i/o settings
  baru = old; //make baru settings same as old settings
  baru.c_lflag &= ~ICANON; //disable buffered i/o
  baru.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
  tcsetattr(0, TCSANOW, &baru); //apply terminal io settings
}
 
/* Restore old terminal i/o settings */
inline void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}
 
/* Read 1 character - echo defines echo mode */
inline char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}
 
/* 
Read 1 character without echo 
getch() function definition.
*/
inline char getch(void) 
{
  return getch_(0);
}
 
/* 
Read 1 character with echo 
getche() function definition.
*/
inline char getche(void) 
{
  return getch_(1);
}

inline void clrscr(void)
{
    system("clear");
}

inline string strlow(string x){
  for (int i = 0; i < x.length(); i++)
    if (x[i] >= 'A' && x[i] <= 'Z')
       x[i] = x[i] + 32;

  return x;
}