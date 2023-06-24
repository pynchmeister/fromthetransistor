module led_blink(
  input wire clk,
  output reg led
);

  reg [3:0] count = 0;

  always @(posedge clk) begin
    count <= count + 1;
    if (count == 10) begin 
        led <= ~led;  // Toggle the LED state
        count <= 0;
    end
  end
endmodule
