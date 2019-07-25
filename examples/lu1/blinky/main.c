#include <stdint.h>
#include <nrf24lu1/regs.h>

// Work around silicon issue fetching code at addresses 0-4 when using bootloader.
void dummy() __interrupt(0) {}

int main() {
  P0DIR &= ~(1<<5);
  TMOD = 0x01;
  TR0  = 1;
  while(1) {
    P0_5 = !P0_5;
    T0  = 0;
    TF0 = 0;
    while(!TF0);
  }
}
