#include <chrono>
#include <ctime>
#include <iostream>
#include <thread>
#include <ratio>
#include <cstdio>
using namespace std;
using namespace std::chrono;

// http://en.cppreference.com/w/cpp/chrono/duration/duration_cast
class ScopeTimer {
public:
  ScopeTimer(const char *_name):m_name(_name) {
    m_start = high_resolution_clock::now();
  }
  ~ScopeTimer() {
    auto m_end = high_resolution_clock::now();
    microseconds elapse_in_ms = duration_cast<microseconds>(m_end - m_start);
    cout << m_name << " elapsed " << elapse_in_ms.count() << " micro seconds" <<std::endl;
  }
    
private:
  string m_name;
  high_resolution_clock::time_point m_start;
};
int main(int argc, char **argv)
{
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
