#include <stdio.h>
#include <string.h>

#include <fcntl.h> //contains files controls like 0_RDWR
#include <errno.h> // error integer  and sterror
#include <termios.h> // contains posix terminal and control defination
#include <unistd.h> // write read and close

int serial_port = open("dev/", 0_RDWR);

if(serial_port < 0){
  printf("Error %i  from open: %s\n",error, strerror(errno)); 
  /* error 2: no such file or directory
   * error 13: Permission denied
   */
  struct termios tty;

  if(tcgetattr(serial_port, &tty) != 0){
    printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
  }
}
