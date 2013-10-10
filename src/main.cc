#include <stdio.h>
#include <stdlib.h>
#include "screen.h"

using namespace nightwing;

void AtExit() {
  Screen::Release();
}

int main() {
  atexit(AtExit); // I ate your camel!

  Screen* screen = Screen::Instance();
  if (screen->HasErrors()) {
    fprintf(stderr, "Connection to X failed! Bye, bye.");
    exit(1);
  }
  
  screen->MainLoop();

  exit(0);
}
