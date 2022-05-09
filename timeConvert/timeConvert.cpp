#include <iostream>
#include <sys/time.h>
#include <unistd.h>
using namespace std;
  
int main(int argc,char *argv[])
{
        char now[64];
        time_t tt;
        struct tm *ttime;
        //tt = atol(argv[1]);
        //tt = 1212132599;  //uint
        //time(&tt);
        //ttime = localtime(&tt);
        while(1) {
          tt = time(nullptr);
          ttime = localtime(&tt);
          strftime(now,64,"%Y-%m-%d %H:%M:%S",ttime);
          cout << "the time is " << now << endl;
          cout << __FILE__ << " " << __LINE__ << endl;
          sleep(1);
        }
}
