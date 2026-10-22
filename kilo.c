#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>



struct termios orig_termios;

// Restore the terminal settings saved before raw mode was enabled.
void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

// Read keypresses without echoing them to the terminal.
void enableRawMode() {
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);
  struct termios raw = orig_termios;
  raw.c_iflag &= ~(IXON);
  raw.c_lflag &= ~(ECHO | ICANON | ISIG);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {

  enableRawMode();
  char c;
  // Keep reading input until the user presses 'q'.
  while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q'){
    if(iscntrl(c)) printf("%d \n", c);
    else printf("%d ('%c')\n", c, c);
  }
  return 0;
}