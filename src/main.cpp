 #include "ALU.h"
 #include "testbenchALU.h"

 int sc_main(int argc, char* argv[])
 {
 sc_signal<int> sig;
 ALU_module* ALUm = new ALU_module("ALUm");
 TestbenchALU* TBm = new TestbenchALU("TBm");

 sc_clock Clock("Clock", 10, SC_NS, 0.5, 0, SC_NS, true);

 sc_signal<sc_uint<3> > op_sel;
 sc_signal<bool> reset;
 sc_signal<sc_uint<32> > data1;
 sc_signal<sc_uint<32> > data2;
 sc_signal<sc_uint<32> > acc;
 sc_signal<sc_uint<8> > stat;

 ALUm-> clk(Clock);
 ALUm-> op_sel(op_sel);
 ALUm-> reset(reset);
 ALUm-> data1(data1);
 ALUm-> data2(data2);
 ALUm-> acc(acc);
 ALUm-> stat(stat);

 TBm-> clk(Clock);
 TBm-> reset(reset);
 TBm-> op_sel(op_sel);
 TBm-> data1(data1);
 TBm-> data2(data2);

 sc_trace_file* file = sc_create_vcd_trace_file("ALUFile");
 cout<< "Start simulation" <<endl;
 cout<< sc_time_stamp() <<"Creating VCD file:\n";

 sc_trace(file,Clock,"clock");
 sc_trace(file,reset,"reset");
 sc_trace(file,op_sel,"count_en");
 sc_trace(file,data1,"ud_ctrl");
 sc_trace(file,data2,"count_out");
 sc_trace(file,acc,"ovf_intr");
 sc_trace(file,stat,"unf_intr");



 cout << sc_time_stamp() << "start simulation";
 sc_start();
 return 0;

 }
