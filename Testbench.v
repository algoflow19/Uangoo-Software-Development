`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:45:19 09/07/2017 
// Design Name: 
// Module Name:    Testbench 
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
module Testbench(
    );
	 
	 reg clk;
	 reg pre;
	 reg clr;
	 reg D;
	initial begin
	pre=1;
	clr=1;
	clk=0;
	D=1;
	forever /* ע��FOREVER�ǹ�����䣨��ҪǶ����initial��,˳��ִ�У�forever�������Զ���ᱻִ�� */
	#10 clk = !clk;  
	end
	
	initial begin
	#33 clr=~clr;
	#1 clr=~clr;
	#2 pre=~pre;
	#2 pre=~pre;
	
	#5 clr=~clr;
	pre=~pre;
	
	#1 clr=~clr;
	pre=~pre;
	
	#20 clr=~clr;
	#1 clr=~clr;
	
	end
	
	ThreeFF FF(.clk(clk),
	.pre(pre),
	.clr(clr),
	.D(D)
	);
	
	

endmodule
