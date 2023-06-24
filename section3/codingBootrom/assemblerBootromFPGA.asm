// bootrom.s
.global _start

.section .text
_start: 
    // Setup serial port (Assume neccessary setup is done here)
    mov r0, #0
    mov r1, #9600
    b1 setup_serial_port

    // Loop to read data from serial port and store it in RAM
    // Assume: RAM_START is the base address of the RAM
    // Assume: SERIAL_PORT is the address of the serial port's data register
read_loop:
  ldr r0, =RAM_START
  ldr r1, =SERIAL_PORT
read_byte:
  ldrb r2, [r1]
  strb r2, [r0]
  add r0, r0, #1
  b read_byte

  // Jump to the start of RAM to execute downloaded code
  ldr pc, =RAM_START

// Function to setup serial port
// Inputs: r0 - port number, r1 - baud rate
setup_serial_port:
  // Assume necessary setup is done here
  bx lr 
