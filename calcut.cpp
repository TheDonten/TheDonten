#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <random>
#include <vector>

double damage = 100;
double t_90 = 1.645
trees_t * treehead = nullptr;

struct max_damage{
    double base_damage;
    double base_chance_crit;
    double agility;
    double range_atk;
    double art_killing;
    double all_damage;
    double level;
    
};

max_damage winable;
winable->all_damage = 0;

struct trees_t{

    trees * root;

    double base_damage;
    double base_chance_crit;
    double sum_middle_damage;
    double agility;
    double range_atk;
    double art_killing;
    double all_damage;
    double level;
    trees * left_ch;
    trees * right_ch;
};

double f1(double chance){
    return rand() % chance;
}

int f2(int l, int r){
    int mean = (l + r) / 2;
    int sigma = (r - l) / (2 * t_90);
    std::mt19937 generator;
    std::normal_distribution<double> normal (mean,stddev);
    return normal(generator);
}


double check_damage_per_three_shots (double base_damage, double chance_crit, double multi_art){
    int min = (damage * (base_damage / 100 + 1)) * 3;
    int max = ((damage*(base_damage / 100 + 1))*((multi_art*10 / 100 + 0.6) + 1)) * 3;

    double sum = 0;

    for(int i = 0; i < 10000; i++){
        sum = f1(chance_crit)*f2(min,max);
    }
    return sum / 10000;
}
void create_tree(trees_t * node, double agil, double level, double free_podoubles,double art, double range){
    
    if(free_podoubles == 0)
        return;

    trees_t * node_time = new trees_t;
    if ( treehead == nullptr){
        node_time->base_damage = 10;
        node_time->base_chance_crit = 10;
        node_time->agility = agil;
        node_time->range_atk = 0;
        node_time->art_killing = 0;
        node_time->all_damage = 0;
        node_time->level = 0;
        treehead = node_time;
    }
    else {
         node_time->base_damage = 10 + agil*10 + range*10;
         node_time->base_chance_crit = 10 + 2*range;
         node_time->agility = agil;
         node_time->range_atk = range;
         node_time->art_killing = art;
         node_time->all_damage = (damage*(base_damage / 100 + 1))*((art*10 / 100 + 0.6) + 1);
         node_time->level = level;
         node = node_time;
        if(winable.all_damage < node_time->all_damage){
            winable.base_damage = node_time->base_damage;
            winable.base_chance_crit = node_time->base_chance_crit;
            winable.agility = node_time->agility;
            winable.range_atk = node_time->range_atk;
            winable.art_killing = node_time->art_killing;
            winable.all_damage = node_time->all_damage;
            winable.level  = node_time->level;
        }
    }

   

    double sum_damage_per_three_shoots_range = check_damage_per_three_shots(10 + agil*10 + (range+1)*10, 10 + 2*(range+1), (art*10 / 100 + 0.6) + 1 );
    double sum_damage_per_three_shoots_art = check_damage_per_three_shots(10 + agil*10 + range*10, 10 + 2*range, ((art + 1)*10 / 100 + 0.6) + 1 );

    std::cout << "Check middle damages per level for up range=" << sum_damage_per_three_shoots_range << "by level tree =" << level << '/n';
     std::cout << "Check middle damages per level for up art=" << sum_damage_per_three_shoots_art << "by level tree =" << level << '/n';

    if(sum_damage_per_three_shoots_range > sum_damage_per_three_shoots_art)
        create_tree(node_time->left_ch, agil, node_time->level + 1, free_podoubles - 1, node_time->art_killing, node_time->range_atk + 1);
        winable.sum_middle_damage = 0;
    else
        create_tree(node_time->right_ch, agil, node_time->level + 1, free_podoubles - 1, node_time->art_killing + 1, node_time->range_atk);
        winable.sum_middle_damage = 0;

    
}

/*void insert_list(trees * child, double free_podoubles){



}*/

void cout_stats (max_damage dam){
    std::cout << "Boost damages =" << dam.base_damage << '\n';
    std::cout << "All damages =" << dam.all_damage << '\n';
    std::cout << "Sum middle_damage_per_3_shots =" << dam.sum_middle_damage << '\n';
    std::cout << "agility =" << dam.agility << '\n';
    std::cout << "Range attack =" << dam.range_atk << '\n';
    std::cout << "art killing =" << dam.art_killing << '\n';
    std::cout << "level =" << dam.level << '\n';
}


double main(){

    double agil = 1;
     srand( time( 0 ) );

    for (int i = 0; i < agil; i++){
        trees_t *  treehead = nullptr;
            winable.base_damage = 0;
            winable.base_chance_crit = 0;
            winable.sum_middle_damage = 0;
            winable.agility = 0;
            winable.range_atk = 0;
            winable.art_killing = 0;
            winable.all_damage = 0;
            winable.level  = 0;
        create_tree(treehead,i,0,5,0,0);
    }

}
