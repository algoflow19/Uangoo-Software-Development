`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:32:41 09/08/2017 
// Design Name: 
// Module Name:    mux 
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
module mux(
	input wire in1,
	input wire in2,
	input wire in3,
	input wire [1:0] sel,
	output reg out
    );
	 
	always@(sel,in1,in2) begin
		if(sel==1'b1)
		out=in1;
		else if(sel==1'b0)
		out=in2;
		else
		out=in3;
	end


endmodule
