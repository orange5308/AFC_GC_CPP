#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <iomanip>

SYSTEMTIME currentTime_start_new;
SYSTEMTIME currentTime_start_d;
SYSTEMTIME currentTime_end;
SYSTEMTIME currentTime;

void time_print_m(std::string data = "", int mod = 1) { // mod = 1 2021/11/10 19:10:58 000
	GetSystemTime(&currentTime);
	if (mod == 1) {
		std::cout << data << " : " << currentTime.wYear << "/" << std::setw(2)
				<< std::setfill('0') << currentTime.wMonth << "/"
				<< std::setw(2) << std::setfill('0') << currentTime.wDay << " "
				<< std::setw(2) << std::setfill('0') << currentTime.wHour << ":"
				<< std::setw(2) << std::setfill('0') << currentTime.wMinute
				<< ":" << std::setw(2) << std::setfill('0')
				<< currentTime.wSecond << " " << std::setw(3)
				<< std::setfill('0') << currentTime.wMilliseconds << std::endl;
	} else {
		std::cout << "time_print mod setting error" << std::endl;
	}
}
class Timer {
	bool clear = false;

public:
	std::string ability_test;
	double pcs_control_local;
	double pcs_reset_local;
	double pcs_control_time_local;
	double PQ_p_ref;
	double PQ_q_ref;
	double mode;
	template<typename T1, typename T2, typename T3, typename T4, typename T5>
	void setFixedTime_AFG(T1 control_thread, T2 HM_link_thread, T3 error_thread,
			T4 PCS_ReadData_thread, T5 EMS_ReadData_thread,
			std::string set_source, double *emsdata, double *mbmsdata,
			double *HMdata, double *pcsdata, int *LEDstate, double scale,
			double soc_max, double soc_min, double System_p_max,
			double System_p_min, double System_q_max, double System_q_min,
			double *f_arr, double *p_arr, double *v_arr, double *q_arr,
			int FP_type, double FP_soc_goal_percent, double FP_main_f_set,
			double FP_line_p_base, double FP_soc_dead_band,
			double FP_soc_adjust, int VC_type, double Vq_v_base,
			double Vq_q_base, double Vq_droop, double Vq_v_set,
			double PF_pf_ref, modbus_t *HM_ctx, int HM_ret, double HM_f,
			double HM_p, double HM_v, double HM_q, modbus_t *pcs_read_ctx,
			int pcs_read_ret, double *control_ab_data, std::string MBMS_eid,
			std::string HM_eid, std::string PCS_eid, std::string pcs_ip,
			int pcs_port, int pcs_id, std::string HM_ip, int HM_port, int HM_id,
			mongocxx::database db, mongocxx::database db2,
			mongocxx::database db4, mongocxx::database db_local,
			mongocxx::database db2_local, mongocxx::database db4_local,
			mongocxx::database db5_local);
	void stop();

};
template<typename T1, typename T2, typename T3, typename T4, typename T5>
void Timer::setFixedTime_AFG(T1 control_thread, T2 HM_link_thread,
		T3 error_thread, T4 PCS_ReadData_thread, T5 EMS_ReadData_thread,
		std::string set_source, double *emsdata, double *mbmsdata,
		double *HMdata, double *pcsdata, int *LEDstate, double scale,
		double soc_max, double soc_min, double System_p_max,
		double System_p_min, double System_q_max, double System_q_min,
		double *f_arr, double *p_arr, double *v_arr, double *q_arr, int FP_type,
		double FP_soc_goal_percent, double FP_main_f_set, double FP_line_p_base,
		double FP_soc_dead_band, double FP_soc_adjust, int VC_type,
		double Vq_v_base, double Vq_q_base, double Vq_droop, double Vq_v_set,
		double PF_pf_ref, modbus_t *HM_ctx, int HM_ret, double HM_f,
		double HM_p, double HM_v, double HM_q, modbus_t *pcs_read_ctx,
		int pcs_read_ret, double *control_ab_data, std::string MBMS_eid,
		std::string HM_eid, std::string PCS_eid, std::string pcs_ip,
		int pcs_port, int pcs_id, std::string HM_ip, int HM_port, int HM_id,
		mongocxx::database db, mongocxx::database db2, mongocxx::database db4,
		mongocxx::database db_local, mongocxx::database db2_local,
		mongocxx::database db4_local, mongocxx::database db5_local) {
	this->clear = false;
	std::thread t([=]() {

		std::string control_point = "aa";
		GetSystemTime(&currentTime_start_new);
		bool first_run = true;
		bool next_sec = false;

		bool remote_first_run = true;/*防止第一次執行去做local的參數 直到讀到remote*/
		bool function_run = false;

		double soc = 50.0;
		char path_dReg = 'N'; //dReg
		char path_sReg = 'N'; //sReg
		bool sReg_flag = false;
		double pcs_out_pre_p;
		double pcs_out_pre_q;

		double pcs_reset;
		double pcs_control;
		double pcs_control_time;
		double pcs_control_time_remote;
		double control_flag = 0;

		int pcs_read_error_count = 0;
		int pcs_write_error_count = 0;
		int HM_error_count = 0;
		int ems_count = 0;
		double mbms_time;
		int mbms_count = 0;
		int ability_test_count = 0;

		bool modbus_link_HM_flag = true;
//		bool modbus_link_pcs_write_flag = true;
		bool modbus_link_pcs_read_flag = true;

		int modea = mode;
//		double scalea = scale;
		double soc_maxa = soc_max;
		double soc_mina = soc_min;
		double System_p_maxa = System_p_max;
		double System_p_mina = System_p_min;
		double System_q_maxa = System_q_max;
		double System_q_mina = System_q_min;
		double f_arra[6] = { f_arr[0], f_arr[1], f_arr[2], f_arr[3], f_arr[4],
				f_arr[5] };
		double p_arra[6] = { p_arr[0], p_arr[1], p_arr[2], p_arr[3], p_arr[4],
				p_arr[5] };
		double v_arra[6] = { v_arr[0], v_arr[1], v_arr[2], v_arr[3], v_arr[4],
				v_arr[5] };
		double q_arra[6] = { q_arr[0], q_arr[1], q_arr[2], q_arr[3], q_arr[4],
				q_arr[5] };

		double PQ_p_refa = PQ_p_ref;
		double PQ_q_refa = PQ_q_ref;
		int FP_typea = FP_type;
		double FP_soc_goal_percenta = FP_soc_goal_percent;
		double FP_main_f_seta = FP_main_f_set;
		double FP_line_p_basea = FP_line_p_base;
		double FP_soc_dead_banda = FP_soc_dead_band;
		double FP_soc_adjusta = FP_soc_adjust;
		int VC_typea = VC_type;
		double Vq_v_basea = Vq_v_base;
		double Vq_q_basea = Vq_q_base;
		double Vq_droopa = Vq_droop;
		double Vq_v_seta = Vq_v_set;
		double PF_pf_refa = PF_pf_ref;

		double pcs_out_p = 0.0; /*P目標值*/
		double pcs_out_q = 0.0; /*Q目標值*/

		bool VQ_Hys_line = false;
		double HM_v_last = 0;
		int scale_len = 1;
		std::string scale_name[scale_len] = { "60f8e79f54841d42146b31df" };
		double scale_data[scale_len];

		double HM_time[10] = { 0 };
		double HM_data_1[41][10];
		double *HM_data[41] = { 0 };
		for (int x = 0; x < 41; x++) {
			HM_data[x] = &HM_data_1[x][0];
		}
		ModbusData::PCS_delta PCS_delta;
		int pcs_read_arr_1[PCS_delta.order][80];
		int *pcs_read_arr[PCS_delta.order];
		for (int x = 0; x < PCS_delta.order; x++) {
			pcs_read_arr[x] = &pcs_read_arr_1[x][0];
		}

		int lock_buffer_10ms = int(currentTime_start_new.wMilliseconds / 10);
		int lock_buffer_100ms = int(currentTime_start_new.wMilliseconds / 100);
		int lock_buffer_1s = int(currentTime_start_new.wSecond);

		int HM_ret_ = HM_ret;
		int pcs_read_ret_ = pcs_read_ret;
//		int pcs_write_ret_ = pcs_write_ret;

		int thread_count = 0;

		bool error_flag1 = false;
		bool error_flag2 = false;
//		bool error_flag3 = false;
		bool error_flag4 = false;
		bool error_flag5 = false;

		while (uint16_t(currentTime_start_new.wMilliseconds / 100) != 9) {
			if (this->clear)
				return;
			GetSystemTime(&currentTime_start_new);
		}
		;
		if (this->clear)
			return;
		std::thread *t_error_thread = nullptr;
//		std::thread *t_PCS_ReadData_thread = nullptr;
		std::thread *t_EMS_ReadData_thread = nullptr;
		std::thread *t_HM_link_thread = nullptr;
		bool thread_end = false;
		t_HM_link_thread = new std::thread([&]() {
			HM_link_thread(std::ref(thread_end), std::ref(thread_count), std::ref(HM_ctx), std::ref(HM_ret_),
	std::ref(modbus_link_HM_flag), db5_local, std::ref(error_flag5));
});
		t_error_thread = new std::thread(
				[&]() {
					error_thread(std::ref(thread_end), std::ref(thread_count),
							std::ref(pcs_read_error_count),
							std::ref(HM_error_count), HM_eid, PCS_eid, db2,
							db2_local, std::ref(error_flag2));
				});
//		t_PCS_ReadData_thread = new std::thread(
//				[&]() {
//					PCS_ReadData_thread(
//							std::ref(thread_count),
//							std::ref(pcsdata),
//							std::ref(pcs_read_error_count),
//							pcs_read_arr, pcs_ip, pcs_port, pcs_id,
//							pcs_read_ctx, std::ref(pcs_read_ret_),
//							std::ref(pcs_write_ctx),
//							std::ref(pcs_write_ret_),
//							std::ref(modbus_link_pcs_read_flag),
//							PCS_eid, db3, db3_local);
//				});
		t_EMS_ReadData_thread = new std::thread(
				[&]() {
					EMS_ReadData_thread(std::ref(thread_end),
							std::ref(thread_count), std::ref(emsdata),
							std::ref(mbmsdata), std::ref(LEDstate),
							std::ref(remote_first_run), set_source, scale_name,
							scale_data, scale_len, std::ref(modea),
							std::ref(soc_maxa), std::ref(soc_mina),
							std::ref(System_p_maxa), std::ref(System_p_mina),
							std::ref(System_q_maxa), std::ref(System_q_mina),
							std::ref(f_arra), std::ref(p_arra),
							std::ref(v_arra), std::ref(q_arra),
							std::ref(PQ_p_refa), std::ref(PQ_q_refa),
							std::ref(FP_typea), std::ref(FP_soc_goal_percenta),
							std::ref(FP_main_f_seta), std::ref(FP_line_p_basea),
							std::ref(FP_soc_dead_banda),
							std::ref(FP_soc_adjusta), std::ref(VC_typea),
							std::ref(Vq_v_basea), std::ref(Vq_q_basea),
							std::ref(Vq_droopa), std::ref(Vq_v_seta),
							std::ref(PF_pf_refa), std::ref(control_ab_data),
							std::ref(soc), std::ref(ems_count),
							std::ref(mbms_time), std::ref(mbms_count),
							std::ref(pcs_write_error_count),
							std::ref(pcs_reset), std::ref(pcs_control),
							std::ref(pcs_control_time_remote), pcs_read_ctx,
							std::ref(pcs_read_ret_), MBMS_eid, PCS_eid, db4,
							db4_local, std::ref(error_flag4));
				});
		while (true) {
			while (lock_buffer_10ms
					== int(currentTime_start_new.wMilliseconds / 10)) { //每10ms跳出去
				if (this->clear) {
					thread_end = true;
					std::cout << "AFC_run STOP start" << std::endl;
					t_HM_link_thread->join();
					t_error_thread->join();
//					t_PCS_ReadData_thread->join();
					t_EMS_ReadData_thread->join();
					delete t_HM_link_thread;
					delete t_error_thread;
//					delete t_PCS_ReadData_thread;
					delete t_EMS_ReadData_thread;
					/*停止PQ 設為0*/
					/*vvvvvvvvvvvvvvvvv暫時寫死資料vvvvvvvvvvvvvvvvvvv*/
					int pcs_start_p = 10; /*P寫入*/
					int pcs_len_p = 1;
					int pcs_start_q = 11; /*Q寫入*/
					int pcs_len_q = 1;
					/*^^^^^^^^^^^^^^^^^^^暫時寫死資料^^^^^^^^^^^^^^^^^^^*/
					int pcs_out_p_now = 0;
					int pcs_out_q_now = 0;
					uint16_t *pcs_write_arr_p = new uint16_t[pcs_len_p];
					uint16_t *pcs_write_arr_q = new uint16_t[pcs_len_q];
					/*modbus PCS 控制    P(pcs_out_p_now)*/
					if (modbus_write_register(pcs_read_ctx, pcs_start_p,
							pcs_write_arr_p[0]) == 1) {
//						std::cout << "pcs_write_arr_p OKK" << std::endl;
					} else {
						/*p寫入失敗*/
//						std::cout << "pcs_write_arr_p error" << std::endl;
					}
					if (modbus_write_register(pcs_read_ctx, pcs_start_q,
							pcs_write_arr_q[0]) == 1) {
						/*q寫入成功*/
//						std::cout << "pcs_write_arr_q OKK" << std::endl;
					} else {/*q寫入失敗*/
//						std::cout << "pcs_write_arr_p error" << std::endl;
					}
					delete pcs_write_arr_p;
					delete pcs_write_arr_q;
					std::cout << "AFC_run STOP end" << std::endl;
					return;
				}
				GetSystemTime(&currentTime_start_new);
				Sleep(10);
			}
			;
			lock_buffer_10ms = int(currentTime_start_new.wMilliseconds / 10);
//			std::cout <<"lock_buffer_10ms :"<< lock_buffer_10ms <<" xxx : "<<int(currentTime_start_new.wMilliseconds/10)<< std::endl;
			if (lock_buffer_100ms
					!= int(currentTime_start_new.wMilliseconds / 100)) { //換0.1秒
				lock_buffer_100ms = int(
						currentTime_start_new.wMilliseconds / 100);
				if (set_source == "Local") {
					modea = mode;
					if (mode == 6) {
						PQ_p_refa = PQ_p_ref;
						PQ_q_refa = PQ_q_ref;
					}
					if (mode == 0) {
						PQ_p_refa = 0;
						PQ_q_refa = 0;
					}
//					std::cout<<"PQ_p_refa :"<<PQ_p_refa<<std::endl;
//					std::cout<<"PQ_q_refa :"<<PQ_q_refa<<std::endl;
				}
				if (lock_buffer_1s != int(currentTime_start_new.wSecond)) { //是否換秒
//					std::cout <<"lock_buffer_1s :"<< lock_buffer_1s <<" xxx : "<<int(currentTime_start_new.wSecond)<< std::endl;
					lock_buffer_1s = int(currentTime_start_new.wSecond);
					next_sec = true;
				}
//				time_print_m("control_thread running", 1);
//				std::cout <<"next_sec :"<< next_sec << std::endl;
//				std::cout <<"modea :"<< modea << std::endl;
//				std::cout <<"control_flag :"<< control_flag << std::endl;
				std::thread *t_control_thread = nullptr;
				t_control_thread = new std::thread(
						[&]() {
							control_thread(std::ref(function_run),
									std::ref(thread_count), remote_first_run,
									set_source, pcs_control_local,
									pcs_reset_local, pcs_control_time_local,
									std::ref(HMdata), std::ref(LEDstate),
									std::ref(next_sec), std::ref(ability_test),
									std::ref(ability_test_count),
									std::ref(lock_buffer_100ms),
									std::ref(HM_error_count),
									std::ref(first_run), std::ref(path_dReg),
									std::ref(path_sReg), std::ref(sReg_flag),
									std::ref(pcs_out_pre_p),
									std::ref(pcs_out_pre_q), std::ref(HM_time),
									std::ref(HM_data), ems_count, mbms_count,
									soc, HM_ctx, std::ref(HM_ret_),
									std::ref(modbus_link_HM_flag), HM_f, HM_p,
									HM_v, HM_q, std::ref(pcs_out_p), PQ_p_refa,
									std::ref(pcs_out_q), PQ_q_refa, modea,
									soc_maxa, soc_mina, System_p_maxa,
									System_p_mina, System_q_maxa, System_q_mina,
									f_arra, p_arra, v_arra, q_arra, FP_typea,
									VC_typea, FP_soc_goal_percenta,
									FP_soc_dead_banda, PF_pf_refa, Vq_v_basea,
									Vq_q_basea, Vq_droopa, Vq_v_seta,
									control_ab_data, std::ref(VQ_Hys_line),
									std::ref(HM_v_last),
									std::ref(control_point), HM_eid, db,
									db_local, std::ref(error_flag1),
									std::ref(pcsdata), std::ref(pcs_reset),
									std::ref(pcs_control),
									std::ref(control_flag),
									std::ref(pcs_control_time_remote),
									std::ref(pcs_control_time),
									std::ref(pcs_read_error_count),
									pcs_read_arr, pcs_ip, pcs_port, pcs_id,
									pcs_read_ctx, std::ref(pcs_read_ret_),
									std::ref(modbus_link_pcs_read_flag),
									PCS_eid);
						});

				t_control_thread->join();
				delete t_control_thread;
//				std::cout <<"thread_count :"<< thread_count <<std::endl;
			}
		}

	});

	t.detach();
}
void Timer::stop() {
	this->clear = true;
}
