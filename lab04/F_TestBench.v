`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:57:00 09/08/2017 
// Design Name: 
// Module Name:    F_TestBench 
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


module F_TestBench(
    
	 );
	 
	 /* ��������߼��������ܵ���ʱӰ���޷������ı������߼������ */
	 
	reg Data;
	reg clk;
	reg Shift;
	reg clr;
	wire out;
	
	initial begin
	clk=0;
	Shift=1;
	clr=1;
	Data=1;
	
	forever  /* Clock Genergate */
	#5 clk=~clk; 
	end
	
	initial begin
	#100 clr=1'b0;
	#1 clr=~clr;
	end
	
	initial begin
	#170 Shift=~Shift;
	Data=1'b0;
	#15 
	Shift=~Shift;
	Data=~Data;
	end
	
	initial begin
	#200 Shift=~Shift;
	#15 Shift=~Shift;
	end
	
	initial begin
	#210 Data = ~Data;
	#10 Data = ~Data;
	end
	
	FiveBit_Serial_Reg UUT(
		.Data(Data),
		.DataOut(out),  /*�ȶ��շ�ʽ,��֤���Ӷ˿ڵ���ȷ��*/
		.clr(clr),
		.Shift(Shift),
		.clk(clk)
	);

endmodule
