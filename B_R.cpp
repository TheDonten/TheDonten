#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>


double EBSELENT = 0.1;

struct Table {
    int k = 0;
//    std::vector<std::pair<int,int>> Choose_player;
//    std::vector<std::tuple<int,int,int>> Win_A;
//    std::vector<std::tuple<int,int,int>> Loose_B;
    std::vector<std::vector<double>> Choose_player;
    std::vector<std::vector<double>> Win_A;
    std::vector<std::vector<double>> Loose_B;
    std::vector<double> max_win;
    std::vector<double> min_loose;
    std::vector<double> e;
};

bool check_element(std::vector<double> vec){
    for(int i = 0; i < vec.size() - 1; i++){
        if(vec[i] != vec[i + 1])
            return false;
    }
    return true;
}

double complexity_e(Table &T){
    return *std::min_element(T.max_win.begin(),T.max_win.end()) - *std::max_element(T.min_loose.begin(), T.min_loose.end());
}

std::vector <double> make_vector_choose (Table &T){
    std::vector<double> choose;
    if(T.Choose_player.empty()){
        choose = {0,0};
        return choose;
    }


    choose.push_back(std::distance(T.Win_A[T.k - 1].begin(),std::max_element(T.Win_A[T.k - 1].begin(),
                                                                             T.Win_A[T.k - 1].end())));
    choose.push_back(std::distance(T.Loose_B[T.k - 1].begin(),std::min_element(T.Loose_B[T.k - 1].begin(),
                                                                             T.Loose_B[T.k - 1].end())));
    return choose;
}



std::vector <double> make_vector_strategy (int i, bool str_or_column, std::vector<std::vector<double>> &C, Table &T){
    std::vector<double> strategy;

    if (str_or_column) {
        for (int k = 0; k < C.size(); k++) {
            strategy.push_back(C[k][i] + T.Win_A[T.k - 1][k]);
        }
        return strategy;
    }
    for (int k = 0; k < C[0].size(); ++k) {
        strategy.push_back(C[i][k] + T.Loose_B[T.k - 1][k]);
    }
    return strategy;


}

Table Braun_Robinson (std::vector<std::vector<double>> C){
    Table B_R;
    B_R.Choose_player.push_back(make_vector_choose(B_R));
//    B_R.Win_A.push_back(make_vector_strategy_init(0,true,C, B_R));
//    B_R.Loose_B.push_back(make_vector_strategy_init(0,false,C, B_R));
    B_R.Win_A.push_back( {C[0][0], C[1][0], C[2][0]});
    B_R.Loose_B.push_back({C[0][0], C[0][1], C[0][2]});
    B_R.max_win.push_back(*std::max_element(B_R.Win_A[B_R.k].begin(),B_R.Win_A[B_R.k].end()));
    B_R.min_loose.push_back(*std::min_element(B_R.Loose_B[B_R.k].begin(),B_R.Loose_B[B_R.k].end()));
    B_R.e.push_back(complexity_e(B_R));
    B_R.k += 1;

    while(B_R.e[B_R.k - 1] >= EBSELENT){
        B_R.Choose_player.push_back(make_vector_choose(B_R));
        B_R.Win_A.push_back(make_vector_strategy(B_R.Choose_player[B_R.k][1],true,C,B_R));
        B_R.Loose_B.push_back(make_vector_strategy(B_R.Choose_player[B_R.k][0],false,C,B_R));
        B_R.max_win.push_back(*std::max_element(B_R.Win_A[B_R.k].begin(),B_R.Win_A[B_R.k].end()) / (B_R.k + 1));
        B_R.min_loose.push_back(*std::min_element(B_R.Loose_B[B_R.k].begin(),B_R.Loose_B[B_R.k].end()) / (B_R.k + 1));
        B_R.e.push_back(complexity_e(B_R));
        B_R.k += 1;
    }

    return B_R;
}

int main() {

    std::vector<std::vector<double>> C = { {2,1,3},
                                            {3,0,1},
                                            {1,2,1}
    };

    Braun_Robinson(C);

    return 0;
}
