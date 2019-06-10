#include<systemc.h>

SC_MODULE(TestbenchALU){
	sc_in<bool> clk;

	sc_out<sc_uint<3> > op_sel;
	sc_out<sc_uint<32> > data1;
	sc_out<sc_uint<32> > data2;
	sc_out<bool> reset;



		void testbench(){

			cout << sc_time_stamp() << "Case1";
			op_sel.write(0);
			data1.write(0b1111);
			data2.write(0b0000);
			wait(3);

			op_sel.write(1);
			data1.write(0b1111);
			data2.write(0b0000);
			wait(3);

			op_sel.write(2);
			data1.write(0b1111);
			data2.write(0b0000);
			wait(3);

			op_sel.write(3);
			data1.write(0b1111);
			data2.write(0b0000);
			wait(3);

			op_sel.write(4);
			data1.write(0b1111);
			data2.write(0b0000);
			wait(3);

			op_sel.write(5);
			data1.write(0b1111);
			data2.write(0b0000);
			wait(3);

			op_sel.write(6);
			data1.write(0b1111);
			data2.write(0b0000);
			wait(3);

			op_sel.write(7);
			data1.write(0b1111);
			data2.write(0b0000);
			wait(3);

			sc_stop();
		}

		SC_CTOR(TestbenchALU){
			SC_THREAD(testbench);
			sensitive << clk;
		}
};
