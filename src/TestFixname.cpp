#include <iostream>
#include <string>

std::string fName(std::string path){
  size_t last_dot = path.find_last_of('.');
  if(last_dot == std::string::npos){
    return (path + ".set");
  } else if(last_dot + 1 == path.length()){
    return (path + "set");
  } else{
    std::string ext = path.substr(last_dot + 1);
    if(ext.compare("set") != 0){
      return (path.substr(0, last_dot + 1) + "set");
    }
    return path;
  }
}

int main(){
  int size = 11;
  std::string tests[size];
  int i;
  tests[0] = "file.set";
  tests[1] = "file";
  tests[2] = "/some/long/path/myset.set";
  tests[3] = "set";
  tests[4] = ".set";
  tests[5] = "file.c";
  tests[6] = "random.dots.everywhere";
  tests[7] = "endswithdot.";
  tests[8] = "lol..cc";
  tests[9] = "...";
  tests[10] = "";

  for(i = 0;i < size; i++)
    std::cout << tests[i] << " -> " << fName(tests[i]) << std::endl;

  return 0;
}
