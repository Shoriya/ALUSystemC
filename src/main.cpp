 #include "ALU.h"
 #include "testbenchALU.h"

 int sc_main(int argc, char* argv[])
 {
 sc_signal<int> sig;
 Testbench_ALU* TBm = new Testbench_ALU("TBm");
 ALU_module* ALUm = new ALU_module("ALUm");

 sc_clock Clock("Clock",2000,SC_MS);

 sc_signal<sc_bv<4> > op_sel;
 sc_signal<bool> reset;
 sc_signal<sc_uint<32> > d1;
 sc_signal<sc_uint<32> > d2;
 sc_signal<sc_uint<32> > acc;
 sc_signal<sc_bv<8> > stat;

 ALUm-> clk(Clock);
 ALUm-> op_sel(op_sel);
 ALUm-> reset(reset);
 ALUm-> d1(d1);
 ALUm-> d2(d2);
 ALUm-> acc(acc);
 ALUm-> stat(stat);

 TBm-> clk(Clock);
 TBm-> reset(reset);
 TBm-> op_sel(op_sel);
 TBm-> d1(d1);
 TBm-> d2(d2);

 sc_trace_file* file = sc_create_vcd_trace_file("ALU");
 cout<< "Start simulation" <<endl;
 cout<< sc_time_stamp() <<"Creating VCD file:\n";

 sc_trace(file,Clock,"clock");
 sc_trace(file,reset,"reset");
 sc_trace(file,op_sel,"op_sel");
 sc_trace(file,d1,"data1");
 sc_trace(file,d2,"data2");
 sc_trace(file,acc,"acc");
 sc_trace(file,stat,"stat");

 cout << sc_time_stamp() << "  start simulation";
 sc_start();
 return 0;
 }
