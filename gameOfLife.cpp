

void game_of_life() {
    clean;
    // Setup inital configuration

    // Scan cube
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int z = 0; z < 8; z++) {
                // check neighbors and save value
                check_neighbors(i, j, z);
            }
        }
    }

    // update state
}

/**
 * Check the LED's neighbors.
 * Live cell with < 2 live neighbors dies
 * Live cell with 2 <= x <= 3 neighbors lives (mutate color)
 * Live cell with > 3 neighbors dies
 * Dead cell with 3 neighbors lives (avg colors)
 * Survivors should increase their brightness
 */
void check_neighbors(int i, int j, int z) {
    // CONSTANTS
    int neighbor_min = 2;
    int neighbor_max = 3;
    // int color_max =

    int i_start = (i > 0) ? i - 1: 0;
    int j_start = (j > 0) ? j - 1: 0;
    int z_start = (z > 0) ? z - 1: 0;
    int i_max = (i < 7) ? i + 1: 7;
    int j_max = (j < 7) ? j + 1: 7;
    int z_max = (z < 7) ? z + 1: 7;
    int neighbor_count = 0;

    int blue = 0;
    int green = 0;
    int red = 0;

    for (int itr = i_start; itr < i_max; itr++) {
        for (int jtr = j_start; jtr < j_max; jtr++) {
            for (int ztr = z_start; ztr < z_max; ztr++) {
                if (itr == i && jtr == j && ztr == z) {
                    continue;
                }
                // How do I fetch an LED value?
                led = LED(itr, jtr, ztr);
                neighbor_count = led.isOn() ? neighbor_count + 1: neighbor_count;
                blue += led.blue();
                green += led.green();
                red += led.red();
            }
        }
    }
    // TODO fix floating point conversion
    blue = blue / neighbor_count;
    green = green / neighbor_count;
    red = red / neighbor_count;

    if (neighbor_min <= neighbor_count <= neighbor_max) {
        return (1, red, green, blue);
    }
    return (0, 0, 0, 0);
}