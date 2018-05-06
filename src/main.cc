#include "main.hh"
#include <fstream>

int main(int argv, char* argc[])
{
  if (argv != 3)
  {
    std::cerr << "Wrong number of arguments." << std::endl;
    return 1;
  }
  std::ifstream inp_dic (argc[1]);
  if (!inp_dic.is_open())
  {
    std::cerr << argc[1] << " Is not a valid file" << std::endl;
    return 1;
  }

  std::ifstream inp_log (argc[2]);
  if (!inp_log.is_open())
  {
    std::cerr << argc[2] << " Is not a valid file" << std::endl;
    return 1;
  }


  inp_dic.close();
  inp_log.close();
  return 0;
}
