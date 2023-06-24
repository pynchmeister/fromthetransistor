`timescale ins/ins
module tb();

  reg clk;
  wire led;

  // Instantiate the led-blink module
  led_blink u1(.clk(clk), .led(led));

  // Generate a clock signal
  always begin
    #5 clk = ~clk;    // assuming the timescale is in ns and we want a 10ns period (100 MHz frequency)
  end

  initial begin 
    clk = 0;      // Initialize clock signal
  end
endmodule
