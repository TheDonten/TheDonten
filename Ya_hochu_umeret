
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

static std::unordered_set<std::string> S;
static std::unordered_set<std::string> S2;
static std::unordered_set<std::string> S3;
static std::string main_str;
static std::string func = "10100111101000001001100100010001";
static int size_vecs;
std::vector<int> how_much_del(std::string str) {
  int a = str.size();
  std::vector<int> vec;
  while (a != 1) {
    a /= 2;
    vec.push_back(a);
  }
  return vec;
}
void print(
    std::string str,
    std::vector<std::vector<std::tuple<std::string, std::string, int, int>>>&
        start) {
  for (int i = 0; i < start.size(); ++i) {
    if (!start[i].empty()) {
      for (int j = 0; j < start[i].size(); ++j) {
        if (std::get<0>(start[i][j]) != "")
          std::cout << std::get<0>(start[i][j]) << "  ";
      }
      std::cout << "= " << str[i];
      std::cout << std::endl;
    }
  }
}
bool next_set(
    std::vector<std::vector<std::tuple<std::string, std::string, int, int>>>&
        vec,
    int n, int str, int k) {
  for (int i = k - 1; i >= 0; --i) {
    if (std::get<2>(vec[str][i]) < n - k + i + 1) {
      std::get<2>(vec[str][i]) += 1;

      for (int j = i + 1; j < k; ++j) {
        std::get<2>(vec[str][j]) = std::get<2>(vec[str][j - 1]) + 1;
      }
      return true;
    }
  }

  return false;
}

std::pair<std::string, int> pash(
    std::vector<std::vector<std::tuple<std::string, std::string, int, int>>>&
        start_func,
    int k, int i) {
  std::vector<std::tuple<std::string, std::string, int, int>> vec;
  bool flag = true;
  int stepen = k;
  for (int j = 0; j < k; j++) {
    if (flag) {
      vec.push_back(
          {std::get<0>(start_func[i][std::get<2>(start_func[i][j]) - 1]), "", 0,
           k});
      flag = false;
    } else
      std::get<0>(vec[0]) +=
          std::get<0>(start_func[i][std::get<2>(start_func[i][j]) - 1]);
  }

  S2.insert(std::get<0>(vec[0]));
  return {std::get<0>(vec[0]), k};
}

std::vector<std::pair<std::string, int>> create_komb(
    std::vector<std::vector<std::tuple<std::string, std::string, int, int>>>
        vec,
    int k, int n, int stroka) {
  std::vector<std::pair<std::string, int>> help;
  std::string str;
  help.push_back(pash(vec, k, stroka));
  while (next_set(vec, n, stroka, k)) {
    help.push_back(pash(vec, k, stroka));
  }

  return help;
}

std::vector<std::vector<std::tuple<std::string, std::string, int, int>>>
start_func(
    int size_vec, int size_str, std::vector<int> num,
    std::vector<std::vector<std::tuple<std::string, std::string, int, int>>>
        start) {
  bool flag = true;
  int k = 0, z = 0;
  for (int i = 0; i < size_vec; ++i) {
    flag = true;
    k = 0;
    z = 0;
    for (int j = 0; j < size_str; ++j) {
      if (flag) {
        std::get<0>(start[j][i]) = "0|X" + std::to_string(i + 1);
        S2.insert(std::get<0>(start[j][i]));
        std::get<1>(start[j][i]) = "0|X";
        std::get<2>(start[j][i]) = i + 1;
        ++k;
      } else {
        std::get<0>(start[j][i]) = "1|X" + std::to_string(i + 1);
        S2.insert(std::get<0>(start[j][i]));
        std::get<1>(start[j][i]) = "1|X";
        std::get<2>(start[j][i]) = i + 1;
        ++z;
      }
      if (k % num[i] == 0 && k != 0) {
        flag = false;
        k = 0;
      }
      if (z % num[i] == 0 && z != 0) {
        flag = true;
        z = 0;
      }
    }
  }

  for (int i = 0; i < size_str; ++i) {
    for (int k = 2; k < size_vec + 1; ++k) {
      std::vector<std::pair<std::string, int>> help;
      help = create_komb(start, k, size_vec, i);

      for (int s = 0; s < help.size(); ++s) {
        start[i].push_back({help[s].first, "", 0, help[s].second});
      }
    }
  }
  return start;
}

std::vector<std::vector<std::tuple<std::string, std::string, int, int>>> iniz(
    int size_str, int size_vec) {
  std::vector<std::vector<std::tuple<std::string, std::string, int, int>>>
      start;
  start.resize(size_str);
  for (int i = 0; i < start.size(); ++i) {
    start[i].resize(size_vec);
  }
  return start;
}

void check_null(
    std::string str,
    std::vector<std::vector<std::tuple<std::string, std::string, int, int>>>&
        start) {
  print(str, start);

  for (int i = 0; i < start.size(); ++i) {
    if (str[i] == '0') {
      for (int j = 0; j < start[i].size(); ++j) {
        S.insert(std::get<0>(start[i][j]));
      }
      start[i].clear();
    }
  }
  print(str, start);

  for (int i = 0; i < start.size(); ++i) {
    if (!start[i].empty()) {
      for (int j = 0; j < start[i].size(); ++j) {
        if (S.find(std::get<0>(start[i][j])) != S.end()) {
          if (S2.find(std::get<0>(start[i][j])) != S2.end()) {
            S2.erase(std::get<0>(start[i][j]));
          }

          std::get<0>(start[i][j]) = "";
        }
      }
    }
  }
  print(str, start);
}

