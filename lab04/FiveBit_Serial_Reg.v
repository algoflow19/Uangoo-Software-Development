`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:33:44 09/08/2017 
// Design Name: 
// Module Name:    FiveBit_Serial_Reg 
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
module FiveBit_Serial_Reg(
    input wire clk,
	 input wire Data,
	 input wire [1:0] Shift,
	 input wire clr,
	 output wire DataOut
	 );
	 wire WD1,WD2,WD3,WD4,WD5;
	 wire WQ1,WQ2,WQ3,WQ4,WQ5;

	
	
	mux mux1(.in1(Data),.in2(WQ1),.in3(Data),.sel(Shift),.out(WD1));
	mux mux2(.in1(WQ1),.in2(WQ2),.in3(Data),.sel(Shift),.out(WD2));
	mux mux3(.in1(WQ2),.in2(WQ3),.in3(Data),.sel(Shift),.out(WD3));
	mux mux4(.in1(WQ3),.in2(WQ4),.in3(Data),.sel(Shift),.out(WD4));
	mux mux5(.in1(WQ4),.in2(WQ5),.in3(Data),.sel(Shift),.out(WD5));
	
	S_DFF DFF1(.D(WD1),.clk(clk),.Q(WQ1),.clr(clr));
	S_DFF DFF2(.D(WD2),.clk(clk),.Q(WQ2),.clr(clr));
	S_DFF DFF3(.D(WD3),.clk(clk),.Q(WQ3),.clr(clr));
	S_DFF DFF4(.D(WD4),.clk(clk),.Q(WQ4),.clr(clr));
	S_DFF DFF5(.D(WD5),.clk(clk),.Q(WQ5),.clr(clr));
	
	
	assign DataOut = WQ5;
	
	
	

endmodule
