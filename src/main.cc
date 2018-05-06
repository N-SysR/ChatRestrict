#include "main.hh"
#include <err.h>

std::unordered_map<std::string,int> fill_words(std::ifstream input_file)
{
  std::string current;
  std::unordered_map<std::string,int> res;
  while(getline(input_file,current))
  {
    unsigned int i = 0;
    std::string behaviour;
    std::string word;
    for (; current.at(i) != ' '; ++i)
      behaviour += current.at(i);
    ++i;
    for (; i < current.length(); ++i)
      word += current.at(i);

    int karma = std::stoi(behaviour);
    if (karma < 5 || karma > 5)
      err(1,"Input dictionnary file not well formated");
    else
      res.insert({word, karma});
  }
  return res;
}

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
