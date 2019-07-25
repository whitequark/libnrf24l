#include <stdint.h>
#include <nrf24le1/regs.h>

int main() {
  P0DIR &= ~(1<<0);
  while(1) P0_0 = !P0_0;
}
