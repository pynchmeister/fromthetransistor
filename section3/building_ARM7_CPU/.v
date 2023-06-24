module SRAM #(parameter ADDR_WIDTH = 10, DATA_WIDTH = 8) (
  input wire clk,
  input wire [ADDR_WIDTH-1:0] address,
  input wire [DATA_WIDTH-1:0] write_data,
  input wire write_enable,
  output reg [DATA_WIDTH-1:0] read_data
);

  // Define the SRAM array with a parameterized size
  reg [DATA_WIDTH-1:0] memory [0:2**ADDR_WIDTH-1];

  // On a positive clock edge
  always @(posedge clk) begin
      // If write enable is high, write data into memory 
    if (write_enable) begin 
      memory[address] <= write_data;
    end
    // Always read data from memory
    read_data <= memory[address];
  end
endmodule
