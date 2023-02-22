#include "std_chrono.h"

void test_chrono()
{
	using namespace std::chrono;
	//3600s = 1h
	seconds td_s(3600);
	auto td_h = duration_cast<hours>(td_s);
	std::cout << td_h.count() << std::endl;

	//1ms = 1000us
	milliseconds td_ms(1);
	auto td_us = duration_cast<microseconds>(td_ms);
	std::cout << td_us.count() << std::endl;

	//1us = 0.001ms
	microseconds td2_us(1);
	auto td2_ms = duration_cast<duration<double, std::ratio<1, 1000>>>(td2_us);
	std::cout << td2_ms.count() << std::endl;
	
	//197001010800(注意系统时钟取决于时区)
	time_point<system_clock, seconds> tp_sys_s(seconds(0));
	std::cout << tp_sys_s.time_since_epoch().count() << std::endl;
	std::time_t tt = system_clock::to_time_t(tp_sys_s);
	std::cout << ctime(&tt) << std::endl;

	time_point<system_clock> today = system_clock::now();
	auto x = system_clock::to_time_t(today);
	std::cout << x << std::endl;
	std::cout << ctime(&x) << std::endl;
	duration<int, std::ratio<60 * 60, 1>> one_day(24);
	time_point<system_clock> tomorrow = today + one_day;
	time_point<system_clock> yesterday = today - one_day;
	time_point<system_clock> day_after_tomorrow = today + one_day * 2;
	x = system_clock::to_time_t(tomorrow);
	std::cout << ctime(&x) << std::endl;
	x = system_clock::to_time_t(yesterday);
	std::cout << ctime(&x) << std::endl;
	x = system_clock::to_time_t(day_after_tomorrow);
	std::cout << ctime(&x) << std::endl;
	
	time_point<system_clock> start_1 = system_clock::now();
	unsigned long long s = 0;
	for (size_t i = 0; i < 100; i++)
	{
		s += 1;
		std::cout << s << std::endl;
	}
	time_point<system_clock> end_1 = system_clock::now();
	auto td_1 = end_1 - start_1;
	auto s1 = system_clock::to_time_t(start_1);
	auto e1 = system_clock::to_time_t(end_1);
	std::cout << "start @ " << s1 << std::endl;
	std::cout << "end   @ " << e1 << std::endl;
	auto td_1_ms = duration_cast<duration<double, std::ratio<1, 1000>>>(td_1);
	auto td_1_us = duration_cast<duration<double, std::ratio<1, 1000000>>>(td_1);
	std::cout << td_1.count() << "? = " << td_1_ms.count() << "ms = " << td_1_us.count() << "us" << std::endl;

	return;
}