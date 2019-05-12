#include "std_lib_facilities.h"

// item name
vector<string>item{"Amethyst", "Turquoise", "Sapphire", "Topaz", "Emerald", "Ruby", "Tiger's Eye", "Gold"};
// price per gram
vector<double>price{0.12, 0.05, 0.2, 0.421, 0.114, 0.47, 0.11, 40.95 };
// weight in grams
vector<double>weight{10, 20, 30, 40, 50, 60, 70, 2};
// value of item
vector<double>item_price{};


double maxv(vector<double> v) {
        sort(v);
        return v[v.size()-1];
}

// compute prices in function of value/gram and weight
int main() {
    //computing prices
    for (int i = 0; i < item.size(); ++i) {
        double p = price[i] * weight[i];
        item_price.push_back(p);
    }
    // print prices
    for (int i = 0; i < item.size(); ++i) {
        cout << weight[i] << " grams of " << item[i]
             << " = " << item_price[i] << "$" << "\n";
    }
    // print value/gram
    cout << "highest value/gram: " << maxv(price) << "$/g\n";
}
