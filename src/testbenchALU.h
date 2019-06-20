#include<systemc.h>

SC_MODULE(Testbench_ALU){

	sc_in<bool> clk;
	sc_out<sc_bv<4> > op_sel;
	sc_out<sc_uint<32> > d1;
	sc_out<sc_uint<32> > d2;
	sc_out<bool> reset;

		void testbench(){
			cout << sc_time_stamp();

			reset.write(false);
			op_sel.write(0);
			d1.write(0x1111);
			d2.write(0x0011);
			wait(2);

			reset.write(false);
			op_sel.write(1);
			d1.write(0xCF11);
			d2.write(0x0FA0);
			wait(2);

			reset.write(false);
			op_sel.write(2);
			d1.write(0xFFFF1111);
			d2.write(0x1c00);
			wait(2);

			reset.write(true);
			op_sel.write(2);
			d1.write(0X1DEF00);
			d2.write(0X118800);
			wait(2);

			reset.write(false);
			op_sel.write(3);
			d1.write(0x3254891);
			d2.write(0xFFFFFF0);
			wait(2);

			reset.write(false);
			op_sel.write(4);
			d1.write(0x1111);
			d2.write(0x0000);
			wait(2);

			reset.write(false);
			op_sel.write(5);
			d1.write(0xFFFF);
			d2.write(0xFFFF);
			wait(2);

			reset.write(false);
			op_sel.write(6);
			d1.write(0x0011);
			d2.write(0x0011);
			wait(2);

			reset.write(false);
			op_sel.write(7);
			d1.write(0x1111);
			d2.write(0x0000);
			//wait(2);

			sc_stop();
		}

		SC_CTOR(Testbench_ALU){
			SC_THREAD(testbench);
			sensitive << clk.pos();
		}
};
