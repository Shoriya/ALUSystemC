#include<systemc.h>

SC_MODULE(ALU_module) {
	//inputs
	sc_in<bool> clk;
	sc_in<bool> reset;

	sc_in< sc_bv<4> > op_sel;
	sc_in< sc_uint<32> > d1,d2;

	//outputs
	sc_out< sc_uint<32> > acc;
	sc_out< sc_bv<8> > stat;

	//result variable
	sc_uint<32> data1,data2;
	sc_bv<8> status;
	sc_uint<33> result;


	void processing() {
		data1=d1.read();
		data2=d2.read();
		sc_uint<4> opsel = op_sel.read();

		if (reset.read() == true) {
			cout<<"\nResetting........\n";
			result=0;
			status=0;
			acc.write(0);
			stat.write(0);

		}
		else {
			switch (opsel) {

			case 0:
				cout << "\nCase0: Bitwise and";
				result = (data1 & data2);
				break;
			case 1:
				cout << "\nCase1: Bitwise or";
				result = (data1 | data2);
				break;
			case 2:
				cout << "\nCase2: Bitwise xor";
				result = (data1 ^ data2);
				break;
			case 3:
				cout << "\nCase3: Bitwise Right shift";
				result = data1 >> 1;
			case 4:
				cout << "\nCase4: Bitwise Left shift";
				result = data1 << 1;
				break;
			case 5:
				cout << "\nCase5: Addition";
				result = (data1 + data2);
				break;
			case 6:
				cout << "\nCase6: Multiplication";
				result = (data1 * data2);
				break;
			case 12:
				cout << "\nCase12: Division";
				result = (data1 / data2);
				break;

			default:
				cout << "Exception";
				break;
			}

			acc.write(result);
			//to get the status flag

			status[0] = ((result == 0) ? 1 : 0);   	//zero flag
			status[1] = ((result[32] == 1) ? 1 : 0); //carry flag
			status[2] = ((result[31] == 1) ? 1 : 0); //sign flag
			status[3] =(((data1[31] == 0) && (data2[31] == 0) && (result[31] == 1)) ?1 : 0); //overflow flag

			status[4]=(((data1[31]==1)&&(data2[31]==1)&&(result[31]==0))?1:0); //underflow flag

			cout << "\n";
			cout << "----------Starting Time :" << sc_time_stamp() << "\n";
			stat.write(status);
			cout << "reset:" << reset << "\n";
			cout << "Result:" << acc << "\n";
			cout << "Operation:" << op_sel << "\n";
			cout << "Data1:" << data1 << "\n";
			cout << "Data2:" << data2 << "\n";
			cout << "status flag:" << stat << "\n";
		}
	}

	SC_CTOR(ALU_module) {
		SC_METHOD(processing);
		sensitive << clk.neg();
	}
};
