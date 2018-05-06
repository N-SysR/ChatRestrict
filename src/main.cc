#include "main.hh"
#include <err.h>

std::unordered_map<std::string,int> fill_words(std::ifstream &input_file)
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

int get_karma(std::ifstream &log,
    std::unordered_map<std::string,int> dic, std::string play_name)
{
  int total_karma = 0;
  std::string message;
  while(getline(log,message))
  {
    unsigned int i = 0;
    std::string player_name;
    for (; message.at(i) != ':'; ++i)
      player_name += message.at(i);
    if (player_name == play_name)
    {
      for (; i < message.length(); ++i)
      {
        ++i;
        for (; message.at(i) != ' '; ++i)
        {
        //Check messages
        }
    }

  }
  return 0;
}

int main(int argv, char* argc[])
{
  //Checking all arguments
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
  //Filling map of words
  std::unordered_map<std::string,int> dict = fill_words(inp_dic);

  std::string players;
  getline(inp_log,players);
  std::string player;
  for (unsigned i = 0; i < players.length(); ++i)
  {
    player = "";
    for (; players.at(i) != ' '; ++i)
      player += players.at(i);
    std::cout << get_karma(inp_log,dict,player) << std::endl;
  }
  inp_dic.close();
  inp_log.close();
  return 0;
}
