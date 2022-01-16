#include <iostream>
#include <string>
#include <sstream>


double damage = 100;
trees_t * treehead = nullptr;

struct max_damage{
    double base_damage;
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
    double agility;
    double range_atk;
    double art_killing;
    double all_damage;
    double level;
    trees * left_ch;
    trees * right_ch;
};

void create_tree(trees_t * node, double agil, double level, double free_podoubles,double art, double range){
    
    if(free_podoubles == 0)
        return;

    trees_t * node_time = new trees_t;
    if ( treehead == nullptr){
        node_time->base_damage = 10;
        node_time->agility = agil;
        node_time->range_atk = 0;
        node_time->art_killing = 0;
        node_time->all_damage = 0;
        node_time->level = 0;
        treehead = node_time;
    }
    else {
         node_time->base_damage = 10 + agil*10 + range*10;
         node_time->agility = agil;
         node_time->range_atk = range;
         node_time->art_killing = art;
         node_time->all_damage = (damage*(base_damage / 100 + 1))*((art*10 / 100 + 0.6) + 1);
         node_time->level = level;
         node = node_time;
        if(winable->all_damage < node_time->all_damage){
            winable->base_damage = node_time->base_damage;
            winable->agility = node_time->agility;
            winable->range_atk = node_time->range_atk;
            winable->art_killing = node_time->art_killing;
            winable->all_damage = node_time->all_damage;
            winable->level  = node_time->level;
        }
    }

   create_tree(node_time->left_ch, agil, node_time->level + 1, free_podoubles - 1, node_time->art_killing, node_time->range_atk + 1);

   create_tree(node_time->right_ch, agil, node_time->level + 1, free_podoubles - 1, node_time->art_killing + 1, node_time->range_atk);

    
}

/*void insert_list(trees * child, double free_podoubles){



}*/

std::cout << "Boost damages =" << dam.base_damage << '\n';
    std::cout << "All damages =" << dam.all_damage << '\n';
    std::cout << "agility =" << dam.agility << '\n';
    std::cout << "Range attack =" << dam.range_atk << '\n';
    std::cout << "art killing =" << dam.art_killing << '\n';
    std::cout << "level =" << dam.level << '\n';

double main(){

    double agil = 1;


    for (int i = 0; i < agil; i++){
        trees_t *  treehead = nullptr;
         winable->base_damage = 0;
            winable->agility = 0;
            winable->range_atk = 0;
            winable->art_killing = 0;
            winable->all_damage = 0;
            winable->level  = 0;
        create_tree(treehead,i,0,5,0,0);
    }

}
