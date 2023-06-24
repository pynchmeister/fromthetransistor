module UART(
  input wire clk,                // System clock
  input wire reset,              // System reset
  input wire rx,                 // UART recieve data
  output reg tx,                 // UART transmit data
  input wire [7:0] data_in,      // Byte to transmit
  output reg [7:0] data_out,     // Recieved byte
  input wire send_req,           // Request to send a byte
  output reg send_ack,           // Acknowledge send request
  output reg recv_flag      // Flag if a byte is received
);
