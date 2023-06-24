module SimpleProcessor(clk, reset);

  input wire clk, reset;
  reg [31:0] memory[0:255];      // 256 32-bit words of memory
  reg [31:0] regfile[0:15];      // 16 32-bit registers
  reg [7:0] pc;                  // 8-bit Program Counter

  reg [31:0] instruction;        // fetched instruction
  reg [3:0] op, rd, rs, rt;      // decoded instruction fields

  // Fetch stage
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      pc <= 8'b0;
    end else begin 
      instruction <= memory[pc];
      pc <= pc + 8'b1;
    end
  end

  // Decode stage
  always @(posedge clk) begin 
    op <= instruction[31:28];    // top 4 bits
    rd <= instruction[27:24];    // next 4 bits 
    rs <= instruction[23:20];    // next 4 bits
    rt <= instruction[19:16];    // next 4 bits
  end

  // Execute stage
  always @(posedge clk) begin
    if(op == 4'b0001) begin       // ADD operation
      regfile[rd] <= regfile[rs] + regfile[rt];
    end
  end

endmodule
