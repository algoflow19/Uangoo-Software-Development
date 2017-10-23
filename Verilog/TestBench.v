`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:20:36 10/23/2017
// Design Name:   Div_5
// Module Name:   E:/ISE_Dseign/14.7/ISE_DS/ISE/ISEexamples/Div_5/TestBench.v
// Project Name:  Div_5
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Div_5
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TestBench;

	// Outputs
	wire outclk;
	reg rst_n;
	reg clk;;
	
	// Instantiate the Unit Under Test (UUT)
	Div_5 uut (
	.clk(clk),
	.rst_n(rst_n),
	.outclk(outlck)
	);

	initial begin
		// Initialize Inputs
		clk=0;
		rst_n=1;
		#1 rst_n=0;
		#1 rst_n=1;
		
		forever begin
			#5 clk=!clk;
			
		end
		// Wait 100 ns for global reset to finish
		
        
		// Add stimulus here

	end
      
endmodule

