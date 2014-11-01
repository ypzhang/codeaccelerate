#include <chrono>
#include <ctime>
#include <iostream>
#include <thread>
#include <ratio>
#include <cstdio>
using namespace std;
using namespace std::chrono;

//typedef std::chrono::high_resolution_clock my_perf_clock;
typedef system_clock my_perf_clock;


my_perf_clock::time_point time_zero = my_perf_clock::now();

double ca_get_wtime()
{
  auto now = my_perf_clock::now();
  std::chrono::microseconds elapse_since_time_zero = duration_cast<microseconds>(now - time_zero);
  return double(elapse_since_time_zero.count()) / 1000000.0;
}

// Http://en.cppreference.com/w/cpp/chrono/duration/duration_cast
class ScopeTimer {
public:
  ScopeTimer(const char *_name):m_name(_name) {
    m_start = my_perf_clock::now();
  }
  ~ScopeTimer() {
    auto m_end = my_perf_clock::now();
    microseconds elapse_in_ms = duration_cast<microseconds>(m_end - m_start);
    cout << m_name << " elapsed " << elapse_in_ms.count() << " micro seconds" <<std::endl;
  }
    
private:
  string m_name;
  my_perf_clock::time_point m_start;
};

int main(int argc, char **argv)
{
  typedef ratio_multiply<my_perf_clock::period, kilo>::type TT;
  cout << fixed << "performance timing precision is " << double(TT::num)/TT::den << " milliseconds" << endl;
  {
    ScopeTimer ts("sleeping");
    milliseconds dura( 2401 );
    std::this_thread::sleep_for(dura);
  }
  
  {
    ScopeTimer ts("2nd sleeping");
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  return 0;
}
