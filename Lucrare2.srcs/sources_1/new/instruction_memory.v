`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/05/2023 06:54:14 PM
// Design Name: 
// Module Name: instruction_memory
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module instruction_memory(
input [9:0] address,
output reg [31:0] instruction
    );
    
    reg [31:0] regmem [0:1023];
    initial begin
        //$display("Loading rom.");
        $readmemh("code.mem", regmem);
    end
    
    always @(address)
    begin
     instruction = regmem[address]; 
    end
    
endmodule
