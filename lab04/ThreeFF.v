`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:16:59 09/05/2017 
// Design Name: 
// Module Name:    Integers 
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
module ThreeFF(
	input wire D,
	input wire clk,
	input wire pre,
	input wire clr,
	output reg Q
    );
	 reg forward;
	 
	 /*
	 always@(posedge clk) 
	 Q <= D;
	 
	 always@(negedge clr,posedge clk) begin
		if(clr == 1'b0) begin
			Q <= 1'b0;
			end
		else
			Q <= D;
	 end
	 */
	 always@(negedge clr,negedge pre,posedge clk)
		if(clr==1'b0) begin
		Q <= 1'b0;
		end
		else if(pre==1'b0) begin
		Q <= 1'b1;
		end
		else
		Q <= D;
		

	 
	 always@(negedge clr) 
	 begin
	 if(pre==1'b0&&forward==1'b1)
	 
	 $strobe("\n***Time=%04d. Unexpected error happened",$time);
	 end
	 
	 always@(negedge pre)
	 forward <=1'b0;
	 
	 always@(posedge pre)  /* 由x跳变时，仍然会触发pre的上升沿 */
	 forward <=1'b1;
	 
	 
endmodule
