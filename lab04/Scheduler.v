// ================================================================
// Scheduler.   This module consists solely of a testbench.
// It illustrates scheduling differences between blocking
// and nonblocking statements.
//
// -----------------------------------------------------------------
// 2005-12-09 jmw:  v. 1.1 Comment changes; interchanged some blocks
//            and declarations.
// 2005-12-08 jmw:  v. 1.0 Implemented.
// =================================================================
//
`timescale 1ns/1ns
//
module Scheduler;
//
reg Clock;
reg[3:0]  Count
       ,  n3_2_1_0  // 'n' for no-delay blocking assignment.
       ,  N3_2_1_0  // 'N' for no-delay Nonblocking.
       ,  z3_2_1_0  // 'z' for #0 (zero) delayed blocking.
       ,  Z3_2_1_0  // 'Z' for #0 (zero) delayed Nonblocking.
       ,  D3_2_1_0  // 'D' for #1 delayed Nonblocking.
       ,  d3_2_1_0; // 'd' for #1 delayed blocking.
//
// Clock generator:
always@(Clock) #100 Clock <= ~Clock;
//
// Stimulus-generating counter:
//
always@(posedge Clock)
  begin : NonblockingCounter  // Count will be incremented in the same
  Count <= Count + 4'h1;      // simulation epoch as posedge Clock, but
  end                         // only after active events and #0 events.
//
// -------------------------------------------------------------------------
//
always@(posedge Clock)
  begin : NoDelayBlocking     // Uses old Count value before
  n3_2_1_0 = Count;           // NonblockingCounter can evaluate
  end                         // its rhs or update the Count value.
//
always@(posedge Clock)
  begin : NoDelayNonBlocking  // Uses old Count value, the same one that   
  N3_2_1_0 <= Count;          // NonblockingCounter will update.
  end
//
always@(posedge Clock)
  begin : ZeroDelayBlocking    // The nonblocking update in
  #0 z3_2_1_0 = Count;         // NonblockingCounter follows all #0
  end                          // updates, so the old value is used.
//
always@(posedge Clock)
  begin : ZeroDelayNonBlocking // The nonblocking update in
  #0 Z3_2_1_0 <= Count;        // NonblockingCounter follows all #0
  end                          // updates, so the old value is used.
//
always@(posedge Clock)
  begin : OneDelayNonBlocking  // #1 schedules this evaluation 1 ns in
  #1 D3_2_1_0 <= Count;        // the future, after the posedge Clock
  end                          // epoch, so the new value of Count is used.
//
always@(posedge Clock)
  begin : OneDelayBlocking     // There is only one (new) Count value
  #1 d3_2_1_0 = Count;         // available 1 ns after the posedge, so
  end                          // blocking and nonblocking evaluations
                               // produce the same result.
//
// ----------------------------------------
// The monitor region evaluations follow all current-epoch active,
// #0, and nonblocking evaluations.   Thus, undelayed $strobe
// sees only the undelayed new value of Count:
//
always@(posedge Clock)
  begin : MonitorRegion
  $strobe("time=%04d:  N=%02d n=%02d Z=%02d z=%02d D=%02d d=%02d\n"
         , $time, N3_2_1_0, n3_2_1_0, Z3_2_1_0, z3_2_1_0, D3_2_1_0, d3_2_1_0);
  end
//
initial
  begin
  Clock     = 1'b0; // Before time 0.
  #10 Count =  'b0;
  //
  #4000 $finish;
  end
//
endmodule // Scheduler.
//
