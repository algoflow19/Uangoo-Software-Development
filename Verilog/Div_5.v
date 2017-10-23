`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Uangoo
// Engineer: Uan
// 
// Create Date:    12:59:29 10/23/2017 
// Design Name: 
// Module Name:    Div_5 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////

// 宏定义定义占空比，此处只能接受正整数，且不超过为4
`define neg_region 4

// `define pos_region	3

module Div_5(
	input wire clk,
	input wire rst_n,
	output wire outclk
    );
	 
	 reg [2:0] counter;
	 reg outclk_reg;
	 
	
	 
	 always@(negedge rst_n or posedge clk) begin
		
		if(!rst_n) 
		begin
			counter <= 3'b000;
			outclk_reg <= 1'b0;
		end
		else
		counter <= counter + 1;
		end

		always @(counter) 
		begin
		
			if( counter == (3'd`neg_region + 1'b1))
			outclk_reg <= !outclk_reg;
			
			if(counter == 3'b110)
			begin
				outclk_reg <= !outclk_reg;
				counter <= 3'b001;
			end
			
		end
		
		assign outclk = outclk_reg;
		



endmodule
