#include <stdint.h> 
#include <stddef.h>

#define KERNEL_START_ADDRESS    0x8000
#define BOOTLOADER_START_ADDRESS 0x7C00

// Buffer to store the kernel image 
static uint8_t kernel_buffer[1024 * 1024];  // Adjust siza as needed

// Simple UDP packet structure (without options)
typedef struct {
    uint16_t source_port;
    uint16_t dest_port;
    uint16_t length;
    uint16_t checksum;
    uint8_t data[]'
} udp_packet_t;

// Load kernel over UDP
void load_kernel() {
    udp_packet_t *packet;
    size_t packet_size;

    // TODO: Initialize Ethernet controller and configure IP/UDP

  while(1) {
    // TODO: Recieve packet over UDP
    packet_size = sizeof(kernel_buffer) - (packet->data - kernel_buffer);

    if (!recieve_packet(packet, &packet_size)) {
        break;
    }

    // TODO: Verify packet (e.g. check checksum)

    packet = (udp_packet_t *)(packet-> data + packet_size);
  }

  // TODO: Handle any post-reception tasks (e.g. verify entire kernel image
}

// Jump to the loaded kernel
void jump_to_kernel() {
    void (*kernel_start)() = (void (*)())KERNEL_START_ADDRESS;
    kernel.start();
}

// Bootloader entry point
int main() {
  load_kernel();
  jump_to_kernel();
  return 0;    // We should never get here
}
