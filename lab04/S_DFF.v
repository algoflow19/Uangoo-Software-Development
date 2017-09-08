`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:30:45 09/08/2017 
// Design Name: 
// Module Name:    S_DFF 
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
module S_DFF(
	input wire clk,
	input wire clr,
	input wire D,
	output reg Q,
	output wire Qn
    );
	 
	 always@(posedge clk,negedge clr)
	 begin
	 if(clr==1'b0)
	 Q <= 1'b0;
	 else 
	 Q <= D;
	 end
	
	assign Qn = ~Q;

endmodule
