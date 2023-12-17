#include <iostream>
using namespace std;
int main() {
	cout<<"\t\t\t\t    Main Menu\n";
	cout<<"\t\t-------------------------------------------------------------------\n";
	cout<<"\t\t|    SYMBOLS\t|    ITEMS \t|     WEIGHTS\t    |   PRICES     |\n";
	cout<<"\t\t|\t\t|\t\t|\t\t    |\t\t   |\n";
	cout<<"\t\t|     C\t\t|    Cement \t| 24.9KG to 25.1KG  |\t  3$\t   |\n";
	cout<<"\t\t|     S\t\t|    Sand \t| 49.5KG to 50.1KG  |\t  2$\t   |\n";
	cout<<"\t\t|     G\t\t|    Gravel\t| 49.5KG to 50.1KG  |\t  2$\t   |\n";
	cout<<"\t\t-------------------------------------------------------------------\n\n";
    int c_sack, g_sack, s_sack;

    std::cout << "\t\tEnter the number of cement sacks: ";
    std::cin >> c_sack;

    std::cout << "\t\tEnter the number of gravel sacks: ";
    std::cin >> g_sack;

    std::cout << "\t\tEnter the number of sand sacks: ";
    std::cin >> s_sack;

    int actual_price = (c_sack * 3) + (g_sack * 2) + (s_sack * 2);
    int total_order = c_sack + g_sack + s_sack;

    int rej = 0;
    float total_weight = 0;
    
    for (int count = 1; count <= total_order; ++count) {
        std::cout << std::endl;
        char content;
        std::cout << "\t\tEnter the content of a sack, C for cement, G for gravel, and S for sand: ";
        std::cin >> content;

        float weight;

        if (content == 'C') {
            while (true) {
                std::cout << "\t\tEnter weight of cement sack between 24.9KG and 25.1KG: ";
                std::cin >> weight;
                if (24.9 <= weight && weight <= 25.1) {
                    break;
                } else {
                    std::cout << "\t\tSack is underweight or overweight" << std::endl;
                }
            }
        } else if (content == 'G' || content == 'S') {
            while (true) {
                std::cout << "\t\tEnter weight of " << content << " sack between 49.0KG and 50.1KG: ";
                std::cin >> weight;
                if (49.0 <= weight && weight <= 50.1) {
                    break;
                } else {
                    std::cout << content << "\t\tsack is underweight or overweight" << std::endl;
                }
            }
        } else {
            std::cout << "\t\tThe entered content is incorrect" << std::endl;
        }

        total_weight += weight;
    }

    std::cout << std::endl;
    std::cout << "\t\tThe total weight of order is: " << total_weight << std::endl;
    std::cout << "\t\tThe number of sacks rejected are: " << rej << std::endl;

    int sp = 0;
    int sp_price = 0;

    while (c_sack >= 1 && g_sack >= 2 && s_sack >= 2) {
        sp += 1;
        c_sack -= 1;
        g_sack -= 2;
        s_sack -= 2;
    }

    if (sp >= 1) {
        sp_price = sp * 10;
        std::cout << "\t\tTotal special packs are: " << sp << std::endl;
        std::cout << "\t\tPrice of special packs in dollars is: $" << sp_price << std::endl;

        int discount_price = (c_sack * 3) + (g_sack * 2) + (s_sack * 2) + sp_price;
        std::cout << "\t\tThe actual price of order is: $" << actual_price << std::endl;
        std::cout << "\t\tThe discounted price of order is: $" << discount_price << std::endl;

        int total_discount = actual_price - discount_price;
        std::cout << "\t\tTotal discount in order is: $" << total_discount << std::endl;
    } else {
        std::cout << "\t\tPrice of regular order in dollars is: $" << actual_price << std::endl;
    }

    return 0;
}
//CODED BY NOOR FATIMA
