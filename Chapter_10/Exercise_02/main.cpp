#include "store_temps.h"
#include "temp_stats.h"

int main() {
    // info: store temp readings from "temps_1.txt" in a new file "temps_2.txt"
    store_temps();
    compute_mean_temps();
}
