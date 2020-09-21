#include <iostream>
#include <vector>

std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    //std::cout << "prev_location: " << prev_location << std::endl;
    //std::cout << "next_location: " << next_location << std::endl;
    // substr [,]
    //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

int main() {
  std::vector<double> x;
  std::vector<double> w;
  std::vector<double> y;
  bool pack_with_zeros = true;

  std::string s;
  std::cin >> s;
  if(s == "false") {
    pack_with_zeros = false;
  }
  std::cin >> s;
  x = readInVector(s);
  std::cin >> s;
  w = readInVector(s);

  // TODO write your code here
  // =========== START =========
  std::string comma;
  std::cout << "x: {";
  for (int i = 0; i < x.size(); i++) {
    if (i < x.size() - 1) {
      comma = ", ";
    } else {
      comma = "";
    }
    std::cout << x[i] << comma;
  }
  std::cout << "}" << std::endl;

  std::cout << "w: {";
  for (int i = 0; i < w.size(); i++) {
    if (i < w.size() - 1) {
      comma = ", ";
    } else {
      comma = "";
    }
    std::cout << w[i] << comma;
  }
  std::cout << "}" << std::endl;

  int sum;
  int vec;

  for (int k = -1; k < (int)(x.size() - 1); k++) {
    sum = 0;
    for (int i = 0, j = k; i < w.size(); i++, j++) {
      if (pack_with_zeros && (j == -1 || j > x.size() - 1)) {
        vec = 0;
      } else if (j == -1) {
        vec = x[j+1];
      } else if (j > x.size() - 1){
        vec = x[j-1];
      } else {
        vec = x[j];
      }
      sum += vec * w[i];
    }
    y.push_back(sum);
  }

  std::cout << "{";
  for (int i = 0; i < y.size(); i++) {
    if (i < y.size() - 1) {
      comma = ", ";
    } else {
      comma = "";
    }
    std::cout << y[i] << comma;
  }
  std::cout << "}" << std::endl;
  // =========== END ===========

  return 0;
}

