#include <iostream>
#include <chrono>

int main()
{
	//3600s = 1h
	std::chrono::seconds td_s(3600);
	auto td_h = std::chrono::duration_cast<std::chrono::hours>(td_s);
	std::cout << td_h.count() << std::endl;

	//1ms = 1000us
	std::chrono::milliseconds td_ms(1);
	auto td_us = std::chrono::duration_cast<std::chrono::microseconds>(td_ms);
	std::cout << td_us.count() << std::endl;

	//1us = 0.001ms
	std::chrono::microseconds td2_us(1);
	auto td2_ms = std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1, 1000>>>(td2_us);
	std::cout << td2_ms.count() << std::endl;
	
	//197001010000(注意系统时钟取决于时区)
	std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> tp_sys_s(std::chrono::seconds(0));
	std::cout << tp_sys_s.time_since_epoch().count() << std::endl;
	std::time_t tt = std::chrono::system_clock::to_time_t(tp_sys_s);
	std::cout << ctime(&tt) << std::endl;

	std::chrono::time_point<std::chrono::system_clock> today = std::chrono::system_clock::now();
	auto x = std::chrono::system_clock::to_time_t(today);
	std::cout << x << std::endl;
	std::cout << ctime(&x) << std::endl;
	std::chrono::duration<int, std::ratio<60 * 60, 1>> one_day(24);
	std::chrono::time_point<std::chrono::system_clock> tomorrow = today + one_day;
	std::chrono::time_point<std::chrono::system_clock> yesterday = today - one_day;
	std::chrono::time_point<std::chrono::system_clock> day_after_tomorrow = today + one_day * 2;
	x = std::chrono::system_clock::to_time_t(tomorrow);
	std::cout << ctime(&x) << std::endl;
	x = std::chrono::system_clock::to_time_t(yesterday);
	std::cout << ctime(&x) << std::endl;
	x = std::chrono::system_clock::to_time_t(day_after_tomorrow);
	std::cout << ctime(&x) << std::endl;
	
	return 0;
}