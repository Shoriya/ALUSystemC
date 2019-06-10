#include<systemc.h>

SC_MODULE(ALU_module){
	//inputs
	sc_in<bool> clk;
	sc_in<sc_uint<3> > op_sel;
	sc_in<bool> reset;
	sc_in<sc_uint<32> > data1;
	sc_in<sc_uint<32> > data2;

	//outputs
	sc_out<sc_uint<32> > acc;
	sc_out<sc_uint<8> > stat;

	//result variable
	sc_uint<32> result;

	SC_CTOR(ALU_module){
		SC_METHOD(processing);
		sensitive<< clk;
	}

	void processing()
	{
		if(reset.read()==true)
		{
			result = 0;
			acc = 0;
			stat = 0;
		}
		else {

			switch(op_sel.read()){

			case 0:
				result = (data1.read() & data2.read());
				break;
			case 1:
				result = (data1.read() | data2.read());
				break;
			case 2:
				result = (data1.read() ^ data2.read());
				break;
			case 3:
				result = data1.read() >> 1;
			case 4:
				result = data1.read() << 1;
				break;
			case 5:
				result = (data1.read() + data2.read());
				break;
			case 6:
				result = (data1.read() * data2.read());
				break;
			case 7:
				result = (data1.read() / data2.read());
				break;
			}

			cout<<"\n";
			cout<< "----------starting Time :"<< sc_time_stamp() << "\n";
			acc.write(result);
			stat.write(stat);
			cout<<"Result:" << acc<<"\n";
			cout<<"Operation:"<< op_sel <<"\n";
			cout<<"Data1:"<<data1<<"\n";
			cout<<"Data2:"<<data2<<"\n";
			cout<<"status flag:"<<stat<<"\n";
	}
	}
};
