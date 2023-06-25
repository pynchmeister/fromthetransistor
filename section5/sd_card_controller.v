module sd_card_controller (
    input wire clk,
    input wire reset,
    input wire mosi,
    output wire miso,
    output wire cs,
    output wire sck
);

  // Declare registers and wires
  reg [7:0] data_in;
  reg [7:0] data_out;
  reg [7:0] counter;
  wire clk_div;

  // Generate slower clock for SPI
  clk_divider div (
    .clk(clk),
    .clk_div(clk_div)
  );

  // SPI Master 
  spi_master spi (
    .clk(clk_div),
    .mosi(mosi),
    .miso(miso),
    .cs(cs),
    .sck(sck),
    .data_in(data_in),
    .data_out(data_out), 
    .counter(counter)
  );

  // Initialization
  always @(posedge clk or posedge reset) begin
    if (reset) begin 
        counter <= 0;
        data_in <= 0;
    end else if (clk_div) begin 
      // Load data_in with command or data to send to SD card
      // Increment counter to send/receive 8 bits
    end
  end
endmodule
  //
