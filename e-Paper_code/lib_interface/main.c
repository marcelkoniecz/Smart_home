
#ifdef __cplusplus
extern "C" {
#endif
#include <stdlib.h>     //exit()
#include <signal.h>     //signal()
// #include "EPD_Test.h"   //Examples
#ifdef __cplusplus
}
#endif
#include "main2.h"

void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:exit\r\n");
    DEV_Module_Exit();

    exit(0);
}

int main(void)
{
    // Exception handling:ctrl + c
    signal(SIGINT, Handler);

arg();
 
    return 0;
}