bool check(std::string str1, std::string str2, int k, int l) {
  std::vector<std::string> vec1, vec2;
  bool flag = false;
  vec1.resize(k + 1);
  vec2.resize(l + 1);
  int count = 0;

  for (int j = 0; j < str1.size(); ++j) {
    if (j % 4 == 0 && j != 0) {
      ++count;
      vec1[count] += str1[j];
    } else {
      vec1[count] += str1[j];
    }
  }

  count = 0;

  for (int j = 0; j < str2.size(); ++j) {
    if (j % 4 == 0 && j != 0) {
      ++count;
      vec2[count] += str2[j];
    } else {
      vec2[count] += str2[j];
    }
  }
  count = 0;
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < k; ++j) {
      if (vec2[i] == vec1[j]) ++count;
    }
  }
  if (count == l)
    return true;
  else
    return false;
}

std::pair<std::string, int> manom(
    std::vector<std::tuple<std::string, std::string, int, int>>& start) {
  int k = 0;
  std::string str;
  for (int i = 0; i < start.size() - 1; ++i) {
    if (std::get<0>(start[k]) == "" && std::get<0>(start[i + 1]) == "") {
      ++k;
    } else if (std::get<0>(start[k]) == "" && std::get<0>(start[i + 1]) != "") {
      ++k;
    } else if (std::get<0>(start[k]) != "" && std::get<0>(start[i + 1]) == "")
      continue;
    else if (std::get<0>(start[k]) != "" && std::get<0>(start[i + 1]) != "") {
      if (std::get<3>(start[k]) > std::get<3>(start[i + 1])) {
        ++k;
      }
    }
  }
  return {std::get<0>(start[k]), std::get<3>(start[k])};
}
bool check_matrix(
    std::vector<std::vector<std::tuple<std::string, std::string, int, int>>>
        start) {
  bool flag = false;
  for (int i = 0; i < start.size(); ++i) {
    for (int j = 0; j < start[i].size(); ++j) {
      if (!start[i].empty()) {
        flag = true;
        return flag;
      }
    }
  }
  return flag;
}
void check_index(
    std::vector<std::vector<std::tuple<std::string, std::string, int, int>>>&
        start,
    int num) {
  std::string str;
  S2.clear();
  std::vector<std::pair<std::string, int>> kernell;
  std::pair<std::string, int> t;
  t.second = 0;
  bool flag = false;
  int a = 0;

  for (auto i = 0; i < start.size(); ++i) {
    if (!start[i].empty()) {
      t = manom(start[i]);

      for (int j = 0; j < start[i].size(); ++j) {
        if (std::get<0>(start[i][j]) == t.first) continue;
        if (std::get<0>(start[i][j]) != "" &&
            check(std::get<0>(start[i][j]), t.first, std::get<3>(start[i][j]),
                  t.second)) {
          std::get<0>(start[i][j]) = "";
        }
      }
    }
  }

  std::cout << std::endl;
  print(func, start);
  while (check_matrix(start)) {
    int k = 0;
    for (auto i = 0; i < start.size(); ++i) {
      k = 0;
      if (!start[i].empty()) {
        t = manom(start[i]);
        for (int j = 0; j < start[i].size(); ++j) {
          if (std::get<0>(start[i][j]) != "" &&
              std::get<0>(start[i][j]) != t.first) {
            ++k;
          }
        }
      }
      if (k == 0) {
        S2.insert(t.first);
      }
    }
    std::cout << "Yadra" << std::endl;
    for (auto& x : S2) {
      std::cout << x << " "
                << "---------------" << std::endl;
      ;
    }
    for (auto i = 0; i < start.size(); ++i) {
      k = 0;
      if (!start[i].empty()) {
        for (int j = 0; j < start[i].size(); ++j) {
          if (std::get<0>(start[i][j]) != "" &&
              S2.find(std::get<0>(start[i][j])) != S2.end()) {
            start[i].clear();
            break;
          }
        }
      }
    }
  }
  std::cout << std::endl;
  print(func, start);
  std::cout << std::endl;
}

void end_print(
    std::string str,
    std::vector<std::vector<std::tuple<std::string, std::string, int, int>>>&
        start) {
  std::cout << "F= ";

  int k = 0;

  for (auto& x : S2) {
    if (k == S2.size() - 1) {
      std::cout << x;

    } else {
      std::cout << x << " v ";
      ++k;
    }
  }
}

int main() {
  std::vector<int> num = how_much_del(func);
  size_vecs = num.size();

  std::vector<std::vector<std::tuple<std::string, std::string, int, int>>>
      start;
  start = iniz(func.size(), num.size());
  start = start_func(num.size(), func.size(), num, start);
  check_null(func, start);
  check_index(start, num.size());

  end_print(main_str, start);
}
